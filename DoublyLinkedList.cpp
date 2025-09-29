
#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* prev;
    Node* next;

    //constructor

    Node(int d){
        this ->data = d;
        this ->prev = NULL;
        this ->next = NULL;
    }
};

//traverse 
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
      cout<< temp -> data<<" ";
      temp = temp -> next;
    }
    cout<< endl;
}
//for length
int getlength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
      len++;
      temp = temp -> next;
    }
    return len;
}
//insert at head
void insertAtHead(Node* &head, int d){

    //empty list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }else{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
   
   
}

//insert at tail
void insertAtTail(Node* &tail, int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;

    }else{

        Node*  temp = new Node(d);
        tail->next = temp;
        temp -> prev = tail; 
        tail = temp;
    }
}
//insert at position
void insertAtPosition(Node* &head,Node* &tail, int position, int d){
   //insert at start
   if(position == 1){
    insertAtHead(head, d);
    return;
   }

   Node* temp = head;
   int cnt =1;

   while(cnt < position-1){
    temp = temp->next;
    cnt++;
   }
   //insert at last position
   if(temp-> next == NULL){
    insertAtTail(tail, d);
    return;
   }

   //creating a node for d
   Node* nodeToIsert = new Node(d);

   nodeToIsert -> next = temp -> next;
   temp -> next -> prev = nodeToIsert;
   temp -> next = nodeToIsert;
   nodeToIsert -> prev = temp;

}


int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail  = node1;

    print(head);
    cout<< getlength(head)<<endl;

    //insert at head
    insertAtHead(head, 11);
    print(head);

    
    insertAtHead(head, 22);
    print(head);

    
    insertAtHead(head, 33);
    print(head);

    //insert at tail
     insertAtTail(tail, 990);
    print(head);

    insertAtPosition(head, tail, 2, 500);
    print(head);

        insertAtPosition(head, tail, 6, 999);
    print(head);

     insertAtPosition(head, tail, 1, 1010);
    print(head);
    return 0;
}
