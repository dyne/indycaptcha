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

#ifndef __CAPTCHA_H__
#define __CAPTCHA_H__

// ritorna 1=successo 0=errore
int generaCaptcha(FILE *fp, float sz, char *str);

#endif
