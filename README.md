# test_libft
This project allows to test the functions necessary for libft and is based on the test framework criterion (https://github.com/Snaipe/Criterion). I would be glad to receive comments and suggestions in order to improve the test quality and readability.
Comes with no warranty whatsoever.

Installation of criterion
---
Follow the instructions on the official criterion git hub page for your setup OR
run the following code in the test_libft root directory:

```
wget https://github.com/Snaipe/Criterion/releases/download/v2.3.3/criterion-v2.3.3-linux-x86_64.tar.bz2
tar -xf criterion-v2.3.3-linux-x86_64.tar.bz2
rm criterion-v2.3.3-linux-x86_64.tar.bz2
```

Test execution
---
1. Add your own source_files.c into the src folder

2. Write the test of function x as test/test_ft_x.h

3. Include the test_ft_x.h in the test/test_main.c file, else the tests will not be executed!

4. Use the Makefile to compile and run the tests:

	Run the following command in the root directory:
	```
	make run_tests
	```
	which compiles with all the flags also used by the Moulinette. To compile without them run

	```
	make run_tests_compile_no_flags
	```
