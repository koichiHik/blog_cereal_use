#!/bin/bash

ADDITIONAL_CMAKE_MODULE_DIR=./cmake

SCRIPT_DIR=$(cd $(dirname $0); pwd)
INSTALL_DIR="${SCRIPT_DIR}/extern/lib"
echo $INSTALL_DIR

if [ ! -e ./extern/build ]; then

mkdir extern/build/
cd extern/build/
cmake \
  -D CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} \
  -D CMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
  ../cereal
make install -j32
cd ../../

fi

# Configure Main Repository.
if [ ! -e ./build ]; then
  mkdir build
fi
cd build

cmake \
  -D ADDITIONAL_CMAKE_MODULE_DIR=${ADDITIONAL_CMAKE_MODULE_DIR} \
  -D CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} \
  ../

make

cd ../