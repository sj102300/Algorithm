//[골드3] 23288.주사위굴리기 https://www.acmicpc.net/problem/23288

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int n, m, k;
int board[21][21];
//위 앞 아 뒤 동 서
//0  1  2  3  4  5
int dice[6] = { 1,5,6,2,3,4 };
vector<pair<int, int>> queue;
int visited[21][21] = { 0 };

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1,0,-1,0 };

void rotateDice(int dir) {
	int tmp;
	if (dir == 0) {
		tmp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[4];
		dice[4] = tmp;
	}
	else if (dir == 1) {
		tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = tmp;
	}
	else if (dir == 2) {
		tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[5];
		dice[5] = tmp;
	}
	else if (dir == 3) {
		tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = tmp;
	}
	return;
}

void getInput() {

	freopen("data.txt", "r", stdin);

	cin >> n >> m >> k;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m; ++j) {
			cin >> board[i][j];
		}
	}

}

bool canGo(pair<int, int> cur, int dir) {
	int x = cur.first + dx[dir];
	int y = cur.second + dy[dir];
	return 0 <= x && x < n && 0 <= y && y < m;
}

int calcScore(pair<int, int> cur) {

	queue.clear();
	queue.push_back(cur);
	memset(visited, 0, sizeof(visited));
	visited[cur.first][cur.second] = 1;

	int f = 0;
	pair<int, int> front;
	int newX, newY;
	while (f < queue.size()) {
		front = queue[f++];

		for (int dir = 0;dir < 4;++dir) {
			newX = front.first + dx[dir];
			newY = front.second + dy[dir];

			if (newX < 0 || newY < 0 || newX >= n || newY >= m)
				continue;

			if (!visited[newX][newY] && board[newX][newY] == board[cur.first][cur.second]) {
				queue.push_back({ newX, newY });
				visited[newX][newY] = 1;
			}
		}
	}

	return queue.size() * board[cur.first][cur.second];

}

int getNextDir(int curdir, pair<int, int> cur) {

	if (dice[2] > board[cur.first][cur.second]) {
		return (curdir + 1) % 4;
	}
	else if (dice[2] < board[cur.first][cur.second]) {
		return (curdir + 4 - 1) % 4;
	}
	else {
		return curdir;
	}

}

int main(void) {

	getInput();

	pair<int, int> cur = { 0,0 };

	int dir = 0;
	int score = 0;

	for (int i = 0;i < k; ++i) {
		if (!canGo(cur, dir)) {
			dir = (dir + 2) % 4;
		}
		rotateDice(dir);
		cur = { cur.first + dx[dir], cur.second + dy[dir] };
		score += calcScore(cur);
		dir = getNextDir(dir, cur);
	}

	cout << score;

	return 0;
}