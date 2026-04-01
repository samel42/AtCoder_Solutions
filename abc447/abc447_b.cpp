#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    vector<int> count(26,0);
    for (char c : str){
        count [c - 'a']++;
    }
    int max_count = *max_element(count.begin(), count.end());
    for (char c : str){
        if (count[c - 'a'] != max_count) {
            cout << c;
        }
    }
    return 0;
}