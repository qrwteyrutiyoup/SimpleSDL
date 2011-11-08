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

#include "screen.h"
#include "sdl_utils.h"

static SDL_Surface *screen_surface = NULL;

SimpleSDL::Screen *create_main_screen(SDL_Surface *surface)
{
	// create the window
	SimpleSDL::Screen *s = new SimpleSDL::Screen("main screen", surface, "bg.jpg");

	// now create several rectangles and place them into the newly created window
	SDL_Color color = {10, 100, 10};

	SimpleSDL::Rectangle *r1 = new SimpleSDL::Rectangle(20, 20, 50, 30, color);
	r1->set_transparency_level(70);
	s->add_component(r1);

	SimpleSDL::Rectangle *r2 = new SimpleSDL::Rectangle(100, 20, 50, 30, color);
	r2->set_transparency_level(70);
	s->add_component(r2);

	SimpleSDL::Rectangle *r3 = new SimpleSDL::Rectangle(180, 20, 50, 30, color);
	r3->set_transparency_level(70);
	s->add_component(r3);

	SimpleSDL::Rectangle *r4 = new SimpleSDL::Rectangle(20, 80, 50, 30, color);
	r4->set_transparency_level(70);
	s->add_component(r4);


	SimpleSDL::Rectangle *r5 = new SimpleSDL::Rectangle(100, 80, 50, 30, color);
	r5->set_transparency_level(70);
	s->add_component(r5);

	SimpleSDL::Rectangle *r6 = new SimpleSDL::Rectangle(180, 80, 50, 30, color);
	r6->set_transparency_level(70);
	s->add_component(r6);

	return s;
}

bool handle_key(int keyp)
{
	bool ret = false;

	switch (keyp) {
	case SDLK_ESCAPE:
		ret = true;
		break;
	}

	return ret;
}

void sdl_main_loop() {
	SDL_Event event;
	bool done = false;


	screen_surface = sdl_initialize_screen("SimpleSDL GUI");

	SimpleSDL::Screen *screen = create_main_screen(screen_surface);

	if (screen == NULL) {
		return;
	}

	screen->show();

	while (!done) {
		/* handle events */
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			int keyp;

			case SDL_QUIT:
				done = SDL_TRUE;
				break;
			case SDL_KEYDOWN:
				keyp = event.key.keysym.sym;
				done = handle_key(keyp);
				break;
			default:
				break;
			}
		}
	}

	delete screen;
	sdl_cleanup();

}

int main() {
	sdl_main_loop();
	return 0;
}
