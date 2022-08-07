<<<<<<< HEAD
name = push_swap 
src = $(shell find . -name "*.c")
obj = $(src:.c=.o)
flags = -Wall -Wextra -Werror 
PRINTF	= printf/libftprintf.a
LIBFT	= libft/libft.a

all : $(name) 

$(name): $(obj) $(PRINTF) $(LIBFT)
		gcc $(flags) $(obj) -o $(name) ./printf/libftprintf.a ./libft/libft.a

$(PRINTF): 
	make -C printf

$(LIBFT):
	make -C libft

		
re: fclean all

clean:
	rm -rf $(obj)
fclean: clean
	rm -rf $(name)
	@make fclean -C printf
	@make fclean -C libft 
norm: 
	norminette *.c
	norminette *.h
.PHONY: clean norm fclean all re
=======
name = push_swap 
src = $(shell find . -name "*.c")
obj = $(src:.c=.o)
flags = -Wall -Wextra -Werror 
PRINTF	= printf/libftprintf.a
LIBFT	= libft/libft.a

all : $(name) 

$(name): $(obj) $(PRINTF) $(LIBFT)
		gcc $(flags) $(obj) -o $(name) ./printf/libftprintf.a ./libft/libft.a

$(PRINTF): 
	make -C printf

$(LIBFT):
	make -C libft

		
re: fclean all

clean:
	rm -rf $(obj)
fclean: clean
	rm -rf $(name)
	@make fclean -C printf
	@make fclean -C libft 
norm: 
	norminette *.c
	norminette *.h
.PHONY: clean norm fclean all re
>>>>>>> 33c4f9fee81162d96c054773bc686e7a0606196d
