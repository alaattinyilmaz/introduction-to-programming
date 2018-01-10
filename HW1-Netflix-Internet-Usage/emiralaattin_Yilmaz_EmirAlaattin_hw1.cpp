#include <iostream> 

using namespace std;

int main() {

	
	double quota; // Internet usage limit 
	int movie; // Number of movies watched by user 
	int episode; // Number of episodes watched by user
	double usage; // Usage of Netflix
	double remquota; // Remaining quota
	
	
	cout << "This program shows your data usage of Netflix and remaining quota." << endl;
	cout << "Please enter your internet usage limit in GBs: ";
	cin >> quota; // Internet usage limit entered by user

	cout << "Please enter the number of movies you watched in this month : ";
	cin >> movie; // Number of movies entered by user

	cout << "Please enter the number of episodes you watched in this month? : ";
	cin >> episode; // Number of episodes entered by user
	// Th2 lines below are calculations of usage and remaining quota
	usage = ((6144 * movie) + (2520 * episode)); // Usage of Netflix in MBs after calculation
	remquota = ((quota) - (usage/1024)); // Remaining Quota of User in GBs after calculation


	cout << "Total Netflix usage in MBs: " << usage << endl; // Showing on the screen of usage
	cout << "Remaining quota in GBs: " << remquota << endl; // Showing on the screen of remaining quota


	return 0;

}
