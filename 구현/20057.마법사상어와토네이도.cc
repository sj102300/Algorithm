//[골드3] 20057.마법사상어와토네이도 https://www.acmicpc.net/problem/20057

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n;
int board[500][500];
pair<int, int> cur;
vector<int> moving;

int tmp[5][5] = { 0 };
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int answer = 0;


void getInput() {

	cin >> n;
	
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			cin >> board[i][j];
		}
	}

	cur = { n / 2, n / 2 };

	int dir = 0;
	for (int i = 1;i <= n-1;++i) {
		if (i % 2 != 0) {
			for (int j = 0;j < i;++j) {
				moving.push_back(0);
			}
			for (int j = 0;j < i;++j) {
				moving.push_back(1);
			}
		}
		else {
			for (int j = 0;j < i;++j) {
				moving.push_back(2);
			}
			for (int j = 0;j < i;++j) {
				moving.push_back(3);
			}
		}
	}

	for (int i = 0;i < n - 1;++i) {
		moving.push_back(0);
	}

}

void moveLeft() {

	memset(tmp, 0, sizeof(tmp));
	int totalSand = board[cur.first][cur.second];
	board[cur.first][cur.second] = 0;

	tmp[4][2] = tmp[0][2] = totalSand * 2 / 100;
	tmp[3][2] = tmp[1][2] = totalSand * 7 / 100;
	tmp[1][1] = tmp[3][1] = totalSand * 10 / 100;
	tmp[2][0] = totalSand * 5 / 100;
	tmp[1][3] = tmp[3][3] = totalSand * 1 / 100;

	int leftSand = totalSand;
	for (int i = 0;i < 5;++i) {
		for (int j = 0;j < 5;++j) {
			leftSand -= tmp[i][j];
		}
	}
	tmp[2][1] = leftSand;

}

void moveDown() {
	memset(tmp, 0, sizeof(tmp));
	int totalSand = board[cur.first][cur.second];
	board[cur.first][cur.second] = 0;

	tmp[1][1] = tmp[1][3] = totalSand * 1 / 100;
	tmp[2][0] = tmp[2][4] = totalSand * 2 / 100;
	tmp[2][1] = tmp[2][3] = totalSand * 7 / 100;
	tmp[3][1] = tmp[3][3] = totalSand * 10 / 100;
	tmp[4][2] = totalSand * 5 / 100;

	int leftSand = totalSand; 
	for (int i = 0;i < 5;++i) {
		for (int j = 0;j < 5;++j) {
			leftSand -= tmp[i][j];
		}
	}
	tmp[3][2] = leftSand;
}

void moveRight() {

	memset(tmp, 0, sizeof(tmp));
	int totalSand = board[cur.first][cur.second];
	board[cur.first][cur.second] = 0;

	tmp[1][1] = tmp[3][1] = totalSand * 1 / 100;
	tmp[0][2] = tmp[4][2] = totalSand * 2 / 100;
	tmp[1][2] = tmp[3][2] = totalSand * 7 / 100;
	tmp[1][3] = tmp[3][3] = totalSand * 10 / 100;
	tmp[2][4] = totalSand * 5 / 100;

	int leftSand = totalSand;
	for (int i = 0;i < 5;++i) {
		for (int j = 0;j < 5;++j) {
			leftSand -= tmp[i][j];
		}
	}
	tmp[2][3] = leftSand;
}

void moveUp() {

	memset(tmp, 0, sizeof(tmp));
	int totalSand = board[cur.first][cur.second];
	board[cur.first][cur.second] = 0;

	tmp[0][2] = totalSand * 5 / 100;
	tmp[1][1] = tmp[1][3] = totalSand * 10 / 100;
	tmp[2][0] = tmp[2][4] = totalSand * 2 / 100;
	tmp[2][1] = tmp[2][3] = totalSand  * 7 / 100;
	tmp[3][1] = tmp[3][3] = totalSand * 1 / 100;

	int leftSand = totalSand;
	for (int i = 0;i < 5;++i) {
		for (int j = 0;j < 5;++j) {
			leftSand -= tmp[i][j];
		}
	}
	tmp[1][2] = leftSand;
}

void addSand() {
	int newX, newY;
	for (int i = 0;i < 5;++i) {
		for (int j = 0;j < 5;++j) {
			newX = cur.first - 2 + i;
			newY = cur.second - 2 + j;

			if (newX < 0 || newY < 0 || newX >= n || newY >= n) {
				answer += tmp[i][j];
				continue;
			}

			board[newX][newY] += tmp[i][j];
		}
	}
}

void printBoard() {
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			cout << board[i][j] << " ";
		}cout << endl;
	}
	cout << "------------------"<<endl;
}

int main(void) {
	getInput();

	void(*getTmps[4])() = { moveLeft, moveDown, moveRight, moveUp };

	for (auto dir : moving) {
		cur = { cur.first + dx[dir], cur.second + dy[dir] };
		getTmps[dir]();
		addSand();
	}

	cout << answer;

}