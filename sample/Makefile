#/***************************************************************************
# *   Copyright (C) 2011 by Sergio Luis O. B. Correia                       *
# *   sergio.correia@uece.net                                               *
# *                                                                         *
# *                                                                         *
# *   This program is free software; you can redistribute it and/or modify  *
# *   it under the terms of the GNU General Public License as published by  *
# *   the Free Software Foundation; either version 2 of the License, or     *
# *   (at your option) any later version.                                   *
# *                                                                         *
# *   This program is distributed in the hope that it will be useful,       *
# *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
# *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
# *   GNU General Public License for more details.                          *
# *                                                                         *
# *   You should have received a copy of the GNU General Public License     *
# *   along with this program; if not, write to the                         *
# *   Free Software Foundation, Inc.,                                       *
# *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
# ***************************************************************************/

###############################################
# LIB BASEDIR
###############################################
SIMPLE_SDL	=	../SimpleSDL


###############################################
# SOURCE FILES
###############################################

GENERAL_SRC 	=	$(SIMPLE_SDL)/src/components/rectangle.cpp \
			$(SIMPLE_SDL)/src/screen.cpp \
			$(SIMPLE_SDL)/src/sdl_utils.cpp 

###############################################
# SAMPLE APP
###############################################
APP_SRC		=	sample-main.cpp

APP_OBJ		=	sample-app


###############################################
# TOOLS AND FLAGS
###############################################
RM	=	rm
CPP	=	g++
CFLAGS	=	-Wall -g -O0 -pedantic -ansi -DX11_DEBUG -Wconversion
INCLUDE	=	-I$(SIMPLE_SDL)/include
LDFLAGS	=	-lSDL -lSDL_ttf -lSDL_image

###############################################
# RULES
###############################################

default: sample

all: default

sample:
	$(CPP) $(CFLAGS) $(INCLUDE) $(APP_SRC) $(GENERAL_SRC) -o $(APP_OBJ) $(LDFLAGS)

clean:
	$(RM) -f $(APP_OBJ)
