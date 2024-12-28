/**       
* @file  Genom.cpp
* @description Genom sınıfındaki kurucu, yıkıcı ve diğer fonksiyonların gövdelerini içerir.
* @course  1.Öğretim A Grubu
* @assignment  1.Ödev
* @date  26.11.2024
* @author  Mustafa İkbal Avcı ikbal.avci@ogr.sakarya.edu.tr
*/ 
#include "Genom.hpp"
#include "Kromozom.hpp"

Genom::Genom() {
    ilk = nullptr;
}

Genom::~Genom() {
    Kromozom* gec = ilk;
    while (gec != nullptr) {
        Kromozom* silinecek = gec;
        gec = gec->sonraki;
        delete silinecek;
    }
}


void Genom::ekle(Liste* liste) {
    Kromozom* yeniDugum = new Kromozom(liste);
    if (ilk == nullptr) {
        ilk = yeniDugum;
    } else {
        Kromozom* gec = ilk;
        while (gec->sonraki != nullptr) {
            gec = gec->sonraki;
        }
        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
    }
}

void Genom::yazdir() {
    Kromozom* gec = ilk;
    while (gec != nullptr) {
        char yazdirilacak = gec->liste->sondanBaslaVeKucukBul();
        std::cout << yazdirilacak << " ";
        gec = gec->sonraki;
    }
    std::cout << std::endl;
}


ostream& operator<<(ostream& os, Genom& genom) {
    os << "Genom icerigi:" << endl;
    Kromozom* gec = genom.ilk;
    int index = 1;

    while (gec != nullptr) {
        os << *(gec->liste) << endl;
        gec = gec->sonraki;
    }

    return os;
}
