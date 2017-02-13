#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

std::string evaluateGuess(int guess, int answer)
{
	std::string output = "";
	if (guess < answer)
	{
		output = "Too Low!\n";
	}
	else if (guess > answer)
	{
		output = "Too High!\n";
	}
	else
	{
		output = "You win!! ";
	}


	return output;
}


int main()
{
	//This outputs the header and directions to the player:
	std::cout << '\t' << "Welcome to Guess My Number" << '\n';



	//Start off by making the computer generate a random number
	const int MAX_NUM = 100;
	const int MIN_NUM = 0;
	
	//something goes here to make it guess
	srand(time(0));
	const int answer = rand() % MAX_NUM + 1;

	int guess = 0;
	int numTries = 0;
	do {
		std::cout << "\nEnter a guess: ";
		std::cin >> guess;
		std::cout << evaluateGuess(guess, answer);
		numTries++;
	} while (guess != answer);
	if (guess == answer) std::cout << "You got it in " << numTries << " tries!" << '\n';

	std::cout << '\n' << "Press any key to exit" << '\n';
	char prompt = ' ';
	std::cin >> prompt;
	return 0;
}