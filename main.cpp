#include <string>
#include <iostream>

using namespace std;

int main() {
    string inputName;
    int age;
    // Set exception mask for cin stream
    cin.exceptions(ios::failbit);

    while (inputName != "-1") {
        try {                          // Use a try statement to set up exception handling
            cin >> inputName;
            if (inputName == "-1") {   // Break out of the loop if the user inputs -1
                break;
            }
            cin >> age;
            cout << inputName << " " << (age + 1) << endl;
        }
        catch (ios_base::failure&) {  // Catch statement block to handle the exception
            age = 0;                   // when a user inputs a string instead of an integer
            cin.clear();               // in the second location, setting age to 0
            cin.ignore(10000, '\n');   // and clearing cin for further use. 
            cout << inputName << " " << age << endl;
        }
    }

    return 0;
}
