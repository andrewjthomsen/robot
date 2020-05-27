#include "Robot.h"



int main()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = '.';
		}
	}

	grid[3][8] = 'B';
	grid[2][6] = 'C';
	print2D(grid);

	Robot R1((rand() % 10), rand() % 10, false, '.');
	Robot R2((rand() % 10), rand() % 10, false, '.');
	print2D(grid);
	cout << R1;
	cout << R2;

	R1.moveTo(9, 2);
	R2.moveTo(3, 4);
	print2D(grid);
	cout << R1;
	cout << R2;

	R1.pickup(3, 8);
	print2D(grid);
	cout << R1;
	cout << R2;
	R1.dropOff(9, 9);
	print2D(grid);
	cout << R1;
	cout << R2;

	R2.pickup(2, 6);
	print2D(grid);
	cout << R1;
	cout << R2;
	R2.dropOff(0, 0);
	print2D(grid);
	cout << R1;
	cout << R2;

	clear(grid);
	print2D(grid);

	return 0;
}



