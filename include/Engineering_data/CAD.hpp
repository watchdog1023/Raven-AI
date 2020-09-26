#ifndef CAD                      
#define CAD

#include<string>
#include<iostream>
#include<fstream>
#include<streambuf>
#ifdef __cplusplus 201402L //C++14
    #include<experimental/filesystem>
#elif __cplusplus 201703L //C++17
    #include<filesystem>
#else
    #error PLease use a c++14 compatiable version of gcc
#endif

/*ID's
Raven 927264789071546705596889147393451300315962
Lexa 013571928672522052260658578708747375146140
Lara 371255035946132864459227962310701892488529
Ciri 164059234287267698811552356795217783210005
*/

using namespace std;

namespace CAD
{
    namespace 
        {
            void check_watermark()
                {
                    
                }
        }
    bool exist;
    void CAD_Open(string filename)
        {
            if(filename.substr(filename.find_last_of(".") + 1) == "scad") 
                {
                    #ifdef __cplusplus 201402L 
                        exist = std::experimental::filesystem::exists(filename);
                    #elif __cplusplus 201703L 
                        exist = std::filesystem::exists(filename);
                    #else
                        #error PLease use a c++14 compatiable version of gcc
                    #endif
                } 
            else 
                {
                    #ifdef DEBUG
                        std::cout << "No...Just No!" << std::endl;
                        std::cout << "Wrong File Format,please use a scad format" << std::endl;
                    #endif
                }
            
        }
    void add_scad_file(string project_name,string import_name)
        {
            std::ifstream t(project_name);
            if(exist)
                {
                    string contents_old((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());
                    ofstream new_file(project_name);
                    if (new_file.is_open())
                        {
                            new_file << "include <"+ import_name +".scad>";
                            new_file << contents_old;
                            new_file.close();
                        }
                }
        }

}

#endif