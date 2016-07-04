#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

void genRandNumber(vector<int>&, int);

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
			genRandNumber(number, digits);
			break;
		}
	}while(true);



	return 0;
}

void genRandNumber(vector<int>& number, int numDigits){
	for(int i = 0; i < numDigits; i++){
		number.push_back(rand() % 10);
	}
	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << endl;
	}
}