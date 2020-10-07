#include<iostream>
#include<vector>
#include<ctime>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>




using namespace std;

const int l = 15;
const int L = pow(2, l);


std::ostream& operator<< (std::ostream& out, bitset<l>& bset) {
	for (int i = 0; i < l; i++)
		out << bset[i];
	return out;
}

void prisposoblennost(vector<int>& vec) {
	int diap = 1000;
	for (int i = 0; i < vec.size(); i++)
		vec[i] = rand() % diap;
}

void kodirovka(vector<bitset<l>>& vec) {
	for (int i = 0; i < vec.size(); i++)
		vec[i] = bitset<l>(i);
}

int main()
{
	vector<bitset<l>> S(L);
	vector<int> landshaft(L);

	int N;
	int max;
	bitset<l> maxS;

	srand(time(NULL));
	kodirovka(S);
	prisposoblennost(landshaft);

	max = landshaft[0];
	maxS = S[0];

	cout << "Vvedite N: ";
	cin >> N;

	for (int j = 0; j < N; j++) {
		cout << j + 1 << " shag:\n\tcur max = " << max
			<< ", \n\tmaxS = " << maxS << " ";
		int i = rand() % L;
		cout << "S[" << j << "] = ";
		cout << S[i] << ", \n\tLand[" << i << "] = " << landshaft[i] << endl;
		if (max < landshaft[i]) {
			max = landshaft[i];
			maxS = S[i];
			cout << "\tchange max & maxS: max = " << max
				<< ", maxS = " << maxS << endl;
		}
		cout << endl;
	}
	cout << "Reshenie:" << maxS << endl;
	cout << "prisposoblennost:" << max << endl;

	system("pause");
	return 0;
}




