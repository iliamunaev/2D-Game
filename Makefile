# --------------------------- Executable and Library ------------------------- #
NAME    := so_long

CC      := cc
CFLAGS  := -Wextra -Wall -Werror

LIBMLX  := ./libs/MLX42
LIBFT   := ./libs/libft

HEADERS := -Iinclude -Ilibs/MLX42/include -I../include

# lglfw: OpenGL graphics library
# ldl: Dynamic linking library for runtime symbol resolution
LIBS    := libs/MLX42/build/libmlx42.a libs/libft/libft.a -ldl -lglfw

SRCS    := $(shell find ./src -name "*.c")
OBJ_DIR := obj
OBJS    := $(SRCS:./src/%.c=$(OBJ_DIR)/%.o)

# ------------------------------ Colors -------------------------------------- #
RESET   := \033[0m
GREEN   := \033[32m
BLUE    := \033[34m
RED     := \033[31m

# ------------------------------- Targets ------------------------------------ #
all: libmlx libft $(NAME)
	@echo "$(GREEN)Program $(NAME) compiled successfully!$(RESET)"

# Download and build MLX42
libmlx:
	@echo "$(BLUE)[LIBMLX] Checking for MLX42 library...$(RESET)"
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "$(RED)MLX42 not found! Downloading...$(RESET)"; \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi
	@echo "$(BLUE)[LIBMLX] Building MLX42 library...$(RESET)"
	cmake $(LIBMLX) -B $(LIBMLX)/build
	make -C $(LIBMLX)/build -j4

# Download and build Libft
libft:
	@echo "$(BLUE)[LIBFT] Checking for Libft library...$(RESET)"
	@if [ ! -d "$(LIBFT)" ]; then \
		echo "$(RED)Libft not found! Cloning...$(RESET)"; \
		git clone https://github.com/iliamunaev/libft-C-library $(LIBFT); \
	fi
	@echo "$(BLUE)[LIBFT] Building Libft library...$(RESET)"
	make -C $(LIBFT)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking executable: $(NAME)$(RESET)"
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

# Rule to compile .c files into .o and store them in obj/
$(OBJ_DIR)/%.o: ./src/%.c | $(OBJ_DIR)
	@echo "$(BLUE)Compiling: $(notdir $<)...$(RESET)"
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(GREEN)Removing object files...$(RESET)"
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean
	@echo "$(BLUE)Cleaned object files and directories.$(RESET)"

fclean: clean
	@echo "$(GREEN)Removing executable: $(NAME)...$(RESET)"
	rm -rf $(NAME)
	@make -C $(LIBFT) fclean
	@echo "$(GREEN)'$(NAME)' executable successfully removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re libmlx libft
