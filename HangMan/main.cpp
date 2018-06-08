#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Function Prototype
string encrypt_message(string encrypted_message);
bool check_guess(char guess, string user_message, string &encrypted_message);
void display_wrong_guess(vector<char> wrong_guesses);
bool check_completion(string encrypted_message, string user_message);
void  display_setting(string &user_mesage, string &encrypted_message);

int main() {
	//Variables
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
	display_setting(user_message, encrypted_message);

	do{
		cout << "Secret Message: " << endl;
		cout << "                  " << encrypted_message << endl;
		display_wrong_guess(wrong_guess);
		cout << "Life: " << lives << endl;
		cout << "###############################################" << endl;
		cout << "Enter an alphabet: ";
		cin >> guess;
		
		correct = check_guess(guess, user_message, encrypted_message);
		
		if(correct)
			win = check_completion(encrypted_message, user_message);
		else{
			wrong_guess.push_back(guess);
			lives-=1;
		}
	}while( lives > 0 && win == false );
	
	if(lives==0){
		cout << "##########################################" << endl;
		cout << "You have failed~ T_T" << endl;
		cout << "The answer is: " << user_message << endl;
	}
	
	return 0;
}

/**
 * @brief This function display the setting and get the user input message and encrypted it
 * @param user_message (pass by reference)
 * @param encrypted_message (pass by reference)
 */
void display_setting(string &user_message, string &encrypted_message){
	cout << "Welcome to Hang Man!!!" << endl;
	do{
		cout << "Enter a message: ";
		getline(cin, user_message);
		if(user_message.size()<=0)
			cout <<"Please enter something..." << endl;
	}while(user_message.size()<=0);
	encrypted_message = encrypt_message(user_message);
	cout << "Encrypting ....................... Done!" << endl;
	cout << "#####################################################" << endl;
}

/**
 * @brief encrypt the user message
 * @param encrypted_message
 * @return encrypted_message
 */
string encrypt_message(string user_message){
	for(size_t i{0}; i<user_message.length(); i++){
		if(isalpha(user_message[i]))
			user_message.at(i) = '-' ;
	}
	return user_message;
}
/**
 * @brief - Check if the user guess is found in the original message. If the guess is found, decrypt the encrypted message. Otherwise dont 
 * 				  do anything and return false
 * @param guess - character guess
 * @param user_message - the original message
 * @param encrypted_message - the encrypted message
 * @return true if the guess is find in the original message ( and changed the encrypted message) else return false
 */
bool check_guess(char guess, string user_message, string &encrypted_message){
	if(user_message.find(tolower(guess))!=string::npos || user_message.find(toupper(guess))!=string::npos ){
		for (size_t i{0}; i < encrypted_message.size(); i++){
			if(tolower(guess) == tolower(user_message[i]))
				encrypted_message[i] = user_message[i];
		}
		return true;
	}
	return false;
}

/**
 * @brief Display the past wrong guesses
 * @param wrong_guesses
 */
void display_wrong_guess(vector<char> wrong_guesses){
	cout << "Wrong guesses: ";
	for(size_t i{0}; i<wrong_guesses.size(); i++)
		cout << wrong_guesses[i] << " ";
	cout << endl;
}
/**
 * @brief Check whether encrypted message have been solved
 * @param encrypted_message
 * @param user_message
 * @return 
 */
bool check_completion(string encrypted_message, string user_message){
	if(encrypted_message==user_message){
		cout << "##############################################" << endl;
		cout << "Horray~ You have decrypted the message!!" << endl;
		return true;
	}
	return false;
}
