# Calculator Project
![github-header-image](https://github.com/redsteadz/PF-Project-23K/assets/86804632/6a08f6a4-f397-49d7-8c95-9118da616baf)
[![asciicast](https://asciinema.org/a/XmyLfvEgxqSrqGZZpAzkBbbeR.svg)](https://asciinema.org/a/XmyLfvEgxqSrqGZZpAzkBbbeR)

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
  - [Arithmetic](#arithmetic)
  - [Quadratic and Cubic Equations](#quadratic-and-cubic-equations)
  - [Logarithmic](#logarithmic)
  - [Trigonometric](#trigonometric)
  - [Matrices](#matrices)
  - [Huzaila's Special Functions](#huzailas-special-functions)
  - [Hamees' Special Functions](#hamees-special-functions)
  - [Rayyan's Special Functions](#rayyans-special-functions)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributors](#contributors)
- [License](#license)

## Introduction
This calculator project is designed to perform a wide range of mathematical operations. It encompasses various mathematical domains, making it a versatile tool for different applications. Whether you need to perform basic arithmetic, solve quadratic or cubic equations, work with logarithms, trigonometric functions, or matrices, this calculator has got you covered. 

## Features

### Arithmetic
- Addition
- Subtraction
- Multiplication
- Division
- Exponents (Powers)
- Square Roots

### Quadratic and Cubic Equations
- Quadratic Equation Solver (using the quadratic formula)
- Cubic Equation Solver (if applicable)
- Equation Table Printing (String manipulation)

### Logarithmic
- Natural Logarithm (ln)
- Base-10 Logarithm (log)
- Base-e Logarithm (e)

### Trigonometric
- Sine (sin)
- Cosine (cos)
- Tangent (tan)
- Cosecant (csc)
- Secant (sec)
- Cotangent (cot)
- Inverse Trigonometric Functions

### Matrices
- Matrix Identification
- Matrix Addition
- Matrix Subtraction
- Matrix Multiplication
- Matrix Inversion (with determinant)
- Cofactors and Minors

### Huzaila's Special Functions
- Idempotent Matrix Identification
- Nilpotent Matrix Identification
- Symmetric Matrix Identification
- Skew-Symmetric Matrix Identification
- Involuntary Matrix Identification

### Hamees' Special Functions
- Upper Triangle Matrix Identification
- Lower Triangle Matrix Identification
- Hermitian Matrix Identification
- Skew-Hermitian Matrix Identification

### Rayyan's Special Functions
- Matrix Transposition
- Matrix Determinant
- Matrix Scalar Multiplication
- Matrix Unit Matrix Identification
- Matrix Null Matrix Identification
- Matrix Diagonal Matrix Identification
- Matrix Row Operations
- Matrix Column Operations

## Getting Started
To use this calculator project, follow these steps:
1. Clone the Git repository to your local machine:
   ```bash
   git clone https://github.com/redsteadz/PF-Project-23K
   ```
### Windows - Building
Navigate to src/build folder and run the following commands:
```
cmake -G "MinGW Makefiles" ..
mingw32-make
 
```
### Linux - Building
Navigate to src/build folder and run the following commands:
```
cmake ..
make
```

## Usage
Provide clear and concise examples of how to use the calculator for different mathematical operations. Include code snippets and any special instructions or considerations.

## Testing
In order to test the program extensively with many problems, let me know when a function is built and I will write the testing mock for it

The files are divided into
- headers/ - These are the header files which would only include declaration of variables, functions and so on
![image](https://github.com/redsteadz/PF-Project-23K/assets/86804632/c3210f93-6063-4dda-a609-982896596c7a)

- functions.c - These are the specific function files that would include running the functions
![image](https://github.com/redsteadz/PF-Project-23K/assets/86804632/4d273342-2730-400c-a5e8-d03df47c16cc)

- ui.c - This file contains the main UI functions

- main.c - Which would include the overall functionality stitched together
![image](https://github.com/redsteadz/PF-Project-23K/assets/86804632/558da17f-dbec-4c43-a17d-4aeedefa51ff)


For more examples and details on each function, refer to the documentation (We don't have one) or code comments in the project's source code.

## Contributors
- Huzaila (GitHub: huzaila)
- Hamees (GitHub: hamees)
- Rayyan (GitHub: rayyan)

## License
This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the code as long as you respect the terms of the license. Please see the [LICENSE](LICENSE) file for more details.

Feel free to contribute to this project by creating issues, suggesting improvements, or submitting pull requests on GitHub. Happy calculating!
