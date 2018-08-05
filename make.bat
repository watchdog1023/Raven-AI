@echo off
g++ -v -fpermissive -Wwrite-strings -Iinclude -c Raven.cpp -o Raven.o
PAUSE
windres icon.rc icon.o
g++ -v -time -c include\SerialPort.cpp -o SerialPort.o -Wfatal-errors
g++ -v -static -static-libgcc -static-libstdc++ -I ../../headers/ -o Raven.exe SerialPort.o Raven.o icon.o -lcrypt32 -lws2_32 -ldnsapi -lwinmm -lwininet -lopencv_core340.dll -lopencv_highgui340.dll -lboost_system -lboost_serialization -lboost_atomic -lboost_chrono -lboost_thread
PAUSE
rm -v *.o