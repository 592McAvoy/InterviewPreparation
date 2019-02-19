#include"problem.h"

bool isValidSudoku(vector<vector<char> > &board)
{
	int used1[9][9] = { 0 }, used2[9][9] = { 0 }, used3[9][9] = { 0 };

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			if (board[i][j] != '.') {
				int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
				if (used1[i][num] || used2[j][num] || used3[k][num])
					return false;
				used1[i][num] = used2[j][num] = used3[k][num] = 1;
			}

	return true;
}

bool isValid(vector<vector<char>> board, int row, int col, char num) {
	vector<char> r = board[row];
	//row
	for (char c : r) {
		if (c == num)return false;
	}
	//col
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == num)return false;
	}
	//block
	row = row / 3 * 3;
	col = col / 3 * 3;
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (board[i][j] == num)return false;
		}
	}
	return true;
}
void findBlank(vector<vector<char>>& board,int& row, int& col) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') {
				row = i; col = j;
				return;
			}
		}
	}
	row = -1; col = -1;
	return;
}
bool fillBlank(vector<vector<char>>& board) {
	int row, col;
	findBlank(board, row, col);
	if (row == -1)return true;
	string nums = "123456789";
	for (char n : nums) {
		if (isValid(board, row, col, n)) {
			board[row][col] = n;
			if (fillBlank(board))return true;
			board[row][col] = '.';
		}		
	}
	return false;
}
void solveSudoku(vector<vector<char>>& board) {
	fillBlank(board);
}