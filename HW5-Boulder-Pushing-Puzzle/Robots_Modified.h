
#ifndef Robots_Modified_h
#define Robots_Modified_h

#include <string>
#include <time.h>

using namespace std;

// Robot world
// Ersin Karabudak, 2003

enum Direction { east, west, north, south };
enum Color { white, yellow, red, blue, green, purple, pink, orange };

class Robot
{
  public:

	Robot (int x, int y, Direction dir = east, int things = 0);
	~Robot ();

	void Move (int distance = 1);
	bool Blocked ();
	void TurnRight ();
	bool PickThing ();
	bool PutThing ();  
	void SetColor (Color color);

	bool FacingEast ();
	bool FacingWall ();
	bool CellEmpty ();
	bool BagEmpty ();

	/**************** START: CS201 students' hw5 member functions ******************/

	void Teleport(int , int , Direction );

	/**************** END: CS201 students' hw5 member functions ********************/

  private:
	int xPos;
	int yPos;
	Direction direction;
	Color color;
	int bag;
	bool stalled;
	bool visible;

	Robot *next;
	Robot *prev;
	static Robot *list;

	friend struct RobotWindow;


};

void ShowMessage (string message);
void ShowMessage (int message);
void GetInput(string prompt, string & var);
void GetInput(string prompt, int & var);
int GetThingCount(int x1,int y1, int x2, int y2); //added by Albert Levi
int GetCellCount (int x, int y); // added by Albert Levi
bool PutThingInCell(int x, int y, unsigned long difference, int things=1);

#endif Robots_h
