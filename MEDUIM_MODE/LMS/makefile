NAME = LMS
SRC = $(shell ls *.c)
CC = cc
HEADER = Operation.h
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra 
all: $(NAME)
	@echo "Compiling Files .c ...."
%.o: %.c Operation.h
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	@echo "Binary files .o are cleaned...."
	rm -f $(NAME)
re: fclean all