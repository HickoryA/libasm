CC = gcc -Wall -Werror -Wextra
NASM = nasm -f elf64
AR = ar -rc
RM = rm -rf

NAME = libasm.a

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJ = $(SRC:.s=.o)

%.o: %.s
	 $(NASM) $<

all: $(NAME)

$(NAME): $(OBJ)
	 $(AR) $(NAME) $(OBJ)

test:
	 $(CC) main.c libasm.a -o test.out

clean:
	 $(RM) $(OBJ)

fclean: clean
	 $(RM) $(NAME) $(TEST_NAME)
	 $(RM) *.out

re: fclean $(NAME)

.PHONY: clean fclean re