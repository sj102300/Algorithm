//[골드4] 1715.카드정렬하기 https://www.acmicpc.net/problem/1715

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
int heap[100003];
int usedsize = 0;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void Push(int data) {
	
	heap[++usedsize] = data;
	int cur = usedsize;
	int parent = usedsize / 2;

	while (cur > 1 && heap[parent] > heap[cur]) {
		swap(&heap[parent], &heap[cur]);
		cur = parent;
		parent /= 2;
	}

}

int Pop() {

	int ret = heap[1];

	heap[1] = heap[usedsize--];

	int cur = 1;
	int child = 2;

	while (child <= usedsize) {
		if (child + 1 <= usedsize && heap[child] > heap[child+1]) {
			++child;
		}

		if (heap[cur] < heap[child])
			break;
		
		swap(&heap[child], &heap[cur]);
		cur = child;
		child = 2 * cur;
	}

	return ret;

}

void printheap() {
	for (int i = 1;i <= usedsize;++i) {
		printf("%d ", heap[i]);
	}
	printf("\n");
}

int main(void) {

	(void)scanf("%d", &n);
	
	int tmp;
	for (int i = 1;i <= n;++i) {
		(void)scanf("%d", &tmp);
		Push(tmp);
	}


	int answer = 0;
	int first, second;
	for(int i=0;i<n-1;++i){
		first = Pop();
		second = Pop();

		answer += first + second;
		Push(first + second);
	}

	printf("%d", answer);


	return 0;
}