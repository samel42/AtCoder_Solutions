#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int A = 0, B = 0, C = 0;
    for (char c : str) {
        if (c == 'A') {
            A++;
        } 
        else if (c == 'B') {
            if (A > 0) {
                A--;
                B++;
            }
        } 
        else if (c == 'C') {
            if (B > 0) {
                B--;
                C++;
            }
        }
    }
    cout << C << endl;
    return 0;
}