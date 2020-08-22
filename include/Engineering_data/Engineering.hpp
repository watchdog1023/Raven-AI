#ifndef ENGINEERING                      
#define ENGINEERING

#include<string>
//SQLite3
#include<sqlite3.h>

//Enigneering Namespace Delcartions
#include "Electrical.hpp"

using namespace std;

namespace Engineering 
{
    //Delcartions
    namespace electrical;

    //Engineering Functions
    void C_2_K(float c)
        {
            float k;
            k = c + 273.15;
            return k; 
        }
    void F_2_K(float f)
        {
            float k;
            k = (f - 32) * (5/9) + 273.15;
            return k; 
        }
}
#endif