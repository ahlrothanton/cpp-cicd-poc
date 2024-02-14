# C++ CI/CD PoC

Simple proof of concept about setting up a CICD pipeline for dockerized C++ application. Aim of this project is just to learn cmake and c++ CICD pipelines.

Basically builds the application, runs unit tests and creates a docker image when the tests pass.

Project is managed with cmake and tests are implemented with gtest.

Project contains a docker setup to test the whole pipeline with Jenkins.

---

## Dependencies

- Git
- CMake
- C++ compiler
- Docker
- Python3

## Usage

- building

        # detect compiler and generate build environment
        cmake -S . -B build

        # generate with build flags
        cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
        cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

        # build the application
        cmake --build build
    
- testing

        # expects the project to be built to ./build
        cd build
        ctest

- coverage

        # expects the project to be built to ./build
        cd build/
        ctest --progress
        lcov -c -d . -o coverage.info
        lcov --remove coverage.info -o coverage.final '/usr/include/*' '*.h'
    
        # generate coverate report as html
        genhtml coverage.final --output-directory out

- docker

        # build the image
        docker build -t cpp-cicd-poc .

        # run the image in a container
        docker run -it --rm --name cpp-cicd-poc cpp-cicd-poc

        # specify debug/release flags for CMake during build time
        docker build -t cpp-cicd-poc --build-arg CMAKE_BUILD_TYPE=Debug .
        docker build -t cpp-cicd-poc --build-arg CMAKE_BUILD_TYPE=Release .

- test out the Jenkins pipeline

        cd cicd
        docker-compose up
