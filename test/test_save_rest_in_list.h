#include "test_utils.h"


Test(test_push_fd_rest_on_lst, first_element)
{
	t_list_sav	*sav = NULL;
	char 		*content = ft_strdup("test");
	int 		fd = 1;
	save_fd_rest(&sav, fd, content);

	cr_assert_not_null(sav);
	cr_expect_eq(sav->fd, 1);
	cr_expect_eq(sav->next, NULL);
	cr_expect_str_eq(sav->content, "test");
	free(pop_fd_res(&sav, fd));
}

Test(test_push_fd_rest_on_lst, second_element)
{
	t_list_sav	*sav = NULL;
	save_fd_rest(&sav, 1, NULL);
	save_fd_rest(&sav, 2, NULL);

	cr_assert_not_null(sav);
	cr_expect_eq(sav->fd, 1);
	cr_expect_eq(sav->next->fd, 2);
	free(pop_fd_res(&sav, 1));
	free(pop_fd_res(&sav, 2));
}

Test(test_push_fd_rest_on_lst, pop_middle_element_relinks)
{
	t_list_sav	*sav = NULL;

	save_fd_rest(&sav, 1, NULL);
	save_fd_rest(&sav, 2, NULL);
	save_fd_rest(&sav, 3, NULL);
	cr_assert_not_null(sav);
	pop_fd_res(&sav, 2);

	cr_assert_not_null(sav);
	cr_expect_eq(sav->fd, 1);
	cr_expect_eq(sav->next->fd, 3);
	free(pop_fd_res(&sav, 1));
	free(pop_fd_res(&sav, 2));
	free(pop_fd_res(&sav, 3));
}

Test(test_push_fd_rest_on_lst, pop_first_element_moves_sav_ptr)
{
	t_list_sav	*sav = NULL;

	save_fd_rest(&sav, 1, NULL);
	save_fd_rest(&sav, 2, NULL);
	cr_assert_not_null(sav);

	pop_fd_res(&sav, 1);

	cr_assert_not_null(sav);
	cr_expect_eq(sav->fd, 2);
	free(pop_fd_res(&sav, 2));
}

Test(test_push_fd_rest_on_lst, pop_last_element)
{
	t_list_sav	*sav = NULL;

	save_fd_rest(&sav, 1, NULL);
	cr_assert_not_null(sav);

	pop_fd_res(&sav, 1);

	cr_expect_null(sav);
}

Test(test_push_fd_rest_on_lst, pop_element_gets_string_but_removes_element)
{
	t_list_sav	*sav = NULL;
	char 		*content = ft_strdup("abc");

	save_fd_rest(&sav, 1, NULL);
	save_fd_rest(&sav, 2, content);
	cr_assert_not_null(sav);

	char	*res = pop_fd_res(&sav, 2);

	cr_assert_str_eq(res, "abc");
	free(pop_fd_res(&sav, 1));
	free(res);
}

Test(test_push_fd_rest_on_lst, pop_non_existing_fd_returns_NULL)
{
	t_list_sav	*sav = NULL;

	save_fd_rest(&sav, 1, NULL);
	cr_assert_not_null(sav);

	char	*res = pop_fd_res(&sav, 2);

	cr_assert_null(res);
	cr_assert_not_null(sav);
	free(pop_fd_res(&sav, 1));
	free(pop_fd_res(&sav, 2));
}

Test(test_push_fd_rest_on_lst, free_linked_list)
{
	t_list_sav	*sav = NULL;

	save_fd_rest(&sav, 1, NULL);
	save_fd_rest(&sav, 5, NULL);
	save_fd_rest(&sav, 2, NULL);
	cr_assert_not_null(sav);

	free_linked_list(&sav);

	cr_assert_null(sav);
}