SRCS	=	main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp\
			FragTrap.cpp

OBJS	= $(SRCS:.cpp=.o)
NAME	= ex02
CXX		= clang++
CXXFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

sani	:	$(OBJS)
		$(CXX) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re
