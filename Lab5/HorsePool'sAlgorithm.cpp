#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int horsePool(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    int shift[26];
    for(int i = 0; i < 26; i++){
        shift[i] = m;
    }
    
    for(int i = 0; i <= m - 2; i++){
        if(pattern[i] == '_'){
        	shift[pattern[i]] = m;
        	continue;
    	
        }
        shift[pattern[i] - 'a'] = m - i - 1;
    }
    
    int j = 0;
    while(j + m <= n){
        if(pattern[m-1] == text[j + m - 1]){
            int i = m - 2;
            while(i >= 0 && text[j + i] == pattern[i]){
                i--;
            }
            if(i == -1){
                return j;
            }
        }
        if((text[j + m - 1] - 'a') >= 0)
    	    j = j + shift[text[j + m - 1] - 'a'];
        else
            j = j + m;
	}
	return -1;
    
}

int main(){
    string text = "jimsawmeinabarbershop";
    string pattern = "barber";
    
    cout << horsePool(text, pattern) << endl;
}
