#ifndef YONETICINODE_HPP
#define YONETICINODE_HPP


#include "SatirListesi.hpp"

class YoneticiNode {
public:
    SatirListesi* data;
    double average;
    YoneticiNode *next;
    YoneticiNode *prev;

    YoneticiNode(SatirListesi* data, YoneticiNode *next, YoneticiNode *prev);
    YoneticiNode(SatirListesi* data, YoneticiNode *next);
    YoneticiNode(SatirListesi* data);
    double calculateAverage();
};


#endif 