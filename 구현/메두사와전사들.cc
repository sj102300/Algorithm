//[L15] 메두사와전사들 https://www.codetree.ai/ko/frequent-problems/problems/medusa-and-warriors/description?introductionSetId=&bookmarkId=

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm> 
#include <queue>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

typedef struct _warrior {
	int first;
	int second;
	bool alive;
}Warrior;

int n, m;
pair<int, int> house;
pair<int, int> park;
pair<int, int> monster;
vector<pair<int, int>> monsterRoute;
vector<Warrior> warriorsVector;

vector<pair<int, int>> targets;
vector<pair<int, int>> tmpWarriors;
vector<pair<int, int>> help;

int board[51][51]; //메두사가 이동할 경로. 도로가 0, 도로아닌거 1
bool ismovable[51][51];  //움직일 수 있으면 true, 움직일 수 없으면 false
int warriors[51][51];  //해당 칸에 있는 전사의 수
int tmp[51][51]; //연산에 사용

int warriorMoved;
int stonedWarrior;
int attackedWarrior;

void getInput() {

	int a, b;
	cin >> n >> m;
	cin >> house.first >> house.second >> park.first >> park.second;
	for (int i = 0;i < m;++i) {
		cin >> a >> b;
		++warriors[a][b];
		warriorsVector.push_back({ a,b, true });
	}

	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			cin >> board[i][j];
		}
	}

}

bool checkRange(int a, int b) {
	return !(a < 0 || b < 0 || a >= n || b >= n);
}

void getMonstersRoute() {

	pair<int, int> prev[51][51];

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	//tmp를 visited로 활용
	queue<pair<int, int>> q;
	q.push(house);
	tmp[house.first][house.second] = true;
	prev[house.first][house.second] = house;
	prev[park.first][park.second] = { -1,-1 };

	pair<int, int> front;

	int newX, newY;

	while (!q.empty()) {
		front = q.front();
		q.pop();

		for (int dir = 0;dir < 4;++dir) {
			newX = front.first + dx[dir];
			newY = front.second + dy[dir];

			if (!checkRange(newX, newY))
				continue;

			if (!tmp[newX][newY] && board[newX][newY] == 0) {
				tmp[newX][newY] = true;
				prev[newX][newY] = front;
				q.push({ newX, newY });
			}
		}
	}

	pair<int, int> cur = prev[park.first][park.second];

	if (cur.first == -1 && cur.second == -1) {
		return;
	}
	monsterRoute.push_back(park);
	while (!(cur.first == house.first && cur.second == house.second)) {
		monsterRoute.push_back(cur);
		cur = prev[cur.first][cur.second];
	}

	reverse(monsterRoute.begin(), monsterRoute.end());
	
}

void printMonsterRoute() {
	for (auto &v : monsterRoute) {
		cout << v.first << " " << v.second << endl;
	}
}

void section1(int x, int y, vector<pair<int, int>> &target) {

	int newX = x;
	int newY = y;
	int dx = -1;
	int dy = 1;

	while (true) {
		newX = newX + dx;
		newY = newY + dy;

		if (!checkRange(newX, newY)) {
			break;
		}

		for (int i = newX;i >= 0;--i) {
			target.push_back({ i, newY });
		}
	}
}

void section2(int x, int y, vector<pair<int, int>> &target) {
	int newX = x;
	int newY = y;
	int dx = -1;
	int dy = 1;

	while (true) {
		newX = newX + dx;
		newY = newY + dy;

		if (!checkRange(newX, newY)) {
			break;
		}
		for (int j = newY; j < n;++j) {
			target.push_back({ newX, j });
		}
	}
}

void section3(int x, int y, vector<pair<int, int>> & target) {
	int newX = x;
	int newY = y;
	int dx = 1;
	int dy = 1;

	while (true) {
		newX = newX + dx;
		newY = newY + dy;

		if (!checkRange(newX, newY)) {
			break;
		}
		for (int j = newY;j < n;++j) {
			target.push_back({ newX, j });
		}
	}
}

void section4(int x, int y, vector<pair<int, int>> & target) {
	int newX = x;
	int newY = y;
	int dx = 1;
	int dy = 1;

	while (true) {
		newX = newX + dx;
		newY = newY + dy;

		if (!checkRange(newX, newY)) {
			break;
		}
		for (int i = newX;i < n;++i) {
			target.push_back({ i, newY });
		}
	}
}

