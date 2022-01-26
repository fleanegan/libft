#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/libft.h"
#include "test_utils.h"

Test(test_lstclear, passing_del_funct_which_prints_content_prints_0_on_list_with_one_element)
{
	char	*dummy_content_string = "0";
	char	*content = ft_strdup(dummy_content_string);
	t_list	*lst = ft_lstnew(content);

	cr_redirect_stdout();
	ft_lstclear(&lst, del);

	cr_bugfix_assert_str_stdout(dummy_content_string);
}

Test(test_lstclear, passing_del_funct_which_prints_content_prints_10_on_list_with_two_element)
{
	char	*content0 = ft_strdup("0");
	char	*content1 = ft_strdup("1");
	t_list	*first = ft_lstnew(content0);
	t_list	*second = ft_lstnew(content1);
	ft_lstadd_back(&first, second);

	cr_redirect_stdout();
	ft_lstclear(&first, del);

	cr_bugfix_assert_str_stdout("01");
}

Test(test_lstclear, passing_del_funct_which_prints_content_prints_210_on_list_with_three_element)
{
	char	*content0 = ft_strdup("0");
	char	*content1 = ft_strdup("1");
	char	*content2 = ft_strdup("2");
	t_list	*first = ft_lstnew(content0);
	t_list	*second = ft_lstnew(content1);
	t_list	*third = ft_lstnew(content2);
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);

	cr_redirect_stdout();
	ft_lstclear(&first, del);

	cr_bugfix_assert_str_stdout("012");
}

Test(test_lstclear, lstclear_sets_adress_to_null)
{
	t_list *lst = ft_lstnew(NULL);

	ft_lstclear(&lst, del);

	cr_assert_null(lst);
}

// how to test that free worked?