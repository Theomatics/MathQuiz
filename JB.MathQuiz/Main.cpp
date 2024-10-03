
// Assignment 5 - Math Quiz
// Jonathan Bloedorn

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
	// Get two vectors to hold all the possible questions and answers from file
	vector<string> QuestionList; // questions stored in vectors so that one could add more questions easily (though you would need to remember to update both files)
	vector<string> SolutionList;
	string line;

	ifstream ifsQuestions("TestQuestions.txt");
	while (getline(ifsQuestions, line)) { // build vector of question possibilities
		QuestionList.push_back(line);
	}
	ifsQuestions.close();

	ifstream ifsSolutions("TestSolutions.txt");
	while (getline(ifsSolutions, line)) { // get the list of solutions corresponding to the question possibilities
		SolutionList.push_back(line);
	}
	ifsSolutions.close();

	// Ask 3 random questions
	const int NUM_QUESTIONS = 3;
	int scoreEstimate = 0; // just for fun I wanted to guess the score (but obviously i wont catch typos and the like)

	cout << "Welcome to the Math Quiz!\n\n";
	srand(time(NULL));
	ofstream ofsStudentAnswers("QuizResults.txt");
	for (int i = 0; i < NUM_QUESTIONS; i++) {
		string answer; // technically because its a string, even non-number answers are allowed (for this i think its fine)
		int randomNum = rand() % 10 + 1;
		cout << "Question " << i << ": " << QuestionList[randomNum] << " =\nEnter your answer: ";
		cin >> answer;
		cout << "\n";

		ofsStudentAnswers << QuestionList[randomNum] << " = " << answer << "\n";

		if (SolutionList[randomNum] == answer) {
			scoreEstimate++;
		}
	}
	cout << "Results saved to QuizResults.txt";
	ofsStudentAnswers << "\nEstimated Score: " << scoreEstimate;
	ofsStudentAnswers.close();

	(void)_getch();
	return 0;
}
