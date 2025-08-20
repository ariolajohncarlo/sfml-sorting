#!/bin/bash

docker run -it -v .:/project ariolajohncarlo/sfml:1.3.0 cmake --preset linux-debug

