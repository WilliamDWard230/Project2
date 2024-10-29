#include "Data.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    PetLinkedList<Pet> PetList;
    PetNode<Pet>* current;
    PetNode<Pet>* previous;
    Pet itr1;
    int menuChoice; 
    int subMenuChoice;
    int length;
    ifstream file("VetPetInfo.txt");
    string fileString;
    file >> fileString;

    PetList.readInText(fileString, &PetList);
    current = PetList.iterator();

    do {
        cout << "\n\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
        cout << "1. View the Pets in the Kennel" << endl;
        cout << "2. Add a Pet to the Kennel" << endl;
        cout << "3. Search for a Pet" << endl;
        cout << "4. Leave the Clinc" << endl;
        cin >> menuChoice;
        while (menuChoice < 1 || menuChoice > 4 || cin.fail())
        {
            if (cin.fail())
            {
                cout << "\nOops! please enter a number" << endl;
                cin.clear();
                cin.ignore();
                cout << "\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Add a Pet to the Kennel" << endl;
                cout << "3. Search for a Pet" << endl;
                cout << "4. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
            else
            {
                cout << "\nOops! you entered an invalid choice! Please enter 1, 2, or 3!" << endl;
                cout << "\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Add a Pet to the Kennel" << endl;
                cout << "3. Search for a Pet" << endl;
                cout << "4. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
        }
        switch (menuChoice){
            case 1:
                if (PetList.isEmpty()){
                    cout << "The clinic is empty \n";
                }
                length = PetList.getLength();
                cout << "There are " << length << " pets in the clinic." << endl;
                PetList.printList();
                break;
            case 2:
                do 
                {   
                    Pet itr = current->getData();
                    cout << itr << endl;
                    cout << "1. Next Character" << endl;
                    cout << "2. Remove Pet" << endl;
                    cout << "3. Update Pet Info" << endl;
                    cout << "4. Return to main menu" << endl;
                    cin >> subMenuChoice;
                    switch(subMenuChoice){
                        case 1:
                            previous = current;
                            current = PetList.iteratorPlus(current);
                            break;
                        case 2:
                            PetList.removePet(previous, current);
                            current = PetList.iteratorPlus(current);
                            previous = current;
                            break;
                        case 3: 
                            PetList.updatePetInfo(current);
                            break;
                        case 4:
                            break;
                    }
                } while (subMenuChoice != 4);
                break;
            case 3:
                break;
            case 4:
                cout << "\nBugger off then!" << endl;
                PetList.~PetLinkedList();
                break;
        }
    }while (menuChoice != 4);
    
    //PetList.sortByAge();
    return 0;
}



