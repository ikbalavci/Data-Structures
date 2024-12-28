/**       
* @file  Liste.cpp
* @description  Genleri tutan Kromozom ve Kromozomları tutan Genom Bağlı listelerindeki fonksiyonları tanımlar
* @course  1.Öğretim A Grubu
* @assignment  1.Ödev
* @date  26.11.2024
* @author  Mustafa İkbal Avcı ikbal.avci@ogr.sakarya.edu.tr
*/ 
#include "Liste.hpp"
#include<iomanip>

using namespace std;

Liste::Liste()
{
    ilk=nullptr;
};
Liste::~Liste()
{
    Gen* gec=ilk;
    while(gec!=nullptr)
    {
        Gen* silinecek = gec;
        gec=gec->sonraki;

        delete silinecek;
    }
    ilk = nullptr;
}
void Liste::ekle(char veri)
{
    Gen* yeniDugum = new Gen(veri);
    if(ilk==nullptr){
        ilk = yeniDugum;
    }
    else{
        Gen* gec = ilk;

        while(gec->sonraki!=nullptr){
            gec = gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki=gec;
    }
}


Gen* Liste::dugumGetir(int sira)
{
    Gen* gec =ilk;

    while(sira>=0 && gec!=nullptr)
    {
        if(sira==0)
            return gec;
        gec=gec->sonraki;

        sira--;
    }
    return 0;

}

char Liste::sondanBaslaVeKucukBul() {
    Gen* gec = ilk;

    if (gec == nullptr) {
        return '\0'; 
    }

    while (gec->sonraki != nullptr) {
        gec = gec->sonraki;
    }

    Gen* kontrol = gec;
    while (kontrol != nullptr) {
        if (kontrol->veri < ilk->veri) {
            return kontrol->veri;
        }
        kontrol = kontrol->onceki;
    }

    return ilk->veri;
}

int Liste::boyut() {
    int sayac = 0;
    Gen* gec = ilk; 
    while (gec != nullptr) {
        sayac++;
        gec = gec->sonraki;
    }
    return sayac; 
}

ostream& operator<<(ostream& os, Liste& liste)
{
Gen* gec = liste.ilk;

while(gec!=nullptr){
    os << gec->veri <<" " ;
    gec=gec->sonraki;
}
return os;
}