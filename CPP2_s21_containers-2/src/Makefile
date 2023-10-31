SHELL := /bin/bash

.PHONY: all clean test style_format style_test

CXX = gcc 
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic 

# DBG_FLGS должен быть закомментирован для тестов на утечки.
# DBG_FLGS = -fsanitize=address -fsanitize=undefined
TST_LIB_FLGS = -lgtest -lgmock -pthread

OS := $(shell uname -s)

ifeq ($(OS),Linux)
		LEAKS_CHECKER=valgrind		
else
	ifeq ($(OS),Darwin)
		LEAKS_CHECKER=leaksT
	endif
endif

# список исходников тестов для list, map, queue, set, stack и vector
TST_SRC_VECTOR = "tests/test_for_vector/vector_tests.cc"
TST_SRC_MAP = "tests/test_for_map/map_tests.cc"
TST_SRC_SET = "tests/test_for_set/set_tests.cc"
TST_SRC_LIST = "tests/test_for_list/list_tests.cc"
TST_SRC_QUEUE = "tests/test_for_queue/queue_tests.cc"
TST_SRC_STACK = "tests/test_for_stack/stack_tests.cc"

all:  clean test

test_separator:
	@echo "================================="
	@read -n 1 -s -r -p "Press any key to start next test."

test:
	@make clean
	clear
	@make t_set
	@make test_separator
	@make t_stack
	@make test_separator
	@make t_vector
	@make test_separator
	@make t_queue
	@make test_separator
	@make t_map
	@make test_separator
	
t_set:
	clear
	@echo "Tests of the SET container are running"
	@echo "======================================="
	@g++ $(CXXFLAGS) $(TST_SRC_SET) $(TST_LIB_FLGS) $(DBG_FLGS) -o test 2> compilation_ouput.txt 
	# ./test
	@make $(LEAKS_CHECKER)
	@rm test

t_list:
	clear
	@echo "Tests of the LIST container are running"
	@echo "======================================="
	@g++ $(CXXFLAGS) $(TST_SRC_LIST) $(TST_LIB_FLGS) $(DBG_FLGS) -o test 2> compilation_ouput.txt 
	./test
	@make $(LEAKS_CHECKER)
	@rm test
	
t_stack:
	clear
	@echo "Tests of the STACK container are running"
	@echo "========================================="	
	@g++ $(CXXFLAGS) $(TST_SRC_STACK) $(TST_LIB_FLGS) $(DBG_FLGS) -o test 2> compilation_ouput.txt 
	# ./test
	@make $(LEAKS_CHECKER) 
	@rm test

t_queue:
	clear
	@echo "Tests of the QUEUE container are running"
	@echo "========================================="
	@g++ $(CXXFLAGS) $(TST_SRC_QUEUE) $(TST_LIB_FLGS) $(DBG_FLGS) -o test 2> compilation_ouput.txt 
	# ./test
	@make $(LEAKS_CHECKER) 
	@rm test

t_vector:
	clear
	@echo "Tests of the VECTOR container are running"
	@echo "=========================================="
	@g++ $(CXXFLAGS) $(TST_SRC_VECTOR) $(TST_LIB_FLGS) $(DBG_FLGS) -o test 2> compilation_ouput.txt 
	# ./test
	@make $(LEAKS_CHECKER) 
	@rm test

t_map: 
	clear
	@echo "Tests of the MAP container are running"
	@echo "======================================="
	@g++ $(CXXFLAGS) $(TST_SRC_MAP) $(TST_LIB_FLGS) $(DBG_FLGS) -o test 2> compilation_ouput.txt 
	#./test
	@make $(LEAKS_CHECKER) 
	@rm ./test

clean: 
	rm -f test *.o *.a valgrind-out.txt compilation_ouput.txt

# для корректной работы компилировать отключив флаги санитайзера
valgrind: 
	@echo "=> valgrind"
#	g++ $(CXXFLAGS) $(TST_SRC) $(TST_LIB_FLGS) -o test
	valgrind --tool=memcheck --leak-check=yes ./test 		 
#	@rm test

leaksT:
	@echo "=> leaks check"
#	g++ $(CXXFLAGS) $(TST_SRC)  $(TST_LIB_FLGS) -o test
	CK_FORK=no leaks -atExit -- ./test
#	@rm test

push: style_format clean
	git pull
	git checkout develop
	git add .
	git commit -m "up"
	git push
