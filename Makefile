#_____________COMPILATION_____________
# Compiler
CC := gcc
# Flags
CFLAGS := -Wall -Wextra -Werror -g -fsanitize=thread
PTRD := -pthread

#_____________COLORS_____________
RED = \033[0;31m
CYAN = \033[0;36m
ORANGE = \033[0;33m
GREEN = \033[0;32m
NC = \033[0m
BOLD = \033[1m

#_____________Directories_____________
INCLUDES := -I./includes
SOURCE := src
OBJDIR := obj

#_____________SOURCES_____________
# files
FILES := main.c init.c routine.c utils.c ft_atoi.c
OBJECTS := $(patsubst %.c, %.o, $(FILES))
# Source files
SRC := $(addprefix $(SOURCE)/, $(SRC))
# Object files
OBJ := $(addprefix $(OBJDIR)/, $(OBJECTS))

#_____________TARGETS_____________
NAME = philo

#_____________RULES_____________

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BOLD)$(CYAN)Compiling...$(NC)"
	$(CC) $(CFLAGS) $(PTRD) $(OBJ) -o $(NAME)
	@echo "$(BOLD)$(GREEN)Compiled!$(NC)"

$(OBJDIR)/%.o: $(SOURCE)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(BOLD)$(CYAN)Cleaning...$(NC)"
	@rm -rf $(OBJDIR)
	@echo "$(BOLD)$(GREEN)Cleaned!$(NC)"


fclean: clean
	@echo "$(BOLD)$(RED)Full Cleaning...$(NC)"
	@rm -f $(NAME)
	@echo "$(BOLD)$(GREEN)Full Cleaned!$(NC)"

re: fclean all

