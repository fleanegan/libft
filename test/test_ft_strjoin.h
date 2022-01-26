#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_strjoin, two_empty_strings_joined_are_an_empty_string)
{
	char a[] = "";
	char b[] = "";
	char *res_exp = "";

	char	*res_act = ft_strjoin(a, b);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_strjoin, first_string_non_empty_second_empty)
{
	char a[] = "a";
	char b[] = "";
	char *res_exp = "a";

	char	*res_act = ft_strjoin(a, b);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_strjoin, first_string_empty_second_non_empty)
{
	char a[] = "";
	char b[] = "b";
	char *res_exp = "b";

	char	*res_act = ft_strjoin(a, b);
	cr_assert_str_eq(res_act, res_exp);
}

Test(test_strjoin, both_non_empty)
{
	char a[] = "abc";
	char b[] = "def";
	char *res_exp = "abcdef";

	char	*res_act = ft_strjoin(a, b);
	cr_assert_str_eq(res_act, res_exp);
}
