#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
constexpr int length = 35;

void initDeck(vector<int>& Deck, int length)
{
	for (int i = 0; i < length; i++)
	{
		Deck.push_back(i + 1);
	}
}

void shuffleTheDeck(vector<int>& Deck)
{
	int cardPosition;
	for (size_t i = 0; i < Deck.size(); i++)
	{
		cardPosition = rand() % Deck.size();
		if (i != cardPosition)
		{
			swap(Deck.at(i), Deck.at(cardPosition));
		}
	}
}

void showDeck(vector<int>& Deck)
{
	for (size_t i = 0; i < Deck.size(); i++)
	{
		cout << Deck.at(i) << ", ";
	}
	cout << endl;
}

int main()
{
	srand(time(0));
	vector<int> Deck;
	initDeck(Deck, length);

	cout << "Our deck of cards initially looks like this:" << endl;
	showDeck(Deck);
	shuffleTheDeck(Deck);
	cout << endl
		 << "Now she is: " << endl;
	showDeck(Deck);

	return 0;
}
