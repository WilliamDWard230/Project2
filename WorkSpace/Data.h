#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;

class HealthInfo
{
    private:

    double Weight;
    double BMI;
    double DesiredWeight;

    public:

    HealthInfo()
    {
        Weight = 0;
        BMI = 0;
        DesiredWeight = 0;
    }
    HealthInfo(double givenWeight, double givenBMI, double givenDesiredWeight)
    {
        Weight = givenWeight;
        BMI = givenBMI;
        DesiredWeight = givenDesiredWeight;
    }
    void setWeight(double givenWeight);
    void setBMI(double givenBMI);
    void setDesiredWeight(double givenDesiredWeight);

    double getWeight();
    double getBMI();
    double getDesiredWeight();

};
class Pet
{
    private:

    string Type;
    string Name;
    string Age;
    HealthInfo HealthObject;

    public:

    //Default Constructor
    Pet()
    {
        Type = "Dog";
        Name = "Whiskers";
        Age = "69";
    }

    //OVERLOAD CONSTRUCTOR
    Pet(string givenType, string givenName, string givenAge, HealthInfo FillinObject)
    {
        Type = givenType;
        Name = givenName;
        Age = givenAge;
        HealthObject = FillinObject;
    }
    
    void setAge(string givenAge);
    void setName(string givenName);
    void setType(string givenType);
    HealthInfo getObject() { return HealthObject; }
    string getAge();
    string getName();
    string getType();

    bool operator==(Pet &right_comparison) { return this->Age == right_comparison.Age; }
    bool operator<(Pet &right_comparison) { return this->Age < right_comparison.Age; }
    bool operator>(Pet &right_comparison) { return this->Age > right_comparison.Age; }

    friend ostream &operator<<(ostream &os, Pet &aPet)
    {
        os << "Name: " << aPet.Name << endl;
        os << "Type: " << aPet.Type << endl;
        os << "Age: " << aPet.Age << endl;

        os << "Weight: " << aPet.HealthObject.getWeight() << endl;
        os << "Desired Weight: " << aPet.HealthObject.getDesiredWeight() << endl; 
        os << "BMI: " << aPet.HealthObject.getBMI() << endl; 
        os << "********************************";

        return os;
    }
};

#endif