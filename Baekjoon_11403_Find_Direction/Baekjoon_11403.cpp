// Baekjoon_11403.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int input[101][101];
bool visit[101][101];
int N;

void dfs(int start, int x, int y);


int main() {

	scanf("%d", &N);

	////�Է°��� ���� �迭 ����
	////2���� �迭�� ���� �Ҵ�
	//int** input = new int*[N];
	//for (int i = 0; i < N; ++i)
	//	input[i] = new int[N];

	////visit �迭 ����
	//int** visit;
	//visit = new int*[N];
	//for (int i = 0; i < N; ++i)
	//	visit[i] = new int[N];

	for (int i = 1; i <= N; i++)//0���� �����ϸ� �迭[0][0]�� �� �����¿� �˻��� -1�� ���� ��Ÿ�� ���� ����
		for (int j = 1; j <= N; j++)
			scanf("%d", &input[i][j]);



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][i] && input[i][j]) // visit[i][i] �� 1�� �ƴϰ� && input[i][j] �� 1�̸�
				dfs(i, i, j);
		}
	}



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%d ", input[i][j]);
		printf("\n");
	}

	return 0;
}

void dfs(int start, int x, int y) {
	input[start][y] = 1;
	visit[start][y] = true;

	for (int i = 1; i <= N; i++) {//���
		if (!visit[start][i] && input[y][i])
			dfs(start, y, i);
	}
}

