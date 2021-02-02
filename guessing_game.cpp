#include<iostream>
#include<cmath>
#include<climits>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<fstream>

int main() {
	int choice;
	void play_game();
	srand(time(NULL));
	do
	{
		std::cout << "0. Quit" << std::endl << "1. Play Game" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			std::cout << "Sadge" << std::endl;
			return 0;
		case 1:
			play_game();
			break;
		}
	} while (choice != 0);
}

void high_score_update(std::vector<int> high_score)
{
	std::ofstream file("C:\\Users\\20193226\\source\\repos\\2hoursin\\2hoursin\\high_score.txt");
	for (int s = 0; s < high_score.size(); s++)
	{
		file << high_score[s] << std::endl;
	}
}

void print_vector(std::vector<int> guess)
{
	std::cout << "these are your previous guesses: ";
	for (int n : guess)
	{
		std::cout << n << "\t";
	}
	std::cout << std::endl << "it took you " << guess.size() << " amount of tries" << std::endl;

	std::vector<int> high_score;

	std::ifstream data("C:\\Users\\20193226\\source\\repos\\2hoursin\\2hoursin\\high_score.txt");
	int input;
	while (data >> input)
	{
		high_score.push_back(input);
	}

	if (high_score.empty())
	{
		high_score.push_back(guess.size());
	}

	else if (high_score.size() < 10)
	{
		for (int v = 0; v < 10; v++)
		{
			if (guess.size() < high_score[v])
			{
				high_score.insert(high_score.begin() + v, guess.size());
				break;
			}

			else
			{
				high_score.push_back(guess.size());
				break;
			}
		}
	}

	else
	{

		for (int i = 0; i < high_score.size(); i++)
		{
			if (guess.size() < high_score[i])
			{
				high_score.insert(high_score.begin() + i, guess.size());
				high_score.pop_back();
				break;
			}
			else
			{
				//niet relevant
			}
		}

	}
	high_score_update(high_score);
}

void play_game()
{
	std::vector<int> guesses;

	int random = rand() % 251;
	while (true)
	{
		std::cout << "Guess a number: ";
		int guess;
		std::cin >> guess;
		guesses.push_back(guess);
		if (guess == random)
		{
			std::cout << "You win" << std::endl;
			break;
		}
		else if (guess < random)
		{
			std::cout << "The number is too low" << std::endl;
		}
		else
		{
			std::cout << "The number is too high" << std::endl;
		}
	}
	print_vector(guesses);
}
