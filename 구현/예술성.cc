//[L13] 예술성 https://www.codetree.ai/ko/frequent-problems/problems/artistry/description

#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_set>
#pragma warning(disable:4996)

using namespace std;

int n;
int board[30][30];
int visited[30][30];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int half;
vector<vector<pair<int, int>>> groups;

void getInput() {

	cin >> n;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			cin >> board[i][j];
		}
	}
	half = n / 2;
	return;
}

void getGroup(vector<pair<int, int>> &group, pair<int, int> start) {

	visited[start.first][start.second] = 1;
	group.push_back(start);

	int f = 0;
	int newX, newY;
	pair<int, int> front;
	while (f < group.size()) {
		front = group[f++];

		for (int dir = 0;dir < 4; ++dir) {
			newX = front.first + dx[dir];
			newY = front.second + dy[dir];

			if (newX < 0 || newY < 0 || newX >= n || newY >= n)
				continue;

			if (!visited[newX][newY] && board[newX][newY] == board[front.first][front.second]) {
				group.push_back({ newX, newY });
				visited[newX][newY] = 1;
			}
		}

	}
	
}

void divideGroups() {

	groups.clear();

	memset(visited, 0, sizeof(visited));

	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			if (!visited[i][j]) {
				groups.push_back({});
				getGroup(groups[groups.size() - 1], { i, j });
			}
		}
	}
}

string pairToStr(pair<int, int> p) {
	return to_string(p.first) + " " + to_string(p.second);
}

pair<int, int> strToPair(string str) {
	stringstream ss;
	ss.str(str);
	int a, b;
	ss >> a >> b;
	return { a,b };
}

int calcScore(vector<pair<int, int>>& a, vector<pair<int,int>>& b) {

	int aNum = board[a[0].first][a[0].second];
	int bNum = board[b[0].first][b[0].second];

	//맞닿은 변의 개수 구하기
	int lineNum = 0;
	vector<string> aSet;  //둘러싸고있는 테두리부분
	unordered_set<string> bSet;

	int newX, newY;
	for (auto& v : a) {
		for (int dir = 0;dir < 4; ++dir) {
			newX = v.first + dx[dir];
			newY = v.second + dy[dir];

			if (newX < 0 || newY < 0 || newX >= n || newY >= n)
				continue;

			aSet.push_back(pairToStr({ newX, newY }));
		}
	}

	for (auto& v : b) {
		bSet.insert(pairToStr(v));
	}

	for (auto &v : aSet) {
		if (bSet.find(v) != bSet.end()) {
			++lineNum;
		}
	}
	
	return (a.size() + b.size())  * aNum * bNum * lineNum;
}

void rotateCenter() {
	memset(visited, 0, sizeof(visited));

	//copy 해놓고 
	for (int i = 0;i < n;++i) {
		visited[half][i] = board[half][i];
		visited[i][half] = board[i][half];
	}

	for (int i = 0; i < half; ++i) {
		board[i][half] = visited[half][n - 1 - i];
		board[half][i] = visited[i][half];
		board[n - 1 - i][half] = visited[half][i];
		board[half][n - 1 - i] = visited[n - 1 - i][half];
	}

}

void printBoard() {
	cout << "-------board-------" << endl;
	for (int i = 0;i < n;++i) { 
		for (int j = 0;j < n;++j) {
			cout << board[i][j];
		}cout << endl;
	}
}
void printVisited() {
	cout << "-------visited-------" << endl;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			cout << visited[i][j];
		}cout << endl;
	}
}

void rotateBox(int sx, int sy) {

	//copy해놓고
	for (int i = sx; i < sx + half; ++i) {
		for (int j = sy; j < sy + half ;++j) {
			visited[i][j] = board[i][j];
		}
	}

	for (int i = 0;i < half;++i) {
		for (int j = 0;j < half;++j) {
			board[sx + j][sy + half - 1 - i] = visited[sx + i][sy + j];
		}
	}

}


int main(void) {

	getInput();
	int score = 0;
	for (int time = 0;time < 4; ++time) {
		//그룹나누기
		divideGroups();
		
		//조화로움 계산
		for (int a = 0;a < groups.size() - 1; ++a) {
			for (int b = a + 1;b < groups.size();++b) {
				score += calcScore(groups[a], groups[b]);
			}
		}

		// + 돌리기
		rotateCenter();

		//사분면 ㅁ 돌리기 
		rotateBox(0, 0);
		rotateBox(0, half + 1);
		rotateBox(half + 1, 0);
		rotateBox(half + 1, half + 1);
	}

	cout << score;
	return 0;
}