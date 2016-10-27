#!/bin/bash

mkdir Dependencies

pushd Dependencies

echo "gtest"
git clone git@github.com:google/googletest.git --depth=1
pushd googletest
	pushd googletest
		cmake .
		make -j4
	popd
	pushd googlemock
		cmake .
		make -j4
	popd
popd

echo "boost (forgive me father)"

git clone https://github.com/boostorg/boost --depth=1
pushd boost
	git submodule update --init
	./bootstrap.sh
	./b2 headers
popd
