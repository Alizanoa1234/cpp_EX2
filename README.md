//alizalazar9@gmail.com

# cpp_EX2 - Square Matrix Operator Overloading

## Overview
This project implements a `SquareMat` class in C++ to model square matrices of real numbers.  
It includes a full suite of overloaded operators for arithmetic, logic, indexing, and transformations — all without using the C++ STL.  
The matrix operations follow the principles of linear algebra and are implemented using raw dynamic memory.

This assignment demonstrates mastery of:
- Operator overloading
- Dynamic memory management (Rule of Three)
- Exception safety
- Modular design and testing
- Memory leak checking using Valgrind


## Project Structure
## 📂 Project Structure

- `cpp_EX2/`
  - `include/`
    - `SquareMat.hpp` — Class declarations
  - `src/`
    - `SquareMat.cpp` — Class implementations
  - `main/`
    - `main.cpp` — Demonstration program
  - `tests/`
    - `test_SquareMat.cpp` — Unit tests (using doctest)
    - `doctest.h` — Testing framework header
  - `Makefile` — Build and automation script
  - `README.md` — Project documentation
  - `submission.txt` — Submission metadata



## Features

- Matrix creation and safe copy (Rule of Three)
- Full operator overloading:
  - Arithmetic: `+`, `-`, `*`, `/`, `%`, `^`
  - Unary: `-`, `!`, `~`, `++`, `--`
  - Indexing: `mat[i][j]`
  - Logical: `==`, `!=`, `<`, `>`, `<=`, `>=`
  - Compound: `+=`, `-=`, `*=`, `/=`, `%=` (including scalars)
- Transpose and determinant
- Input validation and exception handling
- Zero memory leaks (Valgrind tested)
- No usage of STL containers (raw arrays only)
- Clear modular structure, ready for testing


### Build main demo:

```bash
make Main
./main_exec

make test
./test_exec

make valgrind

make clean



- Aliza lazar: 336392899
- GitHub Repo:https://github.com/Alizanoa1234/cpp_EX2.git
- Course: C++ Programming

