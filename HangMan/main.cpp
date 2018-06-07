/**************************************************************************************************
 * @Created by Yu Tang Lin
 * @Date: 2018/06/07
 * @Project: Simple HangMan Game 
 * @Rule: Player need to figure out the encrypted message to win the game. (Note: only alphabet
				will be encrypted.) Player has 5 chances to guess the letter in message to help them 
				figure out the message. If the player cannot figure out the message after 5 guess, 
				the player lose.
 * *************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Function Prototype
string encrypt_message(string encrypted_message);
bool check_guess(char guess, string user_message);
void display(vector<char> wrong_guesses);
bool check_completion(string encrypted_message, string user_message);


int main() {
	
	/**********************************************************************
	 * Variables
	 * *********************************************************************/
	string user_message{};
	string encrypted_message{};
	vector<char> wrong_guess {};
	int lives = 5;
	bool correct = true;
	bool win = false;
	char guess{};
	
	/*****************************************************************
	 * Game Setup
	 * Note: Get the message from user and encypted it
	 * ***************************************************************/
	cout << "Enter a message: ";
	getline(cin, user_message);
	encrypted_message = user_message;
	encrypted_message = encrypt_message(encrypted_message);
	cout << "Encrypting ....................... Done!" << endl;
	cout << "#####################################################" << endl;
	

	do{
		cout << "Secret Message: " << endl;
		cout << "                  " << encrypted_message << endl;
		display(wrong_guess);
		cout << "Life: " << lives << endl;
		cout << "###############################################" << endl;
		cout << "Enter an alphabet: ";
		cin >> guess;
		correct = check_guess(guess, user_message);
		
		if(correct){ 
			for (size_t i{0}; i < encrypted_message.size(); i++){
				if(guess == user_message[i])
					encrypted_message[i] = guess;
			}
			win = check_completion(encrypted_message, user_message);
		} else{
			wrong_guess.push_back(guess);
			lives-=1;
		}
	}while( lives > 0 && win == false );
	if(lives==0){
		cout << "##########################################" << endl;
		cout << "You have failed~ T_T" << endl;
	}
	return 0;
	}

string encrypt_message(string encrypted_message){
	for(size_t i{0}; i<encrypted_message.length(); i++){
		if(isalpha(encrypted_message[i]))
			encrypted_message.at(i) = '-' ;
	}
	return encrypted_message;
}
	
bool check_guess(char guess, string user_message){
	if(user_message.find(guess)!=string::npos)
		return true;
	return false;
}

void display(vector<char> wrong_guesses){
	cout << "Wrong guesses: ";
	for(size_t i{0}; i<wrong_guesses.size(); i++)
		cout << wrong_guesses[i] << " ";
	cout << endl;
}

bool check_completion(string encrypted_message, string user_message){
	if(encrypted_message==user_message){
		cout << "##############################################" << endl;
		cout << "Horray~ You have decrypted the message!!" << endl;
		return true;
	}
	return false;
}
