#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

void DInicCube(int**& a, int& n) {
	cout << "Type N - number of rows and columns!" << endl;
	cin >> n;
	a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
}

void RandomsCube(int**& a, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 10000;
		}
	}
}

void InpCube(int**& a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; i++) {
			cout << "[" << i << "][" << j << "] -> ";
			cin >> a[i][j];
		}
	}
}

int mini(int a, int b) {
	if (a < b) return a;
	return b;
}

int MaxAboveCube(int**& a, int n) {
	int Ans = 1000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			Ans = mini(Ans, a[j][i]);
		}
	}
	return Ans;
}

void DiagTestCube(int**& a, int n) {
	int Zeros = 0;
	int UnitsMain = 0;
	int ZeroMain = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				if (a[i][j] == 1)
					UnitsMain++;
				else if (a[i][j] == 0)
					ZeroMain++;
			}
			else {
				if (a[i][j] == 0)
					Zeros++;
			}
		}
	}
	if (Zeros == (n * (n - 1)) && UnitsMain != n && ZeroMain == 0) cout << "1" << endl;
	else if (Zeros == (n * (n - 1)) && UnitsMain == n && ZeroMain == 0) cout << "2" << endl;
	else if (Zeros == (n * (n - 1)) && UnitsMain == 0 && ZeroMain == n) cout << "3" << endl;
	cout << "None of done!" << endl;
}

void DelCube(int**& a, int n) {
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[]a;
}

void MassOutputCube(int**& a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void DArray7() {
	int n;
	int Ans;
	int** a;
	DInicCube(a, n);
	RandomsCube(a, n);
	MassOutputCube(a, n);
	Ans = MaxAboveCube(a, n);
	DelCube(a, n);
	cout << Ans << endl;
}

void DArray17() {
	int n;
	int** a;
	DInicCube(a, n);
	RandomsCube(a, n);
	MassOutputCube(a, n);
	DiagTestCube(a, n);
	DelCube(a, n);
}

string ClearZeros(string a) {
	int i = 0;
	string b = "";
	while (a[i] == '0')
		i++;
	for (int j = i; j < a.length(); j++) {
		b += a[j];
	}
	return b;
}

int maxi(int a, int b) {
	if (a > b) return a;
	return b;
}

bool StringCheck(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ' || !isdigit(a[i])) return false;
	}
	return true;
}

void Longnumbers() {
	//автору спасибо огромное :) https://vk.com/talie_lie
	int size_a, size_b, length;
	int ind;
	string sa, sb;
	cin >> sa;
	cin >> sb;
	if (StringCheck(sa) && StringCheck(sb)) {
		sb = ClearZeros(sb);
		sa = ClearZeros(sa);
		size_a = sa.length();//длина первого слагаемого
		size_b = sb.length();//длина второго слагаемого
		length = maxi(sa.length(), sb.length());
		int* a = new int[size_a];//выделяем память под первый массив
		int* b = new int[length];//выделяем память под второй массив
		for (int i = size_a - 1; i >= 0; i--) //заполняем массив цифрами первого слагаемого с конца
		{
			a[size_a - 1 - i] = sa[i] - '0';
		}
		for (int i = size_b - 1; i >= 0; i--) //заполняем массив цифрами второго слагаемого с конца
		{
			b[size_b - 1 - i] = sb[i] - '0';
		}
		for (int i = 0; i < length; i++) //вычисления
		{
			if (i < size_a) //не дошли до конца массива a
			{
				if ((b[i] - a[i]) > 0) {
					b[i] -= a[i];
				}
				else {
					b[i] = 10 + b[i] - a[i];
					ind = i + 1;
					while (b[ind] == 0) {
						b[ind] = 9;
						ind++;
					}
					b[ind] -= 1;
				}
			}
		}
		string ans = "";
		for (int i = length - 1; i >= 0; i--)
		{
			ans += to_string(b[i]); //добавляем по 1 цифре к результату с конца
		}
		ans = ClearZeros(ans);
		cout << ans << endl;
	}
	else cout << "Wrong input!" << endl;
	//автору спасибо огромное :)
}