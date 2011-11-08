/***************************************************************************
 *   Copyright (C) 2011 by Sergio Luis O. B. Correia                       *
 *   sergio.correia@uece.net                                               *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef __SDL_UTILS_H__
#define __SDL_UTILS_H__

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "screen.h"

/* screen attributes */
const int SCREEN_BPP = 32;
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 300;

SDL_Surface *sdl_initialize_screen(std::string progname);
SDL_Surface *sdl_load_image(std::string filename);
TTF_Font *sdl_load_font(std::string filename, int size);
void sdl_apply_surface(SDL_Surface *source, SDL_Surface *dest, Sint16 x, Sint16 y);
int sdl_enqueue_userevent(int code, void *data1, void *data2);
void sdl_cleanup();

#endif // __SDL_UTILS_H__
