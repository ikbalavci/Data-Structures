/**       
* @file  Gen.cpp
* @description Projedeki tüm bağlı listelerin düğümleri burada tanımlanır
* @course  1.Öğretim A Grubu
* @assignment  1.Ödev
* @date  26.11.2024
* @author  Mustafa İkbal Avcı ikbal.avci@ogr.sakarya.edu.tr
*/ 
#include "Gen.hpp"

Gen::Gen(char veri)
{
    this->veri = veri;

    onceki = sonraki = nullptr;
}
Gen::~Gen(){}