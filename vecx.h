/**
 *
 * Copyright (C) 2021 Jared B. Resch
 *
 * This file is part of VECX.
 * 
 * VECX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * VECX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with VECX. If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef VECX_VECX_H
#define VECX_VECX_H

#include <stdio.h>

#define VECX_EXPORT static inline
#define VECX_STDOUT stdout

#define VECX(NAME, FUN, N, T, SCALAR_T, SIZE_T, BOOL_T, SQRT, FMT) \
\
typedef T NAME[N]; \
\
VECX_EXPORT void FUN ## init(NAME out, T s) \
{ \
        SIZE_T i;                           \
        for (i = 0; i < N; i++) out[i] = s; \
} \
\
VECX_EXPORT BOOL_T FUN ## eq(NAME a, NAME b) \
{ \
        SIZE_T i;                                   \
        for (i = 0; i < N; i++) {                   \
                if (a[i] != b[i]) return (BOOL_T)0; \
        }                                           \
        return (BOOL_T)1;                           \
} \
\
VECX_EXPORT BOOL_T FUN ## eqs(NAME v, T s) \
{ \
        SIZE_T i;                                \
        for (i = 0; i < N; i++) {                \
                if (v[i] != s) return (BOOL_T)0; \
        }                                        \
        return (BOOL_T)1;                        \
} \
\
VECX_EXPORT void FUN ## add(NAME out, NAME a, NAME b) \
{ \
        SIZE_T i;                                     \
        for (i = 0; i < N; i++) out[i] = a[i] + b[i]; \
} \
\
VECX_EXPORT void FUN ## sub(NAME out, NAME a, NAME b) \
{ \
        SIZE_T i;                                     \
        for (i = 0; i < N; i++) out[i] = a[i] - b[i]; \
} \
\
VECX_EXPORT void FUN ## scale(NAME out, NAME v, T s) \
{ \
        SIZE_T i;                                  \
        for (i = 0; i < N; i++) out[i] = v[i] * s; \
} \
\
VECX_EXPORT SCALAR_T FUN ## dot(NAME a, NAME b) \
{ \
        SIZE_T   i;                                 \
        SCALAR_T dot;                               \
        dot = (SCALAR_T)0;                          \
        for (i = 0; i < N; i++) dot += a[i] * b[i]; \
        return dot;                                 \
} \
\
VECX_EXPORT SCALAR_T FUN ## len(NAME v) \
{ \
        SIZE_T   i;                                   \
        SCALAR_T sqsum;                               \
        sqsum = (SCALAR_T)0;                          \
        for (i = 0; i < N; i++) sqsum += v[i] * v[i]; \
        return SQRT(sqsum);                           \
} \
\
VECX_EXPORT void FUN ## norm(NAME out, NAME v) \
{ \
        SIZE_T   i;                                  \
        SCALAR_T len;                                \
        len = FUN ## len(v);                         \
        if (len == ((SCALAR_T)0)) return;            \
        for (i = 0; i < N; i++) out[i] = v[i] / len; \
} \
\
VECX_EXPORT void FUN ## lerp(NAME out, NAME a, NAME b, T t) \
{ \
        SIZE_T i;                                                  \
        for (i = 0; i < N; i++) out[i] = a[i] + t * (b[i] - a[i]); \
} \
\
VECX_EXPORT void FUN ## fprintf(FILE *f, NAME v) \
{ \
        SIZE_T i;                                 \
        for (i = 0; i < N; i++) {                 \
                fprintf(f, FMT, v[i]);            \
                if (i < (N - 1)) fprintf(f, " "); \
        }                                         \
        fprintf(f, "\n");                         \
} \
\
VECX_EXPORT void FUN ## printf(NAME v) \
{ \
        FUN ## fprintf(stdout, v); \
}

#endif
