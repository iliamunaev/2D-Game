# --------------------------- Executable and Library ------------------------- #
NAME    := so_long

CC      := cc
CFLAGS  := -Wextra -Wall -Werror
LIBMLX  := ./libs/MLX42

HEADERS := -Iinclude -Ilibs/MLX42/include
LIBS    := libs/MLX42/build/libmlx42.a -ldl -lglfw

SRCS    := $(shell find ./src -name "*.c")
OBJS    := $(SRCS:.c=.o)

# ------------------------------ Colors -------------------------------------- #
RESET   := \033[0m
GREEN   := \033[32m
BLUE    := \033[34m

# ------------------------------- Targets ------------------------------------ #
all: libmlx $(NAME)
	@echo "$(GREEN)[SUCCESS] Program $(NAME) compiled successfully!$(RESET)"

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build
	make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build
	@echo "$(BLUE)Cleaned object files and MLX42 build directory.$(RESET)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(BLUE)Cleaned executable $(NAME).$(RESET)"

re: fclean all

.PHONY: all clean fclean re libmlx
