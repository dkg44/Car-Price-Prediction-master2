// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  long long int solve(int S[], int m, int n, vector<vector<long long int>> &dp)
    {
        // base condition
        if (m == -1 && n > 0)
        { // means array size khatm ho gyi and n 0 nhi hua
            return 0;
        }
        if (n == 0)
        { // mtlb bich me hi kahi possible combination ban gya
            return 1;
        }
        if (n < 0)
        { // means n -nme h chala gya toh vconsider nhi krenge
            return 0;
        }
        //memoized step
        if (dp[m][n] != -1)
            return dp[m][n];
        // calculation step
        if (S[m - 1] <= n)
        {
            return dp[m][n] = solve(S, m, n - S[m], dp) + solve(S, m - 1, n, dp);
        }
        return dp[m][n] = solve(S, m - 1, n, dp);
    }
  long long int count(int S[], int m, int n) {

        // code here.
         vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1, -1));

    // solve the sol
    return solve(S, m - 1, n, dp); // m-1 indexing
    }
}; 

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends