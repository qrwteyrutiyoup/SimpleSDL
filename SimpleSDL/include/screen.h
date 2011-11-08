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

#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <deque>
#include <string>

#include "components.h"

namespace SimpleSDL {
	class Screen {
	public:
		Screen(std::string description, SDL_Surface *surface, std::string bgimage);
		~Screen();

		void show();
		void invalidate();
		void add_component(Component *component);

		// pointer to screen surface
		SDL_Surface *surface;

	private:
		// background data
		SDL_Surface *background;
		std::string bgimage_path;

		// screen description
		std::string description;

		// components list
		std::deque<Component *> components;

		void draw_components();
	};
}

#endif // __SCREEN_H__
