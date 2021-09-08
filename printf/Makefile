LIBFT = ../libft/libft.a

N_TEMP = temp.a

NAME = printf_lib.a

SRCS =  ft_printf.c \
		hex_length.c \
		flag_start.c \
		ft_conv.c \
		print_u.c \
		put_hex.c \
		u_length.c \
		int_handle.c\
		char_handle.c\
		handle_s.c\
		handle_percent.c\
		handle_X.c\
		x_handle.c\
		u_handle.c\
		itoa_base.c\

SURPL_O = 	ft_printf.o \
		hex_length.o \
		flag_start.o \
		ft_conv.o \
		print_u.o \
		put_hex.o \
		u_length.o\
		int_handle.o\
		char_handle.o\
		handle_s.o\
		handle_percent.o\
		handle_X.o\
		x_handle.o\
		u_handle.o\
		itoa_base.o\

OBJS = $(SURPL_O:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= printf.a

all:			$(NAME)

$(NAME):		$(OBJS) ft_printf.h Makefile
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus

