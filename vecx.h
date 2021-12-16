/**
 * 
 * Author: Jared B. Resch
 *
 * This file is part of VECX.
 *
 * VECX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * VECX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with VECX. If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef VECX_VECX_H
#define VECX_VECX_H

#include <stdio.h>

#define VECX_EXPORT static inline

#define VECX(NAME, DELIM, N, T, SCALAR_T, SQRT, SCALAR_FMT_STR) \
\
typedef T NAME[N]; \
\
VECX_EXPORT void NAME ## DELIM ## init(NAME out, const T v) \
{ \
        for (int i = 0; i < N; i++) out[i] = v; \
} \
\
VECX_EXPORT void NAME ## DELIM ## add(NAME out, const NAME a, const NAME b) \
{ \
        for (int i = 0; i < N; i++) out[i] = a[i] + b[i]; \
} \
\
VECX_EXPORT void NAME ## DELIM ## sub(NAME out, const NAME a, const NAME b) \
{ \
        for (int i = 0; i < N; i++) out[i] = a[i] - b[i]; \
} \
\
VECX_EXPORT SCALAR_T NAME ## DELIM ## dot(const NAME a, const NAME b) \
{ \
        SCALAR_T dot = (SCALAR_T)0; \
        for (int i = 0; i < N; i++) dot += a[i] * b[i]; \
        return dot; \
} \
\
VECX_EXPORT SCALAR_T NAME ## DELIM ## len(const NAME v) \
{ \
        SCALAR_T sq_sum = (SCALAR_T)0; \
        for (int i = 0; i < N; i++) sq_sum += v[i] * v[i]; \
        return SQRT(sq_sum); \
} \
\
VECX_EXPORT void NAME ## DELIM ## norm(NAME out, const NAME v) \
{ \
        SCALAR_T len = NAME ## DELIM ## len(v); \
        if (len == ((SCALAR_T)0)) return; \
        for (int i = 0; i < N; i++) out[i] = v[i] / len; \
} \
\
VECX_EXPORT void NAME ## DELIM ## lerp(NAME out, \
                                       const NAME a, \
                                       const NAME b, \
                                       const T t) \
{ \
        for (int i = 0; i < N; i++) out[i] = a[i] + t * (b[i] - a[i]); \
} \
\
VECX_EXPORT void NAME ## DELIM ## fprintf(FILE *f, NAME v) \
{ \
        for (int i = 0; i < N; i++) { \
                fprintf(f, SCALAR_FMT_STR, v[i]); \
                if (i < (N - 1)) fprintf(f, " "); \
        } \
        fprintf(f, "\n"); \
} \
\
VECX_EXPORT void NAME ## DELIM ## printf(NAME v) \
{ \
        NAME ## DELIM ## fprintf(stdout, v); \
}

#endif