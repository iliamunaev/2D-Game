# --------------------------- Executable and Library ------------------------- #
NAME    := so_long

CC      := cc
CFLAGS  := -Wextra -Wall -Werror
LIBMLX  := ./libs/MLX42
LIBFT   := ./libs/libft

HEADERS := -Iinclude -Ilibs/MLX42/include -I../include
LIBS    := libs/MLX42/build/libmlx42.a libs/libft/libft.a -ldl -lglfw

SRCS    := $(shell find ./src -name "*.c")
OBJS    := $(SRCS:.c=.o)

# ------------------------------ Colors -------------------------------------- #
RESET   := \033[0m
GREEN   := \033[32m
BLUE    := \033[34m
RED     := \033[31m

# ------------------------------- Targets ------------------------------------ #
all: libmlx libft $(NAME)
	@echo "$(GREEN)Program $(NAME) compiled successfully!$(RESET)"

libmlx:
	@echo "$(BLUE)[LIBMLX] Building MLX42 library...$(RESET)"
	cmake $(LIBMLX) -B $(LIBMLX)/build
	make -C $(LIBMLX)/build -j4

libft:
	@echo "$(BLUE)Building Libft library...$(RESET)"
	make -C $(LIBFT)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking executable: $(NAME)$(RESET)"
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	@echo "$(BLUE)Compiling: $(notdir $<)...$(RESET)"
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@echo "$(GREEN) Removing object files...$(RESET)"
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean
	@echo "$(BLUE)Cleaned object files and directories.$(RESET)"

fclean: clean
	@echo "$(GREEN) '$(NAME)': Removing executable: $(NAME)...$(RESET)"
	rm -rf $(NAME)
	@make -C $(LIBFT) fclean
	@echo "$(GREEN)'$(NAME)': executable successfully removed! $(RESET)"

re: fclean all

.PHONY: all clean fclean re libmlx libft
