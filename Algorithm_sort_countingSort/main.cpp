#include <iostream>
#define k 5

using namespace std;

int b[11] = { -1, 0, }; //������ ��� ������ sort ����� �����ϴ� �迭
int c[10] = { 0, }; //������ ������ ī�����ϴ� �迭

void countSort(int* a) { //�ܼ� ��� ����
	int s = 0;

	for (int i = 0; i < 10; i++) //counting
		c[a[i]]++;

	for (int i = 0; i <= k; i++) { //sort
		for (int j = 0; j < c[i]; j++)
			a[s++] = i;
	}
}

void countSort_v2(int* a) { //��ȭ�� ��� ����
	int s = 0;


	for (int i = 0; i < 10; i++) //counting
		c[a[i+1]]++;
	for (int i = 0; i < k; i++) //c�� ������ ������� Ż�ٲ�
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