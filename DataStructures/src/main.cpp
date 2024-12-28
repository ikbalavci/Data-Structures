/**       
* @file  main.cpp
* @description  main fonksiyonu ve içerisinde menu'de kullanılan fonksiyon gövdelerini de bulunduruyor.Dosya açma ve okuma işlemleri de burada gerçekleştiriliyor.
* @course  1.Öğretim A Grubu
* @assignment  1.Ödev
* @date  26.11.2024
* @author  Mustafa İkbal Avcı ikbal.avci@ogr.sakarya.edu.tr
*/ 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Liste.hpp"
#include "Genom.hpp"
#include "Kromozom.hpp"


using namespace std;


int sayisalGirdiAl(const string& mesaj) {
    string girdi;
    while (true) {
        cout << mesaj;
        cin >> girdi;

        bool sayiMi = true;
        for (char ch : girdi) {
            if (!isdigit(ch)) {
                sayiMi = false; 
                break;
            }
        }

        if (sayiMi) {
            return stoi(girdi);
        } else {
            cout << "Gecersiz girdi! Lutfen sadece sayi giriniz." << endl;
        }
    }
}

void caprazlama(Genom& genom) {
    int satir1 = sayisalGirdiAl("Birinci kromozomun satir numarasini giriniz: ");
    int satir2 = sayisalGirdiAl("Ikinci kromozomun satir numarasini giriniz: ");

    Kromozom* kromozom1 = genom.kromozomGetir(satir1);
    Kromozom* kromozom2 = genom.kromozomGetir(satir2);

    if (kromozom1 == nullptr || kromozom2 == nullptr) {
        cout << "Gecersiz kromozom numaralari! Islem iptal edildi." << endl;
        return;
    }

    Liste* liste1 = kromozom1->liste;
    Liste* liste2 = kromozom2->liste;

    int boyut1 = liste1->boyut();
    int boyut2 = liste2->boyut();

    int orta1 = boyut1 / 2;
    int orta2 = boyut2 / 2;

    Liste* yeni1 = new Liste();
    Liste* yeni2 = new Liste();

    for (int i = 0; i < orta1; i++) {
        yeni1->ekle(liste1->dugumGetir(i)->veri);
    }
    for (int i = (boyut2 % 2 == 0 ? orta2 : orta2 + 1); i < boyut2; i++) {
        yeni1->ekle(liste2->dugumGetir(i)->veri);
    }

    for (int i = (boyut1 % 2 == 0 ? orta1 : orta1 + 1); i < boyut1; i++) {
        yeni2->ekle(liste1->dugumGetir(i)->veri);
    }
    for (int i = 0; i < orta2; i++) {
        yeni2->ekle(liste2->dugumGetir(i)->veri);
    }

    genom.ekle(yeni1);
    genom.ekle(yeni2);

    cout << "Caprazlama islemi tamamlandi ve yeni kromozomlar Genom'a eklendi." << endl;
}

void mutasyon(Genom& genom) {
    int satir = sayisalGirdiAl("Mutasyona ugratmak istediginiz kromozomun satir numarasini giriniz: ");
    int sutun = sayisalGirdiAl("Mutasyona ugratmak istediginiz genin sutun numarasini giriniz: ");


    Kromozom* kromozom = genom.kromozomGetir(satir);

    if (kromozom == nullptr) {
        cout << "Gecersiz kromozom numarasi! Islem iptal edildi." << endl;
        return;
    }

    Liste* liste = kromozom->liste;

    if (sutun < 0 || sutun >= liste->boyut()) {
        cout << "Gecersiz gen sutun numarasi! Islem iptal edildi." << endl;
        return;
    }

    Gen* gen = liste->dugumGetir(sutun);
    gen->veri = 'X';

    cout << "Mutasyon islemi tamamlandi. Genom guncellendi." << endl;
}



