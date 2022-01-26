run_tests:
			$(MAKE) -C 	./test/ run

run_tests_compile_no_flags:
			$(MAKE) -C 	./test/ run_no_flags

re:
			$(MAKE) -C 	./src/ re
			$(MAKE) -C 	./test/ re

clean:
			$(MAKE) -C  ./src/ clean

fclean:		clean
			$(MAKE) -C 	./src/ fclean
			$(MAKE) -C 	./test/ fclean

all:
			$(MAKE) -C 	./src/ bonus
			$(MAKE) -C 	./test/ all

own_tests:
			$(MAKE) -C 	./src/ bonus
			$(MAKE) -C 	./test/ test_own