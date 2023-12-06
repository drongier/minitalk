NAME	= libftprintf.a

SRCS	= ft_printf.c \
		ft_print_hexa.c \
		ft_print_ptr.c \
		ft_print_unsi.c \
		ft_printf_utils.c \
		ft_print_num.c \

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re