#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<stdlib.h>
#include<time.h>

using namespace std;

int genRandNumber();
void makeHiddenNumber(vector<int>&, int);
void playPlayer(vector<int>);
bool convertGuess(int, vector<int>&);
bool checkAnswer(const vector<int>, const vector<int>);

int main(){

	vector<int> number;
	srand(time(NULL));

	//Working only on player trying to win
	//Will then work on computer trying to guess players number after
	do{
		int digits;
		cout << "Welcome to a game of Cows and Bulls! How many digits would you like to play with?\n";
		cout << "Enter a number between 3 and 6: ";
		cin >> digits;
		if(digits < 3 || digits > 6){
			cout << "Number needs to be between 3 and 6!\n";
		}else{
			makeHiddenNumber(number, digits);
			break;
		}
	}while(true);
	for (int i = 0; i < number.size(); i++) {
		cout << number[i];
	}
	cout << endl;
	playPlayer(number);

	return 0;
}

int genRandNumber() {
	return rand() % 10;
}

void makeHiddenNumber(vector<int>& number, int numDigits){
	set<int> seenBefore;
	while (number.size() != numDigits) {
		int num = genRandNumber();
		if(number.size() != 0 || num != 0) {
			if (seenBefore.count(num) == 0) {
				number.push_back(num);
				seenBefore.insert(num);
			}
		}
	}
}

void playPlayer(vector<int> number){

	bool finished = false;
	vector<int> guess;

	while (!finished){
		int tempGuess;
		cout << "Please enter your guess: ";
		cin >> tempGuess;

		if(!convertGuess(tempGuess, guess)) {
			cout << "Check to make sure you have no duplicate digits!\n";
		}else if(guess.size() != number.size()) {
			cout << "Check to make sure you entered the correct number of digits\n";
			cout << "Remember, no leading zeros!\n";
		}else{
			reverse(guess.begin(), guess.end());
			finished = checkAnswer(guess, number);
		}
		guess.clear();
	}
}

bool convertGuess(int tempGuess, vector<int>& guess){
	set<int> seeBefore;
	while(tempGuess != 0){
		if(seeBefore.count(tempGuess % 10) == 0) {
			guess.push_back(tempGuess % 10);
			seeBefore.insert(tempGuess % 10);
			tempGuess /= 10;
		}else{
			return false;
		}
	}
	return true;
}

bool checkAnswer(const vector<int> guess, const vector<int> correct){
	int bulls, cows;
	bulls = cows = 0;
	for(int i = 0; i < guess.size(); i++){
		for(int j = 0; j < correct.size(); j++){
			if(guess[i] == correct[j] && i == j){
				bulls++;
			}else if (guess[i] == correct[j]){
				cows++;
			}
		}
	}

	cout << "There are " << bulls << " bulls and " << cows << " cows.\n";
	if(bulls == correct.size()){
		cout << "Congratulations! You figured out the number!\n";
		return true;
	}

	return false;
}