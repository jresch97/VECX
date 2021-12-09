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

#ifndef VECX_VEC_H
#define VECX_VEC_H

#include "vecx.h"
#include "vec3.h"

#include <math.h>

VECX(vec2f, 2, float, float, sqrtf, "%f")
VECX(vec3f, 3, float, float, sqrtf, "%f")
VECX(vec4f, 4, float, float, sqrtf, "%f")

VECX(vec2d, 2, double, double, sqrt, "%lf")
VECX(vec3d, 3, double, double, sqrt, "%lf")
VECX(vec4d, 4, double, double, sqrt, "%lf")

VECX_VEC3_HELPERS(vec3f, VEC3F, float)
VECX_VEC3_HELPERS(vec3d, VEC3D, double)

#endif