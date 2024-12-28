/**       
* @file  Kromozom.cpp
* @description Genom sınıfındaki kurucu, yıkıcı ve kromozomu getiren fonksiyonların gövdelerini içerir.
* @course  1.Öğretim A Grubu
* @assignment  1.Ödev
* @date  26.11.2024
* @author  Mustafa İkbal Avcı ikbal.avci@ogr.sakarya.edu.tr
*/ 
#include "Genom.hpp"
#include "Kromozom.hpp"


Kromozom::Kromozom(Liste* liste) {
    this->liste = liste;
    onceki = sonraki = nullptr;
}

Kromozom::~Kromozom() {
    delete liste; 
}

Kromozom* Genom::kromozomGetir(int index) {
    Kromozom* gec = ilk;
    int sayac = 0;
    while (gec != nullptr) {
        if (sayac == index) {
            return gec; 
        }
        gec = gec->sonraki; 
        sayac++;
    }
    return nullptr; 
}

