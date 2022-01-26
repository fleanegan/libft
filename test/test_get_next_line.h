#include "test_utils.h"

Test(test_get_next_line, wrong_file_descriptor_returns_NULL, .disabled=0)
{
	int 	fd =  2147483647 - 1;

	char	*res = get_next_line(fd);

	cr_assert_null(res);
	free(res);
	close(fd);
}

Test(test_get_next_line, empty_file_returns_NULL, .disabled=0)
{
	char	*file_name = "./assets/empty_file.txt";
	int 	fd = open(file_name, O_RDONLY);

	char	*res = get_next_line(fd);

	cr_assert_null(res);
	free(res);
	close(fd);
}

Test(test_get_next_line, simplest_case_all_in_one_buffer, .disabled=0)
{
	char	*file_name = "./assets/hello_world.txt";
	int 	fd = open(file_name, O_RDONLY);

	char	*res = get_next_line(fd);

	cr_assert_str_eq(res, "a\n");
	free(res);
	close(fd);
}

Test(test_get_next_line, stop_at_newline, .disabled=0)
{
	//char	*file_name = "./assets/should_save_123.txt";
	char	*file_name = "./assets/ab.txt";
	int 	fd = open(file_name, O_RDONLY);

	char	*res = get_next_line(fd);

	cr_assert_str_eq(res, "a\n");
	free(res);
	free(get_next_line(fd));
	//leak normal since not is_done!
	close(fd);
}

Test(test_get_next_line, run_twice_do_not_lose_rest, .disabled=0)
{
	char	*file_name = "./assets/ab.txt";
	int 	fd = open(file_name, O_RDONLY);

	char	*res0 = get_next_line(fd);
	cr_assert_str_eq(res0, "a\n");

	char	*res1 = get_next_line(fd);
	cr_assert_str_eq(res1, "b012\n");

	free(res0);
	free(res1);
	close(fd);
}

Test(test_get_next_line, multiple_newline_in_one_buffer_reading, .disabled=0)
{
	char	*file_name = "./assets/newlines.txt";
	int 	fd = open(file_name, O_RDONLY);
	char	*res = get_next_line(fd);
	cr_assert_str_eq(res, "a\n");
	free(res);
	res = get_next_line(fd);
	cr_assert_str_eq(res, "\n");
	free(res);

	res = get_next_line(fd);

	cr_assert_str_eq(res, "b\n");
	free(res);
	close(fd);
}

Test(test_get_next_line, no_newline_char, .disabled=0)
{
	char	*file_name = "./assets/no_newline.txt";
	int 	fd = open(file_name, O_RDONLY);

	char	*res = get_next_line(fd);

	cr_assert_str_eq(res, "nope");
	free(res);
	close(fd);
}

Test(test_get_next_line, this_should_not_leak, .disabled=0)
{
	char	*file_name = "./assets/multiple_with_linee_ndings.txt";
	int 	fd = open(file_name, O_RDONLY);

	char	*res = get_next_line(fd);
	cr_assert_str_eq(res, "9876543210987654321098765432109876543210\n");
	free(res);

	res = get_next_line(fd);
	cr_assert_str_eq(res, "01234567890123456789012345678901234567890\n");
	free(res);

	res = get_next_line(fd);
	cr_assert_str_eq(res, "987654321098765432109876543210987654321098\n");
	free(res);

	res = get_next_line(fd);
	cr_assert_str_eq(res, "01234567890123456789012345678901234567890\n");
	free(res);

	res = get_next_line(fd);
	cr_assert_str_eq(res, "9876543210987654321098765432109876543210\n");
	free(res);

	res = get_next_line(fd);
	cr_assert_null(res);
	free(res);
	close(fd);
}

Test(test_get_next_line, read_two_different_fd, .disabled=0)
{
	char	*file_name_0 = "./assets/newlines.txt";
	char	*file_name_1 = "./assets/no_newline.txt";
	int 	fd_0 = open(file_name_0, O_RDONLY);
	int 	fd_1 = open(file_name_1, O_RDONLY);

	char	*res_0 = get_next_line(fd_0);
	char	*res_1 = get_next_line(fd_1);

	cr_assert_str_eq(res_0, "a\n");
	cr_assert_str_eq(res_1, "nope");
	free(res_0);

	res_0 = get_next_line(fd_0);
	cr_assert_str_eq(res_0, "\n");
	free(get_next_line(fd_0));
	free(get_next_line(fd_0));

	free(res_0);
	free(res_1);
	close(fd_0);
	close(fd_1);
}

Test(test_get_next_line, calling_void_does_not_lose_saved)
{
	int fd[4];
	char	*res;

	fd[0] = open("./assets/files/41_with_nl", O_RDWR);
	/* 1 */ res = get_next_line(1000);
	cr_assert_null(res);
	free(res);
	/* 2 */ res = get_next_line(fd[0]);
	cr_assert_str_eq(res, "0123456789012345678901234567890123456789\n");
	free(res);

	fd[1] = open("./assets/files/42_with_nl", O_RDWR);
	/* 3 */ res = get_next_line(1001);
	cr_assert_null(res);
	free(res);
	/* 4 */ res = get_next_line(fd[1]);
	cr_assert_str_eq(res, "01234567890123456789012345678901234567890\n");
	free(res);

	fd[2] = open("./assets/files/43_with_nl", O_RDWR);
	/* 5 */ res = get_next_line(1002);
	cr_assert_null(res);
	free(res);
	/* 6 */ res = get_next_line(fd[2]);
	cr_assert_str_eq(res, "012345678901234567890123456789012345678901\n");
	free(res);

	/* 7 */ res = get_next_line(1003);
	cr_assert_null(res);
	free(res);
	/* 8 */ res = get_next_line(fd[0]);
	cr_assert_str_eq(res, "0");

	/* 9 */ res = get_next_line(1004);
	cr_assert_null(res);
	free(res);
	/* 10 */ res = get_next_line(fd[1]);
	cr_assert_str_eq(res, "1");

}
// use test file with new line as last entry
// use test file with multiple newlines in last read

/*
			printf("result %s\n", result);
			printf("pos_of_nl %d\n", pos_of_nl);
			printf("max_len %d\n", max_len);
 */