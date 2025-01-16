NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Libft source files
LIBFT_SRC = ft_atoi.c \
            ft_bzero.c \
            ft_calloc.c \
            ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_itoa.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_memset.c \
            ft_putchar_fd.c \
            ft_putendl_fd.c \
            ft_putnbr_fd.c \
            ft_putstr_fd.c \
            ft_substr.c \
            ft_split.c \
            ft_strchr.c \
            ft_striteri.c \
            ft_strjoin.c \
            ft_strdup.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strmapi.c \
            ft_strncmp.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_strtrim.c \
            ft_tolower.c \
            ft_toupper.c

# ft_printf source files
PRINTF_SRC = ft_printf/ft_printf.c \
             ft_printf/ft_printf_utils.c

# Combine all source files
SRC = $(LIBFT_SRC) $(PRINTF_SRC)

# Object files directory
OBJ_DIR = obj

# Create object file paths
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Header file
HEADER = libft.h

# Default rule
all: $(NAME)

# Create the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo -e "\033[32m\"$(NAME)\": successfully created!\033[0m"
	@echo ""

# Rule to compile source files into object files in the obj directory
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@) # Ensure subdirectories exist
	$(CC) $(CFLAGS) -I. -c $< -o $@

# Phony targets
.PHONY: all clean fclean re

# Clean object files and directory
clean:
	rm -rf $(OBJ_DIR)
	@echo -e "\033[32m\"$(NAME)\": temporary files successfully removed!\033[0m"
	@echo ""

# Clean all generated files (including the library)
fclean: clean
	rm -f $(NAME)
	@echo -e "\033[32m\"$(NAME)\": executable successfully removed!\033[0m"
	@echo ""

# Rebuild the project
re: fclean all
