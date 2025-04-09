//[L12] 나무박멸 https://www.codetree.ai/ko/frequent-problems/problems/tree-kill-all/description

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int answer;
int trees[21][21];
int killer[21][21];
int visited[21][21]; //제초제로 죽일 나무 개수 확인
int n, m, k, c;
int year = 1;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int crossDx[] = { 1,1,-1,-1 };
int crossDy[] = { 1,-1,1,-1 };

vector<pair<int, int>> treelocs;


void getInput() {

	cin >> n >> m >> k >> c;

	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			cin >> trees[i][j];
		}
	}
}

void getTreeLocs() {
	treelocs.clear();
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			if (trees[i][j] > 0) {
				treelocs.push_back({ i, j });
			}
		}
	}
	return;
}

void treeGrow() {

	int newX, newY;

	for (auto& tree : treelocs) {
		for (int dir = 0;dir < 4;++dir) {
			newX = tree.first + dx[dir];
			newY = tree.second + dy[dir];

			if (newX < 0 || newY < 0 || newX >= n || newY >= n)
				continue;

			if (trees[newX][newY] > 0)
				++trees[tree.first][tree.second];
		}
	}

	return;
}

void treeSpread() {
	
	int newX, newY;
	int childTreeNums;
	int adjEmptyNum;
	vector<pair<int, int>> tmp;
	vector<tuple<int, int, int>> childTrees;

	for (auto& tree : treelocs) {
		adjEmptyNum = 0;
		tmp.clear();

		for (int dir = 0;dir < 4;++dir) {
			newX = tree.first + dx[dir];
			newY = tree.second + dy[dir];

			if (newX < 0 || newY < 0 || newX >= n || newY >= n)
				continue;

			if (trees[newX][newY] == 0 && killer[newX][newY] < year) {
				++adjEmptyNum;
				tmp.push_back({ newX, newY });
			}
		}

		if (adjEmptyNum > 0) {
			childTreeNums = trees[tree.first][tree.second] / adjEmptyNum;
			for (auto& t : tmp) {
				childTrees.push_back({ t.first, t.second, childTreeNums });
			}
		}
	}

	int x, y, nums;
	for (auto& t : childTrees) {
		tie(x, y, nums) = t;
		trees[x][y] += nums;
	}

	return;
}

void killTrees() {

	//제초제를 뿌릴 수 있는 칸 찾기
	vector<pair<int, int>> targetTrees;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			if (trees[i][j] > 0 && killer[i][j] < year) {
				targetTrees.push_back({ i, j }); 
			}
		}
	}

	memset(visited, 0, sizeof(visited));
	int newX, newY;
	int killableTreeNum = 0;

	for (auto& target : targetTrees) {

		killableTreeNum = trees[target.first][target.second];
		
		for (int dir = 0;dir < 4;++dir) {
			newX = target.first;
			newY = target.second;

			for (int curk = 0; curk < k; ++curk) {
				newX += crossDx[dir];
				newY += crossDy[dir];

				if (newX < 0 || newY < 0 || newX >= n || newY >= n)
					break;

				if (trees[newX][newY] <= 0)
					break;

				killableTreeNum += trees[newX][newY];
			}
		}

		visited[target.first][target.second] = killableTreeNum;
	}

	//가장 많이 나무를 죽일 수 있는 자리 찾기
	int maxKills = 0;
	pair<int, int> targetLoc = { 0,0 };
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			if (maxKills < visited[i][j]) {
				maxKills = visited[i][j];
				targetLoc = { i, j };
			}
		}
	}

	trees[targetLoc.first][targetLoc.second] = 0;
	killer[targetLoc.first][targetLoc.second] = year + c;

	for (int dir = 0;dir < 4;++dir) {
		newX = targetLoc.first;
		newY = targetLoc.second;

		for (int curk = 0;curk < k;++curk) {
			newX += crossDx[dir];
			newY += crossDy[dir];

			if (newX < 0 || newY < 0 || newX >= n || newY >= n)
				break;

			if (trees[newX][newY] <= 0) {
				killer[newX][newY] = year + c;
				break;
			}

			trees[newX][newY] = 0;
			killer[newX][newY] = year + c;
		}
	}
	answer += visited[targetLoc.first][targetLoc.second];
}

int main(void) {
	getInput();

	while (year <= m) {
		getTreeLocs();
		treeGrow();
		treeSpread();
		killTrees();
		++year;
	}

	cout << answer;
}