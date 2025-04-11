//[골드3] 16235.나무재테크 https://www.acmicpc.net/problem/16235

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n, m, k;
int A[11][11];
vector<int> tree[11][11];
vector<int> deadtree[11][11];
int food[11][11];

int dx[] = { 0,1,0,-1,1,1,-1,-1 };
int dy[] = { 1,0,-1,0,-1,1,-1,1 };

void getInput() {
	//freopen("data.txt", "r", stdin);

	cin >> n >> m >> k;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			cin >> A[i][j];
		}
	}

	int x, y, age;

	for (int i = 0;i < m;++i) {
		cin >> x >> y >> age;
		tree[x-1][y-1].push_back(age);
	}

	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			food[i][j] = 5;
		}
	}
}

void spring() {
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			sort(tree[i][j].begin(), tree[i][j].end());

			for (auto it = tree[i][j].begin(); it != tree[i][j].end();) {
				int age = *it;

				if (food[i][j] >= age) {
					food[i][j] -= age;
					*it = age + 1;
					++it;
				}
				else {
					//양분 부족, 죽음
					deadtree[i][j].push_back(age);
					it = tree[i][j].erase(it);
				}
			}

		}
	}
}

void summer() {

	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			
			for (auto tree : deadtree[i][j]) {
				food[i][j] += tree / 2;
			}

			deadtree[i][j].clear();
		}
	}

}

void autumn() {
	
	int tmp[11][11];  //번식한 나무 개수
	memset(tmp, 0, sizeof(tmp));
	int newX, newY;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {

			for (auto age : tree[i][j]) {
				if (age % 5 == 0) {  //5의 배수인 나무만 번식
					
					for (int dir = 0;dir < 8;++dir) {
						newX = i + dx[dir];
						newY = j + dy[dir];

						if (newX < 0 || newY < 0 || newX >= n || newY >= n)
							continue;

						++tmp[newX][newY];
					}
				}
			}
		}
	}

	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {

			for (int t = 0;t < tmp[i][j];++t) {
				tree[i][j].push_back(1);
			}

		}
	}

}

void winter() {
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			food[i][j] += A[i][j];
		}
	}
}

int getTreesNum() {
	int answer = 0;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			answer += tree[i][j].size();
		}
	}
	return answer;
}

int main(void) {
	
	getInput();

	for (int year = 0;year < k;++year) {
		spring();
		summer();
		autumn();
		winter();
	}

	cout << getTreesNum();

}