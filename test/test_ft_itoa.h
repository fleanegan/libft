#include <criterion/criterion.h>

Test(test_itoa, zero)
{
	int		in	= 0;
	char	*res_exp = "0";

	char	*res_act = ft_itoa(in);

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_itoa, one)
{
	int		in	= 1;
	char	*res_exp = "1";

	char	*res_act = ft_itoa(in);

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_itoa, ten)
{
	int		in	= 10;
	char	*res_exp = "10";

	char	*res_act = ft_itoa(in);

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_itoa, minus_ten)
{
	int		in	= -10;
	char	*res_exp = "-10";

	char	*res_act = ft_itoa(in);

	cr_assert_str_eq(res_act, res_exp);
}


Test(test_itoa, minimal_int, .disabled=false)
{
	int		in	= -2147483648;
	char	*res_exp = "-2147483648";

	char	*res_act = ft_itoa(in);

	cr_assert_str_eq(res_act, res_exp);
}

