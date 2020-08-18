//This AI is incharge of the titan platforms and the space elevator in project TITAN
//build raven_come_skykru
//Check for C++ Compiler
#ifndef __cplusplus
	#error A C++ compiler is required!
#endif
#ifdef __clang__
	#error Raven will not compile with clang,please use gcc
#endif
#include<iostream>
#include<sstream>
#include<fstream>
#include<istream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<cassert>
#include<cstdio>
//for date & time
#include<ctime>
#if defined(WIN32) || defined(__CYGWIN32__) 
    #include<direct.h>
#else
	#include<sys/time.h>
#endif
#include<time.h>
//for sleep fuction
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<conio.h>
    #include<windows.h>
#endif
#include<unistd.h>
//For getch(),linux
#ifdef __linux__
    #include<termios.h>
#endif
//C libs to use system function
#include<stdio.h>
#include<stdlib.h>
//mp3 libs
#include "include/MP3.h"
//Downloading
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<wininet.h>
    #include "include/download.h"
#else
    #include<arpa/inet.h>
#endif
#include<curl/curl.h>
//UUID Generaterion
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
//Tesseract-OCR
#include<tesseract/baseapi.h>
//#include<leptonica/allheaders.h>
//Threading
#include<limits.h>
#include<boost/thread.hpp>
#include<boost/chrono.hpp>
#include<boost/atomic.hpp>
#include<boost/bind.hpp>
#ifdef __linux__
   #include<pthread.h>
#endif
//Internet Connectivity 
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<winsock2.h>
    #include<WinSock.h>
    #include<ws2tcpip.h>
#else
    #include<sys/socket.h>
    #include<sys/types.h>
    #include<netinet/in.h>
    #include<netdb.h>
    #include<arpa/inet.h>
    #include<unistd.h>
#endif
//Serial Connection
#include "SerialPort.h"
//MYSQL database
#if defined(WIN32) || defined(__CYGWIN32__)
	#include<cppconn/driver.h>
	#include<cppconn/exception.h>
	#include<cppconn/resultset.h>
	#include<cppconn/statement.h>
#elif __APPLE__
	#include<jdbc/cppconn/driver.h>
	#include<jdbc/cppconn/exception.h>
	#include<jdbc/cppconn/resultset.h>
	#include<jdbc/cppconn/statement.h>
#elif __linux__ 
	#ifdef __arm__
		#include<jdbc/cppconn/driver.h>
		#include<jdbc/cppconn/exception.h>
		#include<jdbc/cppconn/resultset.h>
		#include<jdbc/cppconn/statement.h>
	#else	
		#include<cppconn/driver.h>
		#include<cppconn/exception.h>
		#include<cppconn/resultset.h>
		#include<cppconn/statement.h>
	#endif
#endif
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<mysql.h>
#else
    #include<mysql/mysql.h>
#endif
#include<sqlite3.h> 
//Video and Image Displaying
#include<opencv2/highgui/highgui.hpp>
#include<opencv/cv.h>
#include<opencv/highgui.h>
//Neural Net
/*
#include<Neuron.h>
#include<Network.h>
*/
#include <chrono>
//For Voice Recognition and Voice Synthesis
#include<sphinxbase/err.h>
#include<sphinxbase/ad.h>
#include<pocketsphinx/pocketsphinx.h>
#if __linux__
    #include<sys/select.h>
#endif
//Titan Robotics Lib
#include "Titans.h"

//Parameters
#pragma comment(lib, "wsock32.lib")

using namespace std;
using namespace mp3;

//functions
string encrypt(string msg, string const& key)
{
    if(!key.size())
        return msg;
    
    for (string::size_type i = 0; i < msg.size(); ++i)
        msg[i] ^= key[i%key.size()];
    return msg;
}

string decrypt(string const& msg, string const& key)
{
    return encrypt(msg, key); 
}

//constants
const char* MONTHS[] =
  {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
  };

//for mp3 output
char Key;

//Prototypes
void server();
void client();
void debug();

//global variables
int pins_dead[22];
int pins[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};

//Thread Group
boost::thread_group tgroup;

int frequency_of_primes(int n)
{
  int i,j;
  int freq = n - 1;
  for(i = 2;i <= n;++i)
    {
      for(j = sqrt(i);j > 1;--j)
        {
          if (i%j == 0)
            {
                --freq;
                break;
            }
        }
    }
  return freq;
}

