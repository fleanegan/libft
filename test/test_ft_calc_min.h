#include "test_utils.h"

Test(test_min, return_a_if_less_than_b)
{
	size_t	a = 0;
	size_t	b = 1;

	size_t	res_act = calc_min_unsigned(a, b);
	cr_assert_eq(res_act, a);
}

Test(test_min, return_b_if_less_than_a)
{
	size_t	a = 1;
	size_t	b = 0;

	size_t	res_act = calc_min_unsigned(a, b);
	cr_assert_eq(res_act, b);
}