/**
* @SatirListesiNode.cpp" Dosya adı
* @Dosyadan okuduğu verileri çift yönlü bağıl listeye ekleyerek istenilen formatta ekrana yazdırır. Programınızın açıklaması ne yaptığına dair.
* @1-A Dersi aldığınız eğitim türü ve grup
* @1.Ödev Kaçıncı ödev olduğu
* @20.11.2022 Kodu oluşturduğunuz Tarih
*/
#include "SatirListesiNode.hpp"

SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next , SatirListesiNode *prev ) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
SatirListesiNode::SatirListesiNode(const int data) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}