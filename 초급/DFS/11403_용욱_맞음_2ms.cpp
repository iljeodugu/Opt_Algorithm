#pragma warning(disable:4996)

#include<iostream>
#include<cmath>

using namespace std;

int g[100][100] = { 0 };
int N;

void fillMatrix() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (g[j][k] == 1) {
					for (int l = 0; l < N; l++) {
						g[j][l] |= g[k][l];
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &g[i][j]);
		}
	}

	fillMatrix();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}

	return 0;
}