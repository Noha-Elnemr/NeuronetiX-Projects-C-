#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

struct player {
	string name;
	string difficulty = "easy";
	int highscore = 0;
	int currentscore = 0;
	int successive_correct = 0;
	int successive_wrong = 0;
	int qnumber = 1;
};

player p1;

bool endgame() {
	
	char ans;
	bool done = false;

	cout << "are you sure you want to exit? (y/n) " << endl;
	cin >> ans;

	if (ans == 'y') {
		done = true;
		cout << "thank you for playing!!\n " << endl;
		exit(1);
	}
	else {
		cout << "\n";
		return done;
	}

	return done;
}



void resetgame(player &p1) {
	p1.successive_correct = 0;
	p1.successive_wrong = 0;
	p1.currentscore = 0;
	p1.difficulty = "easy";
	p1.qnumber = 1;

}

struct player startgame(player &p1) {

	resetgame(p1);

	int randomnumber1;
	int randomnumber2;
	int answer;
	int min; 
	int max; 
	bool done = false;



	cout << "enter your name: " << endl;
	cin >> p1.name;


		while (p1.qnumber < 20) {

			srand(time(nullptr));

			if (p1.difficulty == "easy") {
				min = 1;
				max = 5;
			}
			else if (p1.difficulty == "normal") {
				min = 5;
				max = 10;
			}
			else if (p1.difficulty == "hard") {
				min = 5;
				max = 15;
			}

			randomnumber1 = rand() % (max - min + 1) + min;
			randomnumber2 = rand() % (max - min + 1) + min;

			cout << "what is " << randomnumber1 << " multiplied by " << randomnumber2 << " ? " << endl;
			cin >> answer;
			p1.qnumber++;

			if (answer == (randomnumber1 * randomnumber2)) {
				p1.successive_correct++;
				p1.successive_wrong = 0;
				p1.currentscore+=10;
				cout << "correct answer!" << endl;
			}
			else {
				cout << "incorrect answer." << endl;
				p1.successive_wrong++;
				p1.successive_correct = 0;

			}

			if (p1.currentscore > p1.highscore) {
				p1.highscore = p1.currentscore;
			}

			if (p1.successive_correct == 3) {
				if (p1.difficulty == "easy") {
					cout << "youve advanced to the next level: normal." << endl;
					p1.difficulty = "normal";
					p1.successive_correct = 0;
				}
				else if (p1.difficulty == "normal") {
					cout << "youve advanced to the next level: hard." << endl;
					p1.difficulty = "hard";
					p1.successive_correct = 0;
				}
				else {
					cout << "congrats !! youve completed the game !!\n\n" << endl;
					return p1;
				}

			}

			if (p1.successive_wrong == 3) {
				cout << "game over. youve made 3 consecutive mistakes. \n"
					<< "please ask your teacher for help.\n"
					<< "your highscore is: " << p1.highscore << endl;
				exit(1);
			}
		} 
		if (p1.qnumber == 20) {
			cout << "youve reached the maximum number of questions.\n\n" << endl;
			return p1;

		} 

		

}


void help() {

	cout<< "game description:\n " 
		<< "The Multiplication Learning Game is a console-based educational application designed to help users practice multiplication skills.Users are challenged with multiplication questions, and their performance is tracked across different difficulty levels.The game adjusts its difficulty based on the user's performance and provides feedback on their progress.\n\n"
		<< "difficulty levels:\n" 
		<< "there are 3 difficulty levels: easy, normal, hard.\n"
		<< "easy: generates multiplication questions using numbers between 1 and 5.\n"
		<< "normal: generates multiplication questions using numbers between 5 and 10.\n"
		<< "hard: generates multiplication questions using numbers between 5 and 15.\n"
		<< "when you answer 3 consecutive questions correctly, you automatically advance to the next difficulty.\n"
		<< "however, if you answer 3 consecutive questions incorrectly, the game ends.\n\n" << endl;

}

void showhighscore(player &p1) {
	cout << "\nhighscore: \n"
		<< p1.highscore
		<< "\n" << endl;

}


int main() {

	srand(time(nullptr));

	struct player p1;
	int inputnumber;
	bool done = false;

	while (!done) {
		cout << "welcome to the multiplication learning game! \n"
			<< "1. start game \n"
			<< "2. help \n"
			<< "3. show highscore\n"
			<< "4. exit\n"
			<< "please choose an option 1-4" << endl;

		cin >> inputnumber;
		switch (inputnumber) {
		case 1:
			p1 = startgame(p1);
			break;

		case 2:
			help();
			break;

		case 3:
			showhighscore(p1);
			break;

		case 4:
			done = endgame();
			break;
		
		default: 
			cout << "please choose a valid option." << endl;
		}

	}

	return 0;
}