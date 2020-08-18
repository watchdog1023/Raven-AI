FROM gitpod/workspace-full

USER root
RUN apt update
RUN apt upgrade -y
#Grabbing Deps
RUN apt-get install libmpich-dev python3 python3-pip build-essential make swig libboost-all-dev libsfml-dev libtesseract-dev bash splint shellcheck -y
#get packager
RUN pip3 install cpplint requests
#Grabbing Titan Robotics repo Deps
RUN wget -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/jsoncpp_3.13.2-1_amd64.deb
RUN wget -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/libtitan_1-1_amd64.deb
RUN wget -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/sphinxbase_5prealpha-1_amd64.deb
RUN wget -c https://sourceforge.net/projects/titan-robotics/files/AI/Deps/Debian%28Deb%29/pocketsphinx_5prealpha-1_amd64.deb
#Installing Debs
RUN dpkg -i jsoncpp_3.13.2-1_amd64.deb
RUN dpkg -i libtitan_1-1_amd64.deb
RUN dpkg -i sphinxbase_5prealpha-1_amd64.deb
RUN dpkg -i pocketsphinx_5prealpha-1_amd64.deb
#Cleaning
RUN apt-get clean
RUN rm *.deb
USER gitpod

# Install custom tools, runtimes, etc.
# For example "bastet", a command-line tetris clone:
# RUN brew install bastet
#
# More information: https://www.gitpod.io/docs/config-docker/
