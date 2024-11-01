#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Data.h"
#include <iostream>
#include <fstream>
using namespace std;

//seperate node class
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
        void setData(PetNode<T> object){Data = object.getData();}

        friend ostream &operator<<(ostream &os, PetNode<T> aNode){ //overloaded << operator

            os << "Name: " << aNode.getData().getName();
            return os;
        }
};

//linked list class for node objects
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
        //getters 
        T* getHead();
        T* getTail();

        //checks if linked list is empty
        bool isEmpty();
        //returns the current node
        PetNode<T>* iterator();
        //increments the iterator
        PetNode<T>* iteratorPlus(PetNode<T>* current);
        //returns length of list
        int getLength();
        //deletes a pet from list
        void removePet(PetNode<T>* previous, PetNode<T>* current);
        //reads from text file and creates pet objects then inserts in list
        void readInText(string testString, PetLinkedList<T>* PetList);
        //inserts a pet object at the head of list
        void insertAtHead(T givenObject);
        //updates a pet's info
        void updatePetInfo(PetNode<T>* current);
        //prints names of pets
        void printList();
        //Adds a new pet
        void addNewPet(PetLinkedList<T>* PetList);
        //sorts linked list into an array
        PetNode<T>* selectionSort();
        void printSorted();
        
        
        
};

//function definitions

template <typename T>
T *PetLinkedList<T>::getHead(){
    return Head;
}
template <typename T>
T *PetLinkedList<T>::getTail(){
    return Tail;
}
template <typename T>
bool PetLinkedList<T>::isEmpty(){
    if(Head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
PetNode<T> *PetLinkedList<T>::iterator(){
    PetNode<T>* current = Head;
    return current;
}
template <typename T>
PetNode<T> *PetLinkedList<T>::iteratorPlus(PetNode<T> *current){
    if (current ->getNext() == NULL)
    {
        current = Head;
    }
    else
    {
    current = current->getNext();
    }
    return current;
}
template <typename T>
int PetLinkedList<T>::getLength(){
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
template <typename T>
void PetLinkedList<T>::removePet(PetNode<T> *previous, PetNode<T> *current){
    if(Head == current)
    {
        Head = current->getNext();
    }
    else
    {
    previous -> setNext(current->getNext());
    }
    delete current;
}
template <typename T>
void PetLinkedList<T>::readInText(std::__1::string testString, PetLinkedList<T> *PetList){
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
template <typename T>
void PetLinkedList<T>::insertAtHead(T givenObject){
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
template <typename T> 
void PetLinkedList<T>::updatePetInfo(PetNode<T> *current){
    Pet temp;
    HealthInfo object;
    string name;
    string type;
    string age;
    int selection;
    double weight;
    double desiredWeight;
    double bmi;

    cout << current->getData().getName() << " -----------" << endl;
    cout << "What information are you updating? \n";
    cout << "1. Name" << endl;
    cout << "2. Type" << endl;
    cout << "3. Age" << endl;
    cout << "4. Weight" << endl;
    cout << "5. Desired Weight" << endl;
    cout << "6. BMI" << endl;
    cin >> selection;

    switch(selection)
    {
        case 1:
            
            cout << "Enter a new Name: ";
            cin >> name;
            temp = current ->getData();
            temp.setName(name);
            current->setData(temp);
            break;
        case 2:
            cout << "Enter a new Type: ";
            cin >> type;
            temp = current ->getData();
            temp.setType(type);
            current->setData(temp);
            break;
        case 3:
            cout << "Enter a new Age: ";
            cin >> age;
            temp = current ->getData();
            temp.setAge(age);
            current->setData(temp);
            break;
        case 4:
            cout << "Enter a new Weight: ";
            cin >> weight;
            temp = current ->getData();
            object = temp.getObject();
            object.setWeight(weight);
            temp.setHealthInfo(object);
            current->setData(temp);
            break;
        case 5:
            cout << "Enter a new Desired Weight: ";
            cin >> desiredWeight;
            temp = current ->getData();
            object = temp.getObject();
            object.setDesiredWeight(desiredWeight);
            temp.setHealthInfo(object);
            current->setData(temp);
            break;
        case 6:
            cout << "Enter a new BMI: ";
            cin >> bmi;
            temp = current ->getData();
            object = temp.getObject();
            object.setBMI(bmi);
            temp.setHealthInfo(object);
            current->setData(temp);
            break; 

    }
}
template <typename T>
void PetLinkedList<T>::printList(){
    PetNode<T>* temp = Head;
    if (Head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "*****Pets*****" << endl;
    while (temp != NULL)
    {
        cout << *temp << endl;
        // cout << temp-> getData().getObject().getWeight() << endl;    This Line works!
        
        temp = temp -> getNext();
    }
}
template <typename T>
void PetLinkedList<T>::addNewPet(PetLinkedList<T> *PetList){
    Pet temp;
    HealthInfo object;
    string name;
    string type;
    string age;
    int selection;
    double weight;
    double desiredWeight;
    double bmi;

    cout << "Enter Pet Name: ";
    cin >> name;

    cout << "Enter Pet Type: ";
    cin >> type;

    cout << "Enter Pet Age: ";
    cin >> age;

    cout << "Enter Pet Weight: ";
    cin >> weight;

    cout << "Enter Pet Desired Weight: ";
    cin >> desiredWeight;

    cout << "Enter Pet BMI: ";
    cin >> bmi;

    object = HealthInfo(weight, bmi, desiredWeight);
    temp = Pet(type, name, age, object);
    PetList -> insertAtHead(temp);
        
}
template <typename T>
PetNode<T>* PetLinkedList<T>::selectionSort(){
    PetNode<T>* current = Head;

    while (current != NULL){

        PetNode<T>* right = current->getNext();
        PetNode<T>* left = current;

        Pet PCurrent = current->getData();
        Pet PRight = right->getData();
        Pet PLeft = left->getData(); 

        int cCurrent = stoi(PCurrent.getAge());
        int cRight = stoi(PRight.getAge());
        int cLeft = stoi(PLeft.getAge());

        while (right != NULL){
            if(stoi(right->getData().getAge()) < stoi(left->getData().getAge())){
                left = right;
            }
            right = right -> getNext();
            Pet t = left -> getData();
        }
        
        Pet tempData = current->getData();
        current->setData(left->getData());
        left->setData(tempData);

        current = current ->getNext();

    }
    return current;
}
template <typename T>
void PetLinkedList<T>::printSorted(){
    PetNode<T>* current = Head;
    while (current != NULL){
        Pet temp;
        temp = current->getData();
        cout << temp;
        current = current ->getNext();
    }
}

#endif

