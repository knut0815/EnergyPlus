#!/bin/bash
set -eux
bash git/re2/kokoro/cmake.sh
exit $?
