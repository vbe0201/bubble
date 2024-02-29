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

#define syscall0(num)                                                                        \
    ({                                                                                       \
        isize __rax;                                                                         \
        __asm__ __volatile__("syscall" : "=a"(__rax) : "a"((num)) : "rcx", "r11", "memory"); \
        __rax;                                                                               \
    })

#define syscall1(num, arg1)                            \
    ({                                                 \
        isize __rax;                                   \
        __asm__ __volatile__("syscall"                 \
                            : "=a"(__rax)              \
                            : "a"((num)), "D"((arg1))  \
                            : "rcx", "r11", "memory"); \
        __rax;                                         \
    })

#define syscall2(num, arg1, arg2)                                  \
    ({                                                             \
        isize __rax;                                               \
        __asm__ __volatile__("syscall"                             \
                            : "=a"(__rax)                          \
                            : "a"((num)), "D"((arg1)), "S"((arg2)) \
                            : "rcx", "r11", "memory"               \
        );                                                         \
        __rax;                                                     \
    })

#define syscall3(num, arg1, arg2, arg3)                                       \
    ({                                                                        \
        isize __rax;                                                          \
        __asm __volatile__("syscall"                                          \
                          : "=a"(__rax)                                       \
                          : "a"((num)), "D"((arg1)), "S"((arg2)), "d"((arg3)) \
                          : "rcx", "r11", "memory"                            \
        );                                                                    \
        __rax;                                                                \
    })

#define syscall4(num, arg1, arg2, arg3, arg4)                                               \
    ({                                                                                      \
        isize __rax;                                                                        \
        register __typeof__(arg4) __r10 __asm__("r10") = (arg4);                            \
        __asm__ __volatile__("syscall"                                                      \
                            : "=a"(__rax)                                                   \
                            : "a"((num)), "D"((arg1)), "S"((arg2)), "d"((arg3)), "r"(__r10) \
                            : "rcx", "r11", "memory"                                        \
        );                                                                                  \
        __rax;                                                                              \
    })

#define syscall5(num, arg1, arg2, arg3, arg4, arg5)                                                    \
    ({                                                                                                 \
        isize __rax;                                                                                   \
        register __typeof__(arg4) __r10 __asm__("r10") = (arg4);                                       \
        register __typeof__(arg5) __r8 __asm__("r8")   = (arg5);                                       \
        __asm__ __volatile__("syscall"                                                                 \
                            : "=a"(__rax)                                                              \
                            : "a"((num)), "D"((arg1)), "S"((arg2)), "d"((arg3)), "r"(__r10), "r"(__r8) \
                            : "rcx", "r11", "memory"                                                   \
        );                                                                                             \
        __rax;                                                                                         \
    })

#define syscall6(num, arg1, arg2, arg3, arg4, arg5, arg6)                                                         \
    ({                                                                                                            \
        isize __rax;                                                                                              \
        register __typeof__(arg4) __r10 __asm__("r10") = (arg4);                                                  \
        register __typeof__(arg5) __r8 __asm__("r8")   = (arg5);                                                  \
        register __typeof__(arg6) __r9 __asm__("r9")   = (arg6);                                                  \
        __asm__ __volatile__("syscall"                                                                            \
                            : "=a"(__rax)                                                                         \
                            : "a"((num)), "D"((arg1)), "S"((arg2)), "d"((arg3)), "r"(__r10), "r"(__r8), "r"(__r9) \
                            : "rcx", "r11", "memory"                                                              \
        );                                                                                                        \
        __rax;                                                                                                    \
    })
