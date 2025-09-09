# Barretta2 Qt6 CMake Project

## Build Instructions

1. **Install Qt6 and CMake**
   - On Ubuntu: `sudo apt install qt6-base-dev cmake`
   - On other distros, use your package manager or download from [Qt website](https://www.qt.io/download)

2. **Configure and Build**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the Application**
   ```bash
   ./Barretta2
   ```

## Project Structure
- `main.cpp`: Minimal Qt6 application
- `CMakeLists.txt`: CMake configuration for Qt6

---

## Game Controls

- **Left Arrow**: Move bar left
- **Right Arrow**: Move bar right
- **Space**: Launch ball
- **R**: Restart game (reset bricks and score)
- **Q** or **Escape**: Quit game

This project demonstrates a basic Qt6 Widgets application using CMake.
