//add or delete somewhere in linkedlist
#include <iostream>

using namespace std;
 
//node class (node veri tipini olşutran class)
class Node{
private:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    friend class LinkedList;
};

//linkedlis üzerinde işlemleri gerçekleştirmeizi sağlayan class
class LinkedList{

private:
    Node *head;

public:

    LinkedList() {
        this->head = nullptr;
    }
  
  
    void insertAtBeginning(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addSomewhereWithIndex(int data, int place) {
        Node* newNode = new Node(data);

        if (place <= 0) {
            cout << "Gecersiz pozisyon." << endl;
            delete newNode;
            return;
        }

        if (place == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        int currentIndex = 1;

        while (temp != nullptr && currentIndex < place - 1) {
            temp = temp->next;
            currentIndex++;
        }

        if (temp == nullptr) {
            cout << "Pozisyon listenin boyutunu asiyor." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Silinecek eleman bulunamadi." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

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
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(40);
    list.insertAtBeginning(5);

    cout << "Ilk liste durumu: " << endl;
    list.printList();

    cout << "\n3. siraya 30 ekleniyor..." << endl;
    list.addSomewhereWithIndex(30, 3);
    list.printList();

    cout << "\n1. siraya 1 ekleniyor..." << endl;
    list.addSomewhereWithIndex(1, 1);
    list.printList();

    cout << "\n20 degeri siliniyor..." << endl;
    list.deleteNode(20);
    list.printList();

    cout << "\nListenin basi (1) siliniyor..." << endl;
    list.deleteNode(1);
    list.printList();

    return 0;
}

