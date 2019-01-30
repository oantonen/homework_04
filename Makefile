NAME = string

OBJ = string.o main.o 

SRC = main.cpp string.cpp

CFLAGS = -Wall -Werror -Wextra

CXX = g++ -std=c++11

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBNAME)

$(OBJ): $(SRC) string.h
	$(CXX) -c $(SRC)

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME) my_func.a
	@echo "All clear"

re: fclean all