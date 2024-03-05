/**
* @Console.cpp" Dosya adı
* @Dosyadan okuduğu verileri çift yönlü bağıl listeye ekleyerek istenilen formatta ekrana yazdırır. Programınızın açıklaması ne yaptığına dair.
* @1-A Dersi aldığınız eğitim türü ve grup
* @1.Ödev Kaçıncı ödev olduğu
* @20.11.2022 Kodu oluşturduğunuz Tarih
*/


#include "Console.hpp"

Console::Console(YoneticiListesi* yonetici) {
    this->yonetici = yonetici;
    if (this->yonetici->Count() < 8) {
        this->finishLine = this->yonetici->Count();
    } else {
        this->finishLine = 8;
    }

    this->startLine = 0;

}

void Console::setOffsets() {
    int page = conditation / 8;
    this->startLine = 8*page;
    this->finishLine = 8 * (page + 1);
    if (this->finishLine >= this->yonetici->Count()) {
        this->finishLine = this->yonetici->Count();

    }
}

void Console::setConditation(Sign c) {

    if (c == up) {
        if (conditation >= this->yonetici->Count() - 1) {
            return;
        }
        ++conditation;
        setOffsets();
    } else if (c == down) {
        if (conditation <= 0) {

            return;
        }
        --conditation;
        setOffsets();
    } else if (c == refresh) {
        setOffsets();
    }

}

void Console::SetPage(PageSign ps) {
    if (ps == downPage) {
        for (int i = 0; i < 8; ++i) {
            this->setConditation(down);
        }
    } else if (ps == upPage) {
        for (int i = 0; i < 8; ++i) {
            this->setConditation(up);
        }
    }
}

void Console::printYoneticiListesi() {
	if(this->yonetici->elementAt(this->conditation)->isEmpty())
    {
        this->yonetici->removeAt(this->conditation);
        this->setConditation(refresh);
    }
    int count = yonetici->Count();
    system("cls");
  
    GoTo.gotoxy(0, 0);
    if (this->startLine == 0) {
        cout << "--ilk--";
    } else {
        cout << "<---geri--";
    }


    int NodeSayi = this->finishLine - this->startLine;
    NodeSayi = ((NodeSayi * 13)+2);


    GoTo.gotoxy(NodeSayi, 0);


    if (this->finishLine == yonetici->Count()) {
        cout << "-son-";
    } else {
        cout << "--ileri-->";
    }
    for (int i = this->startLine; i<this->finishLine; ++i) {

        this->yonetici->printIndex(i, 15 * (i % 8), 1);

    }
    this->printSelectedSatirListesi((this->conditation % 8) *15, 9);
}

 void Console::printSelectedSatirListesi(int x, int y) {
        this->yonetici->elementAt(this->conditation)->printSatirListesi(x, y);

    }
  int Console::chooseRandNode() {

        int chooseRand = this->yonetici->randomGenerator(this->conditation);
        int Pozx = ((this->conditation % 8) + 1)*15;
        int Pozy = ((chooseRand)*6)+12;
        GoTo.gotoxy(Pozx, Pozy);
        cout << "<--silinecek";
        Pozy = this->yonetici->elementAt(this->conditation)->Count()*6 + 12;

        GoTo.gotoxy(0, Pozy - 1);


        return chooseRand;

    }
  void Console::DeleteYoneticiNode() {
        this->yonetici->removeAt(this->conditation);
       this->setConditation(refresh);
      
        if(this->conditation==this->finishLine){
            this->conditation--;
        }
         this->setConditation(refresh);

   

    }
  void Console::DeleteRandomSelectedNode(int randIndex) {
        this->yonetici->randFrmSatirList(this->conditation, randIndex);
    }