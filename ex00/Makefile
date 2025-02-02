COMPILER = c++
NAME_TARGET = zombies
NAME_TEST = tester
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c -std=c++98
LINK_FLAGS = 
PREFIX = 

SRC_NAMES = \
	Zombie.cpp \
	newZombie.cpp \
	randomChump.cpp

ENDPOINT_NAMES = main.cpp

TEST_NAMES = tester.cpp

SRC_OBJS = $(SRC_NAMES:.cpp=.o)

ENDPOINT_OBJS = $(ENDPOINT_NAMES:.cpp=.o)

TEST_OBJS = $(TEST_NAMES:.cpp=.o)

all: $(NAME_TARGET)

$(NAME_TARGET): $(SRC_OBJS) $(ENDPOINT_OBJS)
	$(PREFIX)$(COMPILER) $(SRC_OBJS) $(ENDPOINT_OBJS) -o $(NAME_TARGET) $(LINK_FLAGS)

$(NAME_TEST): $(SRC_OBJS) $(TEST_OBJS)
	$(PREFIX)$(COMPILER) $(SRC_OBJS) $(TEST_OBJS) -o $(NAME_TEST) $(LINK_FLAGS)

%.o: %.cpp
	$(PREFIX)$(COMPILER) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(PREPROC_DEFINES)

clean:
	$(PREFIX)rm -f $(SRC_OBJS) $(TEST_OBJS) $(ENDPOINT_OBJS)

fclean: clean
	$(PREFIX)rm -f $(NAME_TARGET) $(NAME_TEST)

test: $(NAME_TEST)
	$(PREFIX)rm -f out.txt err.txt
	$(PREFIX)valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME_TEST)
	$(PREFIX)rm -f out.txt err.txt

re: fclean all

retest: fclean test

PHONY: all pre clean fclean re test retest