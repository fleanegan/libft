#include <criterion/criterion.h>
#include "../src/libft.h"

Test(test_tolower, letter_tolower)
{
	int 	src = 'A';
	int 	res = 'a';

	int 	res_real = ft_tolower(src);
	cr_assert_eq(res_real, res);
}

Test(test_tolower, non_letter_tolower)
{
	int 	src = '3';
	int 	res = '3';

	int 	res_real = ft_tolower(src);
	cr_assert_eq(res_real, res);
}

Test(test_tolower, exhaustive)
{
	int i;

	i = -100;
	while (i < 530)
	{
		if (i <= 'Z' && i >= 'A')
			cr_assert(i != ft_tolower(i), "should %d", i);
		else
			cr_assert(i == ft_tolower(i), "should not %d", i);
		i++;
	}
}