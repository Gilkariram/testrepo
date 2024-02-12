#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) __builtin_popcount(x)
const int N=1e3+2;

int lcs(string& s1, string& s2, int n, int m, vector<vector<int>>& dp)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    int i = n, j = m;
    string lcs_str = "";
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            lcs_str += s1[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    reverse(lcs_str.begin(), lcs_str.end());
    cout << "LCS: " << lcs_str << endl;
    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    cout << "Length of LCS: " << lcs(s1, s2, n, m, dp) << endl;
    return 0;
}
