NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm
RMFLAGS=-rf
AR=ar
ARFLAGS=rcs
SRCS=ft_printf.c
OBJS=$(SRCS:.c=.o)
INCL=ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) --include $(INCL) -o $@ $<
clean:
	$(RM) $(RMFLAGS) %.o
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: all

.PHONY: all clean fclean re
