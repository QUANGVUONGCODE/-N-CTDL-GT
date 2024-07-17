#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};
int n, a[1001][1001] = {0}, cnt = 0, u , v;
bool user[1001][1001];
bool check = false;
void inp(){
	memset(user, false, sizeof(user));
}
void xuat(){
	cout << "Tong quat ban co: " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n;  j++){
			cout << setw(5) <<  a[i][j];
		}
		cout << endl;
	}
	cout << "Ban co theo nuoc di.\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " : " << "(" << i << "," << j << ")\n";
		}
	}
}
int Count(int u, int v){
	int cnt = 0;
	for(int i = 0; i < 8; i++){
		int u1 = u + dx[i];
		int v1 = v + dy[i];
		if(u1 >= 0 && v1 < n && v1 >= 0 && u1 < n && user[u1][v1] == false){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	inp();
	n = 0;
	while(n <= 0 || n > 50){
		cout << "Nhap kich thuoc ban co: "; cin >> n;
	}
	cout << "Nhap vi tri xuat phat cua con Ma (u,v):\n";
	u = -1, v = -1;
	while(u < 0 || u > n - 1){	
		cout << "Nhap u = "; cin >> u;
	}
	while(v < 0 || v > n - 1){
		cout << "Nhap v = "; cin >> v;
	}
//	if (u < 0 || v < 0 || u >= n || v >= n) {
//        cout << "Nhap khong hop le.\n";
//        return 0;
//    }
	user[u][v] = true;
	stack<pair<int, int>> st;
	st.push({u, v});

	while (!st.empty()) {
		pair<int, int> current = st.top();
		st.pop();
		u = current.first;
		v = current.second;
		++cnt;
		a[u][v] = cnt;

		if (cnt == n * n) {
			xuat();
			check = true;
			break;
		}

		vector<pair<int, pair<int,int>>> ve;
		for(int k = 0; k < 8; k++){
			int u1 = u + dx[k];
			int v1 = v + dy[k];
			if(u1 >= 0 && v1 < n && v1 >= 0 && u1 < n && user[u1][v1] == false){
				int count = Count(u1,v1);
				ve.push_back({count, {u1,v1}});
			}
		}
		sort(ve.begin(), ve.end());
		for(auto x : ve){
			int u1 = x.second.first;
			int v1 = x.second.second;
			user[u1][v1] = true;
			st.push({u1, v1});
		}
	}

	if (!check) {
        cout << "Khon co duong di het map cho huong vua nhap.\n";
    }
}