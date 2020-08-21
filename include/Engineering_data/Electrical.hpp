#ifndef ELECTRICAL                      
#define ELECTRICAL

#include<string>

using namespace std;

namespace Engineering 
{
    namespace electrical
        {
            //based on 2
            string material[] = {
                                "air"
                                ,"Aluminium"
                                ,"Annealed copper"
                                ,"Calcium"
                                ,"Carbon (amorphous)"
                                ,"diamond"
                                ,"graphite"
                                ,"Carbon steel"
                                ,"Cobalt"
                                ,"Constantan"
                                ,"Copper"
                                ,"Deionized water"
                                ,"Drinking water"
                                ,"Fused quartz"
                                ,"Gallium arsenide"
                                ,"Galinstan"
                                ,"Gallium"
                                ,"Germanium"
                                ,"Glass"
                                ,"Gold"
                                ,"Grain oriented electrical steel"
                                ,"Hard rubber"
                                ,"Iron"
                                ,"Lead"
                                ,"Lithium"
                                ,"Manganese"
                                ,"Manganin"
                                ,"Mercury"
                                ,"Nichrome"
                                ,"Nickel"
                                ,"Niobium"
                                ,"Polyethylene terephthalate"
                                ,"Platinum"
                                ,"Ruthenium"
                                ,"Sea water"
                                ,"Silicon"
                                ,"Silver"   
                                ,"Stainless steel"
                                ,"Sulfur"
                                ,"Swimming pool water ph 8.4"
                                ,"Teflon"
                                ,"Tin"
                                ,"Titanium"
                                ,"Tungsten"
                                ,"Wood (damp)"
                                ,"Wood (oven dry)"
                                ,"Zinc"
                                };
            //Ohms Per Meter
            long double resistivity[] = {
                                
                                1000000000000//10^12
                                ,0.0000000265//2.65*10^-8
                                ,//1.72×10^−8
                                ,//3.36×10^−8
                                ,//6.5×10^−4
                                ,//10^12
                                ,//3.75*10^-6
                                ,3×10^−3
                                ,1.43×10^−7
                                ,6.24×10^−8
                                ,4.90×10^−7
                                ,1.68×10^−8
                                ,1.8×10^5
                                ,2*10^2
                                ,7.5×10^17
                                ,10^2.5
                                ,2.89×10−7
                                ,1.40×10−7
                                ,4.6×10−1
                                ,10^13
                                ,2.44×10−8
                                ,4.60×10−7
                                ,10^13
                                ,9.70×10−8
                                ,2.20×10−7
                                ,9.28×10−8
                                ,1.44×10−6
                                ,4.82×10−7
                                ,9.80×10−7
                                ,1.10×10−6
                                ,6.99×10−8
                                ,1.40×10−7 
                                ,10^21
                                ,1.06×10−7
                                ,7.10×10−8
                                ,2.0×10−1
                                ,2.3×10^3
                                ,1.59×10−8
                                ,6.90×10−7
                                ,10^15   
                                ,3.65*10^-1
                                ,10^24
                                ,1.09×10−7
                                ,4.20×10−7
                                ,5.60×10−8
                                ,10^4
                                ,10^15
                                ,5.90×10−8
            };
            long double conductivity[] = {};
            void search_resistivity()
            {

            };
        }
}

#endif