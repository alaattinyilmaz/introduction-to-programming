#include <iostream>
#include <fstream>
#include <string>
#include "strutils.h"
#include <sstream>

using namespace std;


bool timeChecker(string time) // This function check the input time is correct format or not
{

	if (time.length() != 5)
	{
		return false;
	}

	string firstdigits = time.substr(0,2);
	int intfirstdigits = atoi(firstdigits);

	string lastdigits = time.substr(3,2);
	int intlastdigits = atoi(lastdigits);

	if(intfirstdigits > 23 || intfirstdigits < 0) // Checking first two digits between 23 and 0
	{
		return false;
	}

	else if(intlastdigits < 0 || intlastdigits > 59) // Checking last two digits between 0 and 59
	{
		return false;
	}

	else
		return true;


}



int timeconverter(string time) // This function converts given time into 4 digits integer

{

	string timewithoutdots = time.substr(0,2) + time.substr(3,2); // Converting time without dots format ex: 13:00 --> 1300

	int newtime = atoi(timewithoutdots);
	return newtime;
}


int main()

{
	string route;
	string times;
	string departurelocation;
	string starttime;

	ifstream inputroute;
	ifstream inputtimes;

	bool opencheck = true;

		while(opencheck == true)
		{
			cout << "Please enter a filename for route database: ";
			cin >> route;
			inputroute.open(route.c_str()); // Openining route database

			if(inputroute.fail()) // Program checking opening of the input file
			{cout << "cannot open routes database file" << endl;}

			else 
			{opencheck = false;}

		}

		bool checkdb = true;

		while(checkdb == true)
		{
			cout << "Please enter a filename for time database: ";
			cin >> times;
			inputtimes.open(times.c_str());

			if(inputtimes.fail()) // Program checking opening of the input file
			{
				cout << "cannot open times database file" << endl;
			}

			else 
			{
				checkdb = false;
				inputtimes.close();
			}

			
		}



	while (departurelocation != "EXIT") // End condition: If user enters "EXIT" the program will be closed
	{
		

		cout << "Please enter departure location: ";
		cin >> departurelocation;
		if(departurelocation != "EXIT")
		{


			bool startcheck = true;
			bool timecheck = true;

			while(startcheck == true)
			{
				cout << "Please enter start time of travel: ";
				cin >> starttime;

				timecheck = timeChecker(starttime); // checking given time is in correct format

				if(timecheck == false)
				{
					cout << "Time is not in the correct format" << endl;
				}	

				else
				{
					cout << "The search results are in the file: " + departurelocation + ".txt" << endl;
					startcheck = false;
				}

			}



			string rline, tline, foundtime;
			string routeID, idtimes;
			string inputdeparture;
			string arrival;

			ofstream output;
			string outputname = departurelocation + ".txt";

			output.open(outputname.c_str());
			inputroute.close();
			inputroute.open(route.c_str());
			while(getline(inputroute, rline)) // Taking lines of routes.txt one by one
			{

				istringstream routefind(rline); // Parsing lines 

				routefind >> routeID; // First thing in the line is the routeID

				routefind >> inputdeparture; // Second thing in the line is the departure
				if (inputdeparture == departurelocation) // Checking them whether they are same
										{

											inputtimes.open(times.c_str());
											while(getline(inputtimes, tline)) // Taking the lines of times.txt one by one
														{
															
														istringstream timefind(tline);

														timefind >> idtimes;

														while(idtimes == "" || idtimes == " " || idtimes == "\t") // Ignoring blanks and tabs
														{timefind >> idtimes;}
														
														if(idtimes == routeID) // If ID's are same, takes this departure time from times.txt which has this ID
														{

															timefind >> foundtime;	// First thing after the ID in the times.txt is time
															while(foundtime == "" || foundtime == " " || foundtime == "\t") // Ignoring blanks and tabs
															{timefind >> foundtime;}

															if(timeconverter(starttime) <= timeconverter(foundtime)) // Checking times which are after the given time
															{
															routefind >> arrival; // First thing after the time in the time.txt is arrival location
															
															while(arrival == "" || arrival == " " || arrival == "\t") // Ignoring blanks and tabs
															{routefind >> arrival;}
																output << departurelocation << " " << arrival << " " << foundtime << endl;
																// Writing the arrival locations and departure times of these vacations

															}

														
														
														}
													
														}
											inputtimes.close();
				
										}
			


			}




			// Closing the open files
			output.close();
			inputtimes.close();
			inputroute.close();

		}


	}
}













