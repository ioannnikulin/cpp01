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

.PHONY: all clean fclean re