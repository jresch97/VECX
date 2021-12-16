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

VECX(vec3f, _, 3, float, float, sqrtf, "%f")

int main(int argc, char *argv[])
{
        vec3f in, add, sub, norm, lerp;
        const vec3f v = { 1.0f, 2.0f, 3.0f };
        printf("================================================================================\n");
        printf("= vec3f_init test\n");
        printf("================================================================================\n");
        vec3f_init(in, 5.0f);
        vec3f_printf(in);
        assert(in[0] == 5.0f && in[1] == 5.0f && in[2] == 5.0f);
        printf("================================================================================\n");
        printf("= vec3f_init passed\n");
        printf("================================================================================\n");
        printf("= vec3f_add test\n");
        printf("================================================================================\n");
        vec3f_add(add, in, v);
        vec3f_printf(add);
        assert(add[0] == 6.0f && add[1] == 7.0f && add[2] == 8.0f);
        printf("================================================================================\n");
        printf("= vec3f_add passed\n");
        printf("================================================================================\n");
        printf("= vec3f_sub test\n");
        printf("================================================================================\n");
        vec3f_sub(sub, in, v);
        vec3f_printf(sub);
        assert(sub[0] == 4.0f && sub[1] == 3.0f && sub[2] == 2.0f);
        printf("================================================================================\n");
        printf("= vec3f_sub passed\n");
        printf("================================================================================\n");
        printf("= vec3f_dot test\n");
        printf("================================================================================\n");
        float dot = vec3f_dot(add, sub);
        printf("%f\n", dot);
        assert(dot == 61.0f);
        printf("================================================================================\n");
        printf("= vec3f_dot passed\n");
        printf("================================================================================\n");
        printf("= vec3f_len test\n");
        printf("================================================================================\n");
        float len = vec3f_len(in);
        printf("%f\n", len);
        assert(len == sqrtf(75.0f));
        printf("================================================================================\n");
        printf("= vec3f_len passed\n");
        printf("================================================================================\n");
        printf("= vec3f_norm test\n");
        printf("================================================================================\n");
        vec3f_norm(norm, in);
        vec3f_printf(norm);
        float n = 5.0f / sqrtf(75.0f);
        assert(norm[0] == n && norm[1] == n && norm[2] == n);
        printf("================================================================================\n");
        printf("= vec3f_norm passed\n");
        printf("================================================================================\n");
        printf("= vec3f_lerp test\n");
        printf("================================================================================\n");
        vec3f_lerp(lerp, add, sub, 0.5f);
        vec3f_printf(lerp);
        assert(lerp[0] == 5.0f && lerp[1] == 5.0f && lerp[2] == 5.0f);
        printf("================================================================================\n");
        printf("= vec3f_lerp passed\n");
        printf("================================================================================\n");
        return 0;
}