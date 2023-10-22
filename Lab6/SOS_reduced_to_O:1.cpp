#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool knapScack(vector<vector<int>> &mat, vector<int> &arr, int sum, int n){
    
    for(int i = 0; i < n; i++){
        mat[i][0] = 0;
        
    }
    
    for(int i = 1; i <= sum; i++){
        mat[0][i] = 0;
    }
    
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j <= sum; j++){
            if(j < arr[i]){
                mat[i][j] = mat[i-1][j];
            }
            else{
                mat[i][j] = max(mat[i-1][j], mat[i-1][j - arr[i]] + arr[i]);
            }
        }
    }
    
    if(mat[n][sum] >= sum){
        return true;
    }
    return false;
    
}


int main(){
    
    int n;
    cout << "enter the length of the set: " << n;
    cin >> n;
    
    int sum;
    cout << "enter the sum you want to achieve: " << n;
    cin >> sum;
    
    // vector<vector<int>>mat(n+1, vector<int>(sum + 1));
    vector<vector<int>> mat(n+1, vector<int>(sum+1));
    
    set<int> s;
    
    
    cout << "enter the numbers you want to enter: " << endl;
    s.insert(0);
    for(int i = 1; i < n + 1; i++){
        int val;
        cin >> val;
        s.insert(val);
    }
    
    vector<int> arr(s.begin(), s.end());
    if(knapScack(mat, arr, sum, n) == true){
        cout << "got ittt!!!" << endl;
    }
    
    else{
        cout << "shittt!!" << endl;
    }
    
    
    return 0;
    
    
    
    
}
