#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_toupper, letter_toupper)
{
	int 	src = 'a';
	int 	res = 'A';

	int 	res_real = ft_toupper(src);
	cr_assert_eq(res_real, res);
}

Test(test_toupper, non_letter_toupper)
{
	int 	src = '3';
	int 	res = '3';

	int 	res_real = ft_toupper(src);
	cr_assert_eq(res_real, res);
}

Test(test_topper, exhaustive)
{
	int i;

	i = -100;
	while (i < 530)
	{
		if (i <= 'z' && i >= 'a')
			cr_assert(i != ft_toupper(i), "should %d", i);
		else
			cr_assert(i == ft_toupper(i), "should not %d", i);
		i++;
	}
}