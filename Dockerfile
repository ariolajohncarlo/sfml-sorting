FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    wget \
    libsfml-dev \
    libssl-dev \
    libgtest-dev \
    doxygen

RUN wget https://cmake.org/files/v3.28/cmake-3.28.3.tar.gz

RUN tar -xvf cmake-3.28.3.tar.gz

RUN cd cmake-3.28.3 && \
    ./bootstrap && \
    make && \
    make install

WORKDIR /project
