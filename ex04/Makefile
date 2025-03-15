CPP = c++
COMPILE_FLAGS = -Wall -Werror -Wextra --std=c++98 -c -g
LINK_FLAGS = 
TGT_NAME = notsed
TEST_NAME = tester

TGT_SRCS = main.cpp
TGT_OBJS = $(TGT_SRCS:.cpp=.o)

TEST_SRCS = tester.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

%.o: %.cpp
	$(CPP) $(COMPILE_FLAGS) $< -o $@

$(TGT_NAME): $(TGT_OBJS)
	$(CPP) $(LINK_FLAGS) $^ -o $@

all: $(TGT_NAME)

clean:
	rm -f $(TGT_OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(TGT_NAME) $(TEST_NAME)

re: fclean all

$(TEST_NAME): $(TEST_OBJS) $(TGT_NAME)
	$(CPP) $(LINK_FLAGS) $< -o $@

test: $(TEST_NAME)
	./$(TEST_NAME)

.PHONY: all clean fclean test