#include "test_utils.h"

Test(test_strnhr, any_search_in_empty_haystack_returns_NULL)
{
	char	*haystack = "";
	char	*needle = "sth";

	char	*res_act = ft_strnstr(haystack, needle, ft_strlen(haystack));

	cr_assert_null(res_act);
}

Test(test_strnhr, search_with_empty_needle_returns_haystack)
{
	char	*haystack = "sth";
	char	*needle = "";

	char	*res_act = ft_strnstr(haystack, needle, ft_strlen(haystack));

	cr_assert_str_eq(res_act, "sth");
}

Test(test_strnhr, needle_with_one_char_is_like_strchr)
{
	char	*haystack = "sth";
	char	*needle = "t";

	char	*res_act = ft_strnstr(haystack, needle, ft_strlen(haystack));

	cr_assert_eq(res_act, haystack + 1);
}

Test(test_strnhr, finding_needle_longer_than_one)
{
	char	*haystack = "sthto";
	char	*needle = "to";

	char	*res_act = ft_strnstr(haystack, needle, ft_strlen(haystack));

	cr_assert_eq(res_act, haystack + 3, "pos: %s", res_act);
}

Test(test_strnhr, returns_NULL_if_needle_is_out_of_len)
{
	char	*haystack = "abxxx";
	char	*needle = "xxx";

	char	*res_act = ft_strnstr(haystack, needle, 3);

	cr_assert_null(res_act);
}