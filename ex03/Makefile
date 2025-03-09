CPP = c++
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c
LINK_FLAGS = 

NAME = violence

SRCS = \
	Weapon.cpp\
	HumanA.cpp \
	HumanB.cpp \
	main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(LINK_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(COMPILE_FLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME)

.PHONY: all clean fclean re test