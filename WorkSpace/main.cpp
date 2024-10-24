#include "Data.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(){
    PetLinkedList<Pet> PetList;
    string testString;
    string type;
    string name;
    string age;



    ifstream file("VetPetInfo.txt");

    file >> testString;
    while ((testString.find(',')) != std::string::npos) {

        int typeEnd = testString.find(',');
        type = testString.substr(0, typeEnd);
        testString.erase(0, typeEnd +1);

        int nameEnd = testString.find(',');
        name = testString.substr(0,nameEnd);
        testString.erase(0, nameEnd+1);

        int ageEnd = testString.find(',');
        age = testString.substr(0,ageEnd);
        testString.erase(0, ageEnd+1);


        Pet* tempPet = new Pet(type, name, age);
        PetList.insertAtHead(*tempPet);
    }
    PetList.printList();
    cout << PetList.getLength();

    return 0;
}