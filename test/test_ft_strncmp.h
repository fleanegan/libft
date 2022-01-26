#include "test_utils.h"

Test(test_strncmp, only_compare_until_terminating_zero)
{
	char * s1 = "\0a1";
	char * s2 = "\0a0";
	int res_act = ft_strncmp(s1, s2, 3);
	int res_exp = strncmp(s1, s2, 3);

	cr_expect_eq(res_act, 0);
	cr_assert_eq(res_act, res_exp, "act: %d, exp: %d", res_act, res_exp);
}


Test(test_strncmp, calculation_of_n_respects_zero_termination)
{
	char * s1 = "0\0a1";
	char * s2 = "\0a0";
	int res_act = ft_strncmp(s1, s2, 3);
	int res_exp = strncmp(s1, s2, 3);

	cr_expect_eq(res_act, 48);
	cr_assert_eq(res_act, res_exp, "act: %d, exp: %d", res_act, res_exp);
}

Test(test_strncmp, calculation_of_n_respects_zero_termination_neg)
{
	char * s1 = "\0a1";
	char * s2 = "0\0a0";
	int res_act = ft_strncmp(s1, s2, 3);
	int res_exp = strncmp(s1, s2, 3);

	cr_expect_eq(res_act, -48);
	cr_assert_eq(res_act, res_exp, "act: %d, exp: %d", res_act, res_exp);
}