# --------------------------- Executable and Library ------------------------- #
NAME    = so_long
LIBFT   = $(LIBDIR)/libft.a

# ----------------------------- Compiler Settings ---------------------------- #
CC      = cc
CFLAGS  = -lm -Wall -Wextra -Werror

# --------------------------------- Folders ---------------------------------- #
SRCDIR  = src
OBJDIR  = obj
LIBDIR  = libft
INCDIR  = include

# ------------------------------ Source Files -------------------------------- #
SRCS = \
	$(SRCDIR)/main.c

OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

# ------------------------------- Main Targets ------------------------------- #
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBDIR) -lft
	@echo -e "\033[32m\"$(NAME)\": successfully created!\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

# ------------------------------ Object Files -------------------------------- #
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) -c $< -o $@

# ------------------------------- Clean Targets ------------------------------ #
clean:
	rm -rf $(OBJDIR)
	@$(MAKE) clean -C $(LIBDIR)
	@echo -e "\033[32m\"$(NAME)\": temporary files successfully removed!\033[0m"
	@echo ""


fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBDIR)
	@echo -e "\033[32m\"$(NAME)\": executable successfully removed!\033[0m"
	@echo ""



re: fclean all

# ---------------------------- Phony Declarations ---------------------------- #
.PHONY: all clean fclean re
