#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_lstsize, element_without_link_has_size_one)
{
	t_list *lst = ft_lstnew(NULL);

	int res_act = ft_lstsize(lst);

	cr_assert_eq(res_act, 1);
}

Test(test_lstsize, two_elements_have_size_two)
{
	t_list *first = ft_lstnew(NULL);
	t_list *second = ft_lstnew(NULL);
	ft_lstadd_back(&first, second);

	int res_act = ft_lstsize(first);

	cr_assert_eq(res_act, 2);
}

Test(test_lstsize, no_elements_have_size_zero)
{
	t_list *first = NULL;

	int res_act = ft_lstsize(first);

	cr_assert_eq(res_act, 0);
}