#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

// Structure creation
struct Animal{
    string animalType;
    int animalCount;
};

// Function prototypes
int arraySizeInput();
int menuChoice();
int addEntry(vector<Animal> &, int, int);
string toLowerCase(string);
void displayEntries(vector<Animal>, int);

int main(){
    // Ask the user for array size
    int arrSize = arraySizeInput();

    // Create vector based on Animal structure
    vector<Animal> animals;

    // Loop through the menu using the user's choice
    int userChoice, indexTracker = 0;
    do{
        userChoice = menuChoice();

        switch(userChoice){
            case 1: indexTracker = addEntry(animals, indexTracker, arrSize); break;
            case 2: displayEntries(animals, arrSize); break;
            default: break;
        }
    } while(userChoice != 3);

    // Say goodbye to user
    cout << "\n\nThanks for using me!\n";

    system("pause");
    return 0;
}

// Ask user for how many entries they want
int arraySizeInput(){
    int entries, looper = 0;

    cout << "Please enter the amount of entries you want(range 1-5): ";
    do{
        cin >> entries;
        if(entries < 1 || entries > 5){
            cout << "Wrong input(out of range). Try again: ";
        } else {
            looper = 1;
        }
    } while(looper == 0);

    return entries;
}

// Present the user with a menu and return their option choice
int menuChoice(){
    int choice, looper = 0;

    cout << "\n\nMenu\n";
    cout << "1. Add entry\n";
    cout << "2. Display entries\n";
    cout << "3. Quit the program\n";

    cout << "Please enter your choice: ";
    do{
        cin >> choice;
        if(choice < 1 || choice > 3){
            cout << "Wrong input(out of range). Try again: ";
        } else {
            looper = 1;
        }
    } while(looper == 0);

    return choice;
}

int addEntry(vector<Animal> &animals, int index, int size){
    string type;
    int count, looper;
    Animal tempAnimal;

    if(index == size){
        cout << "\nYou have maxed out the entries!\n";
    } else {
        for(int i = index; i < size; i++){
            cin.ignore(30000, '\n');

            // Ask for animal type
            cout << "\nEnter the type of animal or enter \'none\' to exit: ";
            getline(cin, type);

            // Check to see if user entered none
            if(type == "none"){
                index = i;
                break;
            } else {
                // Ask for amount of animals
                cout << "Enter the amount of the animal: ";
                cin >> count;

                // Enter the entries into the temp structure, then that into the main vector
                tempAnimal.animalType = type;
                tempAnimal.animalCount = count;
                animals.push_back(tempAnimal);
            }
        }
    }

    return index;
}

// Convert a string to lower case
string toLowerCase(string word){
    string wordToLower = "";

    for(int i = 0; i < word.size(); i++){
        wordToLower += tolower(word[i]);
    }

    return wordToLower;
}

// Display the contents of the arrays
void displayEntries(vector<Animal> animals, int size){
    for(int i = 0; i < size; i++){
        cout << "\nAnimal: " << animals[i].animalType << endl;
        cout << "Count: " << animals[i].animalCount << endl;
    }
}