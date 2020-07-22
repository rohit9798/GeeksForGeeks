Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
First line consists of T test cases. First line of every test case consists of n, denoting the size of array. Second line of every test case consists of price of ith length piece.

Output:
For each testcase, in a new line, print a single line output consists of maximum price obtained.

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= Ai <= 100

Example:
Input:
1
8
1 5 8 9 10 17 17 20
Output:
22



#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin >> n;
	    int A[n];
	    for(int i = 0; i < n; i++)
	        cin>>A[i];
	    int dp[n][n + 1];
	    for(int i = 0; i <= n; i++)
	        dp[0][i] = i * A[0];
	    for(int i = 1; i < n; i++)
	    {
	        for(int j = 0; j <= n; j++)
	        {
	            if(j == 0)
	                dp[i][j] = 0;
	            else if(j <= i)
	                dp[i][j] = dp[i - 1][j];
	            else
	                dp[i][j] = max(dp[i - 1][j], A[i] + dp[i][j - i - 1]);
	        }
	    }
	    cout<<dp[n - 1][n]<<endl;
	}
	return 0;
}
