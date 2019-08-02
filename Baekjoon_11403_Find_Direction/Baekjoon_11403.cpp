// Baekjoon_11403.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int input[101][101];
bool visit[101][101];
int N;

void dfs(int start, int x, int y);


int main() {

	scanf("%d", &N);

	////입력값에 대한 배열 생성
	////2차원 배열을 동적 할당
	//int** input = new int*[N];
	//for (int i = 0; i < N; ++i)
	//	input[i] = new int[N];

	////visit 배열 생성
	//int** visit;
	//visit = new int*[N];
	//for (int i = 0; i < N; ++i)
	//	visit[i] = new int[N];

	for (int i = 1; i <= N; i++)//0에서 시작하면 배열[0][0]일 때 상하좌우 검색시 -1이 나와 런타임 에러 가능
		for (int j = 1; j <= N; j++)
			scanf("%d", &input[i][j]);



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][i] && input[i][j]) // visit[i][i] 가 1이 아니고 && input[i][j] 가 1이면
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

	for (int i = 1; i <= N; i++) {//재귀
		if (!visit[start][i] && input[y][i])
			dfs(start, y, i);
	}
}

