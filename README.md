# C++ CI/CD PoC

Simple proof of concept about setting up a CICD pipeline for dockerized C++ application.

Basically builds the application, runs unit tests and creates a docker image when the tests pass.

---

## Dependencies

- Git
- CMake
- gtest
- C++ compiler
- Docker

## Usage

- build

    # detect compiler and generate build environment
    cmake .

    # build the application
    cmake --build .

- docker

    # build the image
    docker build -t cpp-cicd-poc .

    # run the image
    docker run -it --rm --name cpp-cicd-poc cpp-cicd-poc
