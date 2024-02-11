# C++ CI/CD PoC

Simple proof of concept about setting up a CICD pipeline for dockerized C++ application.

Basically builds the application, runs unit tests and creates a docker image when the tests pass.

---

## Dependencies

- Git
- CMake
- C++ compiler
- Docker

## Usage

- building the application

    # detect compiler and generate build environment
    cmake .

    # build the application
    cmake --build .
