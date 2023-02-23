/**
THIS EXAMPLE WAS TAKEN FROM BUCKY ROBERTS INTRODUCTORY COURSE TO C++
https://github.com/buckyroberts
**/


#include <iostream>
#include <fstream>

using namespace std;

// prototype functions
int getWhatTheyWant();
void displayItems(int x);


// main function
int main(){

  int whatTheyWant;
  bool isRunning = true;


  while (isRunning){
    whatTheyWant = getWhatTheyWant();

    switch(whatTheyWant){
      case 1:
        displayItems(1);
        break;
      case 2:
        displayItems(2);
        break;
      case 3:
        displayItems(3);
        break;
      case 4:
        isRunning = false;
        break;
      default:
        cout << "I don't recognize this option! Try again: " << endl;
    }
  }

  return 0;
}

// getWhatTheyWant function
int getWhatTheyWant(){
  int choice;

  cout << "*************************************************" << endl;
  cout << "MENU: " << endl;
  cout << "\n1 - just plain items" << endl;
  cout << "2 - helpful items" << endl;
  cout << "3 - harmful items" << endl;
  cout << "4 - quit program\n" << endl;

  cin >> choice;
  return choice;
}

// displayItems function
void displayItems(int x){
  ifstream objectsFile("objects.txt");
  string objectName;
  double objectPower;

  if (objectsFile.is_open()){
    if (x == 1){
      while (objectsFile >> objectName >> objectPower){
        if (objectPower == 0){
          cout << objectName << ' ' << objectPower << endl;
        }
      }
    }else if (x == 2){
      while (objectsFile >> objectName >> objectPower){
        if (objectPower > 0){
          cout << objectName << ' ' << objectPower << endl;
        }
      }
    }else if (x == 3){
      while (objectsFile >> objectName >> objectPower){
        if (objectPower < 0){
          cout << objectName << ' ' << objectPower << endl;
        }
      }
    }
  }else{
    cout << "Something went wrong when opening the file!" << endl;
  }
}
