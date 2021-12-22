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

#include <assert.h>
#include <math.h>
#include <vecx.h>
#include <vec3x.h>

VECX (VEC3F, vec3f, 3, float, float, int, int, sqrtf, "%f")
VEC3X(VEC3F, VEC3F, vec3f, float)

int main(int argc, char *argv[])
{
        VEC3F cross;
        printf("================================================================================\n");
        printf("= vec3fcross test\n");
        printf("================================================================================\n");
        vec3fcross(cross, VEC3FUP, VEC3FRIGHT);
        vec3fprintf(cross);
        assert(vec3feq(cross, VEC3FFWD));
        printf("================================================================================\n");
        printf("= vec3fcross passed\n");
        printf("================================================================================\n");
        return 0;
}