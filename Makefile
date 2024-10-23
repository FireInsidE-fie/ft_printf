NAME=		libftprintf.a
CC=			cc
CFLAGS=		-Wall -Wextra -Werror
RM=			rm
RMFLAGS=	-f
AR=			ar
ARFLAGS=	rcs
LIBFT=		libft/libft.a
SRCS=		ft_printf.c \
			ft_printf_d.c \
			ft_printf_u.c
OBJS=		$(SRCS:.c=.o)
INCL=		ft_printf.h

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -include $(INCL) -c $< -o $@ 
clean:
	$(RM) $(RMFLAGS) $(OBJS) 
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all

$(LIBFT):
	cd ./libft && make
debug: $(SRCS) main.c
	$(CC) $(CFLAGS) $(LIBFT) $(SRCS) main.c -include $(INCL) -o $@
.PHONY: all clean fclean re
