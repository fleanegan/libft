#include "test_utils.h"

Test(calc_pos_of_char_n, returns_minus_one_when_not_found)
{
char	*buf = "";
int	pos_of_nl = calc_pos_of_char_n(buf, '\n', ft_strlen(buf) + SPACE_NULLTERMIN);

cr_assert_eq(pos_of_nl, -1);
}

Test(calc_pos_of_char_n, returns_index_when_found)
{
char	*buf = "\n";
int	pos_of_nl = calc_pos_of_char_n(buf, '\n', ft_strlen(buf) + SPACE_NULLTERMIN);

cr_assert_eq(pos_of_nl, 0);
}

Test(calc_pos_of_char_n, nl_on_second_pos_returns_one)
{
char	*buf = "a\n";
int	pos_of_nl = calc_pos_of_char_n(buf, '\n', ft_strlen(buf) + SPACE_NULLTERMIN);

cr_assert_eq(pos_of_nl, 1, "act %d", pos_of_nl);
}

Test(calc_pos_of_char_n, returns_minus_one_if_input_NULL)
{
	int	pos_of_nl = calc_pos_of_char_n(NULL, '\n', 1);

	cr_assert_eq(pos_of_nl, -1);
}

Test(calc_pos_of_char_n, use_as_strlen)
{
	char	*buf = "abc";
	int	pos_of_nl = calc_pos_of_char_n(buf, 0, ft_strlen(buf) + SPACE_NULLTERMIN);

	cr_assert_eq(pos_of_nl, 3);
}

Test(calc_pos_of_char_n, does_not_find_nl_if_exceeding_max)
{
	char	*buf = "a\n";
	size_t	max_len = 1;
	int	pos_of_nl = calc_pos_of_char_n(buf, 'n', max_len);

	cr_assert_eq(pos_of_nl, -1);
}

Test(calc_pos_of_char_n, do_not_stop_when_size_negative)
{
	char	*buf = "a\n";
	size_t	max_len = 1;
	int	pos_of_nl = calc_pos_of_char_n(buf, 'n', max_len);

	cr_assert_eq(pos_of_nl, -1);
}