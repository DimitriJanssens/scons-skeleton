#!/bin/sh

DO_DIR='do'
BUILD_DIR='do/host'

rm -rf $DO_DIR

scons documentation --target=host
scons unittests --target=host --unittests

mkdir -p $BUILD_DIR/testresults
mkdir -p $BUILD_DIR/coverage

for f in $BUILD_DIR/bin/*-tests
do
RESULTS_DIR=$BUILD_DIR/testresults LD_LIBRARY_PATH=$BUILD_DIR/third-party/lib valgrind --leak-check=full --sim-hints=no-nptl-pthread-stackcache --track-origins=yes -q  $f 2>&1
done

gcovr -r `pwd` --object-directory=`pwd` \
    --xml --output $BUILD_DIR/coverage/coverage.xml \
    -e '.*/third-party/.*' \
    -e '.*/test/src/.*'
