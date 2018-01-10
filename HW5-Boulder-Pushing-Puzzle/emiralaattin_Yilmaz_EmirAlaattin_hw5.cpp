/*

EMÝR ALAATTÝN YILMAZ
19705

This program is a robot puzzle game

To win the game boulder robots should be reached at the point of (10,10)


*/

#include <iostream>
#include "MiniFW_Modified.h"
#include "Robots_Modified.h"
#include "strutils.h"

using namespace std;

void LazarusPit(Robot & robotname) // This function makes a dead robot alive
{
	if(!robotname.IsAlive())
	{
		robotname.Resurrect();
	}
}

void BoulderMover(Robot & Playerrobot, Robot & boulder1, Robot & boulder2, Robot & boulder3) // This function moves boulder robots

{
	// First check them whether alive or dead
	if(!boulder1.IsAlive())
	{
		boulder1.Resurrect(); // Makes them alive if they are dead
		boulder1.TurnFace(Playerrobot.GetDirection()); // It turns boulder1 robot in the direction of player robot
		while(boulder1.Blocked()==false)
		{boulder1.Move();} // Moves while there is no obstacle in front of a boulder robot
	}

	else if(!boulder2.IsAlive())
	{
		boulder2.Resurrect();
		boulder2.TurnFace(Playerrobot.GetDirection());
		while(boulder2.Blocked()==false)
		{boulder2.Move();}

	}

	else if(!boulder3.IsAlive())
	{
		boulder3.Resurrect();
		boulder3.TurnFace(Playerrobot.GetDirection());
		while(boulder3.Blocked()==false)
		{boulder3.Move();}
	}

	else 
		Playerrobot.Resurrect();
}

void RobotMover(Robot & playerrobot, Robot & boulder1, Robot & boulder2, Robot & boulder3) // This function moves player robot

{
	bool MovingControl = true;
	while (MovingControl)
	{

		
		if(IsPressed(keyUpArrow)) // Moves upward
		{
			playerrobot.TurnFace(north);

			if(playerrobot.FacingWall() == false)

			{
				
				playerrobot.Move(1); // Moving player robot 1 unit
				
				if (playerrobot.Blocked()==false)
				{playerrobot.SetBagCount(playerrobot.GetBagCount()-1);}
	
				LazarusPit(playerrobot); // Making alive player robot
				BoulderMover(playerrobot, boulder1, boulder2, boulder3);


				playerrobot.PickAllThings(); // Picks all the things in the current cell

			}

			MovingControl = false;
		}

		else if(IsPressed(keyRightArrow))
		{
			playerrobot.TurnFace(east);

			if(playerrobot.FacingWall() == false)
			{	playerrobot.Move(1);

			if (playerrobot.Blocked()==false)
			{playerrobot.SetBagCount(playerrobot.GetBagCount()-1);}

			LazarusPit(playerrobot);
			BoulderMover(playerrobot, boulder1, boulder2, boulder3);	


			

			playerrobot.PickAllThings();
			}

			MovingControl = false;
		}

		else if(IsPressed(keyDownArrow))
		{
			playerrobot.TurnFace(south);
			if(playerrobot.FacingWall() == false)
			{	playerrobot.Move(1);

			if (playerrobot.Blocked()==false)
			{playerrobot.SetBagCount(playerrobot.GetBagCount()-1);}
			LazarusPit(playerrobot);

			BoulderMover(playerrobot, boulder1, boulder2, boulder3);

			playerrobot.PickAllThings();
			}

			MovingControl = false;
		}

		else if(IsPressed(keyLeftArrow))
		{
			playerrobot.TurnFace(west);
			if(playerrobot.FacingWall() == false)

			{	playerrobot.Move(1);
			if (playerrobot.Blocked()==false)
			{playerrobot.SetBagCount(playerrobot.GetBagCount()-1);}
			LazarusPit(playerrobot);

			BoulderMover(playerrobot, boulder1, boulder2, boulder3);
			

			playerrobot.PickAllThings();
			}
			MovingControl = false;
		}




		MovingControl = false;
	}
}


int main()

{

	int b1xcoor, b1ycoor, b2xcoor, b2ycoor, b3xcoor, b3ycoor;
	GetInput("Please enter X coordinate for boulder1", b1xcoor);
	GetInput("Please enter Y coordinate for boulder1", b1ycoor);
	GetInput("Please enter X coordinate for boulder2", b2xcoor);
	GetInput("Please enter Y coordinate for boulder2", b2ycoor);
	GetInput("Please enter X coordinate for boulder3", b3xcoor);
	GetInput("Please enter Y coordinate for boulder3", b3ycoor);
	// Taking x and y coordinates of boulder robots (above)

	Robot playerrobot(0,0,east,50); // Creating of player robot which is at the point of (0,0) facing east which contains 50 things in its bag
	playerrobot.SetColor(blue); // Setting color of player robot

	Robot boulder1(b1xcoor,b1ycoor); // Creating of boulder robot 1
	boulder1.SetColor(yellow); // Setting color of boulder robot 1

	Robot boulder2(b2xcoor,b2ycoor);
	boulder2.SetColor(green);

	Robot boulder3(b3xcoor,b3ycoor);
	boulder3.SetColor(pink);

	bool conditioncontrol = true;
	while (conditioncontrol) 
	{

		RobotMover(playerrobot,boulder1,boulder2,boulder3); // Calling robot mover function 

		int bag = playerrobot.GetBagCount(); // Number of things in the bag of player robot
		
		if(IsPressed(keyHome)) // Home key turns all the robots in the starting position
		{
			playerrobot.SetBagCount(50);
			playerrobot.Teleport(0,0,east);
			boulder1.Teleport(b1xcoor,b1ycoor,east);
			boulder2.Teleport(b2xcoor,b2ycoor,east);
			boulder3.Teleport(b3xcoor,b3ycoor,east);
		}


		if (bag==0) // If the things are consumed, program executes
		{
			int px = playerrobot.GetXCoordinate();
			int py = playerrobot.GetYCoordinate();
			ShowMessage("You couldn't reach to exit in time and blacked out in " + itoa(px) + "," + itoa(py));

		conditioncontrol = false;

		}
		else if((boulder1.GetXCoordinate()==10 && boulder1.GetYCoordinate()==10) || (boulder2.GetXCoordinate()==10 && boulder2.GetYCoordinate()==10) || (boulder3.GetXCoordinate()==10 && boulder3.GetYCoordinate()==10) )
		// End conditions (if one of the boulder robots reach 10,10 point in the robot world user will win)
		{

		ShowMessage("Congratulations, solved the puzzle with " + itoa(bag) + " energy!");
		conditioncontrol = false;
		}


	}
	
}


