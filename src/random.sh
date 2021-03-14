#!/bin/bash

ARG=`ruby -e "puts (1..6).to_a.shuffle.join(' ')"`
./a.out $ARG
