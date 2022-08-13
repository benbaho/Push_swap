name = push_swap 
src = $(shell find . -name "*.c")
obj = $(src:.c=.o)
flags = -Wall -Wextra -Werror 
PRINTF	= printf/libftprintf.a
LIBFT	= libft/libft.a
CC	= gcc -g

#	Scripti çalıştırmak için; TSM:üretilecek sayı miktarı
#	TMS=100; ARG=$(ruby rnd.rb $TMS); ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l

all : $(name) 

$(name): $(obj) $(PRINTF) $(LIBFT)
		$(CC) $(flags) $(obj) -o $(name) ./printf/libftprintf.a ./libft/libft.a

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
