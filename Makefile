NAME		=	libftprintf.a
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a
OBJ			=	ft_intlen.o ft_print_char.o ft_print_hexa.o ft_print_int.o ft_print_percent.o ft_print_pointer.o ft_print_string.o ft_print_unsigned.o ft_printf.o
HEADERS	=	ft_printf.h libft/libft.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_PATH) all

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean $(NAME)
