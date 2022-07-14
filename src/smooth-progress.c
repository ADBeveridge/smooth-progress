/* smooth-progress.c
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

#include "smooth-progress.h"

typedef struct smooth_progress {
	GTimer* supply_timer;
	GTimer* smooth_timer;

	double rate;
};

struct smooth_progress* smooth_progress_new ()
{
	struct smooth_progress* sp = (struct smooth_progress*)malloc(sizeof(struct smooth_progress));
	sp->supply_timer = NULL;
	sp->smooth_timer = NULL;
	sp->rate = 0.0;

	return sp;
}

/* Return the calculated progress. */
double smooth_progress_get_progress (struct smooth_progress* sp)
{
	/* This executes on the very first call to the progress getter. */
	if (sp->smooth_timer == NULL) {
		sp->smooth_timer = g_timer_new();
		g_timer_start(sp->smooth_timer);
	}

	return g_timer_elapsed(sp->smooth_timer, NULL) * sp->rate;
}

/* Give info so rate can be extrapolated. */
void smooth_progress_supply_progress(struct smooth_progress* sp, double progress)
{
	// Execute only on first call.
	if (sp->supply_timer == NULL)
	{
		sp->supply_timer = g_timer_new();
		g_timer_start(sp->supply_timer);

		return;
	}

	else {
		sp->rate = progress / g_timer_elapsed(sp->supply_timer, NULL);
	}
}

