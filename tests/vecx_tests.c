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

#include <assert.h>
#include <math.h>
#include <vecx.h>

VECX(VEC3F, vec3f, 3, float, float, int, int, sqrtf, "%f")

VEC3F OFFSET = { 1.0f, 2.0f, 3.0f };

int main(int argc, char *argv[])
{
        float dot, len, n;
        VEC3F in, add, sub, scale, norm, lerp;
        printf("============================================================\n");
        printf("= vec3finit test\n");
        printf("============================================================\n");
        vec3finit(in, 5.0f);
        vec3fprintf(in);
        assert(vec3feqs(in, 5.0f));
        printf("============================================================\n");
        printf("= vec3finit passed\n");
        printf("============================================================\n");
        printf("= vec3fadd test\n");
        printf("============================================================\n");
        vec3fadd(add, in, OFFSET);
        vec3fprintf(add);
        assert(add[0] == 6.0f && add[1] == 7.0f && add[2] == 8.0f);
        printf("============================================================\n");
        printf("= vec3fadd passed\n");
        printf("============================================================\n");
        printf("= vec3fsub test\n");
        printf("============================================================\n");
        vec3fsub(sub, in, OFFSET);
        vec3fprintf(sub);
        assert(sub[0] == 4.0f && sub[1] == 3.0f && sub[2] == 2.0f);
        printf("============================================================\n");
        printf("= vec3fsub passed\n");
        printf("============================================================\n");
        printf("= vec3fscale test\n");
        printf("============================================================\n");
        vec3fscale(scale, in, 5.0f);
        vec3fprintf(scale);
        assert(vec3feqs(scale, 25.0f));
        printf("============================================================\n");
        printf("= vec3fscale passed\n");
        printf("============================================================\n");
        printf("= vec3fdot test\n");
        printf("============================================================\n");
        dot = vec3fdot(add, sub);
        printf("%f\n", dot);
        assert(dot == 61.0f);
        printf("============================================================\n");
        printf("= vec3fdot passed\n");
        printf("============================================================\n");
        printf("= vec3flen test\n");
        printf("============================================================\n");
        len = vec3flen(in);
        printf("%f\n", len);
        assert(len == sqrtf(75.0f));
        printf("============================================================\n");
        printf("= vec3flen passed\n");
        printf("============================================================\n");
        printf("= vec3fnorm test\n");
        printf("============================================================\n");
        vec3fnorm(norm, in);
        vec3fprintf(norm);
        n = 5.0f / sqrtf(75.0f);
        assert(vec3feqs(norm, n));
        printf("============================================================\n");
        printf("= vec3fnorm passed\n");
        printf("============================================================\n");
        printf("= vec3flerp test\n");
        printf("============================================================\n");
        vec3flerp(lerp, add, sub, 0.5f);
        vec3fprintf(lerp);
        assert(vec3feqs(lerp, 5.0f));
        printf("============================================================\n");
        printf("= vec3flerp passed\n");
        printf("============================================================\n");
        return 0;
}
