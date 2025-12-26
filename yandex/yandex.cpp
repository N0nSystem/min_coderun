#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;
int main()
{
	int n, m,num; string stroka;
	getline(cin, stroka);
	stringstream ss2(stroka);
	ss2 >> n;
	ss2 >> m; 
	vector<vector<int>> mas(n,vector<int>(m));// массив с данными о яцейках о пище .. не изменять массив
	vector<vector<int>> mas1(n, vector<int>(m)); // состояние 1 - чел который должен ходить, 0 - не должен .... определяет кто должен ходить
	vector<vector<int>> mas2(n, vector<int>(m)); // элементы 150 - изначально .. ищем кротчайший путь
	for (int ni = 0; ni < n; ni++) {
		for (int mi = 0; mi < m; mi++) {
			mas2[ni][mi] = INT_MAX;
		}
	} // заполняем 150
	
	for (int ni = 0; ni < n; ni++) {
		
		getline(cin, stroka);
		stringstream ss(stroka);
		for (int mi = 0; mi < m; mi++) { // заполняем массив mas пользовательским вводом
			ss >> num;
			mas[ni][mi] = num;
		}
	}
	mas1[0][0] = 1;
	mas2[0][0] = mas[0][0];
	/*for (int ni = 0; ni < n; ni++) {
		for (int mi = 0; mi < m; mi++) {
			cout << mas[ni][mi]; // проверка массива
		}
		cout << endl;
	}*/

	int ni = 0;
	for (int ni = 0; ni < n; ni++) {
		for (int mi = 0; mi < m; mi++) {
			if (mas1[ni][mi] == 1) {
				mas1[ni][mi] = 0;
				if (mi != m - 1) {
					if (mas2[ni][mi + 1] > mas2[ni][mi] + mas[ni][mi + 1]) {
						mas2[ni][mi + 1] = mas2[ni][mi] + mas[ni][mi + 1];
						mas1[ni][mi + 1] = 1;
					}
				}
				if (ni != n - 1) {
					if (mas2[ni + 1][mi] > mas2[ni][mi] + mas[ni + 1][mi]) {
						mas2[ni + 1][mi] = mas2[ni][mi] + mas[ni + 1][mi];
						mas1[ni + 1][mi] = 1;
					}
				}
			}
			//cout << mas[ni][mi] << " ";
		}
	}

		
		cout << endl <<mas2[n - 1][m - 1];
	return 0;
}