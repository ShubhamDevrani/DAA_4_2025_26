#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;  

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;   
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList(){
        head = tail = nullptr;
    }

    void pushfront(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;   
            head = newNode;
        }
    }

    void pushback(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;   
            tail = newNode;
        }
    }

    void popfront(){
        if(head == nullptr){
            cout << "Linked List is empty" << endl;
        }else{
            Node* temp = head;
            head = head->next;
            if(head != nullptr) head->prev = nullptr; 
            temp->next = nullptr;
            delete temp;
            if(head == nullptr) tail = nullptr; 
        }
    }

    void popback(){
        if(head == tail){
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;  
            tail->next = nullptr;
            delete temp;
        }
    }

    void insert(int pos, int val){
        if(pos == 0){
            pushfront(val);
            return;
        }
        
        Node* temp = head;
        for(int i=0; i< pos-1; i++){
            if(temp == nullptr){
                cout << "Position out of bounds" << endl;
                return;
            }
            temp = temp->next;
        }

        if(temp==nullptr){
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;         
        if(temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

        if(newNode->next == nullptr){
            tail = newNode; 
        }
    }

    void deleteElement(int val){
        if(head == nullptr){
            cout << "Linked List is empty, nothing to delete" << endl;
            return;
        }

        if(head->data == val){
            Node* temp = head;
            head = head->next;
            if(head != nullptr) head->prev = nullptr;
            else tail = nullptr;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != val){
            temp = temp->next;
        }

        if(temp->next == nullptr){
            cout << "Element not found" << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        if(temp->next != nullptr){
            temp->next->prev = temp;
        } else {
            tail = temp;
        }
        delete delNode;
    }

    void display(){
        if(head == nullptr){
            cout << "NO element in linkedlist" << endl;
        }else{
            Node* temp = head;
            while(temp!=nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
    LinkedList ll;
    ll.pushfront(5);
    ll.pushback(33);
    ll.display();
    ll.popback();
    ll.display();
    ll.pushfront(9);
    ll.display();
    ll.insert(0,1);
    ll.display();
    ll.popfront();
    ll.popfront();
    ll.display();
}