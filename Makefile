NAME  = so_long

CC    = gcc

FLAGS = -Wall -Wextra -Werror

PRINTF = ./ft_printf/libftprintf.a

SRCS  =      check.c \
				check_collectibles.c \
				check_creat.c \
				check_objects.c \
				check_rectangle.c \
				ft_printf/ft_control.c \
				ft_printf/ft_printf.c \
				ft_printf/ft_putchar.c \
				ft_printf/ft_puthex.c \
				ft_printf/ft_putnbr.c \
				ft_printf/ft_putpointer.c \
				ft_printf/ft_putstr.c \
				ft_printf/ft_putuns.c \
				ft_printf/ft_putuphex.c \
				ft_printf/ft_specifier.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				mlx.c \
				so_long.c \
				utils.c \
				utils2.c \
				utils3.c
                          
OBJS  = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C ./ft_printf
		make -C ./mlx
		$(CC) $(FLAGS) $(OBJS) $(PRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		make clean -C ./ft_printf
		make clean -C ./mlx
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME) $(PRINTF)

re:	fclean all

.PHONY: all clean fclean re