#include <iostream>
#include <string>
#include "Contacts.h"

using namespace std;

// First Constructor
Contacts::Contacts(){

}

// Second Constructor
Contacts::Contacts(string name, string lastName, string email, long phone)
:theName(name),
theLastName(lastName),
theEmail(email),
thePhone(phone)
{

}

// Destructor
Contacts::~Contacts(){

}

// Getters (Accesser functions)

string Contacts::getName(){
  return theName;
}

string Contacts::getLastName(){
  return theLastName;
}

string Contacts::getEmail(){
  return theEmail;
}

long Contacts::getPhone(){
  return thePhone;
}



// Setters (Mutator functions)

void Contacts::setName(string newName){
  theName = newName;
}

void Contacts::setLastName(string newLastName){
  theLastName = newLastName;
}

void Contacts::setEmail(string newEmail){
  theEmail = newEmail;
}

void Contacts::setPhone(long newPhone){
  thePhone = newPhone;
}
