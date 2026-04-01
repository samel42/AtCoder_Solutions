#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> DA(M+1,0);
    vector<int> DB(M+1,0);
    int A,B;
    for (int i = 0; i < N; i++){
        cin >> A >> B;
        DA[A]++;
        DB[B]++;
    }
    int output = 0;
    for (int i = 1; i < M+1; i++){
        output = DB[i] - DA[i];
        cout << output << endl;
    }
}