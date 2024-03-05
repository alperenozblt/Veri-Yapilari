/**
* @YoneticiListesi.cpp" Dosya adı
* @Dosyadan okuduğu verileri çift yönlü bağıl listeye ekleyerek istenilen formatta ekrana yazdırır. Programınızın açıklaması ne yaptığına dair.
* @1-A Dersi aldığınız eğitim türü ve grup
* @1.Ödev Kaçıncı ödev olduğu
* @20.11.2022 Kodu oluşturduğunuz Tarih
*/
#include "YoneticiListesi.hpp"

YoneticiNode* YoneticiListesi::FindPreviousByPosition(int index) {
    if (index < 0 || index > size) throw "No Such Element";
    YoneticiNode *prv = head;
    int i = 1;
    for (YoneticiNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}

YoneticiNode* YoneticiListesi::FindPosition(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    return this->FindPreviousByPosition(index + 1);

}

YoneticiListesi::YoneticiListesi() {
    head = NULL;
    size = 0;
}

int YoneticiListesi::Count()const {
    return size;
}

bool YoneticiListesi::isEmpty()const {
    return size == 0;
}

void YoneticiListesi::add(SatirListesi*& item) {
    insert(size, item);
}

void YoneticiListesi::insert(int index, SatirListesi*& item) {
    if (index < 0 || index > size) throw "Index out of Range";
    if (index == 0) {
        head = new YoneticiNode(item, head);
        if (head->next != NULL) head->next->prev = head;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(index);
        prv->next = new YoneticiNode(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}

int YoneticiListesi::indexOf(SatirListesi*& item) {
    int index = 0;
    for (YoneticiNode *itr = head; itr != NULL; itr = itr->next) {
        if (itr->data == item) return index;
        index++;
    }
    throw "No Such Element";
}

void YoneticiListesi::remove(SatirListesi*& item) {
    int index = indexOf(item);
    removeAt(index);
}
void YoneticiListesi::removeAt(int index) {
    if (index < 0 || index >= size) throw "Index out of Range";
    YoneticiNode *del;
    if (index == 0) {
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}

SatirListesi*& YoneticiListesi::elementAt(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    if (index == 0) return head->data;
    return FindPreviousByPosition(index)->next->data;
}

void YoneticiListesi::randFrmSatirList(int index, int index2){


    SatirListesi* satirListesi = this->elementAt(index);

    satirListesi->removeAt(index2);
    calculateAveragee(index);

}
int YoneticiListesi::randomGenerator(int index) {
	 srand(time(NULL));
    int number = this->Count();
	
    SatirListesi* satirListesi = this->elementAt(index);

    int  i= satirListesi->Count();
    if (i == 0) throw "No Such Element";
  
    int rnd = rand() % i;

    return rnd;
}
void YoneticiListesi::calculateAveragee(int index) {
    YoneticiNode* yoneticiNode = this->FindPosition(index);

    if (yoneticiNode == NULL) {

        throw "Not found";
    }

    double total = 0;
    if (yoneticiNode->data->isEmpty()) {

        yoneticiNode->average = total;
        return;
    }
    int number = yoneticiNode->data->Count();
    for (int i = 0; i < number; ++i) {
        total += yoneticiNode->data->elementAt(i);
    }
    yoneticiNode->average = total / number;

}


void YoneticiListesi::sortByAverage() {
    if (this->size <= 1)
        return;

    for (int i = 0; i < size; i++) {


        for (int j = 0; j < size - i - 1; j++) {
            YoneticiNode *tmp = this->FindPosition(j);
            YoneticiNode *tmp2 = tmp->next;

            if (tmp->average > tmp2->average) {


                this->exchange(j+1,j);
            }
        }
    }

}

void YoneticiListesi::exchange(int first, int second) {
   
    YoneticiNode *tmp;
    if (first == 0) {
        tmp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(first);
        tmp = prv->next;
        prv->next = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = prv;
    }
    size--;

    if (second == 0) {

        tmp->next = head;
        tmp->prev = NULL;
        head = tmp;
        if (head->next != NULL) head->next->prev = head;
    } else {
        YoneticiNode *prv = FindPreviousByPosition(second);

        tmp->next = prv->next;
        tmp->prev = prv;
        prv->next = tmp;
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}

void YoneticiListesi::clear() {
    for (;!isEmpty();)
        removeAt(0);
}

void YoneticiListesi::printIndex(int index, int x, int y) {
    YoneticiNode *node = this->FindPosition(index);
    GoTo.gotoxy(x, y);
    cout << fixed << setprecision(2);
    cout << "  "<<setw(4)<< node << "\n";
    GoTo.gotoxy(x, y + 1);
    cout << "------------\n";
    GoTo.gotoxy(x, y + 2);
	if(node->prev ==NULL) {cout<<"| "<<setw(5)<<node->prev<<setw(6)<<"|\n";}
    else {cout << "| " << node->prev << setw(3) << "|\n";}
    GoTo.gotoxy(x, y + 3);
    cout << "------------\n";
    GoTo.gotoxy(x, y + 4);
    cout << "| " << setw(7) << node->average << setw(3) << "|" << endl;
    GoTo.gotoxy(x, y + 5);
    cout << "------------\n";
    GoTo.gotoxy(x, y + 6);
	if(node->next ==NULL) {cout<<"| "<<setw(5)<<node->next<<setw(6)<<"|\n";}
    else {cout << "| " << node->next << setw(3) << "|\n";}
    GoTo.gotoxy(x, y + 7);
    cout << "------------\n\n";

}

YoneticiListesi::~YoneticiListesi() {
    clear();
}