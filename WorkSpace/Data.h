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
};

#endif 