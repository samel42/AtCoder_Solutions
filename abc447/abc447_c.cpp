#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1,str2;
    cin >> str1 >> str2;

    string str3,str4;
    int i = 1;
    for (char c : str1){
        if (c != 'A'){
            str3 += c;
            i++;
        }
    }
    i = 1;
    for (char c : str2){
        if (c != 'A'){
            str4 += c;
            i++;
        }
    }
    if(str3 != str4){
        cout << -1 << endl;
        return(0);
    }
    vector<int> count1(i,0);
    vector<int> count2(i,0);
    i = 0;
    for (char c : str1){
        if (c == 'A'){
            count1[i]++;
        }
        else{
            i++;
        }
    }
    i = 0;
    for (char c : str2){
        if (c == 'A'){
            count2[i]++;
        }
        else{
            i++;
        }
    }
    int output = 0;
    for(int j = 0; j <= i; j++){
        output = output + abs(count1[j] - count2[j]);
    }
    cout << output << endl;
    return(0);
}