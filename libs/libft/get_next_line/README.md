# Get Next Line

This project implements a function, `get_next_line`, that reads a single line from a file descriptor each time it is called, making it easy to handle line-by-line reading.

## Features

- Reads from any file descriptor (e.g., files, standard input).
- Efficiently manages leftover data between calls.
- Utilizes a static buffer for minimal memory allocation and optimized performance.

## Tests

### Test with default buffer size

The default BUFFER_SIZE=42 and compiled with:
```
cc -Wall -Werror -Wextra ../get_next_line.c ../get_next_line_utils.c main.c -o main_test
```
### Test with different buffer sizes
The tests cover:

BUFFER_SIZE=1

BUFFER_SIZE=0

BUFFER_SIZE=2048

BUFFER_SIZE=7

```
cd tests/
bash compile_tests.sh
```
Run
```
./main_test_default_buffer_42
./main_test_buffer_1
./main_test_buffer_0
./main_test_buffer_2048
./main_test_buffer_7
```
### Assign your buffer size
Adjust -D BUFFER_SIZE=**n** where '**n**' is the your buffer size'

```
cc -Wall -Werror -Wextra -D BUFFER_SIZE=n ../get_next_line.c ../get_next_line_utils.c main.c -o main_test_my_buffer_size
```
## Test memory leaks
Replace 'your_program' with the name of your program.
```
valgrind --leak-check=yes ./your_program
```

