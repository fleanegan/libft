#include "test_utils.h"

Test(test_strlcpy, copy_empty_string)
{
	char	*src = "";
	int 	buf_size = ft_strlen(src) + 1;
	char	dest[] = {1};

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[buf_size - 1], 0);
	cr_assert_eq(ret_val, strlcpy(dest, src, buf_size));
}

Test(test_strlcpy, copy_one_char_string)
{
	char	*src = "1";
	int 	buf_size = ft_strlen(src) + 1;
	char	dest[] = {1};

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[0], '1');
	cr_assert_eq(dest[buf_size - 1], 0);
	cr_assert_eq(ret_val, 1);
}

Test(test_strlcpy, copy_two_char_string)
{
	char	*src = "12";
	int 	buf_size = ft_strlen(src) + 1;
	char	dest[buf_size];

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[0], '1');
	cr_assert_eq(dest[1], '2');
	cr_assert_eq(dest[buf_size - 1], 0);
	cr_assert_eq(ret_val, 2);
}

Test(test_strlcpy, copy_only_if_within_buf_size)
{
	char	*src = "1";
	int 	buf_size = 1;
	char	dest[buf_size];

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[0], 0);
	cr_assert_eq(dest[buf_size - 1], 0);
	cr_assert_eq(ret_val, strlcpy(dest, src, buf_size));
}

Test(test_strlcpy, copy_empty_source)
{
	char	*src = "";
	int 	buf_size = 3;
	char	dest[4] = "abc";

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[0], 0);
	cr_assert_eq(ret_val, 0);
}

Test(test_strlcpy, size_zero_does_not_nullterminate)
{
	char	*src = "a";
	int 	buf_size = 0;
	char	dest[4] = "abc";

	size_t	ret_val = ft_strlcpy(dest, src, buf_size);
	cr_assert_eq(dest[0], 'a');
	cr_assert_eq(ret_val, 1);
}

Test(test_strlcpy, war_machine_non_text1)
{
	char	*src = "lorem ipsum dolor sit amet";
	int		buf_size = 11;
	char	*dest_own = ft_strdup("\00rrr\00\00\00\00\00\00\00\00\00");
	char	*dest_orig = ft_strdup("\00rrr\00\00\00\00\00\00\00\00\00");

	size_t	ret_val_own = ft_strlcpy(dest_own, src, buf_size);
	size_t	ret_val_orig = ft_strlcpy(dest_orig, src, buf_size);

	cr_assert_arr_eq(src, dest_own, 10 * sizeof(char));
	cr_assert_arr_eq(dest_orig, dest_own, 10 * sizeof(char));

	cr_assert_eq(ret_val_orig, ret_val_own);
}

