/* smooth-progress.h
 *
 * Copyright 2022 Alan Beveridge
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <glib.h>

G_BEGIN_DECLS

#define SMOOTH_PROGRESS_INSIDE
# include "smooth-progress-version.h"
#undef SMOOTH_PROGRESS_INSIDE

struct smooth_progress* smooth_progress_new ();
double smooth_progress_get_progress (struct smooth_progress* sp);
void smooth_progress_supply_progress(struct smooth_progress* sp, double progress);
void smooth_progress_destroy(struct smooth_progress* sp);

G_END_DECLS
