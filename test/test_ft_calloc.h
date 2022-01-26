#include "test_utils.h"

Test(test_calloc, overflow_returns_NULL_and_does_not_alloate_memory)
{
	int *test = (int *) ft_calloc(2147483647, 2147483647);

	cr_assert_eq(test, NULL);
}

Test(test_calloc, successful_call_allocates_memory_of_size_times_nmemb_bytes)
{
	size_t	nmemb = 2;
	size_t	size = sizeof(int);
	int *test = (int *) ft_calloc(nmemb, size);

	for (size_t i = 0; i < nmemb; i++)
		cr_expect_eq(test[i], 0, "exp %d, act %d, at index %zu", 0, test[i], i);
}

Test(test_calloc, return_freable_on_zero_size)
{
	size_t	nmemb = 0;
	size_t	size = 0 ;
	int *res_own = (int *) ft_calloc(nmemb, size);
	int *res_orig = (int *) calloc(nmemb, size);

	cr_assert_eq(*res_orig, *res_own);
}