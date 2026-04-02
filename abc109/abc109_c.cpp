#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, X;
	cin >> N >> X;
	vector<int> S(N + 1,0);
	S[0] = X;
	for (int i = 1; i <= N; i++){
		int tmp;
		cin >> tmp;
		S[i] = tmp;
	}
	sort(S.begin(),S.end());
	int output;
	if (N == 1){
	  output = S[1] - S[0];
	}
	if (N == 2){
	  output = gcd(S[1]-S[0], S[2]-S[0]);
	}
	if(N >= 3){
	output = gcd(S[1]-S[0], S[2]-S[0]);
  	for (int i = 3; i <= N; i++){
  		output = gcd(S[i] - S[0] , output);
  	}
	}
	cout << output << endl;
}