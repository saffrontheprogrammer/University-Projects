// Libraries
#include <iostream> // library to use input/output feature
#include <string> // library to manipulate strings
#include <conio.h> // console input/output functionality
#include <fstream> // file stream library to allow output file writing
#include <windows.h> // Allows access to Windows API (Application Programming Interface) to control windows functions through the console . Used to play music

using namespace std; // Requests use of pre loaded standard library - Removes the need to use std:: before expressions

// Colours
const string RED = "\033[31m"; const string BLUE = "\033[34m"; const string RESET = "\033[0m";

// Defined Variables
float depositAmount;
float withdrawal;
char option; 
string firstName,lastName;
// declared option as character input & firstName/lastName variables as strings

// Global Variable
float NewBalance = 0.0; // Sets initial bank balance to 0

// Functions
void playMusic(); void ViewBalance(); void DFunds(); void WDFunds(); void StopTheMusic();
/* void playMusic(); - Plays music in the console
void ViewBalance(); - menu option function - view balance
void DFunds(); - menu option function - deposit funds
void WDFunds(); - menu option function - withdraw funds
void StopTheMusic(); - menu option to stop music from playing
void means that function isn't declared as anything. Just executes statements without outputting anything that would usually be specified.*/


#pragma comment(lib, "winmm.lib") // Library that allows multimedia functions. Plays music in console

// Main Code Block // Nested Code

int main() { // declared main as an integer, to return the value of 0 for a validation check (to check that code is working)

	playMusic();
	cout << "Welcome to your favourite " << endl;
	cout << RED << R"(
 __   ___     _             _   ___            _   
 \ \ / (_)_ _| |_ _  _ __ _| | | _ ) __ _ _ _ | |__
  \ V /| | '_|  _| || / _` | | | _ \/ _` | ' \| / /
   \_/ |_|_|  \__|\_,_\__,_|_| |___/\__,_|_||_|_\_\
                                                   )" << '\n'; // ASCII art - R" used for ASCII to print text without losing shape.

	do { // do while loop to check if first/last names are entered, and if empty to request user types them in.
		cout << RESET << "Please enter your first name (press enter), then last name (press enter) : " << endl;
		getline(cin, firstName);
		getline(cin, lastName);
		if (firstName.empty() || lastName.empty()) { // error check. Displays error message in red if nothing inputted
			cout << RED << "You haven't entered the required information. Please try again!  " << endl;
		}
	} while (firstName.empty() || lastName.empty()); 

	cout << "Hi " << firstName << " " << lastName << ", Welcome to your account\n" << endl; // Welcome text on console
	cout << "Your balance starts on 0.\n \nPlease deposit funds first before attempting to withdraw/see balance :)" << endl;

	do {
		cout << "\nSelect an option using the letter keys to continue" << endl;
		cout << "\nView Balance (A)\nDeposit Funds (B)\nWithdraw Funds (C)\nStop Music (D)\nExit (E)\n";
		//switch looks at option and decides which function to execute
		option = _getch();
		switch (option) {
		case 'A': case 'a':
			ViewBalance();
			break;
		case 'B': case 'b':
			DFunds();
			break;
		case 'C': case 'c':
				WDFunds();
				break;
		case 'D': case 'd':
				StopTheMusic();
				break;
		case 'E': case 'e':
			exit(0);
		default:
			cout << "Invalid key pressed, please try again" << endl; break; // error check for invalid keys pressed
		}
	} while (option != 'E' && option != 'e');


	return 0;
	system("pause");
}

// Definitions of Functions

void ViewBalance() { // Show balance on console
	cout << "Your balance is: \x9C" << NewBalance << endl;
}

void DFunds() { // Deposit funds in account
	cout << "Enter amount to deposit: \x9C";
	cin >> depositAmount;
	if (depositAmount > 0) {
		NewBalance += depositAmount;
		cout << "You now have " << "\x9C" << NewBalance << " in your account" << endl; // Displays new balance
	}
	else {
		cout << "Invalid amount. Please input amount you'd like to deposit again." << endl; // error check for anything not a float
	}
}

void WDFunds() { // Withdraw funds from account and show new amount on console
	cout << "Enter amount you wish to withdraw: \x9C"; // \x9C is character code for £ sign computer understands
	cin >> withdrawal;
	if (withdrawal > 0 && withdrawal <= NewBalance) {
		NewBalance -= withdrawal;
		cout << "You have withdrawn: \x9C" << withdrawal << ". Your new balance is \x9C" << NewBalance << endl;
	}
	else {
		cout << "Invalid withdrawal amount or insufficient funds." << endl; // error check 
	}
}

void playMusic() { // Plays music in console
	PlaySound(TEXT("For the Love of Money.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(5000); // Adjust the duration as needed (milliseconds)
}

void StopTheMusic() {
	PlaySound(NULL, 0, 0); // Stops music from playing
	cout << "Music stopped." << endl;
}