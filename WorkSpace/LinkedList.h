#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Data.h"
#include <iostream>
using namespace std;

template <typename T>
class PetNode
{
    private:
        T Data;
        PetNode* Next;

    public:
        PetNode(T givenData)
        {
            this -> Data = givenData;
            Next = NULL;
        }
        void setNext(PetNode* givenNext) {Next = givenNext;}
        PetNode* getNext() {return Next;}
        T getData(){
            return Data;
        }

};

template <typename T>
class PetLinkedList
{
    private:
        PetNode<T>* Head;
        PetNode<T>* Tail;

    public:
        PetLinkedList()
        {
            Head = NULL;
            Tail = NULL;
        }
        void insertAtHead(T &givenObject){
            PetNode<T>* newNode = new PetNode<T>(givenObject);
            if(Head == NULL){
                Head = newNode;
            }
            newNode -> setNext(Head -> getNext());
            Head = newNode;
        }
        void printList(){
            PetNode<T>* temp = Head;

            if (Head == NULL){
                cout << "List is empty" << endl;
                return;
            }
            while (temp != NULL){
                cout << temp-> getData().getType()<< endl;
                cout << temp-> getData().getName() << endl;
                cout << temp-> getData().getAge() << endl;
                cout << endl;

                temp = temp -> getNext();
            }
        }
        int getLength(){
            int count = 0;
            PetNode<T>* temp = Head;
            if (Head == NULL){
                return count;
            }
            while(temp != NULL){
                count++; 
                temp = temp -> getNext();
            }
            return count;
        }

};

#endif