#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){

    string gameAnswers[6] = {"Definitely!", "Most likely!", "Reply hazy, try again!", "Ask again later!", "Don't count on it!", "My sources say no!"};
    string userQuestion;
    char shakeAgain;
    int shakeBall;
    bool isRunning;

    do {

        cout << "Ask a question: " << endl;
        getline(cin, userQuestion);

        srand(time(0));
        shakeBall = rand() % 6;

        cout << "\n---------------------------------" << endl;
        //cout << userQuestion << endl;
        cout << gameAnswers[shakeBall] << endl;


        try {
            cout << "Shake again? (Y/N)" << endl;
            cin >> shakeAgain; // This line actually adds the character + the newline character '\n'
            cin.get(); // This is to get rid of that newline character

            if (shakeAgain == 'Y' || shakeAgain == 'y') {
                isRunning = true;

            } else if (shakeAgain == 'N' || shakeAgain == 'n'){
                cout << "Thank you for playing!" << endl;
                isRunning = false;

            } else {
                throw 99;
            }
        } catch (...) {
            cout << "Something went wrong!" << endl;
            cout << "Terminating..." << endl;
            isRunning = false;
        }

    } while (isRunning);

    return 0;
}
