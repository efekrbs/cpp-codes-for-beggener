#include <iostream>

// Çift Yönlü Bağlı Liste için Düğüm (Node) Sınıfı
class Node {
public:
    int data;       // Düğümde saklanan veri
    Node* next;     // Bir sonraki düğümü gösteren işaretçi
    Node* prev;     // Bir önceki düğümü gösteren işaretçi

    // Yapıcı (Constructor)
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Çift Yönlü Bağlı Liste (DoublyLinkedList) Sınıfı
class DoublyLinkedList {
private:
    Node* head; // Listenin başını gösteren işaretçi
    Node* tail; // Listenin sonunu gösteren işaretçi

public:
    // Yapıcı (Constructor)
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Listenin sonuna eleman ekleme
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) { // Liste boşsa
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        std::cout << data << " listenin sonuna eklendi." << std::endl;
    }

    // Listenin başına eleman ekleme
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) { // Liste boşsa
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        std::cout << data << " listenin basina eklendi." << std::endl;
    }

    // Belirtilen değere sahip düğümü silme
    void deleteNode(int key) {
        Node* current = head;

        // Silinecek düğümü bul
        while (current != nullptr && current->data != key) {
            current = current->next;
        }

        // Düğüm bulunamazsa
        if (current == nullptr) {
            std::cout << "Silinecek eleman (" << key << ") bulunamadi." << std::endl;
            return;
        }

        // Eğer silinecek düğüm baştaysa
        if (current == head) {
            head = current->next;
        }

        // Eğer silinecek düğüm sonda değilse, bir sonrakinin prev'ini güncelle
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else { // Eğer silinecek düğüm sondaysa, tail'i güncelle
            tail = current->prev;
        }

        // Eğer silinecek düğüm başta değilse, bir öncekinin next'ini güncelle
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }

        std::cout << current->data << " listeden silindi." << std::endl;
        delete current; // Düğümü hafızadan sil
    }

    // Listeyi baştan sona yazdırma
    void printForward() {
        if (head == nullptr) {
            std::cout << "Liste bos." << std::endl;
            return;
        }
        Node* temp = head;
        std::cout << "Liste (Bastan Sona): ";
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Listeyi sondan başa yazdırma
    void printBackward() {
        if (tail == nullptr) {
            std::cout << "Liste bos." << std::endl;
            return;
        }
        Node* temp = tail;
        std::cout << "Liste (Sondan Basa): ";
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtBeginning(5);

    dll.printForward();
    dll.printBackward();

    std::cout << "\n--- Silme Islemleri ---" << std::endl;
    dll.deleteNode(20); // Ortadan bir eleman sil
    dll.printForward();

    dll.deleteNode(5);  // Baştan bir eleman sil
    dll.printForward();

    dll.deleteNode(30); // Sondan bir eleman sil
    dll.printForward();
    
    dll.deleteNode(99); // Listede olmayan bir elemanı silmeyi dene

    return 0;
}
