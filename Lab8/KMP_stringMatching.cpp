#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int comp = 0;

void computePrefixFunction(vector<int> &pi, int m, string pattern){
    pi[1] = 0;
    int k = 0;
    
    for(int q = 2; q <= m; q++){
  	 
   	 bool t = pattern[k + 1] != pattern[q];
  	 
   	 comp++;
   	 while(k > 0  && t){
   		 k = pi[k];
   		 t = pattern[k + 1] != pattern[q];
   		 comp++;
  	 
   	 }
  	 
   	 if(!t){
   		 k++;
   	 }
	 
   	 pi[q] = k;
    }
    
    cout << comp << endl;
    for(int i = 1; i <= m; i++){
    	cout << pi[i] << " ";
    }
    cout << endl;
    
    
}


void KmpMatcher(vector<int> pi, string text, string pattern){
	int q = 0, count = 0;
	int m = pattern.length() - 1;
	int n = text.length() - 1;
	for(int i = 1; i <= n; i++){
    	bool t = pattern[q + 1] != text[i];
    	count++;
    	while(q > 0 && t){
        	q = pi[q];
        	t = pattern[q + 1] != text[i];
        	count++;
       	 
       	 
    	}
    	if(!t){
        	q = q + 1;
    	}
 
   	 
    	if(q == m){
       	 
        	cout << "pattern occured with shift: " << i - m << endl;
        	q = pi[q];
       	 
    	}
	}
	cout << count << " ";
}

int main()
{
   
    
	string pattern, text;
	cin >> pattern >> text;
	int m = pattern.length() - 1;
	int n = text.length() - 1;
	vector<int> pi(m + 1);
    
	computePrefixFunction(pi, m, pattern);
    
    
	KmpMatcher(pi, text, pattern);
    
	return 0;
}


