#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSum(int set[], int n, int sum) {
    vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1, false));

    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int set[] = {3, 5, 7, 9, 11};
    int sum = 13;
    int n = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, n, sum)) {
        cout << "Subset with the given sum exists." << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }

    return 0;
}
