cmake_minimum_required(VERSION 3.10)
project(Calc)

# Add all your source files
set(SOURCE_FILES
    functions.c 
    main.c 
    ui.c 
    # Add more files as needed
)

# Create an executable from the source files
add_executable(calc ${SOURCE_FILES})

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm")

if(MINGW)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
endif()
