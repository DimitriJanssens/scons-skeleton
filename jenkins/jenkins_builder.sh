#!/bin/sh

rm -rf do

scons documentation --target=host
scons unittests --target=host --unittests

cd do/host

rm -rf testresults
mkdir -p testresults

rm -rf coverage
mkdir -p coverage

for f in bin/*tests
do
RESULTS_DIR=testresults LD_LIBRARY_PATH=third-party/lib valgrind --leak-check=full --sim-hints=no-nptl-pthread-stackcache --track-origins=yes -q  $f 2>&1
done

gcovr -r `pwd` --object-directory=`pwd` --output coverage/coverage.xml \
    --xml \
    -e '.*/third-party/.*' \
    -e '.*/include/c\+\+/.*' \
    -e '.*/test/c\+\+/.*' \
    -e '.*/test/src/.*' \
    `pwd`
