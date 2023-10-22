#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void FA(string t, string p){
    
    int state_table[4][2] = {
        {1, 0},
        {1, 2},
        {1, 3},
        {1, 0}
    };
    int n = t.length();
    int m = p.length();
    
    
    int q = 0;
    for(int i = 0; i <= n; i++){
        // cout << "q: " << q << " t[i]-'a': " << t[i]-'a'<< endl;
        q = state_table[q][t[i]-'a'];
        cout << "q: " << q << endl;
        if(q == m){
            cout << "shift: '" << i - m + 1 << "' matched " << endl;
            q = 0;
        }
    }
}

int main(){
    
    string text = "abbabbjabb";
    string pattern = "abb";
    
    
    FA(text, pattern);
}
