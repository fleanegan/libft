#include "test_utils.h"

Test(test_memccpy, return_NULL_if_char_not_found)
{
	char	*src = "";
	char	key = 'a';
	char	dest[1];

	void	*res_act = ft_memccpy(dest, src, key, 1);

	cr_assert_null(res_act);
}

Test(test_memccpy, if_key_is_zero_act_like_memcpy)
{
	char	*src = "a\0b";
	char	key = 0;
	char	dest_own[2] = {1, 1};
	char	dest_orig[2] = {1, 1};

	ft_memccpy(dest_own, src, key, 2);
	memcpy(dest_orig, src, 2);

	cr_assert_str_eq(dest_orig, dest_own);
}


Test(test_memccpy, if_key_is_not_zero_copy_all_until_key_including_key)
{
	char	*src = "a\0b";
	char	key = 'b';
	char	dest_own[4] = {1, 1, 56, 22};
	char	dest_orig[4] = {1, 1, 56, 22};

	char *res_act = ft_memccpy(dest_own, src, key, 3);
	char *res_exp = memccpy(dest_orig, src, key, 3);

	cr_assert_arr_eq(dest_own, dest_orig, 3 * sizeof(char), "act .%s., exp .%s.", dest_own, dest_orig);
	cr_assert_eq(*res_act, *res_exp, "act %d, exp %d", *res_act, *res_exp);
	cr_assert_not_null(res_act);
}

Test(test_memccpy, basic_test)
{
	char src[] = "test basic du memccpy !";
	char buff1[22];
	char buff2[22];

	memccpy(buff1, src, 'm', 6);
	ft_memccpy(buff2, src, 'm', 6);

	int success = !memcmp(buff1, buff2, 6);
	cr_assert(success);
}
