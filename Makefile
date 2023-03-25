NAME = libft.a
SRC = libft/src/ft_isalpha.c \
      libft/src/ft_isdigit.c \
      libft/src/ft_isalnum.c \
      libft/src/ft_isascii.c \
      libft/src/ft_isprint.c\
      libft/src/ft_strlen.c \
      libft/src/ft_memset.c \
      libft/src/ft_bzero.c \
      libft/src/ft_memcpy.c \
      libft/src/ft_memmove.c \
      libft/src/ft_strlcpy.c\
      libft/src/ft_strlcat.c \
      libft/src/ft_toupper.c \
      libft/src/ft_tolower.c \
      libft/src/ft_strchr.c \
      libft/src/ft_strrchr.c \
      libft/src/ft_strncmp.c\
      libft/src/ft_memchr.c \
      libft/src/ft_memcmp.c \
      libft/src/ft_strnstr.c \
      libft/src/ft_atoi.c \
      libft/src/ft_calloc.c \
      libft/src/ft_strdup.c\
      libft/src/ft_substr.c \
      libft/src/ft_strjoin.c \
      libft/src/ft_strtrim.c \
      libft/src/ft_split.c \
      libft/src/ft_itoa.c \
      libft/src/ft_strmapi.c\
      libft/src/ft_striteri.c \
      libft/src/ft_putchar_fd.c \
      libft/src/ft_putstr_fd.c \
      libft/src/ft_putendl_fd.c \
      libft/src/ft_putnbr_fd.c\
      libft/src/ft_lstnew.c \
      libft/src/ft_lstadd_front.c \
      libft/src/ft_lstsize.c \
      libft/src/ft_lstlast.c \
      libft/src/ft_lstadd_back.c\
      libft/src/ft_lstdelone.c \
      libft/src/ft_lstclear.c \
      libft/src/ft_lstiter.c \
      libft/src/ft_lstmap.c \
      libft/src/ft_printf_utils1.c \
      libft/src/ft_printf_utils2.c \
      libft/src/len.c \
      libft/src/ft_printf.c \
      libft/src/get_next_line.c \
      libft/src/get_next_line_utils.c \
      teste.c \
      outro_teste.c

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
EXTRA = a.out libft/src/a.out push_swap
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)
		@$(CC) $(CFLAGS) push_swap.c libft.a $(LIBSRC) $(LIBFLAG) -o push_swap

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)
extra: fclean
	@$(RM) $(EXTRA)
re: extra all

ez:
		@$(CC) $(CFLAGS) push_swap.c libft.a $(LIBSRC) $(LIBFLAG) -o push_swap
git:
	git add *
	git commit -m .
	git push
ezz:
	@$(CC) outro_teste.c push_swap.c libft.a -o push_swap
teste:
	./push_swap -707 -256 -404  384 -519 -909 -511  80 -490 -962 -507 -367 -308 -375  257 -740 -687  180 -485 -821 -154  964  536 -272  656  700  134   52 -556  247  -47  589 -370   40 -569  466  -46  326  217  5 -358 -202  706  144  848  -22  266   16 -993 -213  279 -424 -210  -44 -366  873  542 -408 -719 -591 459 -131 -473 369 357 22 -990 -65 -489 989 290 -515 184 -457 -133 -402 563 170 -710 -597 56 -158 631 787 -658 335 528 172 -60 -682 826 -734 -532 -38 -602 -463 218 614 -505 -130

