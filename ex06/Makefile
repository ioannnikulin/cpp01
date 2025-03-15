CPP = c++
COMPILE_FLAGS = -Wall -Wextra -Werror --std=c++98 -g -c
LINK_FLAGS =
NAME = harlFilter

SRCS = \
	main.cpp \
	Harl.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CPP) $(LINK_FLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(COMPILE_FLAGS) $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	-valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME) 
	@echo "\n\n"
	valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME) "DEBUG"
	@echo "\n\n"
	valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME) "INFO"
	@echo "\n\n"
	valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME) "WARNING"
	@echo "\n\n"
	valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME) "ERROR"
	@echo "\n\n"
	valgrind --leak-check=full --show-leak-kinds=all -s -q ./$(NAME) "warning"

.PHONY: all clean fclean re test