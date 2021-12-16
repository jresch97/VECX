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

#ifndef VECX_VEC3_H
#define VECX_VEC3_H

#define VECX_VEC3_HELPERS(NAME, NAME_CONST, DELIM, T) \
\
const NAME NAME_CONST ## DELIM ## RIGHT   = { (T)1, (T)0, (T)0 }; \
const NAME NAME_CONST ## DELIM ## UP      = { (T)0, (T)1, (T)0 }; \
const NAME NAME_CONST ## DELIM ## FORWARD = { (T)0, (T)0, (T)1 }; \
\
VECX_EXPORT void NAME ## DELIM ## cross(NAME out, const NAME a, const NAME b) \
{ \
        out[0] = a[1] * b[2] + a[2] * b[1]; \
        out[1] = a[2] * b[0] + a[0] * b[2]; \
        out[2] = a[0] * b[1] + a[1] * b[0]; \
}

#endif