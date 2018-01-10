/*

EMÝR ALAATTÝN YILMAZ
19705

This program is used to calculate letter grade according to course grade
based on midterms, final and homework grade which is taken as inputs from user.

*/

#include <iostream>
#include <string>

using namespace std;

void letterGrader(string name, string surname, double course_grade)
	// function 4: Gives out letter grades according to course grade and also it takes arguments from function3 (GradeCalculator)
{

	// Below: Letter grades according to course grades
	string letter_grade;
	if (course_grade > 90) { letter_grade = "A"; }
	else if (course_grade > 85) { letter_grade = "A-"; }
	else if (course_grade > 80) { letter_grade = "B+"; }
	else if (course_grade > 75) { letter_grade = "B"; }
	else if (course_grade > 70) { letter_grade = "B-"; }
	else if (course_grade > 60) { letter_grade = "C+"; }
	else if (course_grade > 55) { letter_grade = "C"; }
	else if (course_grade > 50) { letter_grade = "C-"; }
	else if (course_grade > 45) { letter_grade = "D+"; }
	else if (course_grade > 40) { letter_grade = "D"; }

	cout << name << " " << surname << ", you get " << letter_grade;

}

void gradeCalculator(string name, string surname, int midterm1, int midterm2, int finalgrade, double hw_average) 
	// function 3: Calculates average grade and checks passing or fail conditions
{
	if ((midterm1 + midterm2) < 40) // Checking sum of midterms if it is lower than 40
	{ 
		cout << name << " " << surname << ", your lack of grades in your midterms disturbs me: You get F ";
	}

	else if(finalgrade < 20)  // Checking final if it is lower than 20
	{
		cout << name << " " << surname << ", your lack of point in your final disturbs me: You get F";
	}

	else {

		double exam_average;
		exam_average = (((midterm1 + midterm2) * 0.25) + (finalgrade * 0.35)) / 0.85; // Calculating exam average

		if (exam_average < 35) // Checking exam average if it is lower than 35
		{ 
			cout << name << " " << surname << ", your lack of average grades disturbs me: You get F";
		}

		else {

			double course_grade;
			course_grade = ((midterm1 + midterm2) * 0.25) + (finalgrade * 0.35) + (hw_average * 0.15); // Calculating course grade



			// Checking homework average is greater than double of exam average. If it occurs letter grade will be lowered
			if (hw_average > 2 * exam_average) 
			{
				if (course_grade > 90) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get A-"; }

				else if (course_grade > 85) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get B+"; }

				else if (course_grade > 80) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get B"; }

				else if (course_grade > 75) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get B-"; }

				else if (course_grade > 70) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get C+"; }

				else if (course_grade > 60) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get C"; }

				else if (course_grade > 55) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get C-"; }

				else if (course_grade > 50) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get D+"; }

				else if (course_grade > 45) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get D"; }

				else if (course_grade > 40) 
				{ cout << name << " " << surname << ", unfortunately your grade will be lowered" << endl << name << " " << surname << ", you get F"; }

			}

			else { if (course_grade < 40) { cout << name << " " << surname << ", you failed this course: F";  }

			else { letterGrader(name, surname, course_grade); // It calls function 4 to calculate course grade as a letter grade
			}

			}

		}


	}

}





void inputChecker(string name, string surname, int midterm1, int midterm2, int finalgrade, double hw_average) 
	// function 2: Takes inputs from inputTaker function and checks them 
{
	if (midterm1 < 0 || midterm2 < 0 || finalgrade <0) // Checking midterms whether grades are below zero
	{
		cout << name << " " << surname << ", your exam grades cannot be below 0, we aren't that harsh";
	}

	else if (midterm1 > 100 || midterm2 > 100 || finalgrade > 100) // Checking midterms whether grades are above 100
	{
		cout << name << " " << surname << ", over 100 point in an exam? We don't give bonuses, we aren't that nice either";
	}

	else if (hw_average > 100) // Checking homework average if it is above 100
	{
		cout << name << " " << surname << ", your homework grade cannot be more than 100, we never give out bonuses in a homework, sorry";
	}

	else if (hw_average < -100) // Checking homework average if it is below -100
	{
		cout << name << " " << surname << ", we never give less than -100 in a homework, sorry";
	}


	else {
		gradeCalculator(name, surname, midterm1, midterm2, finalgrade, hw_average); // It calls function3 to calculate course grade 
	}
} 

void inputTaker()
	// function 1: Takes inputs from the user
{ 

	string name, surname;
	int midterm1, midterm2, finalgrade;
	double hw_average; // homework average

	cout << "Please enter your name and surname: ";
	cin >> name;
	cin >> surname;

	cout << name << " " << surname << ", Please enter your midterm and final grades: ";
	cin >> midterm1;
	cin >> midterm2;
	cin >> finalgrade;
	cout << name << " " << surname << ", please enter the average score of your homeworks: ";
	cin >> hw_average;

	inputChecker(name, surname, midterm1, midterm2, finalgrade, hw_average); // It calls function2 to check the inputs entered by user

} 


int main()

{

	cout << "This program calculates your average grade and gives your letter grade." << endl;
	inputTaker();
	cout << endl << endl; 
	inputTaker();

	cin.get();
	cin.ignore();
	return 0;

}