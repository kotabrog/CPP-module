SRCS	=	main.cpp\
			AMateria.cpp\
			Character.cpp\
			Ice.cpp\
			Cure.cpp\
			MateriaSource.cpp

OBJS	= $(SRCS:.cpp=.o)
NAME	= ex03
CXX		= clang++
CXXFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

debug	:
		$(CXX) $(CXXFLAGS) -fsanitize=address -std=c++98 -Wshadow $(SRCS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re
