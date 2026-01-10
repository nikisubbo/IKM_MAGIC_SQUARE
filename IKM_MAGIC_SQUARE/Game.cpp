#include <iostream>
#include <vector>
#include "Header.h"
#include <iomanip>
#include <ctime>
void game() {
	srand(time(0));
	vector < vector <int> > matrix(3, vector <int>(3));
	vector < vector <int> > player_matrix(3, vector <int>(3));
	matrix = generationSquare(matrix);
	int column_one = rand() % 3;
	int line_one = rand() % 3;
	int column_two = rand() % 3;
	int line_two = rand() % 3;
	int column_three = rand() % 3;
	int line_three = rand() % 3;
	player_matrix[line_one][column_one] = matrix[line_one][column_one];
	player_matrix[line_two][column_two] = matrix[line_two][column_two];
	player_matrix[line_three][column_three] = matrix[line_three][column_three];
	outputMatrix(matrix);
	outputMatrix(player_matrix);
}