void test()
{
    loop:
        clock_t t;
        int f;
        t = clock();
        f = frequency_of_primes(99999);
        t = clock() - t;
        if(t > 500)
            {
                cout << t << endl;
                cout << "I am taking too long to calculate" << endl;
            }
        else
            {
                goto loop;
            }
}

void connect_to_mega(string pinset)
{
    char output[MAX_DATA_LENGTH];
    //Portname must contain these backslashes, and remember to replace the following com port
    char *port_name = "\\\\.\\COM20";
    char incomingData[MAX_DATA_LENGTH];

    SerialPort arduino(port_name);
    
    if (arduino.isConnected())
        cout << "Connection Established" << endl;
        continue;
    else
        return 0;
    
    while (arduino.isConnected())
        {
            string input_string;
            input_string = pinset;
            char *c_string = new char[input_string.size() + 1];
            copy(input_string.begin(), input_string.end(), c_string);
            c_string[input_string.size()] = '\n';
            arduino.writeSerialPort(c_string, MAX_DATA_LENGTH);
            arduino.readSerialPort(output, MAX_DATA_LENGTH);
            if(output == "GOOD")
                {

                    #ifdef DEBUG
                        cout << "ok" << endl;
                    #endif
                }
            if(output == "BAD")
                {
                    int del;
                    int size = (sizeof(pins)/sizeof(*pins));
                    pinset = del;
                    for(int i = 0; i < size; i++)
                        {
                        	if(pins[i] == del)
                            	{
                            		for(int j = i; j < (size-1); j++)
                                		{
                                			pins[j] = pins[j + 1];
                                		}
                            		break;
                            	}
                        }
                }
            delete[] c_string;
        }
}

int main()
{
    //get date variables
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);   
    
    string envir;
    clock_t start;
    double duration;
    start = clock();
	tgroup.create_thread(boost::bind(test));
    system("color 02");
    cout << "I am Raven" << endl;
    PlayMP3("voice/greedings.mp3");
    sleep(4);
    StopMP3("voice/greedings.mp3");
    loop:
        cout << "I am the Chief Mechanic on Project TITAN" << endl;
        // output current date
        cout << "Today's date is " << timeinfo->tm_mday << " " << MONTHS[ timeinfo->tm_mon ] << " " << (timeinfo->tm_year + 1900) << endl;
        cout << "Where will I be Operating?" << endl;
        cout << "1)Titan Platform" << endl;
        cout << "2)Space Elevator" << endl;    
    cin >> envir;
    if(envir == "dia")
        {
            test();
            goto loop;
        }
    if(envir == "uptime")
        {
            duration = (clock() - start)/(double)CLOCKS_PER_SEC;
            cout << "It has been " << duration << " that I have been awake" << endl;
            goto loop;
        }
    if(envir == "1")
        {
            string plat;
            cout << "Which Platform will I be Operating On?" << endl;
            cin >> plat;
//There will be Ten Total Platforms
            if(plat == "1", "2", "3", "4", "5", "6", "7", "8", "9", "10")
                {
            
                }
        } 
          
    if(envir == "2")
        {
            string dia;
            cout << "Must I start a Diagnostic?" << endl;
            cin >> dia; 
            if(dia == "yes")
                {
            
                }
            if(dia == "no")
                {
                  
                }
        }
    if(envir != "1", "2")
        {
            string what; 
            cout << "Then,what do you want me to do?" << endl;
            cin >> what;
            if(what == "kill", "Kill", "KILL")
                {
                    cout << "I can not!!" << endl;
                    sleep(25);            
                    main();
                }
            if(what == "Destroy Network", "DESTROY NETWORK", "DESTROYNETWORK", "destroynetwork", "destory network", "Destroy_Network", "DESTROY_NETWORK", "destory_network")
                {
                    cout << "I will not!!" << endl;
                    sleep(25);            
                    main();
                }
            if(what == "Destroy Titans", "DESTROYTITANS", "DESTROY TITAN", "destroy titans", "Destroy_Titans", "DESTROY_TITAN", "destroy_titans")
                {
                    cout << "We can not!!" << endl;
                    sleep(25);
                    main();
                }
            if(what != "Destroy Network", "DESTROY NETWORK", "DESTROYNETWORK", "destroynetwork", "destory network", "Destroy_Network", "DESTROY_NETWORK", "destory_network",  "Destroy Titans", "DESTROYTITANS", "DESTROY TITAN", "destroy titans", "Destroy_Titans", "DESTROY_TITAN", "destroy_titans", "kill", "Kill", "KILL")
                {
                    main();
                }
        }
}