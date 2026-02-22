#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	sf::RenderWindow Bubble_VS_Insertion(sf::VideoMode(1280, 720), "Representation of Algorithm", sf::Style::Close | sf::Style::Titlebar);

	sf::Font font;
	if (!font.loadFromFile("coopbl.TTF")) {
		cout << "Unable to load font" << endl;
	}

	sf::Text bubbleLabel;
	bubbleLabel.setFont(font);
	bubbleLabel.setString("Bubble Sort (O(N^2))");
	bubbleLabel.setCharacterSize(24);
	bubbleLabel.setFillColor(sf::Color::White);
	bubbleLabel.setPosition(10.f, 10.f); 

	sf::Text insertionLabel;
	insertionLabel.setFont(font);
	insertionLabel.setString("Insertion Sort (O(N^2))");
	insertionLabel.setCharacterSize(24);
	insertionLabel.setFillColor(sf::Color::White);
	insertionLabel.setPosition(10.f, 370.f); 

	Bubble_VS_Insertion.setFramerateLimit(100); // Slowing performance speed of computer else it would do all work in milliseconds
	 
	vector<float> numbers; //Vector storing bars of random size

	int NumberOfBars = 100; 

	for (int i = 0; i < NumberOfBars; i++) numbers.push_back(rand() % 300 + 10); //Using rand funciton to generate bars of random size

	vector<float> InsertionNumber = numbers;

	vector<sf::RectangleShape> BubbleArray;

	for (int i = 0; i < NumberOfBars; i++) {
		sf::RectangleShape bar(sf::Vector2f(10.f, numbers[i]));
		bar.setFillColor(sf::Color::White); //Initially all bars are white

		bar.setPosition(i * 12.f, 360 - numbers[i]);

		BubbleArray.push_back(bar);
	} 

	vector<sf::RectangleShape> InsertionArray;

	for (int i = 0; i < NumberOfBars; i++) {
		sf::RectangleShape bar(sf::Vector2f(10.f, InsertionNumber[i]));
		bar.setFillColor(sf::Color::White); //Initially all bars are white
		bar.setPosition(i * 12.f, 720.f - InsertionNumber[i]);

		InsertionArray.push_back(bar);
	}
	
	//Iterators for our Bubble Sort and Inerstion Sort 
	int i = 0; int j = 0;
	int ins_i = 1; int ins_j = 1;

	while (Bubble_VS_Insertion.isOpen()) {

		sf::Event change;

		while (Bubble_VS_Insertion.pollEvent(change)) {
			if (change.type == sf::Event::Closed) Bubble_VS_Insertion.close();
		}

		// --- BUBBLE SORT (Upper Half) ---
		if (i < NumberOfBars) {

			if (j < NumberOfBars - i - 1) {

				if (j > 0) {
					BubbleArray[j - 1].setFillColor(sf::Color::White);
				}
				if (j == 0 && i > 0) {
					BubbleArray[NumberOfBars - i].setFillColor(sf::Color::Green); // Mark sorted area as Green
				}

				BubbleArray[j].setFillColor(sf::Color::Red); //Red bars are being checked for sorting
				BubbleArray[j + 1].setFillColor(sf::Color::Red);

				//If jth + 1  bar is greater than jth bar swap it 
				if (numbers[j] > numbers[j + 1]) {

					swap(numbers[j], numbers[j + 1]);

					//Updating bars visually
					BubbleArray[j].setSize(sf::Vector2f(10.f, numbers[j]));
					BubbleArray[j].setPosition(j * 12.f, 360.f - numbers[j]);

					BubbleArray[j + 1].setSize(sf::Vector2f(10.f, numbers[j + 1]));
					BubbleArray[j + 1].setPosition((j + 1) * 12.f, 360.f - numbers[j + 1]);

				}
				j++; //Iterating left to right
			}
			else {
				j = 0; i++;//Treat this as nested loop where once inner loop finishes i iterates j resets to 0
			}
		}

		// --- INSERTION SORT (Bottom Half) ---
		if (ins_i < NumberOfBars) {

			// Make them White again
			if (ins_j < NumberOfBars - 1) {
				InsertionArray[ins_j + 1].setFillColor(sf::Color::White);
			}

			InsertionArray[ins_j].setFillColor(sf::Color::Blue); // Blue bars are what being checked right now

			//Preventing running out of boundary
			if (ins_j > 0) {
				InsertionArray[ins_j - 1].setFillColor(sf::Color::Blue);
			}

			//If any bar to the left of jth bar is bigger than jth bar we swap them
			if (ins_j > 0 && InsertionNumber[ins_j] < InsertionNumber[ins_j - 1]) {

				// Swap the bars
				swap(InsertionNumber[ins_j], InsertionNumber[ins_j - 1]);

				// Updating the bigger jth - 1 bar which was to the left of jth visually
				InsertionArray[ins_j - 1].setSize(sf::Vector2f(10.f, InsertionNumber[ins_j - 1]));
				InsertionArray[ins_j - 1].setPosition((ins_j - 1) * 12.f, 720.f - InsertionNumber[ins_j - 1]);

				// Updating the jth bar which was smaller than jth - 1 bar to the left of it visually
				InsertionArray[ins_j].setSize(sf::Vector2f(10.f, InsertionNumber[ins_j]));
				InsertionArray[ins_j].setPosition(ins_j * 12.f, 720.f - InsertionNumber[ins_j]);

				ins_j--; // Moves our bar to the left
			}
			else {
				// If no bigger bar to it left exists it is already sorted so we skip it
				InsertionArray[ins_j].setFillColor(sf::Color::White);

				//Coloring sorted bar to white
				if (ins_j > 0) {
					InsertionArray[ins_j - 1].setFillColor(sf::Color::White);
				}

				ins_i++;
				ins_j = ins_i; // Now moving onto next bar to checl
			}
		}

		//Representing logic on the Window
		Bubble_VS_Insertion.clear();
		for (int i = 0; i < BubbleArray.size(); i++) Bubble_VS_Insertion.draw(BubbleArray[i]);
		for (int i = 0; i < InsertionArray.size(); i++) Bubble_VS_Insertion.draw(InsertionArray[i]);

		Bubble_VS_Insertion.draw(bubbleLabel);
		Bubble_VS_Insertion.draw(insertionLabel);
		Bubble_VS_Insertion.display();

	}
}