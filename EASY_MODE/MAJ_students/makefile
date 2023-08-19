NAME = students
SRC = $(shell ls *.c)
CC = cc
HEADER = Students.h
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra 
all: $(NAME)
	@echo "Compiling Files .c ...."
%.o: %.c Students.h
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all