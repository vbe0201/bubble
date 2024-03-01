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
#include "memory.h"

#define BLOCKSIZE    (sizeof(long))
#define BIGBLOCKSIZE (BLOCKSIZE << 2)
#define BLOCK_UNALIGNED(x) ((long)x & (BLOCKSIZE - 1))

void *memset(void *dest0, int c, usize len) {
    char *dest;
    unsigned long *aligned_dest;
    unsigned long buf;
    unsigned int fill;

    dest = dest0;
    fill = (c & 0xFF);

    /* Byte copy into unaligned prefix, if any. */
    while (BLOCK_UNALIGNED(dest)) {
        if (len--) {
            *dest++ = (char)fill;
        } else {
            return dest0;
        }
    }

    /* If we have data left, we can copy block-wise now. */
    if (len >= BLOCKSIZE) {
        aligned_dest = (unsigned long *)dest;

        /* Fill each byte of buf with c for quick copying. */
        buf = (((unsigned long)-1) / 0xFF) * (unsigned char)fill;

        /* Copy 4X long words at a time, if possible. */
        while (len >= BIGBLOCKSIZE) {
            *aligned_dest++ = buf;
            *aligned_dest++ = buf;
            *aligned_dest++ = buf;
            *aligned_dest++ = buf;
            len -= BIGBLOCKSIZE;
        }

        /* Copy one long words at a time, if possible. */
        while (len >= BLOCKSIZE) {
            *aligned_dest++ = buf;
            len -= BLOCKSIZE;
        }

        dest = (char *)aligned_dest;
    }

    /* Byte copy into unaligned suffix, if any. */
    while (len--) {
        *dest++ = (char)fill;
    }

    return dest0;
}

void *memcpy(void *dest0, const void *src0, usize len) {
    char *dest;
    long *aligned_dest;
    const char *src;
    const long *aligned_src;

    dest = dest0;
    src  = src0;

    /* If the size is small or the operands are unaligned, punt to byte copying. */
    if ((len >= BIGBLOCKSIZE) && !(BLOCK_UNALIGNED(src) | BLOCK_UNALIGNED(dest))) {
        aligned_dest = (long *)dest;
        aligned_src  = (long *)src;

        /* Copy 4X long words at a time, if possible. */
        while (len >= BIGBLOCKSIZE) {
            *aligned_dest++ = *aligned_src++;
            *aligned_dest++ = *aligned_src++;
            *aligned_dest++ = *aligned_src++;
            *aligned_dest++ = *aligned_src++;
            len -= BIGBLOCKSIZE;
        }

        /* Copy one long word at a time, if possible. */
        while (len >= BLOCKSIZE) {
            *aligned_dest++ = *aligned_src++;
            len -= BLOCKSIZE;
        }

        dest = (char *)aligned_dest;
        src  = (char *)aligned_src;
    }

    /* Copy any residual byte by byte. */
    while (len--) {
        *dest++ = *src++;
    }

    return dest0;
}

void *memmove(void *dest0, const void *src0, usize len) {
    char *dest = dest0;
    const char *src = src0;

    if (src < dest && dest < src + len) {
        /* There's a destructive overlap, so copy backwards. */
        src  += len;
        dest += len;
        while (len--) {
            *--dest = *--src;
        }

        return dest0;
    } else {
        return memcpy(dest0, src0, len);
    }
}

#undef BLOCK_UNALIGNED
#undef BIGBLOCKSIZE
#undef BLOCKSIZE
