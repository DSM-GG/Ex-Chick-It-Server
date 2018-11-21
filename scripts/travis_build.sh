#!/usr/bin/env sh

mkdir Build -p && cd Build

cmake ../../servers/gameplay/src

make