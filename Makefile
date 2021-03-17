CC	=	clang

CFLAGS	=	-Wall -Wextra -fsanitize=address

NAME	=	push_swap

SRCS_D	=	./srcs/

INCS	=	./includes/push_swap.h\
		./includes/push_swap.h\
		./includes/stack.h\
		./includes/quicksort.h\
		./includes/stack_utils.h\
		./includes/first_algo.h\

COMP	=	$(SRCS_D)push_swap.c\
		$(SRCS_D)operations.c\
		$(SRCS_D)quicksort.c\
		$(SRCS_D)stack_utils.c\
		$(SRCS_D)first_algo.c\

all: $(NAME)

$(NAME): $(COMP) $(INCS)
	@echo compilating sources
	@$(CC) $(CFLAGS) -o $(NAME) $(COMP)
	@echo push_swap compilated

clean:
	@rm -rf $(SRCS_D)*.o
	@echo All objects file deleted

fclean: clean
	@rm -rf $(NAME)
	@echo push_swap deleted

re: fclean all

.PHONY: all fclean clean re 
