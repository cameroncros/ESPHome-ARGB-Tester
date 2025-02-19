#!/bin/bash
set -e

if [ -n "$ARGB_LAMBDA" ]; then
  cp "$ARGB_LAMBDA" lambda.txt
else
  cp Christmas.txt lambda.txt
fi

MAKE_ARGS=""
if [ -n "$SLEEP_MS" ]; then
  MAKE_ARGS="$MAKE_ARGS -DSLEEP_MS=$SLEEP_MS"
fi
if [ -n "$CHAIN_LENGTH" ]; then
  MAKE_ARGS="$MAKE_ARGS -DCHAIN_LENGTH=$CHAIN_LENGTH"
fi

rm -rfv build || true
mkdir build && pushd build
cmake .. $MAKE_ARGS && make esphomeRGBTester
./esphomeRGBTester
