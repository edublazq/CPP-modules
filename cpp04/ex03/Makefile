NAME = interfaces

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g3

SRC = src/AMateria.cpp src/Character.cpp src/Cure.cpp src/Ice.cpp src/main.cpp src/MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re