#include <iostream>
#define k 5

using namespace std;

int b[11] = { -1, 0, }; //진보된 계수 정렬의 sort 결과를 저장하는 배열
int c[10] = { 0, }; //원소의 개수를 카운팅하는 배열

void countSort(int* a) { //단순 계수 정렬
	int s = 0;

	for (int i = 0; i < 10; i++) //counting
		c[a[i]]++;

	for (int i = 0; i <= k; i++) { //sort
		for (int j = 0; j < c[i]; j++)
			a[s++] = i;
	}
}

void countSort_v2(int* a) { //진화한 계수 정렬
	int s = 0;


	for (int i = 0; i < 10; i++) //counting
		c[a[i+1]]++;
	for (int i = 0; i < k; i++) //c를 누적합 방식으로 탈바꿈
		c[i+1] += c[i];

	for (int i = 10; i > 0; i--) { //sort
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}

}

int main() {
	int a[11] = {-1, 0, 1, 2, 3, 2, 1, 0, 1, 2, 2 };

	countSort_v2(a);

	for (int i = 1; i <= 10; i++) //counting
		cout << b[i] << " ";
}