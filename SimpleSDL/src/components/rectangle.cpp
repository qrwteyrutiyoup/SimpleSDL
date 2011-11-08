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

#include <cassert>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "components/rectangle.h"
#include "sdl_utils.h"

namespace SimpleSDL {

	Rectangle::Rectangle(Sint16 x, Sint16 y, Uint16 w, Uint16 h, SDL_Color color)
	{
		this->x = x;
		this->y = y;
		this->width = w;
		this->height = h;
		this->color = color;
		this->alpha = 255;
		this->hidden = false;
		this->redraw = true;
	}

	void Rectangle::hide()
	{
		hidden = true;
	}

	void Rectangle::unhide()
	{
		hidden = false;
	}

	void Rectangle::invalidate()
	{
		/* set redraw flag */
		redraw = true;
	}

	void Rectangle::draw()
	{
		SDL_Rect rect;
		SDL_Surface *rectangle = NULL, *base = NULL;

		assert(screen);

		/* check redraw flag */
		if (!redraw)
			return;

		if (!hidden) {
			if (!(base = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCALPHA, width, height, SCREEN_BPP, 0xff << 16, 0xff << 8, 0xff, 0xff))) {
				fprintf(stderr, "%s: Error creating surface: %s\n", __FUNCTION__, SDL_GetError());
				assert(base);
			}

			rectangle = SDL_DisplayFormat(base);

			SDL_FreeSurface(base);

			if (SDL_FillRect(rectangle, NULL, SDL_MapRGB(rectangle->format, color.r, color.g, color.b)) == -1) {
				fprintf(stderr, "Error filling rectangle: %s\n", SDL_GetError());
				assert(0);
			}

			if (SDL_SetAlpha(rectangle, SDL_SRCALPHA, alpha) == -1) {
				fprintf(stderr, "Error setting alpha on rectangle: %s\n", SDL_GetError());
				assert(0);
			}

			rect.x = x;
			rect.y = y;
			SDL_BlitSurface(rectangle, NULL, screen->surface, &rect);
			SDL_FreeSurface(rectangle);

			/* clear redraw flag */
			redraw = false;
		}
	}

	void Rectangle::set_transparency_level(Sint8 transparency)
	{
		alpha = (Uint8)(255 - (255 * transparency) / 100);
	}
}
