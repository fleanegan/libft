#include "test_utils.h"

int	is_int_content_b_greater_a(void *a, void *b)
{
	return (a <= b);
}

Test(test_lstcompare, return_0_if_one_lst_NULL)
{
	t_list	*a = ft_lstnew(NULL);
	t_list	*b = NULL;

	int     result = ft_lstcompare(a, b, is_int_content_b_greater_a);

	cr_assert_eq(result, 0);
}

Test(test_lstcompare, two_lsts_with_the_same_content_return_1)
{
	t_list	*a = ft_lstnew(malloc_int(1));
	t_list	*b = ft_lstnew(malloc_int(1));

	int     result = ft_lstcompare(a, b, is_int_content_b_greater_a);

	cr_assert_eq(result, 1);
}

Test(test_lstcompare, return_0_if_not_the_same_size)
{
	t_list	*a = ft_lstnew(malloc_int(1));
	t_list	*b = ft_lstnew(malloc_int(1));
	t_list	*c = ft_lstnew(malloc_int(1));
	ft_lstadd_back(&b, c);

	int     result = ft_lstcompare(a, b, is_int_content_b_greater_a);

	cr_assert_eq(result, 0);
}
