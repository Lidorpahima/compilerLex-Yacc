#Presenters Lidor Pahima-206735961 and Amit Kalaf-208311654  


# Compiler Implementation with Lex & Yacc

This project implements a compiler front-end in C using **Lex** (Flex) and **Yacc** (Bison). The compiler processes a custom programming language with Python-like syntax.

## Project Overview

The compiler consists of:
- **Lexical Analysis**: Using Flex to tokenize source code
- **Syntax Analysis**: Using Bison to parse the token stream
- **Abstract Syntax Tree (AST)**: Building and traversing a syntax tree representation

## Features

The language supports:
- Functions with `def` keyword
- Control flow statements (`if`, `elif`, `else`, `while`)
- Basic data types (`int`, `float`, `bool`, `string`)
- Variable assignments and expressions
- Boolean literals (`True`, `False`)
- Comments using `#`
- Basic arithmetic and comparison operations

## Project Structure

- `scanner.l` - Lexical analyzer specification (Flex)
- `parser.y` - Grammar specification (Bison)
- `ast.h` / `ast.c` - Abstract Syntax Tree implementation
- `Makefile` - Build configuration
- `test.code` - Sample code for testing

## Prerequisites

To compile and run this project, you need:
- GCC compiler
- Flex (The Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- libfl development libraries

## Installation

On Debian/Ubuntu systems, you can install the required dependencies with:

```bash
sudo apt-get update
sudo apt-get install gcc flex bison libfl-dev
```

## Building the Compiler

To build the compiler, run:

```bash
make
```

This will generate the executable `parser`.

## Usage

To compile a source file:

```bash
./parser test.code
```

## Cleaning Up

To clean the generated files:

```bash
make clean
```

## License

[Specify your license information here]

## Contributors

[Your name or organization]
