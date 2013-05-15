/**
 * Copyright (c) 2012 Vadim Ushakov
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _SPICVIEW_IMAGE_CACHE_H
#define _SPICVIEW_IMAGE_CACHE_H

#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <sys/types.h>

typedef struct _ImageCacheItem
{
    GdkPixbuf* pix;
    GdkPixbufAnimation* animation;
    char * name;
    time_t mtime;
    off_t size;
} ImageCacheItem;

extern gboolean image_cache_get(ImageCacheItem* item);
extern void image_cache_put(ImageCacheItem* item);

unsigned image_cache_get_limit(void);

#endif
