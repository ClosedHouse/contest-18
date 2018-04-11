#!/bin/bash

if [[ $UID != 0 ]]; then
    echo 'you need root!'
    exit 1
fi

pushd /home/oh/
echo -n > .bash_history
rm -rf ./contest-18
git clone https://github.com/ClosedHouse/contest-18.git
chmod -R o-rx ./contest-18
chmod o+rx ./contest-18
chmod -R o-rx ./contest-18/.git/
chmod -R o+rx ./contest-18/0/
chmod -R o+x ./contest-18/contrib
chmod -R o+x ./contest-18/contrib/*
chmod o+r ./contest-18/contrib/next-level
        pushd contest-18/2
        make cool-app
        make cool-app-old
        rm -rf cool-app.c
        rm -rf cool-app-old.c
        popd
popd