void section5(int x, int y, vector<pair<int, int>> & target) {
	int newX = x;
	int newY = y;
	int dx = 1;
	int dy = -1;

	while (true) {
		newX = newX + dx;
		newY = newY + dy;

		if (!checkRange(newX, newY)) {
			break;
		}
		for (int i = newX;i < n;++i) {
			target.push_back({ i, newY });
		}
	}
}

void section6(int x, int y, vector<pair<int, int>> & target) {
	int newX = x;
	int newY = y;
	int dx = 1;
	int dy = -1;

	while (true) {
		newX = newX + dx;
		newY = newY + dy;

		if (!checkRange(newX, newY)) {
			break;
		}
		for (int j = newY;j >= 0;--j) {
			target.push_back({ newX, j });
		}
	}
}

void section7(int x, int y, vector<pair<int, int>> & target) {
	int newX = x;
	int newY = y;
	int dx = -1;
	int dy = -1;

	while (true) {
		newX = newX + dx;
		newY = newY + dy;

		if (!checkRange(newX, newY)) {
			break;
		}
		for (int j = newY;j >= 0;--j) {
			target.push_back({ newX, j });
		}
	}
}

void section8(int x, int y, vector<pair<int, int>> & target) {
	int newX = x;
	int newY = y;
	int dx = -1;
	int dy = -1;

	while (true) {
		newX = newX + dx;
		newY = newY + dy;

		if (!checkRange(newX, newY)) {
			break;
		}
		for (int i = newX;i >= 0;--i) {
			target.push_back({ i, newY });
		}
	}
}

void sectionUp(int x, int y, vector<pair<int, int>> & target) {
	int newX = x;
	int dx = -1;

	while (true) {
		newX = newX + dx;

		if (!checkRange(newX, y)) {
			break;
		}

		target.push_back({ newX, y });
	}
}

void sectionDown(int x, int y, vector<pair<int, int>> & target) {
	int newX = x;
	int dx = 1;

	while (true) {
		newX = newX + dx;

		if (!checkRange(newX, y)) {
			break;
		}

		target.push_back({ newX, y });
	}
}

void sectionLeft(int x, int y, vector<pair<int, int>> & target) {
	int newY = y;
	int dy = -1;

	while (true) {
		newY = newY + dy;

		if (!checkRange(x, newY)) {
			break;
		}

		target.push_back({ x, newY });
	}
}

void sectionRight(int x, int y, vector<pair<int, int>> & target) {
	int newY = y;
	int dy = 1;

	while (true) {
		newY = newY + dy;

		if (!checkRange(x, newY)) {
			break;
		}

		target.push_back({ x, newY });
	}
}

int watchUp() {

	memset(tmp, true, sizeof(tmp));
	int ret = 0;
	int mx = monster.first;
	int my = monster.second;

	targets.clear();
	tmpWarriors.clear();
	help.clear();
	section1(mx, my, targets);   //메두사가 보는 거 가져오기
	for (auto&v : targets) {
		tmp[v.first][v.second] = false; //메두사가 본다 처리
		if (warriors[v.first][v.second] > 0) {  //전사있으면 거기부분 푸쉬
			tmpWarriors.push_back(v);
		}
	}
	for (auto &v : tmpWarriors) {   //메두사한테 걸린 전사들 
		if (tmp[v.first][v.second] == false) {  //중에 맨앞에있던 애들만
			section1(v.first, v.second, help);
			sectionUp(v.first, v.second, help);
			for (auto &vv : help) {
				tmp[vv.first][vv.second] = true;
			}
			ret+=warriors[v.first][v.second];
		}
	}

	targets.clear();
	tmpWarriors.clear();
	help.clear();
	section8(mx, my, targets);
	for (auto&v : targets) {
		tmp[v.first][v.second] = false;
		if (warriors[v.first][v.second] > 0) {
			tmpWarriors.push_back(v);
		}
	}
	for (auto &v : tmpWarriors) {
		if (tmp[v.first][v.second] == false) {
			section8(v.first, v.second, help);
			sectionUp(v.first, v.second, help);
			for (auto &vv : help) {
				tmp[vv.first][vv.second] = true;
			}
			ret += warriors[v.first][v.second];
		}
	}

	targets.clear();
	sectionUp(mx, my, targets);
	for (auto&v : targets) {
		tmp[v.first][v.second] = false;
		if (warriors[v.first][v.second] > 0) {
			ret += warriors[v.first][v.second];
			break;
		}
	}

	return ret;

}

