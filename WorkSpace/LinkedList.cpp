#include "LinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
void setHead(PetNode<T> *givenHead);

template <typename T>
void setTail(PetNode<T> *givenTail);

void insertNode(int, int);
char getPetLetter();
void insertionSortPetNode();

void findPetByAgeLinear(int);
void findPetByAgeBinary(int);

void printList();