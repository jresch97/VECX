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

#define VECX_EXPORT static inline

#define VECX(NAME_LOWER, N, T, SCALAR_T, SQRT, SCALAR_FMT_STR) \
\
typedef T NAME_LOWER[N]; \
\
VECX_EXPORT void NAME_LOWER ## _init(NAME_LOWER vec, T val) \
{ \
        for (int i = 0; i < N; i++) vec[i] = val; \
} \
\
VECX_EXPORT void NAME_LOWER ## _add(NAME_LOWER a, NAME_LOWER b, NAME_LOWER out) \
{ \
        for (int i = 0; i < N; i++) out[i] = a[i] + b[i]; \
} \
\
VECX_EXPORT void NAME_LOWER ## _sub(NAME_LOWER a, NAME_LOWER b, NAME_LOWER out) \
{ \
        for (int i = 0; i < N; i++) out[i] = a[i] - b[i]; \
} \
\
VECX_EXPORT SCALAR_T NAME_LOWER ## _dot(NAME_LOWER a, NAME_LOWER b) \
{ \
        SCALAR_T dot = (T)0; \
        for (int i = 0; i < N; i++) dot = a[i] * b[i]; \
        return dot; \
} \
\
VECX_EXPORT SCALAR_T NAME_LOWER ## _len(NAME_LOWER vec) \
{ \
        SCALAR_T sq_sum = (T)0; \
        for (int i = 0; i < N; i++) sq_sum += vec[i] * vec[i]; \
        return SQRT(sq_sum); \
} \
\
VECX_EXPORT void NAME_LOWER ## _norm(NAME_LOWER vec, NAME_LOWER out) \
{ \
        SCALAR_T len = NAME_LOWER ## _len(vec); \
        if (len == ((SCALAR_T)0)) return; \
        for (int i = 0; i < N; i++) out[i] = vec[i] / len; \
} \
\
VECX_EXPORT void NAME_LOWER ## _lerp(const NAME_LOWER a, \
                                     const NAME_LOWER b, \
                                     T t, \
                                     NAME_LOWER out) \
{ \
        for (int i = 0; i < N; i++) out[i] = a[i] + t * (b[i] - a[i]); \
} \
\
VECX_EXPORT void NAME_LOWER ## _fprintf(NAME_LOWER vec, FILE *f) \
{ \
        for (int i = 0; i < N; i++) { \
                fprintf(f, SCALAR_FMT_STR, vec[i]); \
                if (i < (N - 1)) fprintf(f, " "); \
        } \
        fprintf(f, "\n"); \
} \
\
VECX_EXPORT void NAME_LOWER ## _printf(NAME_LOWER vec) \
{ \
        NAME_LOWER ## _fprintf(vec, stdout); \
}

#endif