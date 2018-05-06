Условие: дан бесконечный массив из 3-х символов:abc.Реализовать генератор,состоящий из случайной посл-ти символов алфавита.
Записать массив в файл.Посчитать кол-во триад: aaa,bbb,ccc.
	
#include<iostream>
#include <fstream>

using namespace std;

int main() {

	int n;
	cin >> n;

	char *arr = new char[n];

	for (int i = 0; i < n; ++i) {
		arr[i] = 'a' + rand() % 3;
	}

	ofstream fout("abc.txt");
	
	for (int i = 0; i < n; ++i) {
		fout << arr[i];
	}

	fout.close();

	ifstream fin("abc.txt");

	int i = 0;
	char *in_arr = new char[n];
	while (!fin.eof()) {
		fin >> in_arr[i];
		i++;
	}

	int ca, cb, cc;
	ca = cb = cc = 0;

	i = 0;
	while (i < n) {
		int j;
		for (j = 0; i + j < n && j < 3 && in_arr[i + j] == 'a'; ++j) {}
		i += j;
		if (j == 3) ca++;

		for (j = 0; i + j < n && j < 3 && in_arr[i + j] == 'b'; ++j) {}
		i += j;
		if (j == 3) cb++;

		for (j = 0; i + j < n && j < 3 && in_arr[i + j] == 'c'; ++j) {}
		i += j;
		if (j == 3) cc++;
	}

	for (int i = 0; i < n; ++i) {
		cout << in_arr[i] << ' ';
	}

	cout << endl << ca << ' ' << cb << ' ' << cc << endl;

	system("pause");
	return 0;

}



