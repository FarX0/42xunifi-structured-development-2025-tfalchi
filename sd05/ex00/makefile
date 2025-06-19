NAME = ex00

SRC = ex00.c

INCLUDES = ./includes

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libftprintf.a

#FLAGS		= -Wall -Werror -Wextra -I includes -pthread -fsanitize=thread -g
CFLAGS		=  -Wall -Wextra -Werror -I includes -lreadline -g

# -s : for valgrind
all:$(NAME)

$(NAME): $(SRC)
	@make all -C $(LIBFT_DIR)
	@cc $(SRC) $(CFLAGS) $(LIBFT) -I $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)[EX00]:\t PROJECT COMPILED$(RESET)"


clean:
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)[EX00]:\t CLEAN$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f *.a
	@rm -f *.gch
	@rm -f $(NAME)
	@echo "$(RED)[EX00]:\t FCLEAN$(RESET)"

re: fclean all

VALGRIND=@valgrind --suppressions=supp.supp --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

val: all
	clear
	$(VALGRIND) ./$(NAME)

t: all
	 ./$(NAME)

.PHONY: all clean fclean re