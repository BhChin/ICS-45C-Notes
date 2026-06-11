#include <iostream>
#include <string>

using namespace std;

//
class Node {
private:
    int data; //data in the beginning node
    Node *head;
    Node *next; //pointer to the next node

public:
    Node(int initdata) {
        data = initdata; //initialized data is set as the head
        next = NULL; //the next node is set as NULL, as there is no next node yet

    }

    int getData() { //returns data of given node
        return data;
    }

    Node *getNext() {
        return next;
    }

    void setData(int newData) {
        data = newData;
    }

    void setNext(Node *newnext) {
        next = newnext;
    }

    void add(int item) {
        Node *temp = new Node(item);
        temp->setNext(head);
        head = temp;
    }
};

int linked_lists() {

    //linked-data structure = a data structure that consists of data structures called nodes that are linked
    //                        together via references or pointers.

    //linked-list = a linear collection of data elements whose order is not determined by the placement in memory.
    //              Each element is stored in a node which points to the next node, connected by a pointer.
    //
    //              The location of the first item of the list must be specified explicitly; also known as the HEAD

    Node temp = Node(93);
    cout << temp.getData() << endl;



    return 0;
}