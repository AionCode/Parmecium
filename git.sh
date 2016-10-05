#!/bin/bash

if [ "$1" == "init" ]
then
    git init
elif [ "$1" == "pull" ]
then
    git pull
elif [ "$1" == "commit" ]
then
    git add --all
    git commit -m "$2" -a
    git push 
fi
