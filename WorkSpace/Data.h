#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;

class Pet{
    private:
        string Type;
        string Name;
        string Age;
    public:
        Pet(){
            Type = "Dog";
            Name = "Whiskers";
            Age = "69";
        }
        Pet(string givenType, string givenName, string givenAge){
            Type = givenType;
            Name = givenName;
            Age = givenAge;
        }
    void setAge(string givenAge);
    void setName(string givenNamme);
    void setType(string givenType);
    string getAge();
    string getName();
    string getType();

    bool operator==(Pet& right_comparison) {return this -> Age == right_comparison.Age;}
    bool operator<(Pet& right_comparison) {return this -> Age < right_comparison.Age;}
    bool operator>(Pet& right_comparison) {return this -> Age > right_comparison.Age;}

    friend ostream& operator<<(ostream& os, Pet& aPet)
    {
        os << "Name: " << aPet.Name << endl;
        os << "Type: " << aPet.Type << endl;
        os << "Age: " << aPet.Age << endl;

        return os;
    }

    //and 3 "sub-data" methods
};

#endif 