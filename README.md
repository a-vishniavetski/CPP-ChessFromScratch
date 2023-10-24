<img src="https://github.com/a-vishniavetski/CPP-ChessFromScratch/assets/132013288/00e0cc43-3d73-4e50-a24b-62ec82186296" align="right" width="400"></img>

# Cross-Platform C++ Chess Application
> Written from scratch by students of Politechnika Łódzka as a mid-term assignment.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Navigation

- [Overview](#overview)
- [Features](#features)
- [Installation and Usage](#installation-and-usage)
- [License](#license)

## Overview

This C++ Chess application is a desktop chess game developed from scratch. It uses the [wxWidgets](https://github.com/wxWidgets/wxWidgets) cross-platform library for GUI. It offers a user experience for playing chess, with features including two-player mode, the ability to play against a bot, ability for saving and loading games, and the code of the application adheres to object-oriented programming (OOP) principles.

## Features

- **Graphical User Interface (GUI):** The application features a GUI created using the wxWidgets library, ensuring cross-platform compatibility for Windows, macOS, and Linux.

- **Game Serialization:** Save and load your chess games at any point. Serialization for the saving system was written from scratch.
  
- **Different Game Modes:** Challenge your friends or colleagues for a classic chess game. The application allows two humans to play against each other. For solo players, test your skills against a computer-controlled bot.

- **Object-Oriented Programming (OOP):** The project strictly follows OOP principles, providing clean, maintainable, and well-organized code.

## Installation and Usage

1. **Prerequisites:**
   - C++ compiler
   - CMake
   - Make
   - [Boost library](https://www.boost.org/)
   - [wxWidgets library](https://github.com/wxWidgets/wxWidgets)

2. **Clone the Repository:**
 ```shell
 git clone https://github.com/a-vishniavetski/CPP-ChessFromScratch.git
```

3. **Compile the Application:**

In the project folder:
```bash
mkdir build
cd build
cmake ..
make
```

4. **Run the Application:**

```bash
./main
```

5. **Gameplay:**

  - Choose the game mode (Two-Player or Against Bot).
  - Use the GUI to make moves.
  - Save and load your games at any time.

## License
The application is licensed under the terms of the MIT Open Source license and is available for free for any purposes.
