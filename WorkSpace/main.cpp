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

    PetList.readInText(fileString, &PetList);       //reads in file and creates list.
    current = PetList.iterator();

    do {
        cout << "\n\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
        cout << "1. View the Pets in the Kennel" << endl;
        cout << "2. Update Pet Info or Remove a Pet" << endl;
        cout << "3. Add a Pet to the Kennel" << endl;
        cout << "4. Sort the pets in the Kennel by age" << endl;
        cout << "5. Leave the Clinc" << endl;
        cin >> menuChoice;
        while (menuChoice < 1 || menuChoice > 5 || cin.fail())
        {
            if (cin.fail())
            {
                cout << "\nOops! please enter a number" << endl;
                cin.clear();
                cin.ignore();
                cout << "\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Update Pet Info or Remove a Pet" << endl;
                cout << "3. Add a Pet to the Kennel" << endl;
                cout << "4. Sort the pets in the Kennel by age" << endl;
                cout << "5. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
            else
            {
                cout << "\nOops! you entered an invalid choice! Please enter 1-5!" << endl;
                cout << "\nWelcome to our Veterinary Office! What would you like to do today?" << endl;
                cout << "1. View the Pets in the Kennel" << endl;
                cout << "2. Update Pet Info or Remove a Pet" << endl;
                cout << "3. Add a Pet to the Kennel" << endl;
                cout << "4. Sort the pets in the Kennel by age" << endl;
                cout << "5. Leave the Clinc" << endl;
                cin >> menuChoice;
            }
        }
        switch (menuChoice){
            case 1:
                if (PetList.isEmpty()){
                    cout << "\n\n\nThe clinic is empty \n";
                }
                length = PetList.getLength();
                cout << "\n\n\nThere are " << length << " pets in the clinic." << endl;
                PetList.printList();
                break;
            case 2:
                do 
                {   
                    Pet itr = current->getData();       //pet object equal to current node
                    cout << "\n\n\n";
                    cout << itr << endl;
                    cout << "1. Next Character" << endl;
                    cout << "2. Remove Pet" << endl;
                    cout << "3. Update Pet Info" << endl;
                    cout << "4. Return to main menu" << endl;
                    cin >> subMenuChoice;
                    switch(subMenuChoice){
                        case 1:
                            previous = current;
                            current = PetList.iteratorPlus(current);        //iterates forward
                            break;
                        case 2:
                            PetList.removePet(previous, current);       //deletes current and tracks previous
                            current = PetList.iteratorPlus(current);    //iteratres forward
                            previous = current;     //rejoins disjointed list
                            break;
                        case 3: 
                            PetList.updatePetInfo(current);
                            break;
                        case 4:
                            break;
                    }
                } while (subMenuChoice != 4);
                break;
            case 3: PetList.addNewPet(&PetList);        //adds new pet
                break;
            case 4:
                if (PetList.isEmpty())
                {
                    cout << "\n\n\nThe clinic is empty \n";
                }
                else
                {
                    PetList.selectionSort();
                    cout << "\n\nThe list has been sorted!!\n\n";
                }
                break;
            case 5:
                cout << "\nBugger off then!" << endl;       //ends program
                break;
        }
    }while (menuChoice != 5);
    
    return 0;
}



