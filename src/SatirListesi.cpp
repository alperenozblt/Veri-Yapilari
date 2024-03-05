/**
* @SatirListesi.cpp" Dosya adı
* @Dosyadan okuduğu verileri çift yönlü bağıl listeye ekleyerek istenilen formatta ekrana yazdırır. Programınızın açıklaması ne yaptığına dair.
* @1-A Dersi aldığınız eğitim türü ve grup
* @1.Ödev Kaçıncı ödev olduğu
* @20.11.2022 Kodu oluşturduğunuz Tarih
*/
#include "SatirListesi.hpp"


SatirListesiNode* SatirListesi::FindPreviousByPosition(int index) {
    if (index < 0 || index > size) throw "No Such Element";
    SatirListesiNode *prv = head;
    int i = 1;
    for (SatirListesiNode*itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}

SatirListesi::SatirListesi() {
    head = NULL;
    size = 0;
}

int SatirListesi::Count()const {
    return size;
}

bool SatirListesi::isEmpty()const {
    return size == 0;
}

void SatirListesi::add(const int& item) {
    insert(size, item);
}

void SatirListesi::insert(int index, const int& item) {
    if (index < 0 || index > size) throw "Index out of Range";
    if (index == 0) {
        head = new SatirListesiNode(item, head);
        if (head->next != NULL) head->next->prev = head;
    } else {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        prv->next = new SatirListesiNode(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}

int SatirListesi::indexOf(const int& item){
    int index = 0;
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return index;
        index++;
    }
    throw "No Such Element";
}

void SatirListesi::remove(const int& item) {
    int index = indexOf(item);
    removeAt(index);
}

void SatirListesi::removeAt(int index) {
    if (index < 0 || index >= size) throw "Index out of Range";
    SatirListesiNode *del;
    if (index == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}
  
const int& SatirListesi::elementAt(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    if (index == 0) return head->data;
    return FindPreviousByPosition(index)->next->data;
}


void SatirListesi::clear() {
    for(;!isEmpty();)
        removeAt(0);
}

ostream& operator <<(ostream& screen, SatirListesi& yaz) {

    for (SatirListesiNode *itr = yaz.head; itr != NULL; itr = itr->next) {
        screen<<itr<<"\n";
        screen<<"-----------\n";
        screen<<"|"<<setw(5)<<itr->data<<setw(5)<<"|"<<endl;
        screen<<"-----------\n";
        screen<<"|"<<itr->next<<setw(3)<<"|\n";
        screen<<"-----------\n\n";
    }
    screen << endl;
    return screen;
}

void SatirListesi::printSatirListesi(int x,int y){
    
    GoTo.gotoxy(x,y);
     for (SatirListesiNode *itr = this->head; itr != NULL; itr = itr->next) {

        GoTo.gotoxy(x,y++);
        cout<<"  "<<setw(2)<<itr<<"\n";
		GoTo.gotoxy(x,y++);
        cout<<"------------\n";
        GoTo.gotoxy(x,y++);
        cout<<"| "<<setw(5)<<itr->data<<setw(5)<<"|"<<endl;
        GoTo.gotoxy(x,y++);
        cout<<"------------\n";
        GoTo.gotoxy(x,y++);
		if(itr->next==NULL){cout<<"| "<<setw(5)<<itr->next<<setw(6)<<"|\n";}
	 else {cout<<"| "<<setw(2)<<itr->next<<setw(3)<<"|\n";}
        GoTo.gotoxy(x,y++);
        cout<<"------------\n\n\n";
		

    }
}

SatirListesi::~SatirListesi() {
    clear();
}