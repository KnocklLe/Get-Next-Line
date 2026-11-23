
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
NAME = ex

GREEN    = \033[0;32m
RED      = \033[0;31m
YELLOW   = \033[0;33m
BLUE     = \033[0;34m
RESET    = \033[0m

all: $(OBJECTS)

%.o: %.c
	@printf "$(YELLOW)Compilation de $<...$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJECTS) main.c
	@printf "$(BLUE)====== TEST GET_NEXT_LINE ======$(RESET)\n"
	@$(CC) $(CFLAGS) main.c $(OBJECTS) -o $(NAME)
	@printf "$(GREEN)Exécution du programme...$(RESET)\n"
	@./$(NAME)

clean:
	@printf "$(YELLOW)Suppression des fichiers objets...$(RESET)\n"
	@rm -f $(OBJECTS)

fclean: clean
	@printf "$(RED)Suppression du programme...$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re main
