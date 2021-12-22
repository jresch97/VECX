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
#define VECX_STDOUT stdout

#define VECX(NAME, FUN, N, T, SCALAR_T, SIZE_T, BOOL_T, SQRT, FMT) \
\
typedef T NAME[N]; \
\
VECX_EXPORT void FUN ## ini(NAME out, const T s) \
{ \
        for (SIZE_T i = 0; i < N; i++) out[i] = s; \
} \
\
VECX_EXPORT BOOL_T FUN ## eq(const NAME a, const NAME b) \
{ \
        for (SIZE_T i = 0; i < N; i++) if (a[i] != b[i]) return (BOOL_T)0; \
        return (BOOL_T)1; \
} \
\
VECX_EXPORT BOOL_T FUN ## eqs(const NAME v, T s) \
{ \
        for (SIZE_T i = 0; i < N; i++) if (v[i] != s) return (BOOL_T)0; \
        return (BOOL_T)1; \
} \
\
VECX_EXPORT void FUN ## add(NAME out, const NAME a, const NAME b) \
{ \
        for (SIZE_T i = 0; i < N; i++) out[i] = a[i] + b[i]; \
} \
\
VECX_EXPORT void FUN ## sub(NAME out, const NAME a, const NAME b) \
{ \
        for (SIZE_T i = 0; i < N; i++) out[i] = a[i] - b[i]; \
} \
\
VECX_EXPORT SCALAR_T FUN ## dot(const NAME a, const NAME b) \
{ \
        SCALAR_T dot = (SCALAR_T)0; \
        for (SIZE_T i = 0; i < N; i++) dot += a[i] * b[i]; \
        return dot; \
} \
\
VECX_EXPORT SCALAR_T FUN ## len(const NAME v) \
{ \
        SCALAR_T sq_sum = (SCALAR_T)0; \
        for (SIZE_T i = 0; i < N; i++) sq_sum += v[i] * v[i]; \
        return SQRT(sq_sum); \
} \
\
VECX_EXPORT void FUN ## norm(NAME out, const NAME v) \
{ \
        SCALAR_T len = FUN ## len(v); \
        if (len == ((SCALAR_T)0)) return; \
        for (SIZE_T i = 0; i < N; i++) out[i] = v[i] / len; \
} \
\
VECX_EXPORT void FUN ## lerp(NAME out, const NAME a, const NAME b, T t) \
{ \
        for (SIZE_T i = 0; i < N; i++) out[i] = a[i] + t * (b[i] - a[i]); \
} \
\
VECX_EXPORT void FUN ## fprintf(FILE *f, NAME v) \
{ \
        for (SIZE_T i = 0; i < N; i++) { \
                fprintf(f, FMT, v[i]); \
                if (i < (N - 1)) fprintf(f, " "); \
        } \
        fprintf(f, "\n"); \
} \
\
VECX_EXPORT void FUN ## printf(NAME v) \
{ \
        FUN ## fprintf(stdout, v); \
}

#endif