#include <criterion/criterion.h>
#include "test_utils.h"

Test(test_strlcat, appending_an_empty_src_to_an_empty_dest_does_nothing_and_returns_zero)
{
	char	*src = "";
	char	dest_own[2] = "";
	char	dest_orig[2] = "";

	size_t	ret_own = ft_strlcat(dest_own, src, 2);
	size_t	ret_orig = strlcat(dest_orig, src, 2);

	cr_assert_eq(dest_own[0], 0);
	cr_assert_eq(ret_own, 0);
	cr_assert_eq(ret_orig, ret_own);
}

Test(test_strlcat, appending_an_empty_src_to_a_dest_bigger_than_size_does_nothing_and_returns_size)
{
	char	*src = "";
	char	dest_own[3] = "ai";
	char	dest_orig[3] = "ai";

	size_t	ret_own = ft_strlcat(dest_own, src, 1);
	size_t	ret_orig = strlcat(dest_orig, src, 1);

	cr_assert_eq(ret_own, 1, "The result was %d. Expected %d", 1, (int) ret_own);
	cr_assert_eq(ret_orig, ret_own);
}

Test(test_strlcat, appending_an_empty_src_to_a_dest_smaller_than_size_does_nothing_and_returns_len_of_dest)
{
	char	*src = "";
	char	dest_own[3] = "ai";
	char	dest_orig[3] = "ai";

	size_t	ret_own = ft_strlcat(dest_own, src, 3);
	size_t	ret_orig = strlcat(dest_orig, src, 3);

	cr_assert_eq(ret_own, 2, "The result was %d. Expected %d", 2, (int) ret_own);
	cr_assert_eq(ret_orig, ret_own);
}

Test(test_strlcat, appending_a_src_to_a_dest_smaller_than_size_appends_src_to_dest_and_returns_total_len)
{
	char	*src = "b";
	char	dest_own[3] = "a";
	char	dest_orig[3] = "a";

	size_t	ret_own = ft_strlcat(dest_own, src, 3);
	size_t	ret_orig = strlcat(dest_orig, src, 3);

	cr_assert_eq(ret_own, 2, "The result was %d. Expected %d", (int) ret_own, 2);
	cr_assert_eq(ret_own, ret_orig);
	cr_assert_str_eq(dest_own, dest_orig);
}

Test(test_strlcat, appending_a_src_bigger_than_size_to_an_empty_dest_appends_a_truncated_src_to_dest_and_returns_succeeded_len)
{
	char	*src = "ab";
	char	dest_own[2] = {0, 0};
	char	dest_orig[2] = {0, 0};

	size_t	ret_own = ft_strlcat(dest_own, src, 2);
	size_t	ret_orig = strlcat(dest_orig, src, 2);

	cr_assert_eq(ret_own, 2, "The result was %d. Expected %d", (int) ret_own, 2);
	cr_assert_eq(ret_own, ret_orig);
	cr_assert_str_eq(dest_own, dest_orig);
}

Test(test_strlcat, appending_a_src_to_a_dest_in_sum_bigger_than_size_appends_a_truncated_src_to_dest_and_returns_succeeded_len) {
	char *src = "bc";
	char dest_own[3] = {'a', 0, 0};
	char dest_orig[3] = {'a', 0, 0};

	size_t ret_own = ft_strlcat(dest_own, src, 3);
	size_t ret_orig = strlcat(dest_orig, src, 3);

	cr_assert_eq(ret_own, 3, "the result was %d. expected %d", (int) ret_own, 3);
	cr_assert_eq(ret_own, ret_orig, "expected %d", (int) ret_orig);
	cr_assert_str_eq(dest_own, dest_orig);
}

Test(test_strlcat, appending_a_src_to_a_dest_in_sum_smaller_than_size_appends_a_non_truncated_src_to_dest_and_returns_succeeded_len) {
char *src = "bc";
char dest_own[4] = {'a', 0, 0, 0};
char dest_orig[4] = {'a', 0, 0, 0};

size_t ret_own = ft_strlcat(dest_own, src, 4);
size_t ret_orig = strlcat(dest_orig, src, 4);

cr_assert_eq(ret_own, 3, "the result was %d. expected %d", (int) ret_own, 3);
cr_assert_eq(ret_own, ret_orig, "expected %d", (int) ret_orig);
cr_assert_str_eq(dest_own, dest_orig);
}

Test(test_strlcat, brute_force)
{
	strcat_obj_ptr result = generate_test_strings(3);
	while (result->src) {
		size_t ret_own = ft_strlcat(result->dst_own, result->src, result->size_parameter);
		size_t ret_orig = strlcat(result->dst_orig, result->src, result->size_parameter);

		//printf("src %s, dst %s, size %d\n ", result->src, result->dst_own, (int) result->size_parameter);

		cr_expect_eq(ret_own, ret_orig);
		cr_expect_str_eq(result->dst_own, result->dst_orig, "own: %s \n act: %s", result->dst_own, result->dst_orig);
		result++;
	}
}