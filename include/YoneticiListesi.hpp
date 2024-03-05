#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include <iostream>

#include "SatirListesi.hpp"
#include "YoneticiNode.hpp"
#include <stdlib.h>     
#include <time.h>      
#include "GoTo.hpp"

class YoneticiListesi {
private:
    YoneticiNode *head;
    int size;

    YoneticiNode* FindPreviousByPosition(int index);

    YoneticiNode* FindPosition(int index);

public:

    YoneticiListesi();
    int Count()const;
    bool isEmpty()const;
	int indexOf(SatirListesi*& item);
    void add(SatirListesi*& item);
    void insert(int index, SatirListesi*& item); 
    void remove(SatirListesi*& item);
	void removeAt(int index);
    void randFrmSatirList(int index, int rnd);
	SatirListesi*& elementAt(int index);
    void calculateAveragee(int index);
	void sortByAverage();
	void exchange(int first, int second);
	void clear();
	int randomGenerator(int index);
    void printIndex(int index, int x, int y);
    ~YoneticiListesi();

};


#endif 
