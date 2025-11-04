//add or delete somewhere in linkedlist
#include <iostream>

using namespace std;
 
// Düğüm (Node) sınıfı: Bağlı listenin her bir elemanını temsil eder.
class Node{
private:
    int data;       // Düğümde saklanan veri
    Node *next;     // Bir sonraki düğümü gösteren işaretçi

    // Yapıcı (Constructor): Yeni bir düğüm oluşturur.
    Node(int data){
        this->data = data;
        this->next = nullptr; // Başlangıçta sonraki düğüm null'dır.
    }

    // LinkedList sınıfının, Node sınıfının özel üyelerine erişebilmesi için friend olarak tanımlanır.
    friend class LinkedList;
};

// Bağlı Liste (LinkedList) sınıfı: Düğümler üzerinde işlemleri gerçekleştirir.
class LinkedList{

private:
    Node *head; // Listenin başını (ilk düğümü) gösteren işaretçi

public:

    // Yapıcı (Constructor): Boş bir bağlı liste oluşturur.
    LinkedList() {
        this->head = nullptr; // Başlangıçta liste boştur.
    }
  
  
    // Listenin başına yeni bir eleman ekler.
    void insertAtBeginning(int data) {
        Node *newNode = new Node(data); // Yeni düğüm oluşturulur.
        newNode->next = head;           // Yeni düğümün 'next'i mevcut başı gösterir.
        head = newNode;                 // Listenin başı yeni düğüm olarak güncellenir.
    }
    // Listenin sonuna yeni bir eleman ekler.
    void insertAtEnd(int data) {
        Node *newNode = new Node(data); // Yeni düğüm oluşturulur.
        if (head == nullptr) {          // Eğer liste boşsa,
            head = newNode;             // yeni düğüm listenin başı olur.
        return;
        }
        Node *temp = head;
        while (temp->next != nullptr) { // Listenin sonuna gitmek için döngü kullanılır.
            temp = temp->next;
        }
        temp->next = newNode;           // Son düğümün 'next'i yeni düğümü gösterir.
    }

    // Belirtilen pozisyona yeni bir eleman ekler.
    void insertPosition(int item, int position) {
        Node* newNode = new Node(item); // Yeni düğüm oluşturulur.

        // Pozisyon kontrolü
        if (position <= 0) {
            cout << "Gecersiz pozisyon." << endl;
            delete newNode; // Oluşturulan düğüm hafızadan silinir.
            return;
        }

        // Eğer pozisyon 1 ise, listenin başına ekleme yapılır.
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        int currentIndex = 1;

        // Eklenecek pozisyonun bir öncesine kadar ilerlenir.
        while (temp != nullptr && currentIndex < position - 1) {
            temp = temp->next;
            currentIndex++;
        }

        // Pozisyon listenin boyutunu aşıyorsa
        if (temp == nullptr) {
            cout << "Pozisyon listenin boyutunu asiyor." << endl;
            delete newNode;
            return;
        }

        // Düğüm araya eklenir.
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Belirtilen pozisyondaki elemanı siler.
    void deleteItem(int position) {
        if (head == nullptr) { // Liste boşsa silinecek bir şey yoktur.
            cout << "Liste bos, silinecek bir sey yok." << endl;
            return;
        }

        Node* temp = head;

        // Pozisyon kontrolü
        if (position <= 0) {
            cout << "Gecersiz pozisyon." << endl;
            return;
        }

        // Eğer ilk eleman silinecekse
        if (position == 1) {
            head = temp->next; // Baş, bir sonraki düğüme kaydırılır.
            delete temp;       // Eski baş düğüm hafızadan silinir.
            return;
        }

        Node* prev = nullptr;
        int currentIndex = 1;

        // Silinecek düğüme kadar ilerlenir.
        while (temp != nullptr && currentIndex < position) {
            prev = temp;
            temp = temp->next;
            currentIndex++;
        }

        // Pozisyon listenin boyutunu aşıyorsa
        if (temp == nullptr) {
            cout << "Pozisyon listenin boyutunu asiyor." << endl;
            return;
        }

        // Düğüm listeden çıkarılır ve hafızadan silinir.
        prev->next = temp->next;
        delete temp;
    }

    // Belirtilen bir elemanı listede arar ve pozisyonunu döndürür.
    int find(int item) {
        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == item) {
                return position; // Eleman bulundu, pozisyonu döndürülür.
            }
            temp = temp->next;
            position++;
        }
        return -1; // Eleman bulunamazsa -1 döndürülür.
    }

    // Belirtilen bir değere sahip ilk düğümü siler.
    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        // Eğer silinecek düğüm baştaysa
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        // Silinecek düğümü bulmak için listeyi dolaşır.
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // Düğüm bulunamazsa
        if (temp == nullptr) {
            cout << "Silinecek eleman bulunamadi." << endl;
            return;
        }

        // Düğümü siler.
        prev->next = temp->next;
        delete temp;
    }

    // Listenin tüm elemanlarını ekrana yazdırır.
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    // Bir LinkedList nesnesi oluşturulur.
    LinkedList list;
    // Listeye elemanlar eklenir.
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(40);
    list.insertAtBeginning(5);

    cout << "Ilk liste durumu: " << endl;
    list.printList(); // Liste yazdırılır: 5 -> 10 -> 20 -> 40 -> nullptr

    // Belirtilen pozisyona eleman ekleme
    cout << "\n3. siraya 30 ekleniyor..." << endl;
    list.insertPosition(30, 3);
    list.printList(); // Liste yazdırılır: 5 -> 10 -> 30 -> 20 -> 40 -> nullptr

    cout << "\n1. siraya 1 ekleniyor..." << endl;
    list.insertPosition(1, 1);
    list.printList(); // Liste yazdırılır: 1 -> 5 -> 10 -> 30 -> 20 -> 40 -> nullptr

    // Değere göre eleman silme
    cout << "\n20 degeri siliniyor (eski method)..." << endl;
    list.deleteNode(20);
    list.printList(); // Liste yazdırılır: 1 -> 5 -> 10 -> 30 -> 40 -> nullptr

    // Pozisyona göre eleman silme
    cout << "\nListenin basi (1. pozisyon) siliniyor..." << endl;
    list.deleteItem(1);
    list.printList(); // Liste yazdırılır: 5 -> 10 -> 30 -> 40 -> nullptr

    // Eleman arama
    cout << "\n40 degeri aranior..." << endl;
    int pos = list.find(40);
    if (pos != -1) {
        cout << "40 degeri " << pos << ". pozisyonda bulundu." << endl;
    } else {
        cout << "40 degeri bulunamadi." << endl;
    }

    cout << "\n99 degeri aranior..." << endl;
    pos = list.find(99);
    if (pos != -1) {
        cout << "99 degeri " << pos << ". pozisyonda bulundu." << endl;
    } else {
        cout << "99 degeri bulunamadi." << endl;
    }

    // Pozisyona göre eleman silme
    cout << "\n3. pozisyondaki eleman siliniyor..." << endl;
    list.deleteItem(3);
    list.printList(); // Liste yazdırılır: 5 -> 10 -> 40 -> nullptr

    return 0;
}

