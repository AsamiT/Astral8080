#!/bin/bash

find . -maxdepth 1 -type d \( ! -name . \) -print0 | xargs -0 -L1 sh -c 'cd "$0" && pwd && git add . && git commit -m "Added by auto-script" && git push'

