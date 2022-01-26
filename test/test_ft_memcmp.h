#include "test_utils.h"

Test(test_memcmp, if_n_is_zero_return_zero)
{
	int dummy_mem = 0;
	int res_act = ft_memcmp(&dummy_mem, &dummy_mem, 0);
	int res_exp = memcmp(&dummy_mem, &dummy_mem, 0);

	cr_expect_eq(res_act, 0);
	cr_assert_eq(res_act, res_exp);
}

Test(test_memcmp, skip_same_bytes)
{
	char * s1 = "02";
	char * s2 = "00";
	int res_act = ft_memcmp(s1, s2, strlen(s1));
	int res_exp = memcmp(s1, s2, strlen(s1));

	cr_expect_eq(res_act, 2);
	cr_assert_eq(res_act > 0, res_exp > 0, "act: %d, exp: %d", res_act, res_exp);
	cr_assert_eq(res_act == 0, res_exp == 0, "act: %d, exp: %d", res_act, res_exp);
}

Test(test_memcmp, return_difference_of_first_differing_bytepair)
{
	char * s1 = "2";
	char * s2 = "0";
	int res_act = ft_memcmp(s1, s2, strlen(s1));
	int res_exp = memcmp(s1, s2, strlen(s1));

	cr_expect_eq(res_act, 2, "act: %d", res_act);
	cr_assert_eq(res_act, res_exp);
}

Test(test_memcmp, return_difference_of_first_differing_bytepair_neg)
{
	char * s1 = "012";
	char * s2 = "020";
	int res_act = ft_memcmp(s1, s2, strlen(s1));
	int res_exp = memcmp(s1, s2, strlen(s1));

	cr_expect_eq(res_act, -1);
	cr_assert_eq(res_act > 0, res_exp > 0, "act: %d, exp: %d", res_act, res_exp);
	cr_assert_eq(res_act == 0, res_exp == 0, "act: %d, exp: %d", res_act, res_exp);
}

Test(test_memcmp, comparison_is_done_in_unsigned)
{
	int s1 = -1;
	char * s2 = "\1";
	int res_act = ft_memcmp(&s1, s2, 1);
	int res_exp = memcmp(&s1, s2, 1);

	cr_assert_eq(res_act, res_exp, "act: %d, exp: %d", res_act, res_exp);
}