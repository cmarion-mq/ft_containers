NAME_FT			= 	ft_containers
NAME_STD		= 	std_containers

OBJ_PATH		=	./obj/

SRCS			=	my_main.cpp
SRCS_42			=	main.cpp

CXX	 			=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

OBJS_FT			=	$(addprefix $(OBJ_PATH),$(SRCS:.cpp=_ft.o))
OBJS_STD		=	$(addprefix $(OBJ_PATH),$(SRCS:.cpp=_std.o))
OBJS_42			=	$(addprefix $(OBJ_PATH),$(SRCS_42:.cpp=.o))

all: 				$(NAME_FT) $(NAME_STD)

$(OBJ_PATH)%_ft.o:	%.cpp
					@mkdir -p $(dir $@)
					$(CXX) $(CXXFLAGS) -D NS=ft -MMD -c $< -o $@ -I.

$(OBJ_PATH)%_std.o:	%.cpp
					@mkdir -p $(dir $@)
					$(CXX) $(CXXFLAGS) -D NS=std -MMD -c $< -o $@ -I.

$(NAME_FT): 		$(OBJS_FT)
					$(CXX) $(CXXFLAGS) $(OBJS_FT) -o $(NAME_FT)

$(NAME_STD): 		$(OBJS_STD)
					$(CXX) $(CXXFLAGS) $(OBJS_STD) -o $(NAME_STD)

clean:
					rm -rf $(OBJ_PATH)

fclean: 			clean
					rm -f $(NAME)

re: 				fclean 
					make

.PHONY: 			all clean fclean re
