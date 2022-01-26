#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_lstnew, next_is_null)
{
	t_list *new_lst = ft_lstnew(NULL);

	cr_assert_eq(new_lst->next, NULL);
	cr_assert_eq(new_lst->prev, NULL);
}

Test(test_lstnew, content_is_put_into_struct)
{
	char *content = "test";
	t_list *new_lst = ft_lstnew(content);

	cr_assert_str_eq((char *) new_lst->content, content);
}