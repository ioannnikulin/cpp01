COMPILER = c++
NAME_TARGET = brain
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c -std=c++98
LINK_FLAGS = 
PREFIX = 

ENDPOINT_NAMES = main.cpp

ENDPOINT_OBJS = $(ENDPOINT_NAMES:.cpp=.o)

all: $(NAME_TARGET)

$(NAME_TARGET): $(ENDPOINT_OBJS)
	$(PREFIX)$(COMPILER) $(SRC_OBJS) $(ENDPOINT_OBJS) -o $(NAME_TARGET) $(LINK_FLAGS)

%.o: %.cpp
	$(PREFIX)$(COMPILER) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(PREPROC_DEFINES)

clean:
	$(PREFIX)rm -f $(ENDPOINT_OBJS)

fclean: clean
	$(PREFIX)rm -f $(NAME_TARGET)

test: $(NAME_TARGET)
	$(PREFIX)valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME_TARGET)

re: fclean all

retest: fclean test

PHONY: all pre clean fclean re test retest