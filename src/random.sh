#!/bin/bash

ARG=`ruby -e "puts (1..20).to_a.shuffle.join(' ')"`
./push_swap $ARG
