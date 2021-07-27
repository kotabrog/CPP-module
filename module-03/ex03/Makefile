SRCS	=	main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp\
			FragTrap.cpp\
			DiamondTrap.cpp

OBJS	= $(SRCS:.cpp=.o)
NAME	= ex03
CXX		= clang++
CXXFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

debug	:	$(OBJS)
		$(CXX) $(CFLAGS) -fsanitize=address -std=c++98 $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re
