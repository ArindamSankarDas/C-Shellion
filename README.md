# 🐚 C-Shellion – A Custom Unix Shell in C

**C-Shellion** is a minimalist yet functional custom shell written in C. It supports core Unix-like built-in commands, as well as custom reimplementations of commonly used external commands like `touch`, `mkdir`, and `ls`. This project is built from scratch to understand and recreate how shells like `bash` or `sh` work under the hood.

---

## 🔧 Features

### 🧠 Built-in Commands (executed within the shell process):
- `cd` – Change current directory
- `pwd` – Show current working directory
- `exit` – Exit the shell
- `help` – Display shell help message
- `history` – Show a list of previously entered commands (stored in memory)

### ⚙️ Custom External Commands (written from scratch in C):
- `touch` – Create an empty file
- `mkdir` – Create a directory
- `ls` – List directory contents
- `clear` – Clear the terminal screen

### 🧩 Shell Features:
- Command parsing with space-separated arguments
- Process creation using `fork()` and execution using `execvp()`
- `$PATH` support for command discovery
- Graceful error handling with `perror()`
- Command history stored in memory (optional file support planned)

---

## 📁 Project Structure
```text
C-Shellion/
├── include/          # Header files
│   ├── shell.h       # Declarations for core shell logic
│   ├── cmds.h        # Declarations for custom commands
│   └── builtin.h     # Declarations for built-in commands
│
├── src/              # Source files
│   ├── main.c        # Main entry point, configuration
│   ├── shell.c       # Core shell loop and command handling
│   └── builtin.c     # Implementation of built-in commands
│
├── build/            # Compiled output (e.g., the shell executable)
│
├── bin/              # Compiled custom commands (this dir is added to PATH)
│
├── cmds/             # Source code for all custom commands
│   └── Makefile      # Makefile to compile custom commands
│
├── CMakeLists.txt    # Root CMake configuration for the project
└── README.md         # You are here!
```

## ⚙️ Building the Project

### 🔧 Prerequisites
- C compiler (e.g., `gcc` or `clang`)
- CMake ≥ 3.10
- Make

### 🛠 Build Instructions

```bash
# Create and navigate to build directory
mkdir -p build && cd build

# Run CMake configuration
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

or,

cmake .. (if you don't want compile_commands.json for your code editors to navigate the folder structure)

# Build the executable to be run
cmake --build .

# ▶️ Running the Shell
./app_exec (or whatever the name of the executable is)

# Ensure your path variable is updated to the location where the custom commands are
export PATH=$HOME/your_path:$HOME/.local/bin:/usr/local/bin:$PATH

eg: your_path = Projects/C-Shellion/bin
```

### 🧪 Sample Session
```bash
C-Shellion > mkdir demo
C-Shellion > cd demo
C-Shellion > touch file.txt
C-Shellion > ls
file.txt
C-Shellion > history
1. mkdir demo
2. cd demo
3. touch file.txt
4. ls
5. history
```
