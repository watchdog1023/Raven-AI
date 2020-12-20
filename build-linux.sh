if [ $GITPOD == "YES" ]; then
    mkdir assets/
    mkdir assets/usr/
    mkdir assets/usr/local/
fi
if [ ! -e mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/ ]; then
    wget -c https://dev.mysql.com/get/Downloads/Connector-C++/mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz
    tar xf mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit.tar.gz
    cp -vr mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/jdbc/* mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/include/
    cp -vr mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/lib64/ mysql-connector-c++-8.0.16-linux-glibc2.12-x86-64bit/lib/
    if [ $GITPOD == "YES" ]; then
        cp -vr mysql-*/* /workspace/Raven-AI/assets/usr/local/
    else
        cp -vr mysql-*/* assets/usr/local/
    fi
else
    cp -vr mysql-*/* assets/usr/local/
fi
if [ ! -e opencv-3.4.3/ ]; then 
    wget -c https://github.com/opencv/opencv/archive/3.4.3.zip
    wget -c https://github.com/opencv/opencv_contrib/archive/3.4.3.zip -O contrib-343.zip
    unzip -qq 3.4.3.zip
    unzip -qq contrib-343.zip
    cd opencv-3.4.3/
    mv -vf ../opencv_contrib-3.4.3/* .
    mkdir build
    cd build
    cmake -quiet ..
    make -j4
    if [ $GITPOD == "YES" ]; then
        make install DESTDIR="/workspace/Raven-AI/assets/"
    else
       sudo make install
    fi
      cd ../..
else
    if [ "$(ls -A opencv-3.4.3/)" ]; then
        cd opencv-3.4.3/
        cd build
        if [ $GITPOD == "YES" ]; then
           make install DESTDIR="/workspace/Raven-AI/assets/"
        else
           sudo make install
        fi
            cd ../..
    else
        wget -c https://github.com/opencv/opencv/archive/3.4.3.zip
        wget -c https://github.com/opencv/opencv_contrib/archive/3.4.3.zip -O contrib-343.zip
        unzip -qq 3.4.3.zip
        unzip -qq contrib-343.zip
        cd opencv-3.4.3/
        mv -v ../opencv_contrib-3.4.3/* .
        mkdir build
        cd build
        cmake -quiet ..
        make -j4
        if [ $GITPOD == "YES" ]; then
            make install DESTDIR="/workspace/Raven-AI/assets/"
        else
           sudo make install
        fi
        cd ../..
    fi
fi
sudo apt-get install libboost-all-dev libsfml-dev libtesseract-dev

g++ -v -Iinclude/ -Iassets/usr/local/include -I/usr/local/include/pocketsphinx/ -I/usr/local/include/sphinxbase -c Raven.cpp  -fpermissive -Wfatal-errors
