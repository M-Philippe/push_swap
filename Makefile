CFLAGS	= -Wall -Wextra

NAME	=	push_swap

SRCS_D	=	./srcs/

COMP	=	$(SRCS_D)push_swap.c\
		$(SRCS_D)operations.c\

OBJ	=	$(COMP:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(SRCS_D)
	clang $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
