#!/bin/sh

#include <string.h>

  echo "Enter your password:"
  read password
  length=${#password}

  for i in length
  do
      if [$password[i] -ge 35 -a $password[i] -lt 38]
      then
        echo "Includes special character\n"
        .
      elif [$password[i] == 42 -o $password[i] == 43] -o $password[i] == 45 ]
      then
        echo "Includes special character\n"
        .
      else
        echo "Doesn't include special character\nPassword Failed\n"
      fi

      if [$password[i] -lt 64 -a $password[i] -lt 96]
      then
        echo "Includes Upper Case\n"
      else
        echo "Doesn't include upper case\nPassword Failed\n"
      fi

      if [$password[i] -lt 96 -a $password[i] -lt 123]
      then
        echo "Includes lower case\n"
      else
        echo "Doesn't include upper case\nPassword Failed\n"
      fi
  done
