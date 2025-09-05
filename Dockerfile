FROM ubuntu:24.04

RUN apt-get update

RUN apt-get install -y \
    build-essential=12.10ubuntu1 \
    g++=4:13.2.0-7ubuntu1 \
    wget=1.21.4-1ubuntu4.1 \
    libsfml-dev=2.6.1+dfsg-2build2 \
    libssl-dev=3.0.13-0ubuntu3.5 \
    libgtest-dev=1.14.0-1 \
    doxygen=1.9.8+ds-2build5

RUN wget https://cmake.org/files/v3.28/cmake-3.28.3.tar.gz

RUN tar -xvf cmake-3.28.3.tar.gz

RUN cd cmake-3.28.3 && \
    ./bootstrap && \
    make && \
    make install && \
    cd / && \
    rm -rfv /cmake-3.28.3.tar.gz /cmake-3.28.3/

WORKDIR /project
