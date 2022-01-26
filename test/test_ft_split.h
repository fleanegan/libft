#include "test_utils.h"


Test(test_split, last_entry_of_result_is_NULL)
{
	char	*src = "";
	char	set = 0;

	char 	**res_act = ft_split(src, set);

	cr_assert_eq(res_act[1], 0);
}

Test(test_split, a_string_not_split_is_copied_into_the_first_memory_segment_returned)
{
	char	*src = "aa";
	char	set = 'b';
	char	*res_exp_sub_0 = "aa";

	char 	**res_act = ft_split(src, set);

	cr_assert_str_eq(res_act[0], res_exp_sub_0);
}

Test(test_split, a_splittable_string_gets_split_once_and_stored_in_two_memory_entries)
{
	char	*src = "aba";
	char	set = 'b';
	char	*res_exp_sub_0 = "a";
	char	*res_exp_sub_1 = "a";

	char 	**res_act = ft_split(src, set);

	cr_assert_str_eq(res_act[0], res_exp_sub_0);
	cr_assert_str_eq(res_act[1], res_exp_sub_1);
}

Test(test_split, two_following_split_chars_do_only_split_once)
{
	char	*src = "abba";
	char	set = 'b';
	char	*res_exp_sub_0 = "a";
	char	*res_exp_sub_1 = "a";

	char 	**res_act = ft_split(src, set);

	cr_assert_str_eq(res_act[0], res_exp_sub_0);
	cr_assert_str_eq(res_act[1], res_exp_sub_1);
}

Test(test_split, leading_set_chars_are_ignored)
{
	char	*src = "babba";
	char	set = 'b';
	char	*res_exp_sub_0 = "a";
	char	*res_exp_sub_1 = "a";

	char 	**res_act = ft_split(src, set);

	cr_assert_str_eq(res_act[0], res_exp_sub_0);
	cr_assert_str_eq(res_act[1], res_exp_sub_1);
}

Test(test_split, split_many)
{
	char	*src = "ababa";
	char	set = 'b';
	char	*res_exp_sub_0 = "a";
	char	*res_exp_sub_1 = "a";
	char	*res_exp_sub_2 = "a";

	char 	**res_act = ft_split(src, set);

	cr_assert_str_eq(res_act[0], res_exp_sub_0);
	cr_assert_str_eq(res_act[1], res_exp_sub_1);
	cr_assert_str_eq(res_act[2], res_exp_sub_2);
}

Test(test_split, if_set_not_in_src_return_NULL)
{
	char	*src = "";
	char	set = 'z';

	char 	**res_act = ft_split(src, set);

	cr_assert_null(res_act[0]);
}

Test(test_split, war_machine_test)
{
	//char	*src = ft_strdup("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse");
	char	*src = ft_strdup("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse  ");
	char	set = ' ';
	char *res_exp_sub_0;
	res_exp_sub_0 = "lorem";
	char *res_exp_sub_1;
	char *res_exp_sub_2;
	char *res_exp_sub_3;
	char *res_exp_sub_4;
	char *res_exp_sub_5;
	char *res_exp_sub_6;
	char *res_exp_sub_7;
	char *res_exp_sub_8;
	char *res_exp_sub_9;
	char *res_exp_sub_10;
	char *res_exp_sub_11;
	char **res_act;

for (int i = 0; i < 1; i++)
{
	res_exp_sub_1 = "ipsum";
	res_exp_sub_2 = "dolor";
	res_exp_sub_3 = "sit";
	res_exp_sub_4 = "amet,";
	res_exp_sub_5 = "consectetur";
	res_exp_sub_6 = "adipiscing";
	res_exp_sub_7 = "elit.";
	res_exp_sub_8 = "Sed";
	res_exp_sub_9 = "non";
	res_exp_sub_10 = "risus.";
	res_exp_sub_11 = "Suspendisse";

	res_act = ft_split(src, set);

	cr_assert_str_eq(res_act[0], res_exp_sub_0);
	cr_assert_str_eq(res_act[1], res_exp_sub_1);
	cr_assert_str_eq(res_act[2], res_exp_sub_2);
	cr_assert_str_eq(res_act[3], res_exp_sub_3);
	cr_assert_str_eq(res_act[4], res_exp_sub_4);
	cr_assert_str_eq(res_act[5], res_exp_sub_5);
	cr_assert_str_eq(res_act[6], res_exp_sub_6);
	cr_assert_str_eq(res_act[7], res_exp_sub_7);
	cr_assert_str_eq(res_act[8], res_exp_sub_8);
	cr_assert_str_eq(res_act[9], res_exp_sub_9);
	cr_assert_str_eq(res_act[10], res_exp_sub_10);
	cr_assert_str_eq(res_act[11], res_exp_sub_11);
}
}
// add test for failing malloc - how to do this?
// add random brute force