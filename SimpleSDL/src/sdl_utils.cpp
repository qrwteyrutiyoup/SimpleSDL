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

#include <iostream>
#include <cassert>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "sdl_utils.h"
#include "screen.h"


/* perform cleanup */
void sdl_cleanup()
{
	/* quit SDL_ttf */
	TTF_Quit();

	/* quit SDL */
	SDL_Quit();
}

/* perform initialization */
SDL_Surface *sdl_initialize_screen(std::string progname)
{
	SDL_Surface *sdl_screen = NULL;

	/* initialize SDL video subsystem */
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	/* clean up on exit */
	atexit(sdl_cleanup);

	/* setup screen surface */
	if (!(sdl_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
			SDL_SWSURFACE))) {
		fprintf(stderr, "Error setting %dx%dx%d video mode: %s\n", SCREEN_WIDTH,
				SCREEN_HEIGHT, SCREEN_BPP, SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* initialize SDL_ttf */
	if (TTF_Init() == -1)
		exit(EXIT_FAILURE);

	if (progname.length() > 0) {
		SDL_WM_SetCaption(progname.c_str(), NULL);
	}

	/* ignore mouse events */
	//SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);

	/* do not show mouse cursor */
//	SDL_ShowCursor(0);

	return sdl_screen;
}


/* load image file into surface */
SDL_Surface *sdl_load_image(std::string filename)
{
	SDL_Surface *loaded = NULL, *optimized = NULL;

	/* load image */
	if (!(loaded = IMG_Load(filename.c_str()))) {
		std::cout << "Error loading image [" << filename << "]: " <<  SDL_GetError() << std::endl;
		assert(loaded);
	}

	/* create optimized image */
	optimized = SDL_DisplayFormat(loaded);

	/* free old image */
	SDL_FreeSurface(loaded);

	/* abort on optimization error */
	if (!optimized) {
		std::cout << "Error optimizing image [" << filename << "]: " <<  SDL_GetError() << std::endl;
		assert(optimized);
	}

	/* return optimized image */
	return optimized;
}

/* load font file */
TTF_Font *load_font(std::string filename, int size)
{
	TTF_Font *loaded = NULL;

	/* load font */
	if (!(loaded = TTF_OpenFont(filename.c_str(), size))) {
		std::cout << "Error loading font [" << filename << "]: " <<  SDL_GetError() << std::endl;
		assert(loaded);
	}

	/* return loaded font */
	return loaded;
}

/* apply source surface to destination surface */
void sdl_apply_surface(SDL_Surface *source, SDL_Surface *dest, Sint16 x, Sint16 y)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = 0;
	rect.h = 0;

	/* blit surface */
	SDL_BlitSurface(source, NULL, dest, &rect);
}

int sdl_enqueue_userevent(int code, void *data1, void *data2)
{
	SDL_Event event;
	SDL_UserEvent userEvent;

	userEvent.type = SDL_USEREVENT;
	userEvent.code = code;
	userEvent.data1 = data1;
	userEvent.data2 = data2;
	event.type = SDL_USEREVENT;
	event.user = userEvent;

	return SDL_PushEvent(&event);
}
