//[골드5] 7576.토마토 https://www.acmicpc.net/problem/7576

//큐 구현을 진짜로 다하다니..
#include<stdio.h>
#include<stdlib.h>

int N, M;
int board[1002][1002];

typedef struct _node {
	int x;
	int y;
	int day;
}Node;

int f = 0;
int r = 0;
int answer = 0;

Node queue[1000003];

int isEmpty() {
	return f == r;
}

void Enqueue(int i, int j, int day) {
	queue[r++] = (Node){ i, j, day };
	return;
}

Node Dequeue() {
	return queue[f++];
}

inline int SetMaxAnswer(int a, int b) {
	answer = a > b ? a : b;
}

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int GetAnswer() {
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			if (board[i][j] == 0) {
				return -1;
			}
		}
	}
	return answer;
}

int main(void) {

	(void)scanf("%d %d", &M, &N);
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			(void)scanf("%d", &board[i][j]);
			if (board[i][j] == 1) {
				Enqueue(i, j, 0);
			}
		}
	}

	int newX, newY;
	while (!isEmpty()) {
		Node first = Dequeue();

		for (int dir = 0;dir < 4;++dir) {
			newX = first.x + dx[dir];
			newY = first.y + dy[dir];

			if (newX < 0 || newY < 0 || newX >= N || newY >= M)
				continue;

			if (board[newX][newY] == 0) {
				board[newX][newY] = 1;
				Enqueue(newX, newY, first.day + 1);
				SetMaxAnswer(answer, first.day + 1);
			}
		}
	}

	printf("%d", GetAnswer());

	return 0;
}