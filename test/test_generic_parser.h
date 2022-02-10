#include "test_utils.h"
#include "test_generic_parser/test_generic_parser_utils.h"

Test(test_generic_parser, parse_file_into_struct)
{
	char			*file_name = "assets/generic_parser/zero_one_two.txt";
	t_dummy_struct *res = parse_file(file_name, \
                                     generate_dummy_struct, \
                                     fill_dummy_struct_line_wise, \
                                     free);
	cr_assert_not_null(res);
	assert_struct_filled_correctly(res);
	free(res);
}

Test(test_generic_parser, non_existing_file_returns_NULL)
{
	char			*file_name = "non_existing";
	t_dummy_struct *res = parse_file(file_name, \
                                     generate_dummy_struct, \
                                     fill_dummy_struct_line_wise, \
                                     free);
	cr_assert_null(res);
}

Test(test_generic_parser, error_in_struct_populate_frees_struct)
{
	char			*file_name = "assets/generic_parser/invalid_file_too_long.txt";
	t_dummy_struct *res = parse_file(file_name, \
                                     generate_dummy_struct, \
                                     fill_dummy_struct_line_wise, \
                                     free);
	cr_assert_null(res);
}

Test(test_generic_parser, error_in_struct_initializer_returns_NULL)
{
	char			*file_name = "assets/generic_parser/zero_one_two.txt";
	t_dummy_struct *res = parse_file(file_name, \
                                     generate_dummy_struct_broken, \
                                     fill_dummy_struct_line_wise, \
                                     free);
	cr_assert_null(res);
}

Test(test_generic_parser, each_column_of_line_string_gets_stored_in_struct)
{
	t_dummy_struct	container;
	char			*in = "0 1 2";

	int result = generic_split_line_parser(in, &container, 0, fill_dummy_struct_grid_wise);

	cr_assert_eq(result, 0);
	assert_struct_filled_correctly(&container);

}
// TODO: Now create generic line split base function to fill struct