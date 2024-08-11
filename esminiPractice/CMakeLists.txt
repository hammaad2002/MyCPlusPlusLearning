cmake_minimum_required(VERSION 3.22)
set(PROJECTNAME "testesmini")
set(TARGET "tempTarget")
project(${PROJECTNAME})

include_directories(/myGitWork/esmini_work/esminiFolder/EnvironmentSimulator/Libraries/esminiLib)

# Create a library target (use a valid name, e.g., "esminiLib")
add_library(esminiLib SHARED IMPORTED)
set_target_properties(esminiLib PROPERTIES IMPORTED_LOCATION "/myGitWork/esmini_work/esminiFolder/bin/libesminiLib.so")

# Add the executable
add_executable(${TARGET} main.cpp)

# Link the esminiLib to your executable
target_link_libraries(${TARGET} PRIVATE esminiLib)
