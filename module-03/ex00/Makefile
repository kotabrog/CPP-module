SRCS	=	main.cpp\
			ClapTrap.cpp

OBJS	= $(SRCS:.cpp=.o)
NAME	= ex00
CXX		= clang++
CXXFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

sani	:	$(OBJS)
		$(CXX) $(CXXFLAGS) -fsanitize=address $(OBJS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re
