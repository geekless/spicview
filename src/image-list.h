/***************************************************************************
 *   Copyright (C) 2007 by PCMan (Hong Jen Yee)   *
 *   pcman.tw@gmail.com   *
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

#ifndef IMAGELIST_H
#define IMAGELIST_H

#include <glib.h>
#include <gtk/gtk.h>

/* for stat and time_t */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct _ImageList ImageList;

ImageList* image_list_new();

gboolean image_list_open_dir( ImageList* il, const char* path, GError** error);

gboolean image_list_set_current( ImageList* il, const char* name );

const char* image_list_get_current( ImageList* il );

const char* image_list_get_first( ImageList* il );
const char* image_list_get_next( ImageList* il );
const char* image_list_get_prev( ImageList* il );
const char* image_list_get_last( ImageList* il );

const char* image_list_to_first( ImageList* il );
const char* image_list_to_next( ImageList* il );
const char* image_list_to_prev( ImageList* il );
const char* image_list_to_last( ImageList* il );

void image_list_free( ImageList* il );

void image_list_close( ImageList* il );

gboolean image_list_is_empty( ImageList* il );

gboolean image_list_has_multiple_files( ImageList* il );

gchar* image_list_get_current_file_path( ImageList* il );
gchar* image_list_get_current_file_dir_path( ImageList* il );

gchar* image_list_get_file_path_for_item( ImageList* il, const char * name );

void image_list_sort_by_name( ImageList* il, GtkSortType type );

void image_list_remove( ImageList* il, const char* name );

/* FIXME: currently only GTK_SORT_ASCENDING is supported */
void image_list_add_sorted( ImageList* il, const char* name, gboolean set_current );

#endif
