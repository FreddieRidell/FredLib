#! /bin/bash

FILE=$(echo $1 | sed "s/.\+\///g")
echo $FILE
FOLDERS=$(echo $1 | sed "s/\/[^\/]\+$//g")

mkdir -p Inc/${FOLDERS}
mkdir -p Src/${FOLDERS}
mkdir -p Test/${FOLDERS}

HEADER_FILE="Inc/${FOLDERS}/${FILE}.hpp"
SRC_FILE="Src/${FOLDERS}/${FILE}.cpp"
TEST_FILE="Test/${FOLDERS}/${FILE}.cpp"

touch $HEADER_FILE
touch $SRC_FILE
touch $TEST_FILE

FOLDERS=$(echo $FOLDERS | sed "s/\//\n/g")

HEADER_GUARD=$(echo ${1} | sed "s/\//_/g")_H_

echo "#pragma once" > $HEADER_FILE
echo >> $HEADER_FILE

for f in $FOLDERS
do
	echo "namespace ${f,,} {" >> $HEADER_FILE
done
echo >> $HEADER_FILE
echo >> $HEADER_FILE
echo >> $HEADER_FILE
for f in $(echo $FOLDERS | awk '{ for (i=NF; i>1; i--) printf("%s ",$i); print $1; }')
do
	echo "} //${f,,}" >> $HEADER_FILE
done

echo "#include<${1}.hpp>" > $TEST_FILE
echo >> $TEST_FILE
echo "#include<gtest/gtest.h>" >> $TEST_FILE
echo "#include<gmock/gmock.h>" >> $TEST_FILE
echo >> $TEST_FILE
for f in $FOLDERS
do
	echo "using namespace ${f,,};" >> $TEST_FILE
done
echo >> $TEST_FILE
echo "TEST(${FILE^^}, FailTest){EXPECT_TRUE(false);}" >> $TEST_FILE
echo >> $TEST_FILE

echo "#include<${1}.hpp>" > $SRC_FILE
echo >> $SRC_FILE
for f in $FOLDERS
do
	echo "using namespace ${f,,};" >> $SRC_FILE
done
echo >> $SRC_FILE
