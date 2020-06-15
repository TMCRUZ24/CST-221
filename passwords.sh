#!/usr/bin/env bash

#Tyson M. Cruz
#06/14/2020
#CST221 - Operating Systems Concepts
#Professor Michael Landreth

PASSWORD=$1

if [[ ${#PASSWORD} -lt 8 ]]
 then
  echo "Your password is too short."
elif ! [[ $PASSWORD =~ [0-9] ]]
 then
  echo "Your password does not contain any numbers."
elif ! [[ $PASSWORD =~ ['@#\$%\&*+-='] ]]
  then
    echo "Your password does not contain any special characters."
    echo "Your password must contain one of @, #, $, %, &, *, +, -, =."
else
  echo "Your password looks good!"
fi
