#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> room(N,0);
	int index_first  = 0 ;
	int first =0,last = 0;
	for(int i = 0; i < N;i++){
		cin >> room[i];
		if (room[i] == 1 && index_first == 0){
			first = i;
			index_first = 1;
		}
		if (room[i] == 1){
			last = i;
		}
	}
	cout << last - first << endl;
}