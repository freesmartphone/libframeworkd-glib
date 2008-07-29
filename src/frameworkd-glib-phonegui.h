/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
 *              Marc-Olivier Barre <marco@marcochapeau.org>
 *              Julien Cassignol <ainulindale@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Public License as published by
 *  the Free Software Foundation; version 2 of the license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser Public License for more details.
 */

#ifndef PHONEGUI_H
#define PHONEGUI_H

void phonegui_init(int argc, char** argv);

void phonegui_display_pin_UI (const int initial_status);
void phonegui_destroy_pin_UI ();

//void phonegui_display_call_UI(const int id_call, const int status, const char *number);
//void phonegui_destroy_call_UI(const int id_call);
#endif
