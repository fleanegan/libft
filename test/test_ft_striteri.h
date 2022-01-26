#include "test_utils.h"

void	test_iteri_function(unsigned int param, char *to_be_mapped)
{
	*to_be_mapped = (1 + *to_be_mapped);
	(void) param;
}

Test(test_striteri, apply_add_one_to_string)
{
	char	*in = malloc(4 * sizeof(char));
	ft_strlcpy(in, (const char *) &"abc", 4);

	ft_striteri(in, test_iteri_function);

	cr_assert_str_eq(in, "bcd");
}