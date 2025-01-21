# Libft-C Library

The **Libft-C** library is a custom implementation of essential C library functions, developed as part of the Hive Helsinki (School 42) curriculum. This library provides functions for memory manipulation, string handling, character classification, and data conversion, among others.

## Function Categories

### Memory Manipulation Functions

- **ft_bzero**: Sets all bytes in a memory block to zero.
- **ft_calloc**: Allocates and zeroes a memory block.
- **ft_memchr**: Locates a byte in a memory block.
- **ft_memcmp**: Compares two memory blocks.
- **ft_memcpy**: Copies bytes between non-overlapping memory blocks.
- **ft_memmove**: Safely copies bytes between potentially overlapping memory blocks.
- **ft_memset**: Sets a memory block to a specific byte value.

### String Manipulation Functions

- **ft_strlen**: Calculates the length of a string.
- **ft_strdup**: Duplicates a string.
- **ft_strcpy** / **ft_strncpy**: Copies a string.
- **ft_strcat** / **ft_strlcat**: Concatenates strings with length limits.
- **ft_strjoin**: Joins two strings into a new one.
- **ft_strtrim**: Trims characters from the start and end of a string.
- **ft_split**: Splits a string by a specified delimiter.
- **ft_substr**: Extracts a substring from a string.

### Character Classification and Conversion Functions

- **ft_isalpha**: Checks if a character is alphabetic.
- **ft_isdigit**: Checks if a character is a digit.
- **ft_isalnum**: Checks if a character is alphanumeric.
- **ft_isascii**: Checks if a character is an ASCII character.
- **ft_isprint**: Checks if a character is printable.
- **ft_tolower**: Converts a character to lowercase.
- **ft_toupper**: Converts a character to uppercase.

### String to Integer Conversion

- **ft_atoi**: Converts a string to an integer.

### File Descriptor Functions

- **ft_putchar_fd**: Writes a character to a file descriptor.
- **ft_putstr_fd**: Writes a string to a file descriptor.
- **ft_putendl_fd**: Writes a string followed by a newline to a file descriptor.
- **ft_putnbr_fd**: Writes an integer to a file descriptor.

### Advanced String Operations

- **ft_strchr** / **ft_strrchr**: Finds a character in a string.
- **ft_strncmp**: Compares strings up to a specified length.
- **ft_striteri**: Applies a function to each character in a string.
