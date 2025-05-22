# kgen

`kgen` is a command-line tool for generating random keys with customizable character sets and lengths. It is an open-source project designed to be simple, flexible, and easy to use.

## Features

- Generate random keys using numbers, lowercase letters, uppercase letters, and symbols.
- Customize the key length and character sets via command-line arguments.
- Support for abbreviated options (e.g., `--no-nums` for `--no-numbers`).
- Informative help and version information.

## Installation

### Prerequisites

- **C++ Compiler**: Visual Studio (2015 or later) or any C++17-compliant compiler (e.g., g++, clang++).
- **Operating System**: Windows, Linux, or macOS.
- No external libraries are required (OpenSSL is not used in the current version).

### Building from Source

1. **Clone the repository**:

   ```bash
   git clone https://github.com/yanothere/kgen.git
   cd kgen
   ```

2. **Compile the project**:

   - **Windows (Visual Studio)**: Open the project in Visual Studio, select the `Release` or `Debug` configuration, and build. Alternatively, use the Developer Command Prompt:

     ```bash
     cl src/kgen.cpp
     ```

   - **Linux/macOS**:

     ```bash
     g++ src/kgen.cpp -o kgen -std=c++17
     ```

3. **Run the executable**: The compiled `kgen.exe` (Windows) or `kgen` (Linux/macOS) will be created in the current directory.

## Usage

Run `kgen` with the following syntax:

```bash
kgen [gentype] [mods]
```

### Gen Types

| Type | Description |
| --- | --- |
| `--randkey` | Generate a random key with specified length and character sets |

### Modifiers

| Modifier | Description |
| --- | --- |
| `--length N` | Specify the length of the key (default: 32) |
| `--no-numbers` | Exclude numbers (also `--no-nums`) |
| `--no-lowers` | Exclude lowercase letters (also `--no-lows`) |
| `--no-uppers` | Exclude uppercase letters (also `--no-ups`) |
| `--no-symbols` | Exclude symbols (also `--no-syms`) |

### Commands

| Command | Description |
| --- | --- |
| `--help` | Show the help message |
| `--version` | Show version information |
| `--cmds` | Show available commands (same as `--help`) |

### Examples

- Generate a 16-character random key:

  ```bash
  kgen --randkey --length 16
  ```

  Output:

  ```
  Key: aB7#kP9mX2nQ5jL8
  ```

- Generate an 8-character key without symbols or numbers:

  ```bash
  kgen --randkey --length 8 --no-symbols --no-numbers
  ```

  Output:

  ```
  Key: abCdEfGh
  ```

- Show help:

  ```bash
  kgen --help
  ```

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes. Ensure your code follows the existing style and includes tests if applicable.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Author

- Yanothere
- GitHub: https://github.com/yanothere