#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Data.h"
#include <iostream>
#include <fstream>
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
        T* getTail() {return Tail;}

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
        
        PetNode<T>* iterator(){
            PetNode<T>* current = Head;
            return current;
        }
        PetNode<T>* iteratorPlus(PetNode<T>* current){
            if (current ->getNext() == NULL){
                current = Head;
            }
            current = current->getNext();
            return current;
        }
        
        void readInText(string testString, PetLinkedList<T>* PetList){
            string type;
            string name;
            string age;
            int count = 0;
            ifstream file("VetPetInfo.txt");

            file >> testString;
            while ((testString.find(',')) != std::string::npos) 
            {   
                int typeEnd = testString.find(',');
                type = testString.substr(0, typeEnd);
                testString.erase(0, typeEnd +1);

                int nameEnd = testString.find(',');
                name = testString.substr(0,nameEnd);
                testString.erase(0, nameEnd+1);

                int ageEnd = testString.find(',');
                age = testString.substr(0,ageEnd);
                testString.erase(0, ageEnd+1);

                HealthInfo object = HealthInfo(0,0,0);
       
                Pet* tempPet = new Pet(type, name, age, object);
                PetList -> insertAtHead(*tempPet);
        
            }
        }
        
        void insertAtHead(T givenObject)
        {
            PetNode<T>* newNode = new PetNode<T>(givenObject);

            if(Head == NULL)
            {
                Head = newNode;
            }
            else
            {
                newNode ->setNext(Head);
                Head = newNode;
            }
        }

        void removePet(PetNode<T>* previous, PetNode<T>* current)
        {
            previous -> setNext(current->getNext());
            delete current;
        }

        void printList()
        {
            PetNode<T>* temp = Head;
            if (Head == NULL)
            {
                cout << "List is empty" << endl;
                return;
            }
            cout << "*****Pets*****" << endl;
            while (temp != NULL)
            {
                cout << "Name: " << temp-> getData().getName();
                // cout << temp-> getData().getObject().getWeight() << endl;    This Line works!
                cout << endl;
                temp = temp -> getNext();
            }
        }


        //sorts the list via Insertion Sort
        void insertionSortByAge(T givenObject)
        {   
            PetNode<T>* newNode = new PetNode<T>(givenObject);
            PetNode<T>* nodePtr = Head;
            PetNode<T>* nextNode = NULL;
            int comparisonAge;
            int newAge;

            if(!Head)
            {
                cout << "\nThe  list is empty... nothing to sort.\n\n";
                return;
            }
            else
            {
                nextNode = nodePtr->getNext();
                while (nodePtr ->getNext() == NULL){
                    comparisonAge = stoi(nextNode ->getData().getAge());
                    newAge = stoi(newNode ->getData().getAge());
                    if(comparisonAge < newAge)
                    {
                        newNode ->setNext(nextNode);
                        Head = newNode;
                    }
                    if(comparisonAge > newAge)
                    {
                        newNode ->setNext(nextNode);
                        Head = newNode;
                    }
                    nodePtr = nodePtr -> getNext();
                    nextNode = nodePtr;

                }

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
};


#endif