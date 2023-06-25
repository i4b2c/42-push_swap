NAME = push_swap
SRC =	src/erro.c \
		src/extra_func.c \
		src/extra.c \
		src/geral_extra.c \
		src/geral.c \
		src/get_extra.c \
		src/get.c \
		src/iniciar.c \
		src/media.c \
		src/no_print.c \
		src/option.c \
		src/organizar_3.c \
		src/organizar_5.c \
		src/principais_a.c \
		src/principais_b.c \
		src/push_swap.c \
		src/replica.c \
		src/stack_b.c \
		src/stack_big.c \
		src/stack_big2.c \
		src/stack_small.c \
		src/verificar_geral.c \
		src/verificar.c

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
EXTRA = push_swap a.out
LIBFT = libft/libft.a
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
		@$(RM) $(OBJ)
		@$(RM)

fclean: clean
		@$(RM) $(NAME)
		@make fclean -C libft/
extra: fclean
	@$(RM) $(EXTRA)

re: extra all

git:
	git add *
	git commit -m .
	git push
