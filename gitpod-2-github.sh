#!/bin/bash
#cleaning the source tree
rm -vr opencv-3.4.3/
rm -vr opencv_contrib-3.4.3/
rm -vr 3.4.3.zip
rm -vr contrib-343.zip
rm -vr mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit*
yes | rm -vr assets/
rm -vr data/obj_detect/
rm -vr *.o
if [ -e raven-alive ]; then
    rm -vr raven-alive
fi
if [ -e raven ]; then
    rm -vr raven  
fi
#rm -vr data/
rm -vr RavenB.txt RavenC.txt
clear
echo "Ready to push!"