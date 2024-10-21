#include "Data.h"
#include <iostream>
using namespace std;

void Pet::setAge(string givenAge) {Age = givenAge;}
void Pet::setName(string givenName) {Name = givenName;}
void Pet::setType(string givenType) {Type = givenType;}
string Pet::getAge() {return Age;}
string Pet::getName() {return Type;}
string Pet::getType() {return Type;}