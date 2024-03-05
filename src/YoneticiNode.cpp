/**
* @YoneticiNode.cpp" Dosya adı
* @Dosyadan okuduğu verileri çift yönlü bağıl listeye ekleyerek istenilen formatta ekrana yazdırır. Programınızın açıklaması ne yaptığına dair.
* @1-A Dersi aldığınız eğitim türü ve grup
* @1.Ödev Kaçıncı ödev olduğu
* @20.11.2022 Kodu oluşturduğunuz Tarih
*/
#include "YoneticiNode.hpp"


YoneticiNode::YoneticiNode(SatirListesi* data, YoneticiNode *next , YoneticiNode *prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->average = calculateAverage();
}

YoneticiNode::YoneticiNode(SatirListesi* data, YoneticiNode *next ) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->average = calculateAverage();
}

YoneticiNode::YoneticiNode(SatirListesi* data) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->average = calculateAverage();
}
double YoneticiNode::calculateAverage() {
    double total = 0;
    if (this->data->isEmpty())
        return total;

    int number = this->data->Count();
    for (int i = 0; i < number; ++i) {
        total += this->data->elementAt(i);
    }
    return total / number;
}