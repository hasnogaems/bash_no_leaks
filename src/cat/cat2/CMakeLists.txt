# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.0)

# Define the project name
project(MyProject)

# Add the executable and specify the source files
add_executable(my_program cat.c parse_flags.c functions.c)
