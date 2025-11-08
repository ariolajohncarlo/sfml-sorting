FROM ariolajohncarlo/cmake:3.28.3-ubuntu

RUN apt-get update

RUN apt-get install -y \
    build-essential=12.10ubuntu1 \
    g++=4:13.2.0-7ubuntu1 \
    libsfml-dev=2.6.1+dfsg-2build2 \
    libgtest-dev=1.14.0-1 \
    doxygen=1.9.8+ds-2build5

WORKDIR /project
