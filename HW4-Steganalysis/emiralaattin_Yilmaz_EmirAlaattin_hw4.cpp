/*
EMÝR ALAATTÝN YILMAZ
19705
This program removes certain characters from a scrambled text to create extracted text and reveals the hidden message from extracted text.
*/

#include <iostream>
#include <string>

using namespace std;

string textExtractor (string text)
// This function deletes the even digits of the received text to extract
{
	unsigned int i = 0;
	unsigned int len = text.length(); // length of the text
	string extractedtext; 
	while (i < len)
	{
		if (i%2==0)
		{ extractedtext += text.substr(i,1); }
	i+=2;
	}

	return extractedtext;
}

string characterRemover(string text, string characterstodelete)
// This function removes certain recived characters from received text
{
	 
	unsigned int len = text.length();

	for (unsigned int i=0; i < characterstodelete.length(); i++)
	{
		string letter = characterstodelete.substr(i,1); // This for loop seperates characters to letters
		unsigned int location = text.find(letter);

		while (location <= len && location!= string::npos) // This while loop deletes the letter from the text and it continues until no letter found
		{
			text = text.substr(0, location) + text.substr(location+1,len);
			location = text.find(letter);
			len = text.length();
		}
	}
		return text;
}


int main()

{


	string scrambledtext;
	string characterstodelete;
	
	cout << "This program removes certain characters from a scrambled text and reveals hidden message in the text." << endl;
	cout << "Scrambled Text: ";
	cin >> scrambledtext; // Scrambledtext input

	unsigned int scramlen = scrambledtext.length(); // Length of scrambled text

		while (scramlen<40) // Checking of input whether longer than 40
		{
			
			cout << "Input string must be longer than 40 characters" << endl;
			cout << "Scrambled Text: ";
			cin >> scrambledtext;
			scramlen = scrambledtext.length();

		}

	cout << "Characters to be deleted: ";
	cin >> characterstodelete; // Characters to delete input
	

	cout << "Extracted String: " << textExtractor(scrambledtext) << endl << endl; // Sending scrambled text to the extraction function to delete even digits of scrambled text
	cout << "Hidden Message: " << characterRemover(textExtractor(scrambledtext), characterstodelete) << endl; // Sending extracted text and the characters to the character remover function to remove certain characters

	return 0;

}