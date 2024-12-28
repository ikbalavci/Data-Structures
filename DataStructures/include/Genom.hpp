/**       
* @file  Genom.hpp
* @description Genom sınıfının fonksiyon imzaları burada bulunur
* @course  1.Öğretim A Grubu
* @assignment  1.Ödev
* @date  26.11.2024
* @author  Mustafa İkbal Avcı ikbal.avci@ogr.sakarya.edu.tr
*/ 
#ifndef Genom_hpp
#define Genom_hpp
#include "Liste.hpp"
#include "Kromozom.hpp"
#include <iostream>
using namespace std;

class Genom {
public:
    Genom();
    ~Genom();
    void ekle(Liste* liste); 
    Kromozom* kromozomGetir(int index); 
    friend ostream& operator<<(ostream& os, Genom& genom);
    void yazdir();
private:
    Kromozom* ilk; 
};

#endif