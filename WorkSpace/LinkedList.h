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
        T getData() {return Data;}
};

template <typename T>
class PetLinkedList
{
    private:
        PetNode<T>* Head;
        PetNode<T>* Tail;
    public:
        //DEFULT CONSTRUCTOR
        PetLinkedList()
        {
            Head = NULL;
            Tail = NULL;
        }

        //DECONSTRUCTOR
        ~PetLinkedList()
        {
            PetNode<T>* nodePtr;
            PetNode<T>* nextNode;

            nodePtr = Head;

            while(nodePtr != NULL)
            {
                nextNode = nodePtr->getNext();

                delete nodePtr;

                nodePtr = nextNode;
            }
        }

        T* getHead() {return Head;}

        void insertAtHead(T givenObject)
        {
            PetNode<T>* newNode = new PetNode<T>(givenObject);

            if(Head == NULL)
            {
                Head = newNode;
            }
            else
            {
                newNode -> setNext(Head);
                Head = newNode;
            }
        }

        void printList()
        {
            PetNode<T>* temp = Head;
            if (Head == NULL)
            {
                cout << "List is empty" << endl;
                return;
            }
            while (temp != NULL)
            {
                cout << temp-> getData().getType()<< endl;
                cout << temp-> getData().getName() << endl;
                cout << temp-> getData().getAge() << endl;
                // cout << temp-> getData().getObject().getWeight() << endl;    This Line works!
                cout << endl;
                temp = temp -> getNext();
            }
        }

        int getLength()
        {
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

        //sorts the list via Insertion Sort
        void insertionSortByAge()
        {
            PetNode<T>* nodePtr = Head;
            PetNode<T>* nextNode = NULL;

            if(!Head)
            {
                cout << "\nThe  list is empty... nothing to sort.\n\n";
                return;
            }
            else
            {
                nextNode = nodePtr->getNext();

                //I do not know how to use the get Data yet (trying to get the age of the pet)
                cout << nodePtr->getData().getAge();

                if(nodePtr->getData().getAge() > nextNode->getData().getAge())
                {
                    
                }
            }
        }

        bool isEmpty()
        {
            if(Head == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


};

#endif