OBJ_PATH		=	./obj/
VECTOR_PATH		=	./vector/
STACK_PATH		=	./stack/
MAP_PATH		=	./map/

SRCS			=	main_42.cpp \
					vector.cpp \
					stack.cpp \
					map.cpp

CXX	 			=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address

OBJS_FT			=	$(addprefix $(OBJ_PATH),$(SRCS:.cpp=_ft.o))
OBJS_STD		=	$(addprefix $(OBJ_PATH),$(SRCS:.cpp=_std.o))

DEPS			=	$(OBJS_STD:.o=.d) $(OBJS_FT:.o=.d)

all: 				$(OBJS_FT) $(OBJS_STD)

$(OBJ_PATH)%_ft.o:	%.cpp
					@mkdir -p $(dir $@)
					$(CXX) $(CXXFLAGS) -D NS=ft -MMD -c $< -o $@ -I.

$(OBJ_PATH)%_std.o:	%.cpp
					@mkdir -p $(dir $@)
					$(CXX) $(CXXFLAGS) -D NS=std -MMD -c $< -o $@ -I.		

vector:				all
					@mkdir -p $(VECTOR_PATH) 
					$(CXX) $(CXXFLAGS) $(OBJ_PATH)vector_ft.o -o $(VECTOR_PATH)ft_vector
					$(CXX) $(CXXFLAGS) $(OBJ_PATH)vector_std.o -o $(VECTOR_PATH)std_vector
					time $(VECTOR_PATH)ft_vector > $(VECTOR_PATH)ft.out
					time $(VECTOR_PATH)std_vector > $(VECTOR_PATH)std.out
					diff $(VECTOR_PATH)ft.out $(VECTOR_PATH)std.out

stack:				all
					@mkdir -p $(STACK_PATH) 
					$(CXX) $(CXXFLAGS) $(OBJ_PATH)stack_ft.o -o $(STACK_PATH)ft_stack
					$(CXX) $(CXXFLAGS) $(OBJ_PATH)stack_std.o -o $(STACK_PATH)std_stack
					time $(STACK_PATH)ft_stack > $(STACK_PATH)ft.out
					time $(STACK_PATH)std_stack > $(STACK_PATH)std.out
					diff $(STACK_PATH)ft.out $(STACK_PATH)std.out				

map:				all
					@mkdir -p $(MAP_PATH) 
					$(CXX) $(CXXFLAGS) $(OBJ_PATH)map_ft.o -o $(MAP_PATH)ft_map
					$(CXX) $(CXXFLAGS) $(OBJ_PATH)map_std.o -o $(MAP_PATH)std_map
#					time $(MAP_PATH)ft_map > $(MAP_PATH)ft.out
#					time $(MAP_PATH)std_map > $(MAP_PATH)std.out
#					diff $(MAP_PATH)ft.out $(MAP_PATH)std.out

clean:
					rm -rf $(OBJ_PATH)

fclean: 			clean
					rm -rf $(VECTOR_PATH)
					rm -rf $(STACK_PATH)
					rm -rf $(MAP_PATH)

re: 				fclean 
					make

.PHONY: 			all clean fclean re

-include $(DEPS)
