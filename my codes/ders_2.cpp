#include <iostream>

using namespace std;

// Node class
class Node {
private:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
  
  friend class LinkedList; 
};

// Linked list class
class LinkedList {
private:
  Node *head;

public:
  LinkedList() {
    this->head = nullptr;
  }

void DeleteFromEnd(){
    
    if (head==nullptr)
    {
        cout <<"by by"<< endl;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp ->next;
    }
    delete temp->next;
    temp->next = nullptr;

}
void insertAtBeginning(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }


void printList() {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
};

int main() {
// Create a linked list
LinkedList list;


// Insert some nodes at the beginning of the list
list.insertAtBeginning(3);
list.insertAtBeginning(2);
list.insertAtBeginning(1);

// Print the list
cout << "Original list: ";
list.printList();

list.DeleteFromEnd();
// Print the List again
cout << "List after deleting a node at the end: ";
list.printList();


return 0;
}

