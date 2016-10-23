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
