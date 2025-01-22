//[골드2] 1655.가운데를말해요 https://www.acmicpc.net/problem/1655

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElementType;

typedef struct _node {
	ElementType data;
}Node;

typedef int (*compFuc)(ElementType, ElementType);

typedef struct _heapTree {
	Node* node;
	int capacity;
	int usedsize;
	compFuc comp;
}HeapTree;

HeapTree* HT_CreateHeapTree(int capacity, compFuc comp) {
	HeapTree* tmp = (HeapTree*)calloc(1, sizeof(HeapTree));
	if (tmp == NULL)
		return NULL;
	tmp->capacity = capacity;
	tmp->usedsize = 0;
	tmp->comp = comp;
	tmp->node = (Node*)calloc(capacity + 1, sizeof(Node));

	return tmp;
}

void HT_DestroyTree(HeapTree* tree) {
	free(tree->node);
	free(tree);
}

void swap(Node* a, Node* b) {
	Node tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

int comp_min(ElementType a, ElementType b) {
	return a < b;
}
int comp_max(ElementType a, ElementType b) {
	return a > b;
}

void HT_InsertNode(HeapTree* tree, ElementType data) {
	if (tree->usedsize + 1 >= tree->capacity)  //힙 꽉 참
		return;

	Node newnode = { data };
	++tree->usedsize;
	tree->node[tree->usedsize] = newnode;
	int parent = tree->usedsize / 2;
	int cur = tree->usedsize;

	Node* node = tree->node;
	while (cur > 1 && tree->comp(node[cur].data, node[parent].data)) {
		swap(node + parent, node + cur);
		cur = parent;
		parent = cur / 2;
	}

	return;
}

void HT_PrintTree(HeapTree* tree) {
	Node* arr = tree->node;
	for (int i = 1;i <= tree->usedsize;++i) {
		printf("%d ", arr[i].data);
	}printf("\n");
	return;
}

Node HT_DeleteNode(HeapTree* tree) {
	Node* node = tree->node;
	Node ret = node[1];

	node[1].data = node[tree->usedsize--].data;

	int cur = 1;
	int left = cur * 2;
	int right = left + 1;
	int target = left;
	while (left <= tree->usedsize) {
		if (tree->usedsize < right)
			target = left;
		else
			target = tree->comp(node[left].data, node[right].data) ? left : right;

		if (tree->comp(node[target].data, node[cur].data)) {
			swap(node + cur, node + target);
			cur = target;
			left = 2 * cur;
			right = left + 1;
		}
		else
			break;
	}

	return ret;
}
int seek(HeapTree* tree) {
	return tree->node[1].data;
}

int main(void) {

	HeapTree* maxheap = HT_CreateHeapTree(100001, comp_max);
	HeapTree* minheap = HT_CreateHeapTree(100001, comp_min);

	int N;
	(void)scanf("%d", &N);

	int i;

	int tmp;
	int a, b;
	for (i = 0;i < N;++i) {
		(void)scanf("%d", &tmp);
		if (maxheap->usedsize > minheap->usedsize) {
			HT_InsertNode(minheap, tmp);
		}
		else {
			HT_InsertNode(maxheap, tmp);
		}

		if (minheap->usedsize != 0 && seek(maxheap) > seek(minheap)) {
			a = HT_DeleteNode(minheap).data;
			b = HT_DeleteNode(maxheap).data;
			HT_InsertNode(maxheap, a);
			HT_InsertNode(minheap, b);
		}

		printf("%d\n", seek(maxheap));
	}

}
