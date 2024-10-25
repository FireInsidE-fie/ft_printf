NAME=		libftprintf.a
CC=			cc
CFLAGS=		-Wall -Wextra -Werror
RM=			rm
RMFLAGS=	-f
AR=			ar
ARFLAGS=	r
LIBFT=		libft/libft.a
SRCS=		ft_printf.c \
			ft_printf_d.c \
			ft_printf_s.c
OBJS=		$(SRCS:.c=.o)
INCL=		ft_printf.h

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(LIBFT) $(OBJS)
	cp $(LIBFT) ./$(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -include $(INCL) -c $< -o $@ 
clean:
	$(RM) $(RMFLAGS) $(OBJS) 
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all

$(LIBFT):
	cd ./libft && make
debug: $(LIBFT) $(SRCS) main.c
	$(CC) $(CFLAGS) -g $(SRCS) main.c -include $(INCL) -Llibft/ -lft -o $@
.PHONY: all clean fclean re
