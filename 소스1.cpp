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
	int key; //����
	char sex; //�̸�, ����(f,m)
	char name[3];
	struct node* left, *right;
}NODE;

//AVL����
NODE* rotate_LL(NODE* parent) { //LLȸ��(���������� ȸ���Ѵ�)
	NODE* child = parent->left;
	parent->left = child->right; //�θ��� ���� ���=�ڽ� ������ ���(�θ𿡰Դ� NULL���� ��/���� �޸�)
	child->right = parent; //�θ� �ڽ��� ������ ����(�ڽ� �����ʿ��ٰ� �θ� Ʈ�� ����)
	return child;
}

NODE* rotate_RR(NODE* parent) { //RRȸ��(�������� ȸ���Ѵ�)
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

NODE* rotate_LR(NODE* parent) { //LRȸ��(������-�������� ȸ���Ѵ�)
	NODE* child = parent->left;
	parent->left = rotate_RR(child); //�ڽ� ��� RRȸ���ؼ� ��������
	return rotate_LL(parent); //�θ� LLȸ���ؼ� �ڽ��� ����������
}

NODE* rotate_RL(NODE* parent) { //RLȸ��(����-���������� ȸ���Ѵ�)
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}

int get_height(NODE* node) { //��带 �������� Ʈ���� ���� ���ϱ�
	int height = 0;
	if (node != NULL)
		//NULL�� �ƴϸ� ��Ʈ 1���� ������ ����
		//max(���� ����, ������ ����)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_balance(NODE* node) { //������ �Ǵ� ���̸� ����
	if (node == NULL) return 0;
	return get_height(node->left) - get_height(node->right); //���� ����Ʈ�� ���� - ������ ����Ʈ�� ���� 
}

NODE* balance_tree(NODE** node) { //Ʈ���� ���� ����
	int height = get_balance(*node); //���� ����-������ ����
	if (height > 1) { //������ �� ũ�ٸ� ���� ����Ʈ�� ������ ����
		if (get_balance((*node)->left) > 0) { //���� ��尡 �� ũ��
			//printf("LL\n");
			*node = rotate_LL(*node); //���������� ����
		}
		else {
			//printf("LR\n");
			*node = rotate_LR(*node); //�ƴϸ� ������-��������
		}
	}
	else if (height < -1) { //������ ����Ʈ�� ������ ����
		if (get_balance((*node)->right) < 0) { //������ ��尡 �� ũ��
			//printf("RR\n");
			*node = rotate_RR(*node); //�������� ����
		}
		else {
			//printf("RL\n");
			*node = rotate_RL(*node); //�ƴϸ� ����-����������
		}
	}
	//0�̸� ������ �´� ���̹Ƿ� �н�
	return *node;
}

int cnt = 0;
NODE* search(NODE* root, int key) {
	if (root == NULL) return NULL;
	cnt++;
	printf("%d->", root->key);

	if (root->key == key) return root; //key�� �ڱ� �ڽ��� ��� ã�����Ƿ� ����
	else if (root->key < key) return search(root->right, key); //����Ű<ã������ Ű�� ������ Ʈ����(ū����)
	else return search(root->left, key); //�ƴϸ� ���� Ʈ����
}

NODE* insert(NODE** node, int key, char name[], char sex) {
	if (*node == NULL) {
		*node = (NODE*)malloc(sizeof(NODE));
		(*node)->key = key;
		for (int i = 0; i < 4; i++) (*node)->name[i] = name[i];
		(*node)->sex = sex;
		(*node)->left = (*node)->right = NULL;
	}
	else if (key < (*node)->key) {
		(*node)->left = insert(&(*node)->left, key, name, sex); //ã��Ű<���Ű�� ����
		(*node) = balance_tree(node); //���� ����
	}
	else if (key > (*node)->key) {
		(*node)->right = insert(&(*node)->right, key, name, sex); //�ݴ�� ������
		(*node) = balance_tree(node); //���� ����
	}
	else {
		printf("�ߺ��� �����ͷ� ���� ����");
	}
	return *node; //��� ������ ��ȯ
}


void inorder(NODE* root) {
	if (root != NULL) {
		inorder(root->left);

		printf("%d�� �̸�: ", root->key);
		for (int i = 0; i < 3; i++) printf("%c", root->name[i]);
		;		if (root->sex == 'f') printf(", ����\n");
		else printf(", ����\n");

		inorder(root->right);
	}
}

int main() {
	srand((unsigned)time(NULL));

	char rand_name[7][3]; //���� �̸� ����
	for (int i = 0; i < 7; i++) {
		int j;
		for (j = 0; j < 3; j++) {
			rand_name[i][j] = 'a' + rand() % 26;
		}
		rand_name[i][j] = 0;
	}

	NODE* root = NULL;
	root = insert(&root, 50, rand_name[0], 'f');
	insert(&root, 30, rand_name[1], 'm');
	insert(&root, 20, rand_name[2], 'm');
	insert(&root, 40, rand_name[3], 'f');
	insert(&root, 70, rand_name[4], 'm');
	insert(&root, 60, rand_name[5], 'f');
	insert(&root, 80, rand_name[6], 'f');

	printf("��� ��� �������� ���\n");
	inorder(root);


	while (1) {
		int findAge = 0;
		printf("\nã�� ���� ����� ���̴�?(����� 0) ");
		scanf("%d", &findAge);
		if (findAge == 0) exit(1);

		cnt = 0;
		NODE* res = search(root, findAge);
		if (res == NULL) printf("\n�׷� ������ ����� �����ϴ�");
		else {
			printf("\n%d�� �̸�: ", res->key);
			for (int i = 0; i < 3; i++) printf("%c", root->name[i]);
			if (res->sex == 'f') printf(", ����\n");
			else printf(", ����\n");
			printf("\n�� %d������ ã�ҽ��ϴ�\n", cnt);
		}
	}
}