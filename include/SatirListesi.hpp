#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP
#include "SatirListesiNode.hpp"
#include "GoTo.hpp"

#include <iomanip>

class SatirListesi {
private:
    SatirListesiNode *head;
    int size;

    SatirListesiNode* FindPreviousByPosition(int index);
public:
    SatirListesi();
    int Count()const;
    bool isEmpty()const;
	int indexOf(const int& item);
    void add(const int& item);
    void insert(int index, const int& item);
    void remove(const int& item);
    void removeAt(int index);
    const int& elementAt(int index);
    void clear();
    friend ostream& operator<<(ostream& screen, SatirListesi& yaz);
    void printSatirListesi(int x, int y);
    ~SatirListesi();

};


#endif