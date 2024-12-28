/**       
* @file  Gen.hpp
* @description Gen sınıfının fonksiyonları ve propertyleri tanımlanmıştır.
* @course  1.Öğretim A Grubu
* @assignment  1.Ödev
* @date  26.11.2024
* @author  Mustafa İkbal Avcı ikbal.avci@ogr.sakarya.edu.tr
*/ 
#ifndef Gen_hpp
#define Gen_hpp

class Gen
{
public:
Gen(char veri);
~Gen();
char veri;
Gen* onceki;
Gen* sonraki;
};

#endif