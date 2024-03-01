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
#pragma once

#include "types.h"

/**
 * @brief Copies the byte c into the first len bytes of dest.
 * @param dest Pointer to the object to fill.
 * @param c The fill byte.
 * @param len Number of bytes to fill.
 * @return A copy of dest.
 */
void *memset(void *dest, int c, usize len);

/**
 * @brief Copies len bytes of memory from src to dest.
 * @param dest Pointer to the object to copy to.
 * @param src Pointer to the object to copy from.
 * @param len Number of bytes to copy.
 * @return A copy of dest.
 */
void *memcpy(void * __restrict dest, const void * __restrict src, usize len);

/**
 * @brief Copies len bytes of memory from src to dest.
 * @param dest Pointer to the object to copy to.
 * @param src Pointer to the object to copy from.
 * @param len Number of bytes to copy.
 * @return A copy of dest.
 */
void *memmove(void *dest, const void *src, usize len);
