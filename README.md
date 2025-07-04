# Huffman Coding Project

## Overview
This is a simple implementation of Huffman Coding in C++, created by IamXraj. Huffman Coding is a lossless data compression algorithm that assigns variable-length codes to characters based on their frequencies. This project demonstrates both encoding and decoding functionality without any external dependencies.

## Author
- **Developer**: IamXraj
- **Created**: April 2025

## Features
- Builds a Huffman tree based on character frequencies
- Generates unique binary codes for each character
- Encodes text into a compressed binary string
- Decodes the binary string back to original text
- Memory management with proper cleanup
- Uses only C++ Standard Library

## Requirements
- C++ compiler (e.g., g++ via MinGW on Windows)
- Visual Studio Code (optional, for development)

## Installation and Setup (Windows with VS Code)
1. **Install Prerequisites**
   - Visual Studio Code: [Download](https://code.visualstudio.com/)
   - MinGW: [Download](http://www.mingw.org/), install with "mingw32-gcc-g++" package
   - Minimalist GNU for Windows
   - Add MinGW bin directory to Windows PATH

2. **Project Setup**
   - Clone or download this project
   - Open the project folder in VS Code
   - Install C/C++ Extension by Microsoft

3. **Build Configuration**
   - Create `tasks.json` via "Tasks: Configure Task"
   - Use the provided build task configuration

## Usage
1. **Compile**
   - In VS Code: Ctrl+Shift+B (Run Build Task)
   - Command line: `g++ huffman.cpp -o huffman.exe`

2. **Run**
   - In VS Code terminal: `.\huffman.exe`
   - Command line: `huffman.exe`

3. **Example Output**
   ```
   Original text: hello world
   Huffman Codes:
   l: 00
   o: 01
   h: 100
   e: 101
   w: 110
   r: 1110
   d: 1111
   Encoded: 10010100... (binary string)
   Decoded: hello world
   ```

## File Structure
- `huffman.cpp`: Main source code with Huffman implementation
- `README.md`: This documentation

## How It Works
1. Counts character frequencies in the input text
2. Builds a Huffman tree using a priority queue
3. Generates binary codes for each character
4. Encodes the text using these codes
5. Decodes by traversing the tree based on bits

## Limitations
- Works with ASCII characters only
- Simple example uses hardcoded "hello world" text
- No file input/output support

## Future Improvements
- Add support for file input/output
- Handle larger texts efficiently
- Add command-line arguments for custom text

## License
All Rights Researve @IamXraj.exe
