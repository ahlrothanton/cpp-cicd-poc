### base image
FROM ubuntu AS base

RUN apt-get update && apt-get install -yq libzmq5

# TODO: clear apt cache

### builder image
FROM base AS builder

ARG COVERAGE=true
ARG CMAKE_BUILD_TYPE=Debug
ARG CPPZMQ_VERSION=4.10.0
RUN apt-get install -yq g++ curl cmake libzmq3-dev &&  \
    mkdir -p /usr/src && \
    cd /usr/src && \
    curl -L https://github.com/zeromq/cppzmq/archive/v${CPPZMQ_VERSION}.tar.gz | tar -zxf - && \
    cd /usr/src/cppzmq-${CPPZMQ_VERSION} && \
    cmake -D CPPZMQ_BUILD_TESTS:BOOL=OFF . && \
    make && \
    make install

WORKDIR /usr/src/print_time

# copy required files
COPY src/ ./src
COPY tests/ ./tests
COPY CMakeLists.txt .
COPY cmake/ ./cmake

RUN cmake -S . -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCOVERAGE=${COVERAGE} . && \
    make && \
    make all

# TODO: conditionally run unit tests/coverage

### app image
FROM base AS runtime

# copy all possible print_time binaries
COPY --from=builder /usr/src/print_time/print_time* /usr/local/bin/

#CMD tail -f /dev/null
ENTRYPOINT ["print_time"]
