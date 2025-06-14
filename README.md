# Racing Through Our Nights

[Video Preview of the Game](https://drive.google.com/file/d/1APIosDpXc9ZvN1zF04ZMWEb3kNQ8PjXC/view?usp=sharing)

![alt text](https://raw.githubusercontent.com/fsudjatmiko/racing-through-our-nights/refs/heads/main/assets/ui/mainmenu.gif)


A 2D action-adventure game built with C++ and the BGI graphics library.

## Project Structure

```
racing-through-our-nights/
├── assets/                    # Game assets
│   ├── backgrounds/          # Background images
│   ├── characters/           # Player character animations
│   ├── enemies/             # Enemy sprites and animations
│   ├── ui/                  # User interface elements
│   ├── images/              # General images
│   └── sounds/              # Audio files (future use)
├── include/                  # Header files
│   ├── Game.h               # Main game class
│   └── Menu.h               # Menu system class
├── src/                     # Source files
│   ├── Game.cpp             # Core game logic
│   ├── PlayerAnimations.cpp # Player movement and animations
│   ├── Enemies.cpp          # Enemy behaviors and AI
│   ├── FinalStage.cpp       # Boss fight implementation
│   └── Menu.cpp             # Menu system implementation
├── build/                   # Build artifacts
├── obj/                     # Object files
├── docs/                    # Documentation
├── main.cpp                 # Main entry point
├── main_original.cpp        # Original monolithic file (backup)
├── Makefile                 # Build configuration
└── README.md               # This file
```

## Game Features

- **Multi-stage Adventure**: Progress through different environments
- **Character Animation**: Smooth walking, jumping, and attack animations
- **Enemy Variety**: Face different types of enemies with unique behaviors
- **Boss Battles**: Epic final stage with challenging boss mechanics
- **Health System**: Manage your health throughout the adventure
- **Menu System**: Character selection and game navigation

## Building the Game

### Prerequisites

- C++ compiler (g++)
- BGI (Borland Graphics Interface) library or compatible graphics library
- Windows environment (for WinAPI dependencies)

### Compilation

Using the provided Makefile:

```bash
# Build the game
make

# Build and run
make run

# Debug build
make debug

# Release build (optimized)
make release

# Clean build files
make clean
```

Manual compilation:
```bash
g++ -Wall -Wextra -std=c++11 -Iinclude main.cpp src/*.cpp -o racing_game -lgraph -lwinmm -lgdi32 -luser32
```

## Controls

- **A/D**: Move left/right
- **E**: Attack
- **Shift**: Run (faster movement)
- **Space**: Shoot (in final stage)
- **Arrow Keys**: Navigate menus
- **Enter**: Select menu option
- **Escape**: Back/Exit

## Code Architecture

### Game Class (`Game.h`, `Game.cpp`)
- Core game state management
- Player positioning and movement
- Stage progression
- Health and scoring systems

### Player Animations (`PlayerAnimations.cpp`)
- Character movement animations
- Attack sequences
- Flying mechanics (final stage)

### Enemy System (`Enemies.cpp`)
- Multiple enemy types (Orcs, Knights, Shamans, Sharks)
- AI behaviors and movement patterns
- Combat mechanics
- Boss fight logic

### Menu System (`Menu.h`, `Menu.cpp`)
- Main menu navigation
- Character selection
- Game state transitions

### Final Stage (`FinalStage.cpp`)
- Boss battle mechanics
- Weak point system
- Advanced combat features

## Asset Organization

Assets are organized by category for better maintainability:
- **Backgrounds**: Stage environments and scenery
- **Characters**: Player sprites and animations
- **Enemies**: All enemy sprites and boss graphics
- **UI**: Menus, HUD elements, and interface graphics

## Development Notes

### Original Refactoring
The original `main.cpp` was a single monolithic file with over 1300 lines. This has been refactored into:
- Modular class structure
- Separated concerns (game logic, animations, enemies, menu)
- Organized asset structure
- Build system with Makefile

### Future Improvements
- Sound system integration
- Configuration file support
- Additional character classes
- More enemy types and stages
- Save/load game functionality

## Troubleshooting

### Common Issues
1. **Graphics library not found**: Ensure BGI or compatible graphics library is installed
2. **Asset loading errors**: Check that asset paths are correct relative to executable
3. **Compilation errors**: Verify all dependencies are installed and paths are correct

### Windows-Specific Notes
This game uses Windows-specific APIs (WinUser.h, Windows.h) for input handling and may require compilation on Windows or with appropriate compatibility layers.
