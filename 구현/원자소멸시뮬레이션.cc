//[SWEA] 5648.원자소멸시뮬레이션 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRFInKex8DFAUo

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int T;
int n;
int board[4001][4001];
//상하좌우
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,-1,1 };

vector<pair<int, int>> deleteAtoms;

typedef struct _atom {
	int r;
	int c;
	int dir;
	int energy;
	bool live;
} AtomInfo;

vector<AtomInfo> atoms;

void getInput() {

	cin >> n;

	atoms.clear();

	int a, b, c, d;
	int x, y;
	for (int i = 0;i < n;++i) {
		cin >> a >> b >> c >> d;
		x = a * 2 + 2000;
		y = b * 2 + 2000;
		++board[y][x];
		atoms.push_back({ y, x, c, d, true });
	}
}

int moveAtoms() {

	int answer = 0;
	int newR, newC;
	while (n > 0) {

		deleteAtoms.clear();

		for (auto &atom : atoms) {

			if (!atom.live)
				continue;
			
			board[atom.r][atom.c] -= 1;
			newR = atom.r + dr[atom.dir];
			newC = atom.c + dc[atom.dir];
			
			if (newR < 0 || newC < 0 || newR > 4000 || newC > 4000) {
				--n;
				atom.live = false;
			}
			else {
				board[newR][newC] += 1;
				atom.r = newR;
				atom.c = newC;
			}
		}

		for (auto& atom : atoms) {
			if (!atom.live)
				continue;

			if (board[atom.r][atom.c] >= 2 ) {
				--n;
				atom.live = false;
				answer += atom.energy;
				deleteAtoms.push_back({ atom.r, atom.c });
			}
		}

		for (auto& tmp : deleteAtoms) {
			board[tmp.first][tmp.second] = 0;
		}
	}

	return answer;
}

int main(void) {

	freopen("data.txt", "r", stdin);
	cin >> T;

	for (int test = 1; test <= T; ++test) {
		getInput();
		cout << "#" << test << " " << moveAtoms() << "\n";
	}
}