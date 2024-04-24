#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	//doc du lieu
	vector<string> lines;
	string line;
	while (getline(cin,line)) {
		lines.push_back(line);
	}	
	
	char start = lines[0][lines[0].length()-1];
	char finish = lines[1][lines[1].length()-1];
	
	int k['Z'+1]['Z'+1];
	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 'A'; j <= 'Z'; j++) {
			k[i][j] = 0;
		}
	}
	
	int h['Z'+1];
	for (int i = 'A'; i<= 'Z'; i++) {
		h[i] = 0;
	}
	
	int d = 3;
	while (lines[d] != "" ) {
		char c = lines[d][0];
		lines[d].erase(lines[d].begin(), lines[d].begin() + 2);
		string val = lines[d];
		h[c] = atoi(val.c_str());
		d++;
	}
	
//	for (int i = 'A'; i<= 'Z'; i++) {
//			cout << char(i) << " " << h[i] << endl;
//		}

	d++;
	for (int i = d; i < lines.size(); i++) {
		char m = lines[i][0];
		char n = lines[i][2];
		lines[i].erase(lines[i].begin(), lines[i].begin() + 4);
		string val = lines[i];
		k[m][n] = atoi(val.c_str());
	}
	
//thuat toan
	
	vector<char> L;
	vector<int> f;
	vector<int> g;
	
	vector<char> duyet;
	vector<char> road;
	
	cout << "TT\t|\tTTK\t|\tk(u,v)\t|\th(v)\t|\tg(v)\t|\tf(v)\t|\tDS L" << endl;
	L.push_back(start);
	f.push_back(h[start]);
	g.push_back(0);
	
	while(true) {
		int check = 0;
		cout << L[0];
		char xet = L[0];
		duyet.push_back(xet);
		
		//kiem tra ket thuc
		if (xet == finish) {
			cout << "\t Trang thai ket thuc " << endl;
			cout << "Do dai : " << f[0] << endl;
			// tim duong di
			char m = finish;
			road.push_back(m);
			for (int i = duyet.size()-1; i >=0; i--) {
				if (k[duyet[i]][m] > 0) {
					m = duyet[i];
					road.push_back(m);
				}
			}
			cout << "Duong di : " << start;
			for (int i = road.size() - 2; i >= 0; i--) {
				cout << " -> " << road[i];
			}
			break;
		}
		//duyet 
		L.erase(L.begin());
		f.erase(f.begin());
		int gu = g[0];
		g.erase(g.begin());
		cout << "\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t";
		
		for (int i = 'A'; i<= 'Z'; i++) {
			if (k[xet][i] > 0) {
				check = 1;
				int fv = gu + k[xet][i] + h[i];
				int gv = gu + k[xet][i];
				cout << endl << "\t|\t" << char(i) << "\t|\t" << k[xet][i] << "\t|\t"
					<< h[i] << "\t|\t" << gv
					<< "\t|\t" << fv << "\t| ";
					
				//chen vao danh sach L	
				int check_d = 0;
				for (int j=0; j<L.size(); j++) {
					if (f[j] > fv) {
						check_d = 1;
						L.insert(L.begin()+j, i);
						f.insert(f.begin()+j, fv);
						g.insert(g.begin()+j, gv);
						break;
					}			
				}
				if (check_d == 0) {
					L.push_back(i);
					f.push_back(fv);
					g.push_back(gv);
				}
			}
		}
		//in danh sach L
		for (int i=0; i<L.size(); i++) {
			cout << L[i] << f[i] << " ";
		}
		cout << endl << "------------------------------------------------------------------------------------------------------" << endl;
		//kiem tra that bai
		if (check == 0) {
			cout << endl << "That bai!";
			break;
		}
	}
}
