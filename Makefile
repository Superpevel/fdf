SRCS=		main.c read_file.c GNL_get_next_line/get_next_line.c GNL_get_next_line/get_next_line_utils.c minilibx_macos/libmlx.a libft/libft.a draw.c  printf/printf.a

CC=		gcc 

NAME=		fdf

CFLAGS +=	
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -g -framework OpenGL -framework AppKit 

clean:
	rm -rvf $(OBJS)

fclean:		clean
	rm -rvf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re