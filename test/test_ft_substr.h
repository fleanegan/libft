#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_substr, zero_length_returns_empty_string)
{
	char	src[] = "a";
	char	res_exp[] = "";
	size_t	len = 0;
	size_t	start = 0;

	char	*res_act = ft_substr(src, start, len);

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_substr, one_length_returns_zeroterminated_string)
{
	char	src[] = "a";
	char	res_exp[] = "a";
	size_t	len = 1;
	size_t	start = 0;

	char	*res_act = ft_substr(src, start, len);

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_substr, start_offsets_the_returned_string)
{
	char	src[] = "ab";
	char	res_exp[] = "b";
	size_t	len = 1;
	size_t	start = 1;

	char	*res_act = ft_substr(src, start, len);

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_substr, len_limits_the_substring_size)
{
	char	src[] = "ab";
	char	res_exp[] = "a";
	size_t	len = 1;
	size_t	start = 0;

	char	*res_act = ft_substr(src, start, len);

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_substr, returns_empty_string_if_start_after_zero_termination)
{
	char	*src = "a\0b";
	char	res_exp[] = "";
	size_t	len = 1;
	size_t	start = 2;

	char	*res_act = ft_substr(src, start, len);

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_substr, returned_string_shorter_than_len_if_zeroterminated_earlier)
{
	char	*src = "a\0b";
	char	res_exp[] = "a";
	size_t	len = 2;
	size_t	start = 0;

	char	*res_act = ft_substr(src, start, len);

	cr_assert_str_eq(res_act, res_exp);
}

Test(test_substr, returns_malloc_string)
{
	char	src[] = "a\0b";
	char	res_exp[] = "a";
	size_t	len = 2;
	size_t	start = 0;

	char	*res_act = ft_substr(src, start, len);
	ft_bzero(src, 1);

	cr_assert_str_eq(res_act, res_exp);
}
