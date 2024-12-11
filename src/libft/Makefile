NAME = libft.a

CFLAGS = -Werror -Wall -Wextra -g

CSRC = ft_atoi.c\
		ft_isascii.c\
		ft_memcpy.c\
		ft_strlcpy.c\
		ft_tolower.c\
		ft_bzero.c\
		ft_isdigit.c\
		ft_memset.c\
		ft_strlen.c\
		ft_toupper.c\
		ft_isalnum.c\
		ft_isprint.c\
		ft_strchr.c\
		ft_strncmp.c\
		ft_isalpha.c\
		ft_memchr.c\
		ft_strlcat.c\
		ft_strrchr.c\
		ft_memmove.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_strdup.c\
		ft_calloc.c\
		ft_strjoin.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c

COBJ = $(CSRC:.c=.o)

BONUS_SRC = ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

%.o:%.c
	cc $(CFLAGS) $< -c -o $@

$(NAME): $(COBJ)
	ar rcs $(NAME) $(COBJ)

bonus: $(BONUS_OBJ) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJ)

clean: 
	rm -f $(COBJ) 
	rm -f $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft.so

all: $(NAME)

re: fclean all

so: bonus
	gcc -shared -o libft.so $(NAME)

.PHONY: so re all fclean clean bonus