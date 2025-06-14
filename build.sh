#!/bin/bash

# Racing Through Our Nights - Build Script
# This script provides easy build commands for the game

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Function to check if required directories exist
check_directories() {
    print_status "Checking project structure..."
    
    if [[ ! -d "src" ]]; then
        print_error "src/ directory not found!"
        exit 1
    fi
    
    if [[ ! -d "include" ]]; then
        print_error "include/ directory not found!"
        exit 1
    fi
    
    if [[ ! -d "assets" ]]; then
        print_warning "assets/ directory not found - game may not load properly"
    fi
    
    # Create build directories if they don't exist
    mkdir -p obj build
    print_success "Directory structure verified"
}

# Function to clean build files
clean_build() {
    print_status "Cleaning build files..."
    rm -rf obj/*.o build/racing_game
    print_success "Build files cleaned"
}

# Function to build the game
build_game() {
    print_status "Building Racing Through Our Nights..."
    
    # Check if make is available
    if command -v make &> /dev/null; then
        print_status "Using Makefile for build..."
        make
    else
        print_status "Make not found, using manual compilation..."
        
        # Manual compilation
        g++ -Wall -Wextra -std=c++11 -Iinclude \
            main.cpp src/*.cpp \
            -o build/racing_game \
            -lgraph -lwinmm -lgdi32 -luser32
    fi
    
    print_success "Game built successfully!"
}

# Function to run the game
run_game() {
    if [[ -f "build/racing_game" ]] || [[ -f "build/racing_game.exe" ]]; then
        print_status "Running Racing Through Our Nights..."
        if [[ -f "build/racing_game" ]]; then
            ./build/racing_game
        else
            ./build/racing_game.exe
        fi
    else
        print_error "Game executable not found! Please build first."
        exit 1
    fi
}

# Function to show help
show_help() {
    echo "Racing Through Our Nights - Build Script"
    echo ""
    echo "Usage: $0 [COMMAND]"
    echo ""
    echo "Commands:"
    echo "  build     Build the game"
    echo "  clean     Clean build files"
    echo "  run       Run the game (builds if necessary)"
    echo "  rebuild   Clean and build"
    echo "  help      Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 build"
    echo "  $0 run"
    echo "  $0 rebuild"
}

# Main script logic
case "${1:-build}" in
    "build")
        check_directories
        build_game
        ;;
    "clean")
        clean_build
        ;;
    "run")
        check_directories
        if [[ ! -f "build/racing_game" ]] && [[ ! -f "build/racing_game.exe" ]]; then
            print_status "Game not built, building first..."
            build_game
        fi
        run_game
        ;;
    "rebuild")
        check_directories
        clean_build
        build_game
        ;;
    "help"|"-h"|"--help")
        show_help
        ;;
    *)
        print_error "Unknown command: $1"
        show_help
        exit 1
        ;;
esac
