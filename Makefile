NAME		= 		ft_containers

OBJ_PATH	=		./obj/

SRCS		=		main.cpp

CXX	 		=		c++
CXXFLAGS	=		-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

OBJS		=		$(addprefix $(OBJ_PATH),$(SRCS:.cpp=.o))

all: 				$(NAME)

$(OBJ_PATH)%.o:		%.cpp
					@mkdir -p $(dir $@)
					$(CXX) $(CXXFLAGS) -c $< -o $@ -I.

$(NAME): 			$(OBJS)
					$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
					rm -rf $(OBJ_PATH)

fclean: 			clean
					rm -f $(NAME)

re: 				fclean 
					make

.PHONY: 			all clean fclean re
