#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;
	int output = 0;
	int minxy = min(X,Y);

	if (A + B >= C*2){
		output = output + minxy * C * 2;
		Y = Y - minxy;
		X = X - minxy;
	}
	if (A >= C*2){
		output = output + X*C*2;
	}
	if (A <= C*2){
		output = output + X*A;
	}
	if (B >= C*2){
		output = output + Y*C*2;
	}
	if (B <= C*2){
		output = output + Y*B;
	}
	cout << output << endl;
}