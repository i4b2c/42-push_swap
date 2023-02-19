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
      libft/src/get_next_line_utils.c

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
