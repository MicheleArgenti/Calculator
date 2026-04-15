
# C++ Calculator Application

## Overview

As a software engineer committed to building a strong foundation in systems-level programming, I developed this calculator application to master the C++ programming language. C++ offers unique challenges and opportunities compared to managed languages like Java, particularly with manual memory management, pointer manipulation, and direct control over system resources. This project represents my deliberate effort to understand C++ syntax, the Standard Template Library (STL), and the language's approach to object-oriented programming while creating something practical and functional.

The software is a feature-rich console-based calculator application that performs basic arithmetic operations (addition, subtraction, multiplication, division) as well as advanced functions including exponentiation, square roots, and percentage calculations. The application maintains a persistent calculation history using file I/O, allowing users to review past calculations across sessions. Additional features include the ability to clear history, export calculations to external files, and recall the most recent result, all presented through an intuitive menu-driven interface.

My primary purpose for writing this software was to gain hands-on experience with C++'s unique syntax and paradigms while building a complete, usable application. Unlike higher-level languages I have used previously, C++ required me to think carefully about include directives, namespace management, stream formatting, and the distinction between stack and heap allocation. This project also allowed me to explore the STL vector container for dynamic data storage and practice file handling with fstream, both essential skills for more complex systems programming I plan to undertake in the future.

[Software Demo Video](https://youtu.be/UmI-H2TVAKY)

## Development Environment

**Tools Used:**
- **Visual Studio Code** - Primary code editor with C++ extensions for syntax highlighting, IntelliSense, and debugging
- **g++ (GNU Compiler Collection)** - Command-line compiler used to build and test the application on Windows Subsystem for Linux (WSL) and native Windows environments
- **Git** - Version control system for tracking changes and managing code iterations throughout development
- **Windows Terminal** - For compiling, running, and testing the console application across multiple sessions

**Programming Language and Libraries:**
- **C++17** - A systems programming language chosen for its performance, control over memory, and extensive standard library. C++ compiles directly to machine code, offering execution speed advantages over interpreted or virtual machine-based languages.
- **Standard Libraries Used:**
    - `iostream` - Handles console input and output operations including `cin`, `cout`, and `cerr`
    - `vector` - STL container for dynamic array storage of calculation history entries
    - `string` - Provides string manipulation capabilities including concatenation, formatting, and file operations
    - `fstream` - File stream library for reading from and writing to the history file (`ofstream`, `ifstream`)
    - `sstream` - String stream library for formatting numbers and constructing complex output strings
    - `iomanip` - Input/output manipulators for controlling output formatting such as `setprecision()` and `fixed`
    - `cmath` - Mathematical functions library providing `pow()` for exponentiation and `sqrt()` for square root operations

## Useful Websites

- [cplusplus.com Reference](http://www.cplusplus.com/reference/) - Comprehensive documentation for C++ standard library functions, classes, and headers, particularly helpful for understanding `fstream` file operations and `iomanip` formatting
- [LearnCpp.com](https://www.learncpp.com/) - Excellent tutorial site that explains C++ concepts from fundamentals to advanced topics, invaluable for understanding the differences between C++ and other languages I have learned
- [Stack Overflow C++ Tag](https://stackoverflow.com/questions/tagged/c%2b%2b) - Critical resource for troubleshooting compiler errors, understanding undefined behavior, and learning best practices from experienced C++ developers
- [cppreference.com](https://en.cppreference.com/w/) - The definitive reference for C++ language syntax and standard library, particularly useful for verifying function signatures and understanding STL container requirements
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/) - Official documentation for the GNU Compiler Collection, helpful for understanding compiler flags, warnings, and optimization options

## Future Work

- **Add Scientific Calculator Functions** - Implement trigonometric functions (sine, cosine, tangent), logarithmic calculations, and factorial operations to expand the calculator's utility for math and engineering applications. This would require additional input validation and careful handling of domain-specific edge cases.

- **Implement Expression Parsing** - Replace the current menu-driven approach with a natural expression parser that allows users to type full mathematical expressions like "25 * 3 + sqrt(16)" and receive correct results following order of operations. This would involve learning recursive descent parsing or using the Shunting-yard algorithm.

- **Add Memory Registers** - Create multiple memory storage locations (M1, M2, M3) with store, recall, add-to-memory, and clear-memory functions. This would demonstrate more advanced use of STL maps or arrays while providing practical functionality for complex calculations.

- **Improve Error Handling** - Enhance the exception handling system to provide more specific error messages, gracefully recover from invalid inputs without crashing, and implement input validation loops that reject non-numeric entries. Currently, entering letters instead of numbers causes stream failures that need better recovery.

- **Create a Graphical User Interface** - Port the console application to a GUI framework such as Qt, wxWidgets, or even a web-based interface using Emscripten. This would make the calculator more accessible to non-technical users while teaching GUI programming concepts in C++.

- **Support Complex Numbers** - Extend the calculator to handle complex number arithmetic, including addition, subtraction, multiplication, division, and advanced functions on complex values. This would demonstrate template usage and operator overloading while creating genuinely useful functionality for engineering students.