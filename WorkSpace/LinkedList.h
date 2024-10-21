template <typename T>
class PetNode{
    private:
        T Data;
        PetNode* Next;
    public:
        PetNode(){
            Next = NULL;
        }
};
template <typename T>
class PetLinkedList{
    private:
        PetNode* Head;
        PetNode* Tail;
    public:
        PetLinkedList(){
            Head = NULL;
            Tail = NULL;
        }
};