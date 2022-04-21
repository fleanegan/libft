#include "test_utils.h"

void print_matrix(t_matrix *a)
{
	int					x;
	int					y;

	x = 0;
	printf("height %d width %d\n", a->height, a->width);
	while (x < a->height)
	{
		y = 0;
		while (y < a->width)
		{
			printf("%f at [%d][%d]", a->mat[x][y], x, y);
			y++;
		}
		printf("\n");
		x++;
	}
}

void cr_assert_identity(t_matrix *t)
{
	cr_assert_float_eq((*t).mat[0][0], 1, 0.001);
	cr_assert_float_eq((*t).mat[1][0], 0, 0.001);
	cr_assert_float_eq((*t).mat[2][0], 0, 0.001);
	cr_assert_float_eq((*t).mat[0][1], 0, 0.001);
	cr_assert_float_eq((*t).mat[1][1], 1, 0.001);
	cr_assert_float_eq((*t).mat[2][1], 0, 0.001);
	cr_assert_float_eq((*t).mat[0][2], 0, 0.001);
	cr_assert_float_eq((*t).mat[1][2], 0, 0.001);
	cr_assert_float_eq((*t).mat[2][2], 1, 0.001);
}

Test(test_matrix, rotation_with_zero_deg_results_in_identity_matrix)
{
	t_matrix t = euler2rot(0., 0., 0.);
	cr_assert_identity(&t);
}

Test(test_matrix, dot_product_matrix_point)
{
	t_matrix r;
	t_matrix p;
	zero_init_rotation_matrix(&r);
	zero_init_point(&p);
	p.mat[0][0] = 1;
	p.mat[1][0] = 2;
	p.mat[2][0] = 3;
	r.mat[0][0] = 4;
	r.mat[1][0] = 5;
	r.mat[2][0] = 6;
	r.mat[0][1] = 7;
	r.mat[1][1] = 8;
	r.mat[2][1] = 9;
	r.mat[0][2] = 10;
	r.mat[1][2] = 11;
	r.mat[2][2] = 12;
	t_matrix result;

	multiply(&r, &p, &result);

	cr_assert_float_eq(result.mat[0][0], 48, 0.01, "act x: %f", result.mat[0][0]);
	cr_assert_float_eq(result.mat[1][0], 54, 0.01, "act y: %f", result.mat[1][0]);
	cr_assert_float_eq(result.mat[2][0], 60, 0.01, "act z: %f", result.mat[2][0]);
}

Test(test_matrix, rotating_point_in_xy_plane)
{
	t_matrix	rotation_matrix = euler2rot(0., 0., 90.);
	t_matrix	point;
	zero_init_point(&point);
	point.mat[0][0] = 1.0;
	t_matrix result;

	cr_assert(multiply(&rotation_matrix, &point, &result) == 0);

	cr_assert_float_eq(result.mat[0][0], 0, 0.01, "act x: %f", result.mat[0][0]);
	cr_assert_float_eq(result.mat[1][0], 1, 0.01, "act y: %f", result.mat[1][0]);
	cr_assert_float_eq(result.mat[2][0], 0, 0.01, "act z: %f", result.mat[2][0]);
}