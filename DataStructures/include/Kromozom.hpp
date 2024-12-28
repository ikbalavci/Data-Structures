/**       
* @file  Kromozom.hpp
* @description Kromozom sınıfının fonksiyon imzaları burada bulunur
* @course  1.Öğretim A Grubu
* @assignment  1.Ödev
* @date  26.11.2024
* @author  Mustafa İkbal Avcı ikbal.avci@ogr.sakarya.edu.tr
*/ 
#ifndef Kromozom_hpp
#define Kromozom_hpp
#include "Liste.hpp"

class Kromozom {
public:
    Kromozom(Liste* liste);
    ~Kromozom();

    Liste* liste;     
    Kromozom* onceki;   
    Kromozom* sonraki;  
};

#endif