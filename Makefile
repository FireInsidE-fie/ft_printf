NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm
RMFLAGS=-rf
AR=ar
ARFLAGS=rcs
LIBFT=libft/libft.a
SRCS=ft_printf.c \
	 ft_printf_d.c \
	 ft_printf_u.c
OBJS=$(SRCS:.c=.o)
INCL=ft_printf.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(AR) $(ARFLAGS) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -include $(INCL) -c $< -o $@ 
clean:
	$(RM) $(RMFLAGS) $(OBJS) 
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all

$(LIBFT):
	cd ./libft && make
debug: $(OBJS)
	$(CC) $(CFLAGS) --include $(INCL) -o $@ $<
.PHONY: all clean fclean re
