We will use the same frame work from the previous project. We will read in a  text file containing pet info. 
The data will go through a constructor and a class object will be created. We will also use a node class and linked 
list class using template<typename T> as the data type. The pet object will be passed in as the T type object and be 
pushed to the linked list. 

Attached to our Linked List class will be a variety of functions. This class will include sorting algorithms to arrange pet data
numerous amounts of ways (ascending order, descending order, ect...). This class will also include methods to find certain items
in the list and add or remove items in the list. There will also be a function to display the items in the list or specific values
of the pets in the list.

Our Pet class will include getter methods to get whatever information a user could want to retrieve. Setter methods will also be 
included if pet names or other attributes will want to be changed. 


class Pet{                     //data class
    private:
        string Type;
        string Name;
        int Age;
    public:
        getters()   //*3
        setters()   //*3
};

template <typename T>           //template
class PetNode{                  //node class
    public:
        T PetInfo;
        ItemNode* Next;

        ItemNode(T givenInfo){
            this -> PetInfo = givenInfo;
            Next = NULL;
        }
};

template <typename T>
class PetLinkedList{            //linked list class
    private:
        PetNode<T>* Head;
        PetNode<T>* Tail;
    public:
        int SortingFunc();
        void PushToLocation();
        void PushToHead();
        void PushToTail();
        void Pop();
        friend ostream& operator<<();
};