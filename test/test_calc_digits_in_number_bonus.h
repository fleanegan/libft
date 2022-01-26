#include "test_utils.h"

#ifdef own_source
int	calc_digits_in_number(int in);
Test(test_itoa, calc_res_len_for_zero)
{
	int	in = 0;
	int	res_exp = 1;

	int	res_act = calc_digits_in_number(in);

	cr_assert_eq(res_act, res_exp, "act: %d, res: %d", res_act, res_exp);
}

Test(test_itoa, calc_res_len_for_one)
{
	int	in = 1;
	int	res_exp = 1;

	int	res_act = calc_digits_in_number(in);

	cr_assert_eq(res_act, res_exp, "act: %d, res: %d", res_act, res_exp);
}

Test(test_itoa, calc_res_len_for_minus_one)
{
	int	in = -1;
	int	res_exp = 2;

	int	res_act = calc_digits_in_number(in);

	cr_assert_eq(res_act, res_exp, "act: %d, res: %d", res_act, res_exp);
}

Test(test_itoa, calc_res_len_for_ten)
{
	int	in = -1;
	int	res_exp = 2;

	int	res_act = calc_digits_in_number(in);

	cr_assert_eq(res_act, res_exp, "act: %d, res: %d", res_act, res_exp);
}

Test(test_itoa, calc_res_len_for_minus_ten)
{
	int	in = -10;
	int	res_exp = 3;

	int	res_act = calc_digits_in_number(in);

	cr_assert_eq(res_act, res_exp, "act: %d, res: %d", res_act, res_exp);
}

Test(test_itoa, calc_res_len_for_int_min)
{
	int	in = -2147483648;
	int	res_exp = 11;

	int	res_act = calc_digits_in_number(in);

	cr_assert_eq(res_act, res_exp, "act: %d, res: %d", res_act, res_exp);
}

#endif