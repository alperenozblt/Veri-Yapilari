#ifndef CONSOLE_HPP
#define CONSOLE_HPP
#include "GoTo.hpp"
#include "YoneticiListesi.hpp"


enum PageSign {
    upPage = 0,
    downPage = 1,
};

enum Sign {
    up = 0,
    down = 1,
    refresh = 2,

};

class Console {
private:
    YoneticiListesi *yonetici;
    int conditation;
    int startLine;
    int finishLine;

    void setOffsets();
public:
	void setConditation(Sign pc);
    void SetPage(PageSign p);
    Console(YoneticiListesi* yonetici);
    void printYoneticiListesi();
    void printSelectedSatirListesi(int x, int y);
    int chooseRandNode();
    void DeleteYoneticiNode();
    void DeleteRandomSelectedNode(int randIndex);
};

#endif 