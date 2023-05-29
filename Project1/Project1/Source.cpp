#include <iostream>
#include <omp.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		int v = 0;
		if (i % 2 == 0)
		{
#pragma omp parallel for private(v)
			for (int j = 0; j < n; j += 2) {
				if (j < n - 1) {
					if (a[j] > a[j + 1])
					{
						v = a[j];
						a[j] = a[j + 1];
						a[j + 1] = v;
					}
				}
			}
		}
		else
		{
#pragma omp parallel for private(v)
			for (int j = 1; j < n; j += 2) {
				if(j < n - 1) {
					if (a[j] > a[j + 1])
					{
						v = a[j];
						a[j] = a[j + 1];
						a[j + 1] = v;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}