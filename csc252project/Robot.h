#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
using namespace std;

// global grid
char grid[10][10];

class Robot {
private:
	int xLocation;
	int yLocation;
	bool cargoBed;
	char load;
	// constructor is responsible for initializing all instance variables
public:
	Robot(int x, int y, bool b, char l) {
		xLocation = x;
		yLocation = y;
		cargoBed = b;
		load = l;

	}
	// set functions
	void setX(int x) {
		xLocation = x;
	}
	void setY(int y) {
		yLocation = y;
	}
	// Get functions
	int getX() {
		return xLocation;
	}
	int getY() {
		return yLocation;
	}
	void setCargo(bool b) {
		cargoBed = b;
	}
	bool getCargo() {
		return cargoBed;
	}
	// l for load
	void setLoad(char l) {
		load = l;
		// set cargobed = true
		cargoBed = true;
	}
	char getLoad() {
		return load;
	}

	bool moveTo(int lx, int ly) {
		// Checks if out of bounds (not on 10 x 10 grid)
		if (lx >= 10 || lx < 0 || ly >= 10 || ly < 0) {
			return false;
		}
		while (xLocation != lx) {

			lx < xLocation ? xLocation-- : xLocation++;

		}
		while (yLocation != ly) {

			ly < yLocation ? yLocation-- : yLocation++;
		}
		return true;
	}

	bool pickup(int lx, int ly) {
		// verify location and if cargobed is already full
		if (cargoBed || grid[lx][ly] == '.') {
			return false;
		}
		// if not false, move to location
		moveTo(lx, ly);
		// move cargo to cargobed
		load = grid[lx][ly];
		cargoBed = true;
		// remove from grid
		grid[lx][ly] = '.';
		return true;
	}

	bool dropOff(int lx, int ly) {
		if (!cargoBed || grid[lx][ly] != '.') {
			return false;
		}
		moveTo(lx, ly);
		grid[lx][ly] = load;
		load = '.';
		cargoBed = false;
		return true;
	}
	friend ostream& operator<< (ostream& out, Robot& RoboT100);
};
// define the operator overload
ostream& operator<< (ostream& out, Robot& RoboT100) {
	out << "(" << RoboT100.xLocation << "," << RoboT100.yLocation << ") : " << RoboT100.load << endl;
	return out;
}
// non-member function
void print2D(char grid[10][10]) {
	cout << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
//
void clear(char grid[10][10]) {
	// nested for loop
	// Traverse all elements of array and if character is found, create a robot and pickup the load
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (grid[i][j] != '.') {
				// if anything but char ., create new robot object
				Robot* r = new Robot(i, j, false, '.');
				r->pickup(i, j);
				// Delete robot
				delete r;
			}
		}
	}
}
#endif 

