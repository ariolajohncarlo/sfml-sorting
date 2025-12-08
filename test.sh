#!/bin/bash

docker run -it -v .:/project ariolajohncarlo/sfml:1.4.0 ctest --preset linux-debug

