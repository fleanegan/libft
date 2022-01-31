#include "test_utils.h"

Test(test_count_entries_in_2d_char_array, empty_array_returns_zero)
{
	char	*in_raw = "";
	char	**in = ft_split(in_raw, ' ');

	size_t	count = count_entries_in_2d_char_array(in);

	cr_assert_eq(count, 0);
	free_2d_array((void **)in);
}

Test(test_count_entries_in_2d_char_array, one_element_array_returns_one)
{
	char	*in_raw = "1 ";
	char	**in = ft_split(in_raw, ' ');

	size_t	count = count_entries_in_2d_char_array(in);

	cr_assert_eq(count, 1);
	free_2d_array((void **)in);
}

Test(test_count_entries_in_2d_char_array, safety_test)
{
	char	*in_raw = "1 4 4 3 1 ";
	char	**in = ft_split(in_raw, ' ');

	size_t	count = count_entries_in_2d_char_array(in);

	cr_assert_eq(count, 5);
	free_2d_array((void **)in);
}
