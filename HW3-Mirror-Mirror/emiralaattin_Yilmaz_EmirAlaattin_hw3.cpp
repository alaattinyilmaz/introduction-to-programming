/*
EMİR ALAATTIN YILMAZ 
19705 

This program moves the Player Robot to the target cell and moves the Reflection Robot according to the Player Robot's movement.

*/
#include <string>
#include "robots.h"

using namespace std;

void TurnLeft(Robot & robotname) // This function turns robot left
{	
		robotname.TurnRight();
		robotname.TurnRight();
		robotname.TurnRight();

}

void TurnBack(Robot & robotname) // This function turns robot back
{	
		robotname.TurnRight();
		robotname.TurnRight();
}

void RobotMover(int xcoor, int ycoor, Robot & player, Robot & reflection) 
// RobotMover function moves player and reflection robots according to their coordinates

{ 
	// If-elses controls the region of the coordinates according to target cell (7,8)
	if (xcoor <= 7 && ycoor <= 8)
	{

		TurnLeft(player);
		player.Move(8-ycoor); // Moving of the player robot on y-axis

		reflection.TurnRight(); // Changing (turning right) of the reflection robot
		reflection.Move(8-ycoor); // Moving of the reflection robot on y-axis
		
		player.TurnRight();
		player.Move(7-xcoor); // Moving of player robot on x-axis
		
		TurnLeft(reflection);
		reflection.Move(7-xcoor); // Moving of the reflection robot on x-axis

		player.SetColor(red); // Changing color of the player robot
		reflection.SetColor(blue); // Changing color of the reflection robot
		
	}

else if (xcoor <= 7 && ycoor > 8)
	{	
		player.Move(7-xcoor);
		
		
		reflection.Move(7-xcoor);


		player.TurnRight();
		player.Move(ycoor-8);
	
		TurnLeft(reflection);
		reflection.Move(ycoor-8);
		player.SetColor(red);
		reflection.SetColor(blue);


	}	

	else if (xcoor > 7 && ycoor > 8)
	{
		
		TurnBack(player);
		player.Move(xcoor-7);

		TurnBack(reflection);
		reflection.Move(xcoor-7);
		
		TurnLeft(player);
		player.Move(ycoor-8);
		
		
		reflection.TurnRight();
		reflection.Move(ycoor-8);
		
		player.SetColor(red);
		reflection.SetColor(blue);


	}
	
	
	else if (xcoor > 7 && ycoor <= 8)
	{	
		TurnBack(player);
		player.Move(xcoor-7);

		TurnBack(reflection);
		reflection.Move(xcoor-7);


		player.TurnRight();
		player.Move(8-ycoor);
		player.SetColor(red);

		TurnLeft(reflection);
		reflection.Move(8-ycoor);
		reflection.SetColor(blue);


	}


}

void RobotCreater(int xcoor, int ycoor) // This function is used for creating player and reflection robots

{
	Robot PlayerRobot(xcoor, ycoor); // Creating of player robot facing east
	PlayerRobot.SetColor(blue); // Setting color of the player robot


	int rxcoor = (27 - xcoor); // Position calculation of reflection robot 

	Robot ReflectionRobot(rxcoor,ycoor,west); // Creating of reflection robot facing west
	ReflectionRobot.SetColor(red); // Setting color of the reflection robot

	RobotMover(xcoor,ycoor,PlayerRobot, ReflectionRobot); // Sending arguments to move the robots 



}



int main()
{

	int xcoor;
	ShowMessage ("This program moves the Player Robot to the target cell and moves the Reflection Robot according to the Player Robot's movement.");


	GetInput("Please enter X position of the robot", xcoor); // Getting x-coordinate from user

	if (xcoor < 0 || xcoor > 13) // Checking x-coordinate 0 ≤ x < 14
	{
		ShowMessage("Invalid X coordinate!"); // Error Message
	}

	else {
		int ycoor;
		GetInput("Please enter Y position of the robot", ycoor); // Getting y-coordinate from user
		if (ycoor < 0 || ycoor > 13) // Checking y-coordinate 0 ≤ y < 14
		{
			ShowMessage("Invalid Y coordinate!"); 
		}
		else {
			RobotCreater(xcoor,ycoor); // Creating robots

		}
	}






}