NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm
RMFLAGS=-rf
AR=ar
ARFLAGS=rcs
LIBFT=libft/libft.a
SRCS=ft_printf.c
OBJS=$(SRCS:.c=.o)
INCL=ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) --include $(INCL) -o $@ $<
clean:
	$(RM) $(RMFLAGS) $(OBJS) 
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: all

.PHONY: all clean fclean re
