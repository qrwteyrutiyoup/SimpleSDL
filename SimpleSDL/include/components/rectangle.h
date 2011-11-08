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

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <SDL/SDL.h>

#include "component.h"

namespace SimpleSDL {

	class Rectangle : public Component {
	public:
		Rectangle(Sint16 x, Sint16 y, Uint16 w, Uint16 h, SDL_Color color);
		void draw();
		void invalidate();
		void set_transparency_level(Sint8 transparency);
		void hide();
		void unhide();

	private:
		Sint16 x;
		Sint16 y;
		Uint16 width;
		Uint16 height;
		Uint8 alpha;
		SDL_Color color;
		bool redraw;
		bool hidden;
	};
}

#endif // __RECTANGLE_H__
