/*
    Copyright (C) 2005-2006  Michel de Boer <michelboer@xs4all.nl>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef _ID_OBJECT_H
#define _ID_OBJECT_H

#include "threads/mutex.h"

typedef unsigned short		t_object_id;

/*
 * Parent class for objects that need a unique object id.
 */
class t_id_object {
private:
	// Mutex for concurrent object id creation.
	static t_mutex		mtx_next_id;
	
	// Id for the next object
	static t_object_id	next_id;
	
	// Unique object identifier.
	t_object_id		id;
	
public:
	t_id_object();
	
	// Get the object id
	t_object_id get_object_id();
	
	// Generate a new object identifier. This can be useful
	// after making a copy of an object.
	void generate_new_id();
};

#endif
