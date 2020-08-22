#ifndef ELECTRICAL                      
#define ELECTRICAL

#include "Engineering.hpp"

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
                                ,0,0000000172//1.72*10^−8
                                ,0.0000000336//3.36*10^−8
                                ,0.00065//6.5*10^−4
                                ,1000000000000//10^12
                                ,0.00000375//3.75*10^-6
                                ,0.003//3*10^−3
                                ,0.000000143//1.43*10^−7
                                ,0.0000000624//6.24*10^−8
                                ,0.000000490//4.90*10^−7
                                ,0.0000000168//1.68*10^−8
                                ,180000//1.8*10^5
                                ,200//2*10^2
                                ,750000000000000000//7.5×10^17
                                ,1000//10^3
                                ,0.000000289//2.89×10−7
                                ,0.000000140//1.40×10−7
                                ,0.46//4.6×10−1
                                ,10000000000000//10^13
                                ,0.0000000244//2.44×10−8
                                ,0.00000046//4.60×10−7
                                ,10000000000000//10^13
                                ,0.000000097//9.70×10−8
                                ,0.00000022//2.20×10−7
                                ,0.0000000928//9.28×10−8
                                ,0.00000144//1.44×10−6
                                ,0.000000482//4.82×10−7
                                ,0.00000098//9.80×10−7
                                ,0.0000011//1.10×10−6
                                ,0.0000000699//6.99×10−8
                                ,0.00000014//1.40×10−7 
                                ,1000000000000000000000//10^21
                                ,0.000000106//1.06×10−7
                                ,0.000000071//7.10×10−8
                                ,0.2//2.0×10−1
                                ,2300//2.3×10^3
                                ,0.0000000159//1.59×10−8
                                ,0.00000069//6.90×10−7
                                ,1000000000000000//10^15   
                                ,0.365//3.65*10^-1
                                ,1000000000000000000000000//10^24
                                ,0.000000109//1.09×10−7
                                ,0.00000042//4.20×10−7
                                ,0.000000056//5.60×10−8
                                ,10000//10^4
                                ,1000000000000000//10^15
                                ,0.000000059//5.90×10−8
            };
            long double conductivity[] = {};
            void search_resistivity()
            {

            };
        }
}

#endif