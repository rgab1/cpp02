NAME = executable
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CPPFLAGS = -MMD -MP
INCLUDE = -I .

SRC_ROOT = main Fixed 

SRC = $(addsuffix .cpp, $(SRC_ROOT))

OBJ = $(SRC:.cpp=.o)

DEPENDENCIES = $(OBJ:.o=.d)

all : $(NAME)

-include $(DEPENDENCIES)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -f $(DEPENDENCIES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re clean fclean
