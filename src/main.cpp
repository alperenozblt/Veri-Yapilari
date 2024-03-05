/**
* @Main.cpp" Dosya adı
* @Dosyadan okuduğu verileri çift yönlü bağıl listeye ekleyerek istenilen formatta ekrana yazdırır. Programınızın açıklaması ne yaptığına dair.
* @1-A Dersi aldığınız eğitim türü ve grup
* @1.Ödev Kaçıncı ödev olduğu
* @20.11.2022 Kodu oluşturduğunuz Tarih
*/
#include <cstdlib>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "ReadAndWrite.hpp"
#include "Console.hpp"

using namespace std;

int main(int argc, char** argv) {

    ReadAndWrite * readingFile = new ReadAndWrite("veriler.txt");
     
    YoneticiListesi *yoneticiListesi = readingFile->WriteYoneticiListesi();
	Console *console = new Console(yoneticiListesi);
    yoneticiListesi->sortByAverage();
	
    char chr = ' ';
    do {
        console->printYoneticiListesi();
        cin>>chr;
		if (chr == 'a') {
            console->SetPage(downPage);
        }
		else if (chr == 'd') {
            console->SetPage(upPage);
        }
		else if (chr == 'z') {
            Sign sign = down;
            console->setConditation(sign);
	    } 
        else if (chr == 'c') {
            Sign sign = up;
            console->setConditation(sign);
        }
	
		else if (chr == 'p') {
            console->DeleteYoneticiNode();
        } 
        
		else if (chr == 'k') {
            int randIndex = 0;
               randIndex = console->chooseRandNode();
           
            cin>>chr;
            if (chr == 'k') {

                console->DeleteRandomSelectedNode(randIndex);
				yoneticiListesi->sortByAverage();
            }
		}
    } while (chr != 'q');



    return 0;



}
