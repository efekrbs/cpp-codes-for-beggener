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

    void AddSomeWhereWhitİndex(int data,int place){
        Node *newNode = new Node(data);
        int c = 1 ;
        
        if (head==nullptr)
        {
            cout << "This inkedlist is empty. "<< endl ;
            return;
        }
        
        Node *temp = head;
        
        while (c!=place)
        {
            temp = temp->next;
            c +=1;
        }
        


    }



};

