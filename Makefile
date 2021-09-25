SRCS=		main.c read_file.c draw.c gnl/get_next_line.c gnl/get_next_line_utils.c

LIBS = minilibx_macos/libmlx.a printf/printf.a libft/libft.a
CC=		gcc

NAME=		fdf

CFLAGS +=
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.

OBJS=		$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./minilibx_macos
	$(MAKE) -C ./libft
	$(MAKE) -C ./printf
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS) -g -framework OpenGL -framework AppKit

clean:
	cd printf && $(MAKE) clean
	cd minilibx_macos && $(MAKE) clean
	cd libft && $(MAKE) clean
	rm -rvf $(OBJS)

fclean:		clean
	cd printf && $(MAKE) fclean
	cd libft && $(MAKE) fclean
	rm -rvf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re