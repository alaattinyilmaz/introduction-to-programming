/*

EMÝR ALAATTÝN YILMAZ
19705
This program takes boardgames as input and sort them according to their yearly sales.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "strutils.h"
#include <vector>

using namespace std;

struct GameMarket // A struct which named GameMarket it has three component gamename, company and sale as seen below
{

	string gamename;
	string company;
	int sale;

};

bool Exist(vector <GameMarket> & crowdedvector, string & gamename, int & sale)
	// This function check a taken gamename is absent in a vector or not
{
	unsigned int k;

	for(k = 0; k < crowdedvector.size(); k++)
	{
		if(crowdedvector[k].gamename == gamename) // If they are equal that means there is a same component in the vector
		{
			crowdedvector[k].sale = crowdedvector[k].sale + sale; // If there is same boardgame name this sums up the all sales of games 
			return true;
		}


	}
	return false;

}

void SortVector (vector <GameMarket> & cleanvector)
	// Selection sort from lecture notes
{

	int j, k, minIndex, numElts = cleanvector.size();

	GameMarket temp;

	for(k=0; k < numElts - 1; k++)
	{  
		minIndex = k;             // minimal element index

		for(j=k+1; j < numElts; j++)
		{  
			if (cleanvector[j].sale < cleanvector[minIndex].sale)
			{ 
				minIndex = j;     // new min, store index
			}

			else if(cleanvector[j].sale == cleanvector[minIndex].sale)
			{
				if(cleanvector[j].company > cleanvector[minIndex].company)
				{
					minIndex = j;
				}

				else if(cleanvector[j].company == cleanvector[minIndex].company)
				{
					if(cleanvector[j].gamename > cleanvector[minIndex].gamename)
					{
						minIndex = j;
					}
				}
			}
		}
		temp = cleanvector[k];         // swap min and k-th elements
		cleanvector[k] = cleanvector[minIndex];
		cleanvector[minIndex] = temp;
	}


}



void DeleteOldies(vector <GameMarket> & crowdedvector)
	// This function deletes the recurring components of a given vector
{
	vector <GameMarket> cleanvector; // I created a new vector it is like its name "clean" it will has just one of the recurring components of crowdedvector

	unsigned int i;
	for(i = 0; i < crowdedvector.size(); i++)
	{

		if(!Exist(cleanvector, crowdedvector[i].gamename, crowdedvector[i].sale)) // If this component does not occur before it adds this component to new cleanvector
		{
			cleanvector.push_back(crowdedvector[i]);
		}

	}

	crowdedvector = cleanvector; // Crowdedvector is being clean vector, their recurring components were deleted


}

void GetWord(istringstream & wantword, string & takename)
	// This function takes words until it sees ';' and deletes ';' in it
{
	string resultname = "";


	do
	{	
		wantword >> takename;
		resultname = resultname + " " + takename;
	}
	while(resultname.at(resultname.size()-1) != ';');

	takename = resultname.substr(1,resultname.size()-2); // Deleting first unnecessary blank and the last ';'
	ToUpper(takename); // It converts the letters of the string to upper cases

}
int main()

{


	ifstream inputbgame; // Input file

	string fboard; 

	do
	{
		cout << "Please enter a filename for Board Game file: ";
		cin >> fboard;

		inputbgame.open(fboard.c_str()); // opening of input file

		if(inputbgame.fail())
		{
			cout << "Can not find the specified file." << endl;
		}
	}

	while(inputbgame.fail()); 


	cout << "Please enter a filename for output file: ";

	ofstream output;

	string oname;
	cin >> oname;

	output.open(oname.c_str());

	string line, gname, month, companyname, gsale;
	int convertsale;
	vector <GameMarket> gamerecords; // Creating a vector which doesn't have any components

	while(getline(inputbgame, line)) // Taking lines of input file one by one
	{

		istringstream wantword(line); // This helps splitting words of line

		GetWord(wantword, gname); // Getting gamename

		GameMarket game; // Creating a game object in GameMarket struct
		game.gamename = gname; // Gamename of the game object is gname now

		GetWord(wantword, month); // Getting month

		GetWord(wantword, companyname); // Getting company name
		game.company = companyname; // Company name of the game object is companyname now


		wantword >> gsale; // Getting sale
		convertsale = atoi(gsale); // Converting string into integer 

		game.sale = convertsale; 

		gamerecords.push_back(game); // Game object is the member of vector now


	}

	DeleteOldies(gamerecords); // Deleting recurring elements of vector
	int p;
	int rank = 1;

	SortVector(gamerecords); // Sorting the vector in ascending order according to boardgame sales

	output << "RANK, COMPANY, GAME, SALES"<< endl;

	for (p = gamerecords.size()-1; p >= 0; p--)
		// We sorted the vector ascending order but we will print them in output file inversely by this for loop
			// Which means it is now inverse of ascending, it is descending.
	{
		output << rank << ", "<< gamerecords[p].company << ", "  << gamerecords[p].gamename << ", " <<gamerecords[p].sale << endl;
		rank++;
	}

	inputbgame.close();
	output.close();

	cout << "Results are in the file: " << oname << endl;

	return 0;
}