int watchDown() {
	memset(tmp, true, sizeof(tmp));

	int ret = 0;
	int mx = monster.first;
	int my = monster.second;

	targets.clear();
	tmpWarriors.clear();
	help.clear();
	section4(mx, my, targets);   //메두사가 보는 거 가져오기
	for (auto&v : targets) {
		tmp[v.first][v.second] = false; //메두사가 본다 처리
		if (warriors[v.first][v.second] > 0) {  //전사있으면 거기부분 푸쉬
			tmpWarriors.push_back(v);
		}
	}
	for (auto &v : tmpWarriors) {   //메두사한테 걸린 전사들 
		if (tmp[v.first][v.second] == false) {  //중에 맨앞에있던 애들만
			section4(v.first, v.second, help);
			sectionDown(v.first, v.second, help);
			for (auto &vv : help) {
				tmp[vv.first][vv.second] = true;
			}
			ret += warriors[v.first][v.second];
		}
	}

	targets.clear();
	tmpWarriors.clear();
	help.clear();
	section5(mx, my, targets);
	for (auto&v : targets) {
		tmp[v.first][v.second] = false;
		if (warriors[v.first][v.second] > 0) {
			tmpWarriors.push_back(v);
		}
	}
	for (auto &v : tmpWarriors) {
		if (tmp[v.first][v.second] == false) {
			section5(v.first, v.second, help);
			sectionDown(v.first, v.second, help);
			for (auto &vv : help) {
				tmp[vv.first][vv.second] = true;
			}
			ret += warriors[v.first][v.second];
		}
	}

	targets.clear();
	sectionDown(mx, my, targets);
	for (auto&v : targets) {
		tmp[v.first][v.second] = false;
		if (warriors[v.first][v.second] > 0) {
			ret += warriors[v.first][v.second];
			break;
		}
	}

	return ret;

}


int watchLeft() {
	memset(tmp, true, sizeof(tmp));

	int ret = 0;
	int mx = monster.first;
	int my = monster.second;

	targets.clear();
	tmpWarriors.clear();
	help.clear();
	section6(mx, my, targets);   //메두사가 보는 거 가져오기
	for (auto&v : targets) {
		tmp[v.first][v.second] = false; //메두사가 본다 처리
		if (warriors[v.first][v.second] > 0) {  //전사있으면 거기부분 푸쉬
			tmpWarriors.push_back(v);
		}
	}
	for (auto &v : tmpWarriors) {   //메두사한테 걸린 전사들 
		if (tmp[v.first][v.second] == false) {  //중에 맨앞에있던 애들만
			section6(v.first, v.second, help);
			sectionLeft(v.first, v.second, help);
			for (auto &vv : help) {
				tmp[vv.first][vv.second] = true;
			}
			ret += warriors[v.first][v.second];
		}
	}

	targets.clear();
	tmpWarriors.clear();
	help.clear();
	section7(mx, my, targets);
	for (auto&v : targets) {
		tmp[v.first][v.second] = false;
		if (warriors[v.first][v.second] > 0) {
			tmpWarriors.push_back(v);
		}
	}
	for (auto &v : tmpWarriors) {
		if (tmp[v.first][v.second] == false) {
			section7(v.first, v.second, help);
			sectionLeft(v.first, v.second, help);
			for (auto &vv : help) {
				tmp[vv.first][vv.second] = true;
			}
			ret += warriors[v.first][v.second];
		}
	}

	targets.clear();
	sectionLeft(mx, my, targets);
	for (auto&v : targets) {
		tmp[v.first][v.second] = false;
		if (warriors[v.first][v.second] > 0) {
			ret += warriors[v.first][v.second];
			break;
		}
	}

	return ret;

}


