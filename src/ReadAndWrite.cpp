/**
* @ReadAndWrite.cpp" Dosya adı
* @Dosyadan okuduğu verileri çift yönlü bağıl listeye ekleyerek istenilen formatta ekrana yazdırır. Programınızın açıklaması ne yaptığına dair.
* @1-A Dersi aldığınız eğitim türü ve grup
* @1.Ödev Kaçıncı ödev olduğu
* @20.11.2022 Kodu oluşturduğunuz Tarih
*/
#include "ReadAndWrite.hpp"
  

using namespace std;

YoneticiListesi* ReadAndWrite::WriteYoneticiListesi(){
    readLine();
    YoneticiListesi *tmp=new YoneticiListesi();
    int sayac=rowSay();
    for(int i=0;i<sayac;i++){
        tmp->add(this->rows[i]);
    }
    return tmp;
    
}
void ReadAndWrite::readLine() {
	ifstream file(this->fileName);
	string row;
	int numbers;
	int index =0;

	for(;getline(file,row);)
	{
	stringstream ss;
	ss<<row; //değer yazmak için
	for(;ss>>numbers;){
	this->rows[index]->add(numbers);
	}
	index++;
	}
	file.close();
}

ReadAndWrite::ReadAndWrite(string fileName) {
    this->fileName = fileName;


    int nums = rowSay();
    this->rows = new SatirListesi*[nums];
    for (int i = 0; i < nums; i++) {
        this->rows[i] = new SatirListesi();
    }
}

int ReadAndWrite::rowSay() {
    int sayac = 0;
    ifstream file(this->fileName);
    string n;
    for (;getline(file, n);)
        sayac++;

    file.close();
    return sayac;
}


ReadAndWrite::~ReadAndWrite(){
	if(rows!=0){
		int sayac =rowSay();
		for (int i = 0; i < sayac; i++){
			if(rows[i]!=0) delete rows[i];
		}
		delete[] rows;
	}
	
}