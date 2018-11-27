/* Jaro CGI (part of Jaro Web)
 *
 *  (C) Copyright 2013 Denis Roio <jaromil@dyne.org>
 *
 * This source code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Affero Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This source code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  Please refer
 * to the GNU Afffero Public License for more details.
 *
 * You should have received a copy of the GNU Affero Public License
 * along with this source code; if not, write to: Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */


// Nuovo codice di generazione Captcha - usa libGD2

#define _XOPEN_SOURCE 1
 
#include <time.h>
#include <sys/time.h>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

#include <gd.h>

#include "captcha.h"
#include "jutils.h"

// static char *font = "/usr/share/fonts/truetype/freefont/FreeSerif.ttf";
static char *font = "/usr/share/fonts/dejavu/DejaVuSerif.ttf";

static int bg_color;
static int fg_color; 

static gdImagePtr image;  

void vertical_distort(gdImagePtr image, int factor);
void horizontal_distort(gdImagePtr image, int factor);

void get_delta_1(int* delta, int length, int factor);
void get_delta_2(int* delta, int length, int factor);
int randint(int a, int b) { return rand() % (b - a + 1) + a; }

static int w, h;

int generaCaptcha(FILE *fp, float sz, char *str) {
  int brect[8];
  int x, y;
  char *err;
  int line_col;


  /* obtain brect so that we can size the image */
  err = gdImageStringFT(NULL,&brect[0],0,font,sz,0.,0,0,str);
  if(err) { fprintf(stderr,"CAPTCHA ERROR: %s\n", err); return(0); }
  
  /* create an image big enough for the string plus a little whitespace */
  w = brect[2]-brect[6] + 32;
  h = brect[3]-brect[7] + 32;
  image = gdImageCreate(w,h);
  
  // primo colore e' background
  bg_color = gdImageColorAllocate(image, 0xff, 0xff, 0xff); // bianco
  fg_color = gdImageColorAllocate(image, 0, 0, 0); // nero

  line_col = gdImageColorAllocate(image, 100, 100, 100); // grigio
  gdImageFilledRectangle (image, 0, 20, w, 22, line_col);
  gdImageFilledRectangle (image, 0, h/2, w, (h/2)+2, line_col);


  x = 8 - brect[6];
  y = 8 - brect[7];
  err = gdImageStringFT(image, brect, fg_color, font, sz, 0., x, y, str);
  if(err) { fprintf(stderr,"CAPTCHA ERROR: %s\n", err); return(0); }

  func("Captcha drawn in rect: %i %i %i %i %i %i %i %i",
    brect[0], brect[1], brect[2], brect[3], brect[4], brect[5], brect[6], brect[7]);



  //  gdImageLine (image, 0, h-30, w, h-30, fg_color);

  vertical_distort(image, 20);
  horizontal_distort(image, 20);
  //smooth(image);
  gdImagePng(image, fp);
  fclose(fp);

  gdImageDestroy(image);

  return(1);
}

void vertical_distort(gdImagePtr image, int factor)
{
	int x, y, t;
	int height = gdImageSY(image);
	int width = gdImageSX(image);
	int *delta = calloc(height, sizeof(int));

	get_delta_1( delta, height, factor );
	for(y = 0; y < height; y++){
	  if(delta[y] >= 0){
            for(x = width - 1, t = x - delta[y]; x >= delta[y]; x--, t--){
	      gdImageSetPixel(image, x, y, gdImageGetPixel(image, t, y));
            }
            while(x >= 0){
	      gdImageSetPixel(image, x, y, bg_color);
	      x--;
            }
	  }
	  else{
            for(x = 0, t = x - delta[y]; x < width + delta[y]; x++, t++){
	      gdImageSetPixel(image, x, y, gdImageGetPixel(image, t, y));
            }
            while(x < width){
	      gdImageSetPixel(image, x, y, bg_color);
	      x++;
            }
	  }
	}
	free(delta);
}

void horizontal_distort(gdImagePtr image, int factor) {
  int x, y, t;
  int height = gdImageSY(image);
  int width = gdImageSX(image);
  int *delta = calloc(width, sizeof(int));

  get_delta_2( delta, width, factor );

  for(x = 0; x < width; x++){
    if(delta[x] >= 0){
      for(y = height - 1, t = y - delta[x]; y >= delta[x]; y--, t--){
	gdImageSetPixel(image, x, y, gdImageGetPixel(image, x, y));
      }
      while(y >= 0){
	gdImageSetPixel(image, x, y, bg_color);
	y--;
      }
    }
    else{
      for(y = 0, t = y - delta[x]; y < width + delta[x]; y++, t++){
	gdImageSetPixel(image, x, y, gdImageGetPixel(image, x, t));
      }
      while(y < width){
	gdImageSetPixel(image, x, y, bg_color);
	y++;
      }
    }
  }
  free(delta);
}

void get_delta_1(int* delta, int length, int factor)
{
	int p[3] = {0, 0, 0};
	int i;
	double t;

	p[1] = randint(-factor, factor);
	//	printf("%d %d\n", factor, p[1]);
	for(i = 0; i < length; i++){
		t = i / (double)length;
		delta[i] = (int)((1 - t) * (1 - t) * (1 - t) * p[0] +
			3 * t * (1 - t) * p[1] +
			t * t * t * p[2]);
	}
}

void get_delta_2(int* delta, int length, int factor){
	#define min_curvature  7
	#define max_curvature  12
    int offset = randint(-factor, factor);
    int a = randint(min_curvature, max_curvature);
    int i;
    double t;
    double b = drand48() * 2 * M_PI;
    for(i = 0; i < length; i++){
        t = i / (double)length;
        delta[i] = (int)(offset * sin(a * t + b));
    }
}
