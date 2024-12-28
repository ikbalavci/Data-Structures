/**       
* @file  Liste.hpp
* @description Liste sınıfının fonksiyonları ve propertyleri tanımlanmıştır
* @course  1.Öğretim A Grubu
* @assignment  1.Ödev
* @date  26.11.2024
* @author  Mustafa İkbal Avcı ikbal.avci@ogr.sakarya.edu.tr
*/ 
#ifndef Liste_hpp
#define Liste_hpp
#include<exception>
#include<iostream>
#include "Gen.hpp"

using namespace std;

class Liste
{
public:
    Liste();
    ~Liste();
    void ekle(char veri);
    int boyut();
    char sondanBaslaVeKucukBul();

    friend ostream& operator<<(ostream& os,Liste& liste);

    Gen* dugumGetir (int sira);
private:
    
    Gen* ilk;
};

#endif