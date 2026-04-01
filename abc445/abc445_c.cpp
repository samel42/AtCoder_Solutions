#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1,0);
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for (int i = N; i >= 1; i--){
        if(A[i] != i){
            A[i] = A[A[i]];
        }
    }
    for (int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
}