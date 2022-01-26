#include "test_utils.h"

Test(test_atoi, empty_string_returns_zero) {
	char *in = "";
	int res_exp = atoi(in);

	int res = ft_atoi(in);

	cr_assert_eq(res_exp, res, "expected: %d , real: %d", res_exp, res);
	cr_assert_eq(res_exp, 0, "expected: %d , real: %d", res_exp, 0);
}

Test(test_atoi, invalid_input_returns_zero) {
	char *in = "j";
	int res_exp = atoi(in);

	int res = ft_atoi(in);
	
	cr_assert_eq(res_exp, res, "expected: %d , real: %d", res_exp, res);
	cr_assert_eq(res_exp, 0, "expected: %d , real: %d", res_exp, 0);
}

Test(test_atoi, single_digit_input) {
	char *in = "1";
	int res_exp = atoi(in);

	int res = ft_atoi(in);
	
	cr_assert_eq(res_exp, res, "expected: %d , real: %d", res_exp, res);
	cr_assert_eq(res_exp, 1, "expected: %d , real: %d", res_exp, 1);
}

Test(test_atoi, single_digit_input_with_signs) {
	char *in1 = "-1";
	int res_exp1 = atoi(in1);
	int res1 = ft_atoi(in1);
	char *in2 = "+1";
	int res_exp2 = atoi(in2);
	int res2 = ft_atoi(in2);

	cr_assert_eq(res_exp1, res1, "expected: %d , real: %d", res_exp1, res1);
	cr_assert_eq(res_exp1, -1, "expected: %d , real: %d", res_exp1, -1);
	cr_assert_eq(res_exp2, res2, "expected: %d , real: %d", res_exp2, res2);
	cr_assert_eq(res_exp2, 1, "expected: %d , real: %d", res_exp2, 1);
}

Test(test_atoi, whitespaces_at_begining) {
	char *in = "	 -1";
	int res_exp = atoi(in);

	int res = ft_atoi(in);

	cr_assert_eq(res_exp, res, "expected: %d , real: %d", res_exp, res);
	cr_assert_eq(res_exp, -1, "expected: %d , real: %d", res_exp, -1);
}

Test(test_atoi, multiple_digits) {
	char *in = "123";
	int res_exp = atoi(in);

	int res = ft_atoi(in);

	cr_assert_eq(res_exp, res, "expected: %d , real: %d", res_exp, res);
	cr_assert_eq(res_exp, 123, "expected: %d , real: %d", res_exp, 123);
}

Test(test_atoi, overflow_with_normal_int) {
	char *in = "-2147483648";
	long res_exp = atoi(in);

	long res = ft_atoi(in);

	cr_assert_eq(res_exp, res, "expected: %ld , real: %ld", res_exp, res);
	cr_assert_eq(res_exp, -2147483648, "expected: %ld , real: %ld", res_exp, -2147483648);
}

Test(test_atoi, behaves_like_stdlib_for_undefined_behavior) {
	char *in = "-21474836481";
	int res_exp = atoi(in);

	int res = ft_atoi(in);

	cr_assert_eq(res_exp, res, "expected: %d , real: %ld", res_exp, -2147483648);
}



// what else !?