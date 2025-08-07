# get_next_line

A 42 School project that implements a function to read a file line by line from a file descriptor.

## 📋 Project Overview

The `get_next_line` function allows you to read a text file line by line, which is extremely useful for processing large files without loading the entire content into memory at once. This project teaches fundamental concepts in C programming including:

- File I/O operations
- Static variables
- Dynamic memory allocation
- Buffer management

### Parameters
- `fd`: The file descriptor to read from

### Return Value
- Returns a line read from the file descriptor
- Returns `NULL` when there's nothing else to read or an error occurred
- The returned line includes the terminating `\n` character (except for the last line if it doesn't end with `\n`)

## 🛠️ Compilation

Compile with the buffer size macro definition:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You can adjust the `BUFFER_SIZE` value to optimize performance based on your needs.

## 📁 File Structure

```
get_next_line/
├── get_next_line.c          # Main function implementation
├── get_next_line_utils.c    # Helper functions
├── get_next_line.h          # Header file
└── README.md                # This file
```

## 🚀 Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

## ⚡ Key Features

- **Line-by-line reading**: Reads one line at a time from any file descriptor
- **Memory efficient**: Uses a configurable buffer size to manage memory usage
- **Multiple file descriptors**: Can handle multiple files simultaneously
- **Static variables**: Maintains state between function calls using static variables
- **Memory leak free**: Properly manages all allocated memory

## 🔧 Implementation Details

The function works by:

1. **Reading data**: Uses the `read()` system call to fetch `BUFFER_SIZE` bytes from the file descriptor
2. **Buffer management**: Maintains a static buffer to store data between function calls
3. **Line extraction**: Searches for newline characters (`\n`) to determine line boundaries
4. **Memory allocation**: Dynamically allocates memory for each line returned
5. **State preservation**: Uses static variables to remember the position in the file across multiple calls

## 📝 Technical Requirements

- Must handle files, standard input, and other file descriptors
- Should work with different buffer sizes (defined at compilation time)
- Must be memory leak free
- Cannot use global variables
- Must use only allowed functions: `read`, `malloc`, `free`

## 🧪 Testing

Test your implementation with:
- Regular text files
- Empty files
- Files without final newline
- Large files
- Multiple file descriptors simultaneously
- Different buffer sizes (1, 42, 1024, etc.)

## 🎓 Learning Objectives

This project helps you understand:
- How file descriptors work in Unix systems
- The concept and usage of static variables in C
- Dynamic memory management
- Buffer handling and optimization
- System calls and file I/O operations

## ⚠️ Important Notes

- The caller is responsible for freeing the returned line
- The function returns `NULL` when EOF is reached or an error occurs
- Each call returns the next line in the file
- The returned line includes the `\n` character (when present)

## 🔗 42 School

This project is part of the 42 School curriculum, designed to teach fundamental file I/O concepts and memory management in C programming.
