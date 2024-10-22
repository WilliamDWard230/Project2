#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class PetNode
{
    private:
    
        T Data;
        PetNode* Next;

    public:

        PetNode()
        {
            Next = NULL;
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

        //DESTRUCTOR
        ~PetLinkedList();

        PetNode* getHead();
        PetNode* getTail();

        void setHead(PetNode<T>* givenHead);
        void setTail(PetNode<T>* givenTail);

        void insertNode();
        char getPetLetter();
        void insertionSortPetNode();

        void findPetByAgeLinear();
        void findPetByNameLinear();
        // void findPetByNameLinear();

        void printList();

        // operators << , < , > , == 
};

#endif