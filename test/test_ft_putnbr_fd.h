#include "test_utils.h"

Test(test_putnbr_fd, print_0)
{
	int		file_descriptor = STDOUT_FILENO;
	int 	in = 0;
	char	*exp_res = "0";
	cr_redirect_stdout();

	ft_putnbr_fd(in, file_descriptor);

	cr_bugfix_assert_str_stdout(exp_res);
}

Test(test_putnbr_fd, print_10)
{
	int		file_descriptor = STDOUT_FILENO;
	int 	in = 10;
	char	*exp_res = "10";
	cr_redirect_stdout();

	ft_putnbr_fd(in, file_descriptor);

	cr_bugfix_assert_str_stdout(exp_res);
}

Test(test_putnbr_fd, print_100)
{
	int		file_descriptor = STDOUT_FILENO;
	int 	in = 100;
	char	*exp_res = "100";
	cr_redirect_stdout();

	ft_putnbr_fd(in, file_descriptor);

	cr_bugfix_assert_str_stdout(exp_res);
}

Test(test_putnbr_fd, minus_print_100)
{
	int		file_descriptor = STDOUT_FILENO;
	int 	in = -100;
	char	*exp_res = "-100";
	cr_redirect_stdout();

	ft_putnbr_fd(in, file_descriptor);

	cr_bugfix_assert_str_stdout(exp_res);
}

Test(test_putnbr_fd, min_int)
{
	int		file_descriptor = STDOUT_FILENO;
	int 	in = -2147483648;
	char	*exp_res = "-2147483648";
	cr_redirect_stdout();

	ft_putnbr_fd(in, file_descriptor);

	cr_bugfix_assert_str_stdout(exp_res);
}