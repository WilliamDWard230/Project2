#include "Data.h"
#include <iostream>
using namespace std;

void HealthInfo::setWeight(double givenWeight) {Weight = givenWeight;}
void HealthInfo::setBMI(double givenBMI) {BMI = givenBMI;}
void HealthInfo::setDesiredWeight(double givenDesiredWeight) {DesiredWeight = givenDesiredWeight;}
double HealthInfo::getWeight() {return Weight;}
double HealthInfo::getBMI() {return BMI;}
double HealthInfo::getDesiredWeight() {return DesiredWeight;}


void Pet::setAge(string givenAge) {Age = givenAge;}
void Pet::setName(string givenName) {Name = givenName;}
void Pet::setType(string givenType) {Type = givenType;}
string Pet::getAge() {return Age;}
string Pet::getName() {return Name;}
string Pet::getType() {return Type;}