# Tic-Tac-Toe

A professional, console-based implementation of Tic-Tac-Toe using **Low-Level Design (LLD)** principles in C++. This project demonstrates a scalable architecture capable of handling $N \times N$ grids with clean separation of concerns.

## 🏗️ System Architecture

The project follows a modular structure where each class has a specific responsibility:

* **`Grid`**: Manages the $N \times N$ board state, including dynamic memory allocation for the matrix and rendering the arena.
* **`Player`**: Represents a user with a unique name and symbol ('X' or 'O').
* **`Game`**: The engine that controls the game flow, including turn management, move validation, and win-condition checking.

## 📂 Project Structure

```text
├── headers/          # Header files (.h)
│   ├── Game.h        # Game engine interface
│   ├── Grid.h        # Board management interface
│   └── Player.h      # Player entity definition
├── src/              # Implementation files (.cpp)
│   ├── Game.cpp      # Game loop and logic implementation
│   └── Grid.cpp      # Board rendering and creation logic
├── main.cpp          # Entry point
└── Makefile          # Build automation for Windows
```

## 🛠️ Installation & Setup

### Prerequisites
* **C++ Compiler**: `g++` (MinGW for Windows).
* **Make Utility**: To automate the build process.

### Build Instructions
The provided **Makefile** is specifically configured for Windows environments.

1.  **Compile the project**:
    Open your terminal in the project root and run:
    ```bash
    make
    ```
    This compiles all `.cpp` files in `src/` and the `main.cpp` into a single executable named `tic_tac_toe.exe`.

2.  **Run the game**:
    ```bash
    make run
    ```

3.  **Clean build files**:
    To remove object files and the executable:
    ```bash
    make clean
    ```
    *Note: The clean command uses `del`, which is specific to Windows CMD/PowerShell.*

## 🎮 Play Demo

The game provides an interactive command-line interface.

### 1. Initialization
The game starts by asking for player names, symbols, and the grid size.

```text
Enter name of player 1 : Amit
Enter the choice of player 1 : (X/O)  X
Enter name of player 2 : Bot
Enter size of Tic-Toe-Grid : 3

Creating Arena ! 

 - | - | - 
---+---+---
 - | - | - 
---+---+---
 - | - | -
```
### 2. Gameplay Loop
Players enter their moves using 1-indexed coordinates (Row and Column). The game validates the move to ensure the coordinates are within the grid boundaries and the cell is not already occupied.

```text
Amit, Your Turn! Enter Row from (1-3) and Column from (1-3)
1 1

 X | - | - 
---+---+---
 - | - | - 
---+---+---
 - | - | -
```

### 3. Win Detection
The engine automatically checks for a win condition after every turn using the `CheckGameWin` logic. It evaluates the grid across four dimensions:

* **Rows**: Checks if all cells in any horizontal row match the player's symbol.
* **Columns**: Checks if all cells in any vertical column match the player's symbol.
* **Principal Diagonal**: Checks the diagonal from top-left to bottom-right.
* **Anti-Diagonal**: Checks the diagonal from top-right to bottom-left.

If a match is found, the game loop terminates and the winner is announced:

```text
Amit Wins !
```

## ✨ Key Features

* **Dynamic Grid Size**: Supports any $N \times N$ board configuration, allowing for flexible gameplay beyond the standard $3 \times 3$ matrix.
* **Input Validation**: Includes robust checks to ensure player moves are within the grid boundaries and prevent overwriting already occupied cells.
* **Automated Makefile**: Features a structured build system that manages multi-file compilation and includes a customized cleanup command for Windows environments.
* **Clean Object-Oriented Design**: Utilizes distinct classes for the Grid, Player, and Game logic to ensure high modularity and separation of concerns.
* **Header Protection**: Employs `#ifndef` preprocessor guards in all header files to prevent double inclusion and compilation errors.
