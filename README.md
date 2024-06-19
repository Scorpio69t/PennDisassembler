
# Dynamic Memory & File I/O Project

This repository contains the final project for the CIT 5930 course, focusing on dynamic memory management and file I/O operations in C. The project involves reading a .OBJ file created by PennSim, parsing it, and converting it back to assembly code.

## Table of Contents

- [Dynamic Memory \& File I/O Project](#dynamic-memory--file-io-project)
  - [Table of Contents](#table-of-contents)
  - [Project Overview](#project-overview)
  - [File Structure](#file-structure)
  - [Requirements](#requirements)
  - [Setup](#setup)
  - [Usage](#usage)
  - [Implementation Details](#implementation-details)
  - [Testing](#testing)
  - [License](#license)

## Project Overview

The goal of this project is to write a program that can open and read a .OBJ file, parse it, and load it into a linked list representing the LC4’s program and data memories. This process is known as reverse assembling or disassembling.

## File Structure

- `lc4.c`: Contains the `main()` function.
- `lc4_memory.c`: Contains linked list helper functions.
- `lc4_memory.h`: Contains the declaration of the `row_of_memory` structure and linked list helper functions.
- `lc4_loader.h`: Contains loader function declarations.
- `lc4_loader.c`: Contains .OBJ parsing function.
- `lc4_disassembler.h`: Contains disassembler function declarations.
- `lc4_disassembler.c`: Contains disassembling function.
- `Makefile`: Contains build targets for compiling the program.

## Requirements

- Codio platform or a similar C development environment.
- C compiler (gcc recommended).
- Make utility.

## Setup

1. **Clone the repository:**
   ```sh
   git clone https://github.com/yourusername/dynamic-memory-file-io.git
   cd dynamic-memory-file-io
   ```

2. **Compile the project:**
   ```sh
   make
   ```

3. **Run the program:**
   ```sh
   ./lc4 <object_file.obj>
   ```

## Usage

1. **Provide an .OBJ file:**
   The program takes an .OBJ file created by PennSim as input.

2. **Run the program:**
   ```sh
   ./lc4 my_file.obj
   ```

3. **Error handling:**
   If no file is passed, the program will output:
   ```
   error1: usage: ./lc4 <object_file.obj>
   ```

4. **Output:**
   The program will print the contents of the linked list representing LC4's memory.

## Implementation Details

1. **LC4 Loader:**
   - `open_file()`: Opens the .OBJ file specified by the user.
   - `parse_file()`: Reads and parses the .OBJ file, populating the linked list.

2. **Reverse Assembler:**
   - `reverse_assemble()`: Translates hex instructions into their assembly equivalents for OPCODE: 0001.

3. **Linked List Management:**
   - Functions for adding nodes, searching by address or opcode, and printing the list.

4. **Memory Management:**
   - The program ensures all dynamically allocated memory is freed before exiting.

## Testing

- Use `valgrind` to check for memory leaks:
  ```sh
  valgrind --leak-check=full ./lc4 my_file.obj
  ```

- Ensure `valgrind` reports 0 errors and no memory leaks.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

This project was completed as part of the CIT 5930 course at the University of Pennsylvania. The primary goal was to enhance understanding of dynamic memory and file I/O operations in C programming.
