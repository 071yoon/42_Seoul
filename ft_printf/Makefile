NAME 		=	libftprintf.a
FLAGS 		=	-Wall -Wextra -Werror
SRC 		=	ft_printf.c \
				char_format.c \
				hex_format.c \
				int_format.c \
				ptr_format.c \

OBJ			=	$(SRC:.c=.o)
INC_LINK	=	-I./includes
LIBFT		=	-L./Libft -lft


FILES		=	ft_strlen \
				ft_strlcpy \

all : $(NAME)

$(NAME) : $(OBJ) libft
	cp Libft/libft.a ./$(NAME)
	ar rsc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) $(INC_LINK) -c $< -o $(<:.c=.o)

# libft compile
libft :
	@$(MAKE) -C ./Libft all

clean :
	@$(MAKE) -C ./Libft clean
	@rm -rf $(OBJ)
fclean : clean
	@$(MAKE) -C ./Libft fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re libft