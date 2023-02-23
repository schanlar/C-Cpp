#ifndef CONTACTS_H
#define CONTACTS_H

#include <string>



class Contacts {

public:

  // prototype Constructors
  Contacts();
  Contacts(std::string name, std::string lastName, std::string email, long phone);

  // prototype Destructor
  ~Contacts();

  // prototype getters
  std::string getName();
  std::string getLastName();
  std::string getEmail();
  long getPhone();


  //prototype setters
  void setName(std::string newName);
  void setLastName(std::string newLastName);
  void setEmail(std::string newEmail);
  void setPhone(long newPhone);


private:
  std::string theName;
  std::string theLastName;
  std::string theEmail;

  long thePhone;


};


#endif // CONTACTS_H