void otomatikIslemler(Genom& genom) {
    ifstream dosya("Islemler.txt");
    if (!dosya.is_open()) {
        cout << "Islemler.txt dosyasi acilamadi!" << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir)) {
        if (satir.empty()) continue;

        char islemTipi;
        int param1, param2;
        stringstream ss(satir);
        ss >> islemTipi >> param1 >> param2;

        if (islemTipi == 'C') {
            Kromozom* kromozom1 = genom.kromozomGetir(param1);
            Kromozom* kromozom2 = genom.kromozomGetir(param2);
            if (kromozom1 && kromozom2) {
                Liste* liste1 = kromozom1->liste;
                Liste* liste2 = kromozom2->liste;

                int boyut1 = liste1->boyut();
                int boyut2 = liste2->boyut();

                int orta1 = boyut1 / 2;
                int orta2 = boyut2 / 2;

                Liste* yeni1 = new Liste();
                Liste* yeni2 = new Liste();

                for (int i = 0; i < orta1; i++) {
                    yeni1->ekle(liste1->dugumGetir(i)->veri);
                }
                for (int i = (boyut2 % 2 == 0 ? orta2 : orta2 + 1); i < boyut2; i++) {
                    yeni1->ekle(liste2->dugumGetir(i)->veri);
                }

                for (int i = (boyut1 % 2 == 0 ? orta1 : orta1 + 1); i < boyut1; i++) {
                    yeni2->ekle(liste1->dugumGetir(i)->veri);
                }
                for (int i = 0; i < orta2; i++) {
                    yeni2->ekle(liste2->dugumGetir(i)->veri);
                }

                genom.ekle(yeni1);
                genom.ekle(yeni2);
            } else {
                cout << "Caprazlama icin gecersiz satir numaralari!" << endl;
            }
        } else if (islemTipi == 'M') {
            Kromozom* kromozom = genom.kromozomGetir(param1);
            if (kromozom) {
                Liste* liste = kromozom->liste;
                Gen* gen = liste->dugumGetir(param2);
                if (gen) {
                    gen->veri = 'X'; 
                } else {
                    cout << "Mutasyon icin gecersiz gen sutun numarasi!" << endl;
                }
            } else {
                cout << "Mutasyon icin gecersiz kromozom satir numarasi!" << endl;
            }
        } else {
            cout << "Gecersiz islem tipi: " << islemTipi << endl;
        }
    }

    dosya.close();
    cout << "Otomatik islemler tamamlandi." << endl;
}


void menu() {
    cout << "\n============== Menu ==============" << endl;
    cout << "1- Caprazlama" << endl;
    cout << "2- Mutasyon" << endl;
    cout << "3- Otomatik Islemler" << endl;
    cout << "4- Ekrana Yaz" << endl;
    cout << "5- Cikis" << endl;
    cout << "Seciminizi yapiniz: ";
}

int main() {
    ifstream file("Dna.txt");
    if (!file.is_open()) {
        cout << "Dna.txt dosyasi acilamadi!" << endl;
        return 1;
    } 

    Genom genom; 

    string line;
    while (getline(file, line)) {
        Liste* liste = new Liste();
        stringstream ss(line);
        char karakter;
        while (ss >> karakter) {
            liste->ekle(karakter); 
        }
        genom.ekle(liste); 
    }

    file.close();

    int secim = 0;

    do {
        menu();
        secim = sayisalGirdiAl("");

        switch (secim) {
            case 1:
                caprazlama(genom);
                break;
            case 2:
                mutasyon(genom);
                break;
            case 3:
                otomatikIslemler(genom);
                break;
            case 4:
                cout << "Genom icerigi ekrana yaziliyor:" << endl;
                genom.yazdir();
                break;
            case 5:
                cout << "Cikis yapiliyor..." << endl;
                break;
            default:
                cout << "Gecersiz secim! Lutfen tekrar deneyiniz." << endl;
                break;
        }
    } while (secim != 5);

    return 0;
}