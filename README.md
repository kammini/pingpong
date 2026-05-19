# Ping Pong Game

A classic Ping Pong game built with **C++** and the **Raylib** library. This project features a player-controlled paddle, an AI-controlled CPU paddle, and a scoring system.

## Features

- **Smooth Gameplay:** Responsive paddle movement and ball physics.
- **AI Opponent:** A CPU paddle that tracks the ball's movement.
- **Visuals:** Field markings, scoring display, and rounded paddles.
- **Cross-Platform Potential:** Built using Raylib, which supports multiple platforms.

## Prerequisites

To build and run this project, you need:

1.  **C++ Compiler:** Support for C++17 (e.g., `g++` or `clang`).
2.  **Raylib:** A simple and easy-to-use library to enjoy videogames programming.
    - On macOS: `brew install raylib`
    - On Linux/Windows: Refer to the [Raylib Installation Guide](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux).

## Building the Project

### Using VS Code

This project includes a `.vscode/tasks.json` file. You can compile the project by:
1. Opening the project folder in VS Code.
2. Pressing `Cmd+Shift+B` (macOS) or `Ctrl+Shift+B` (Windows/Linux).

### Using the Command Line

If you have Raylib installed via Homebrew on macOS, you can use the following command:

```bash
g++ -std=c++17 main.cpp -o PingPong -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib
```

## How to Play

1.  Run the compiled executable:
    ```bash
    ./PingPong
    ```
2.  **Controls:**
    - Use the **UP Arrow** key to move your paddle up.
    - Use the **DOWN Arrow** key to move your paddle down.
3.  **Goal:** Prevent the ball from passing your paddle and try to score against the CPU!

## Project Structure

- `main.cpp`: The core logic of the game, including ball and paddle classes, collision detection, and the main game loop.
- `.vscode/`: Configuration for VS Code building and debugging.

## License

This project is open-source and available under the MIT License.
