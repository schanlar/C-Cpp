#include <iostream>
#include <string>
#include "Contacts.h"


using namespace std;
void welcomeMessage();
void farewellMessage();
void debugging();


Contacts createContact(string contactName, string contactLastName, string contactEmail, long contactPhone){
  Contacts person;
  person.setName(contactName);
  person.setLastName(contactLastName);
  person.setEmail(contactEmail);
  person.setPhone(contactPhone);
  return person;
}

void showContact(Contacts person){
  cout << "Full name: " << person.getName() << " " << person.getLastName() << endl;
  cout << "Email: " << person.getEmail() << endl;
  cout << "Phone number: " << person.getPhone() << endl;
}





int main() {

  // ##################################################################
  Contacts people[3]; // An array that will contain contacts objects
  bool running = true; // flag variable
  char answer; // to terminate the for loop


  string name, lastName, email; //input
  long number; //input
  // ##################################################################

  // START
  welcomeMessage();

  //debugging();

  while (running) {

    for (int idx = 0; idx < 3; idx++){

      // Ask the user for info

      cout << "Name: " << endl;
      cin >> name;
      cout << "Last name: " << endl;
      cin >> lastName;
      cout << "Email: " << endl;
      cin >> email;
      cout << "Phone number: " << endl;
      cin >> number;


      // Create the contact
      Contacts person = createContact(name, lastName, email, number);

      // Append the contact to the array
      people[idx] = person;

      // Ask the user if he/she wishes to continue
      cout << "Do you want to add another contact? (Y/N)" << endl;
      cin >> answer;
      cout << endl;

      if (answer == 'N' || answer == 'n') {
        cout << "******************************************" << endl;
        cout << "CONTACTS" << endl;
        running = false;
        break;
      }else if (idx == 2 && (answer != 'N' || answer != 'n')){
        cout << "Sorry, you ran out of memory!" << endl;
        cout << "******************************************" << endl;
        cout << "CONTACTS" << endl;
        running = false;
        break;
      } // end if
    } // end for


    // Display the existing contacts
    for (int j = 0; j < 3; j++){

      // Check if the array element contains a Contacts object
      if (people[j].getName() != ""){

        showContact(people[j]);
        cout << endl;

      }else{

        break;
      } //end if
    } // end for

  } // end while

  // END
  farewellMessage();

  return 0;
}


void debugging(){
  // FOR DEBUGGIN ONLY
  // Create a contact using the two different constructors
  Contacts contact1;
  contact1 = createContact("John", "Poe", "hohn.doe@gmail.com", 5552013451);

  showContact(contact1);

  contact1.setLastName("Doe");
  contact1.setEmail("john.doe@gmail.com");

  showContact(contact1);

  cout << "-----------------------------------" << endl;

  Contacts contact2("Jack", "Black", "john.black@gmail.com", 458721365893);

  showContact(contact2);

  contact2.setName("John");
  contact2.setPhone(458721365899);
  showContact(contact2);
}

void welcomeMessage(){
  // Print out a welcome message
  cout << "******************************************" << endl;
  cout << "WELCOME!" << endl;
  cout << "******************************************" << endl;
}

void farewellMessage(){
  // Print out a farewell message
  cout << "******************************************" << endl;
  cout << "GOODBYE!" << endl;
  cout << "******************************************" << endl;
}
