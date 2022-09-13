
NAME			=	tester_containers

CXX				=	c++

SRC_DIR			=	$(shell find ./ -type d)

OBJ_DIR			=	.obj

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

# library -----------------------------------------------------------

SRC			=	vector.cpp map.cpp stack.cpp main.cpp

INC			=	tester.hpp \
				iterator.hpp \
				type_traits.hpp \
				mapIterator.hpp \
				utilityMap.hpp \
				iterator_tag.hpp \
				redBlackTree.hpp \
				stack.hpp \
				map.hpp \
				compare.hpp \
				vector.hpp \
				reverseIterator.hpp \
				iterator_traits.hpp 

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

# Compilation flags -------------------------------------------------

CPPFLAGS			=	-Wall -Wextra -Werror -std=c++98
IFLAGS			=	-I includes/ -I /usr/include

# Colors ------------------------------------------------------------

_GREY	=	$'\e[30m
_RED	=	$'\e[31m
_GREEN	=	$'\e[32m
_YELLOW	=	$'\e[33m
_BLUE	=	$'\e[34m
_PURPLE	=	$'\e[35m
_CYAN	=	$'\e[36m
_WHITE	=	$'\e[37m

# main part ---------------------------------------------------------

$(OBJ_DIR)/%.o : %.cpp $(INC)
		@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
		@mkdir -p $(OBJ_DIR)
		@$(CXX) $(CPPFLAGS) $(IFLAGS) -c $< -o $@
		@echo "$(_GREEN)DONE$(_WHITE)"

all: $(NAME)

$(NAME): $(OBJ)
		@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
		$(CXX) $(CPPFLAGS) $(OBJ) $(IFLAGS) -o $(NAME)
		@echo "$(_GREEN)DONE$(_WHITE)\n-----"

clean:
		@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
		@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
		@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean: clean
		@echo "$(_WHITE)Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
		@rm -f $(NAME) $(NAME_BONUS)
		@echo "$(_GREEN)DONE$(_WHITE)\n-----"

re:		fclean all

.PHONY:		all bonus clean fclean re
