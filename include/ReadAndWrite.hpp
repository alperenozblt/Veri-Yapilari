#ifndef READANDWRITE_HPP
#define READANDWRITE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
using namespace std;
class ReadAndWrite {
private:
    string fileName;
    int rowSay();
    SatirListesi **rows;
    void readLine();
public:
    ReadAndWrite(string);
    ~ReadAndWrite();
    YoneticiListesi* WriteYoneticiListesi();
};

#endif 