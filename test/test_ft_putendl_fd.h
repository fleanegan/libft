#include "test_utils.h"

Test(test_putendl_fd, write_with_new_line)
{
	int		file_descriptor = STDOUT_FILENO;
	char	*in = "abc";
	char	*exp_res = "abc\n";
	cr_redirect_stdout();

	ft_putendl_fd(in, file_descriptor);

	cr_bugfix_assert_str_stdout(exp_res);
}