/*
 * Copyright (c) 2024 Valentin B.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "assert.h"

#include "impl/debug.h"

COLD NORETURN NOINLINE void assert_fail_impl(const char *expr, const char *file, unsigned line) {
    (void)expr;
    (void)file;
    (void)line;

    /* TODO: Print diagnostics? */

    for (;;) {
        debug_break();
    }
}