int watchRight() {
	memset(tmp, true, sizeof(tmp));

	int ret = 0;
	int mx = monster.first;
	int my = monster.second;

	targets.clear();
	tmpWarriors.clear();
	help.clear();
	section2(mx, my, targets);   //메두사가 보는 거 가져오기
	for (auto&v : targets) {
		tmp[v.first][v.second] = false; //메두사가 본다 처리
		if (warriors[v.first][v.second] > 0) {  //전사있으면 거기부분 푸쉬
			tmpWarriors.push_back(v);
		}
	}
	for (auto &v : tmpWarriors) {   //메두사한테 걸린 전사들 
		if (tmp[v.first][v.second] == false) {  //중에 맨앞에있던 애들만
			section2(v.first, v.second, help);
			sectionRight(v.first, v.second, help);
			for (auto &vv : help) {
				tmp[vv.first][vv.second] = true;
			}
			ret += warriors[v.first][v.second];
		}
	}

	targets.clear();
	tmpWarriors.clear();
	help.clear();
	section3(mx, my, targets);
	for (auto&v : targets) {
		tmp[v.first][v.second] = false;
		if (warriors[v.first][v.second] > 0) {
			tmpWarriors.push_back(v);
		}
	}
	for (auto &v : tmpWarriors) {
		if (tmp[v.first][v.second] == false) {
			section3(v.first, v.second, help);
			sectionRight(v.first, v.second, help);
			for (auto &vv : help) {
				tmp[vv.first][vv.second] = true;
			}
			ret += warriors[v.first][v.second];
		}
	}

	targets.clear();
	sectionRight(mx, my, targets);
	for (auto&v : targets) {
		tmp[v.first][v.second] = false;
		if (warriors[v.first][v.second] > 0) {
			ret += warriors[v.first][v.second];
			break;
		}
	}
	return ret;
}
void makeStone() {
	int stonedWarriorsDir[] = { watchUp(), watchDown(), watchLeft(), watchRight() };

	int dir = 0;
	int max = stonedWarriorsDir[0];
	for (int i = 1;i < 4;++i) {
		if (max < stonedWarriorsDir[i]) {
			max = stonedWarriorsDir[i];
			dir = i;
		}
	}
	stonedWarrior = max;
	memset(ismovable, true, sizeof(ismovable));

	int mx = monster.first;
	int my = monster.second;
	targets.clear();

	if (dir == 0) { //상
		watchUp();
		section1(mx, my, targets);
		section8(mx, my, targets);
		sectionUp(mx, my, targets);
	}
	else if (dir == 1) { //하
		watchDown();
		section4(mx, my, targets);
		section5(mx, my, targets);
		sectionDown(mx, my, targets);
	}
	else if (dir == 2) {  //좌
		watchLeft();
		section7(mx, my, targets);
		section6(mx, my, targets);
		sectionLeft(mx, my, targets);
	}
	else if (dir == 3) {   //우
		watchRight();
		section2(mx, my, targets);
		section3(mx, my, targets);
		sectionRight(mx, my, targets);
	}
	for (auto&v : targets) {
		ismovable[v.first][v.second] = tmp[v.first][v.second];
	}
}

void printVector(vector<pair<int, int>> a) {
	for (auto&v : a) {
		cout << v.first << " " << v.second << endl;
	}cout << endl;
}

int calcDistanceToMonster(pair<int, int> a) {
	return abs(a.first - monster.first) + abs(a.second - monster.second);
}

void moveWarriors() {

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	int newX, newY;

	int dir;
	for (int time = 0;time < 2;++time) {

		if (time == 0) {
			dir = 0;
		}
		if (time == 1) {
			dir = 2;
		}

		for (auto &v : warriorsVector) {
			if (!v.alive)
				continue;

			if (!ismovable[v.first][v.second])
				continue;

			int minDistance = calcDistanceToMonster({ v.first, v.second });
			int tmpDistance = -1;
			int targetDir = -1;
			for (int i = 0;i < 4;++i, dir = (dir + 1) % 4) {
				newX = v.first + dx[dir];
				newY = v.second + dy[dir];

				if (!checkRange(newX, newY))
					continue;

				if (!ismovable[newX][newY])
					continue;

				tmpDistance = calcDistanceToMonster({ newX, newY });
				if (minDistance > tmpDistance) {
					minDistance = tmpDistance;
					targetDir = dir;
				}
			}

			if (targetDir == -1) {
				continue; //가만히 있는게 젤 가깝거나, 움직일 수 없음 
			}

			warriors[v.first][v.second]--;
			v.first = v.first + dx[targetDir];
			v.second = v.second + dy[targetDir];
			warriors[v.first][v.second]++;
			++warriorMoved;

			if (v.first == monster.first && v.second == monster.second) {
				++attackedWarrior;
				v.alive = false;
				warriors[v.first][v.second]--;
			}
		}
	}
}

void killWarriors() {
	for (auto&v : warriorsVector) {
		if (v.first == monster.first && v.second == monster.second) {
			v.alive = false;
		}
	}
	warriors[monster.first][monster.second] = 0;
}
int main(void) {

	getInput();
	getMonstersRoute();

	if (monsterRoute.size() == 0) {
		cout << -1;
		return 0;
	}

	for (int turn = 0;turn < monsterRoute.size()-1; ++turn) {
		warriorMoved = 0;
		stonedWarrior = 0;
		attackedWarrior = 0;
		monster = monsterRoute[turn];
		killWarriors();
		makeStone();
		moveWarriors();

		cout << warriorMoved << " " << stonedWarrior << " " << attackedWarrior << endl;
	}

	cout << 0; //도착한 턴에는 0 출력 후 끝

}