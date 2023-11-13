cmake_minimum_required(VERSION 3.10)
project(Calc)

# Add all your source files
set(SOURCE_FILES
    matrices.c 
    main.c 
    ui.c 
    # Add more files as needed
)

# Create an executable from the source files
add_executable(calc ${SOURCE_FILES})
