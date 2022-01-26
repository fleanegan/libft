#include "test_utils.h"

Test(test_putstr_fd, print_one_char_to_stdout)
{
	int	file_descriptor = STDOUT_FILENO;
	char	s = 'a';

	cr_redirect_stdout();
	ft_putstr_fd(&s, file_descriptor);

	cr_bugfix_assert_str_stdout(&s);
}

Test(test_putstr_fd, print_whole_str_to_stdout)
{
	int	file_descriptor = STDOUT_FILENO;
	char	*s = "abc";

	cr_redirect_stdout();
	ft_putstr_fd(s, file_descriptor);

	cr_bugfix_assert_str_stdout(s);
}

Test(test_putstr_fd, print_one_char_to_stderr)
{
	int	file_descriptor = STDERR_FILENO;
	char	s = 'a';

	cr_redirect_stderr();
	ft_putstr_fd(&s, file_descriptor);

	cr_bugfix_assert_str_stderr(&s);
}