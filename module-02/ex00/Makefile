SRCS	=	main.cpp\
			Fixed.cpp

OBJS	= $(SRCS:.cpp=.o)
NAME	= ex00
CC		= clang++
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

.cpp.o	:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

sani	:	$(OBJS)
		$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re
