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

#include <string>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "screen.h"
#include "sdl_utils.h"

namespace SimpleSDL {

	Screen::Screen(std::string description, SDL_Surface *surface, std::string bgimage)
	{
		assert(surface);

		this->surface = surface;
		this->description = description;
		this->bgimage_path = bgimage;

		this->background = sdl_load_image(this->bgimage_path);
	}

	Screen::~Screen()
	{
		surface = NULL;

		description.clear();
		bgimage_path.clear();

		if (background) {
			SDL_FreeSurface(background);
			background = NULL;
		}

		// the components now
		if (components.size() > 0) {
			Component *c = NULL;

			for (size_t i = 0, total = components.size(); i < total; i++) {
				c = components[i];
				delete c;
			}

			components.clear();
		}
	}

	void Screen::add_component(Component *component)
	{
		assert(component);

		components.push_back(component);
		component->set_screen(this);
	}


	void Screen::show()
	{
		assert(surface);

	#ifdef DEBUG
		std::cout << __FUNCTION__ << " [" <<  description << "]" << std::endl;
	#endif

		sdl_apply_surface(background, surface, 0, 0);

		draw_components();

		SDL_Flip(surface);
	}


	void Screen::draw_components()
	{
		if (components.size() > 0) {
			Component *c = NULL;

			for (size_t i = 0, total = components.size(); i < total; i++) {
				c = components[i];
				c->draw();
			}
		}
	}

	void Screen::invalidate()
	{
		if (components.size() > 0) {
			Component *c = NULL;

			for (size_t i = 0, total = components.size(); i < total; i++) {
				c = components[i];
				c->invalidate();
			}
		}
	}
}
