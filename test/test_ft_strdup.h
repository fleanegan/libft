#include <criterion/criterion.h>

Test(test_strdup, empty_string)
{
	char	*in = "";
	char	*res_exp = "";

	char	*res_act = ft_strdup(in);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_strdup, result_is_not_reffering_to_same_memory)
{
	char	in[1] = "";
	char	*res_exp = "";

	char	*res_act = ft_strdup(in);
	*in = '1';

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_strdup, long_string)
{
	char	*in = "this is a test";
	char	*res_exp = "this is a test";

	char	*res_act = ft_strdup(in);
	cr_assert_str_eq(res_act, res_exp);
}