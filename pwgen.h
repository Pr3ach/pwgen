/*
 *  Copyright (C) 2018 - Preacher
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PWGEN_H
#define PWGEN_H
void usage(const char *self);
char *pw_gen(int pw_len, int opt);

#define MAX_LEN 255

/* Options mask */
#define O_NONE 0
#define O_ALPHA 1
#define O_NUM 2
#define O_SPECIAL 4

int OPTIONS;

#endif
