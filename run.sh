#!/bin/bash
set -e

if [ -n "$ARGB_LAMBDA" ]; then
  cp "$ARGB_LAMBDA" lambda.txt
else
  cp Christmas.txt lambda.txt
fi

rm -rfv build || true
mkdir build && pushd build
cmake .. && make esphomeRGBTester
./esphomeRGBTester
