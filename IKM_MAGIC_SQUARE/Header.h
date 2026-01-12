#include <vector>
#include <string>
using namespace std;
int input();
vector<vector<int>> generationSquare(vector<vector<int>> matrix, int size, int center_num);
bool checkCorrectSquare(vector<vector<int>> matrix, int m);
void outputSumm(vector<vector<int>> matrix);
void outputToFile(vector <vector<int>> player_matrix, int size, vector <int> moves);
vector<vector<int>> loadFromFileMatrix(vector<vector<int>> player_matrix, string file_name);
void newGame();
void loadGame();
void outputMatrix(vector<vector<int>> matrix);
vector<vector<int>> generationPlayersSquare(vector<vector<int>> matrix, int m);
void playersMove(vector<vector<int>>& matrix, vector <int>& moves);
vector <int> possibleMoves(vector<vector<int>> matrix, vector<vector<int>> player_matrix, int m);
void outputVector(vector<int> moves);
vector <int> deleteUsedMove(vector <int> moves, int number);
bool testEndGame(vector<vector<int>> player_matrix, vector <int> moves);
void saveGame(vector <vector <int>> player_matrix, int size, vector <int> moves);
vector<int> loadFromFileMoves(vector<int> moves, string file_name);