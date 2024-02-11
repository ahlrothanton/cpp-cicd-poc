### base image
FROM debian:buster AS base

RUN apt-get update && apt-get install -yq libzmq5

### builder image
FROM base AS builder

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

RUN cmake . && \
    make && \
    make all

### app image
FROM base AS runtime

COPY --from=builder /usr/src/print_time/PrintTime /usr/local/bin/pt

ENTRYPOINT ["pt"]
