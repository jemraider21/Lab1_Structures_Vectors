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
int menuChoice();
int addEntry(vector<Animal> &, int);
string toLowerCase(string);
void displayEntries(vector<Animal>);

int main(){
    // Create vector based on Animal structure
	vector<Animal> animals;

	// Loop through the menu using the user's choice
	int userChoice, indexTracker = 0;
	do {
		userChoice = menuChoice();

		switch (userChoice) {
			case 1: indexTracker = addEntry(animals, indexTracker); break;
			case 2: displayEntries(animals); break;
			default: break;
		}
	} while (userChoice != 3);

	cout << endl;
	system("pause");
	return 0;
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

// Add entries to the vector
int addEntry(vector<Animal> &animals, int index){
    string type = "";
	int count, looper = 0;
	Animal temp;

	if (animals.size() == 5) {
		cout << "\nYou have maxed out the entries!\n";
	} else {
		for (int i = index; i < 5; i++) {
			cin.ignore(30000, '\n');

			// Ask for animal type
			cout << "\nEnter the type of animal or enter \'none\' to exit: ";
			getline(cin, type);

			// Check to see if user entered none
			type = toLowerCase(type);
			if (type == "none") {
				index = i;
				break;
			} else {
				// Ask for amount of animals
				cout << "Enter the amount of the animal: ";
				cin >> count;

				// Enter the entries into temp, add temp to main vector
				temp.animalType = type;
				temp.animalCount = count;
				animals.push_back(temp);
				index += i;
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
void displayEntries(vector<Animal> animals){
    for(int i = 0; i < animals.size(); i++){
        cout << "\nAnimal: " << animals[i].animalType << endl;
        cout << "Count: " << animals[i].animalCount << endl;
    }
}