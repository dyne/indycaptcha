#include <stdio.h>
#include <stdlib.h>

#include <jutils.h>
#include <captcha.h>

// simple usage example
int main(int argc, char **argv) {
	(void)argc;
	notice("generating %s",argv[1]);
	FILE *fd = fopen(argv[1],"w");
	if(!fd) return 1;
	return generaCaptcha(fd,40.0,"Hello world");
	
}
