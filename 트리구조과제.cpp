#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <list>
#include <algorithm>
using namespace std;
#define max(a,b) (((a)>(b)) ? (a):(b))

typedef struct node {
	int key; 
	char gender; 
	char name[3];
	struct node* left, *right;
}NODE;

NODE* rotate_LL(NODE* parent) { 
	NODE* child = parent->left;
	parent->left = child->right; 
	child->right = parent; 
	return child;
}

NODE* rotate_RR(NODE* parent) {
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

NODE* rotate_LR(NODE* parent) { 
	NODE* child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent); 
}

NODE* rotate_RL(NODE* parent) { 
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}

int get_height(NODE* node) { 
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_balance(NODE* node) { 
	if (node == NULL) return 0;
	return get_height(node->left) - get_height(node->right); 
}

NODE* balance_tree(NODE** node) {
	int height = get_balance(*node); 
	if (height > 1) { 
		if (get_balance((*node)->left) > 0) { 
			*node = rotate_LL(*node); 
		}
		else {
			*node = rotate_LR(*node); 
		}
	}
	else if (height < -1) {
		if (get_balance((*node)->right) < 0) { 
			*node = rotate_RR(*node);
		}
		else {
			*node = rotate_RL(*node);
		}
	}
	return *node;
}

int cnt = 0;
NODE* search(NODE* root, int key) {
	if (root == NULL) return NULL;
	cnt++;
	printf("%d->", root->key);

	if (root->key == key) return root; 
	else if (root->key < key) return search(root->right, key);
	else return search(root->left, key);
}

NODE* insert(NODE** node, int key, char name[], char gender) {
	if (*node == NULL) {
		*node = (NODE*)malloc(sizeof(NODE));
		(*node)->key = key;
		for (int i = 0; i < 4; i++) (*node)->name[i] = name[i];
		(*node)->gender = gender;
		(*node)->left = (*node)->right = NULL;
	}
	else if (key < (*node)->key) {
		(*node)->left = insert(&(*node)->left, key, name, gender); 
		(*node) = balance_tree(node);
	}
	else if (key > (*node)->key) {
		(*node)->right = insert(&(*node)->right, key, name, gender); 
		(*node) = balance_tree(node); 
	}
	else {
		printf("중복된 데이터로 삽입 실패");
	}
	return *node; 
}


void inorder(NODE* root) {
	if (root != NULL) {
		inorder(root->left);

		printf("%d세 이름: ", root->key);
		for (int i = 0; i < 3; i++) printf("%c", root->name[i]);
		;		if (root->gender == 'f') printf(", 여자\n");
		else printf(", 남자\n");

		inorder(root->right);
	}
}

int main() {
	srand((unsigned)time(NULL));
	char nameSet = 'A'; 
	char gender = 'f';
	int totalNum = 80; 
	int ageArr[85];

	list<int> ages;
	list<int>::iterator itor;
	itor = ages.begin();

	while (ages.size() < 80) {
		int tmp = (rand() % 81) + 20;
		bool found = (find(ages.begin(), ages.end(), tmp) != ages.end());
		if (!found) ages.push_back(tmp);
	}
	char rand_name[81][3]; 
	for (int i = 0; i < 81; i++) {
		int j;
		for (j = 0; j < 3; j++) {
			rand_name[i][j] = 'a' + rand() % 26;
		}
		rand_name[i][j] = 0;
	}

	NODE* root = NULL;
	NODE* tmp = NULL;
	for (int i = 0; i < totalNum; i++) {
		int age = ages.back();
		ages.pop_back();

		int setGender = rand() % 2;
		if (setGender == 0) gender = 'f';
		else gender = 'm';

		printf("%d세 이름: ", age);
		for (int j = 0; j < 3; j++) printf("%c", rand_name[i][j]);
		if (gender == 'f') printf(", 여자");
		else printf(", 남자");
		printf("가 들어왔습니다\n");

		if (i == 0) root = insert(&root, age, rand_name[i], gender);
		else tmp = insert(&root, age, rand_name[i], gender);
	}
	while (1) {
		int findAge = 0;
		printf("\n찾고 싶은 사람의 나이는?(종료는 0) ");
		scanf("%d", &findAge);
		if (findAge == 0) exit(1);

		cnt = 0;
		NODE* res = search(root, findAge);
		if (res == NULL) printf("\n그런 나이의 사람은 없습니다");
		else {
			printf("\n%d세 이름: ", res->key);
			for (int i = 0; i < 3; i++) printf("%c", root->name[i]);
			if (res->gender == 'f') printf(", 여자\n");
			else printf(", 남자\n");
			printf("\n총 %d번만에 찾았습니다\n", cnt);
		}
	}
}