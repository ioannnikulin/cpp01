COMPILER = c++
NAME_TARGET = zombies
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c -std=c++98
LINK_FLAGS = 
PREFIX = 

SRC_NAMES = \
	Zombie.cpp \
	zombieHorde.cpp

ENDPOINT_NAMES = main.cpp

SRC_OBJS = $(SRC_NAMES:.cpp=.o)

ENDPOINT_OBJS = $(ENDPOINT_NAMES:.cpp=.o)

all: $(NAME_TARGET)

$(NAME_TARGET): $(SRC_OBJS) $(ENDPOINT_OBJS)
	$(PREFIX)$(COMPILER) $(SRC_OBJS) $(ENDPOINT_OBJS) -o $(NAME_TARGET) $(LINK_FLAGS)

%.o: %.cpp
	$(PREFIX)$(COMPILER) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(PREPROC_DEFINES)

clean:
	$(PREFIX)rm -f $(SRC_OBJS) $(ENDPOINT_OBJS)

fclean: clean
	$(PREFIX)rm -f $(NAME_TARGET)

test: $(NAME_TARGET)
	$(PREFIX)valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME_TARGET)

re: fclean all

retest: fclean test

PHONY: all pre clean fclean re test retest