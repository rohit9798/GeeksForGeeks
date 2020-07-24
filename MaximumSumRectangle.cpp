Given a 2D array, find the maximum sum subarray in it. For example, in the following 2D array, the maximum sum subarray is highlighted with blue rectangle and sum of this subarray is 29.

                                                          

Input:
First line of every test case consists of T test case. First line of every test case consists of 2 integers R and C , denoting number of rows and columns. Second line consists of R*C spaced integers denoting number of elements in array.

Output:
Single line output, print the Max sum forming a rectangle in a 2-D matrix

Example:
Input:
1
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
Ouptut:
29



#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
	int t, n;
	cin>>t;
	while(t--)
	{
	    int R, C, max_sum = INT_MIN;
	    cin>>R>>C;
	    int matrix[R][C];
	    for(int i = 0; i < R; i++)
	    {
	        for(int j = 0; j < C; j++)
	            cin >> matrix[i][j];
	    }
	    for(int i = 0; i < C; i++)
	    {
	        vector<int> temp(R, 0);
	        for(int j = i; j < C; j++)
	        {
	            for(int k = 0; k < R; k++)
	                temp[k] += matrix[k][j];
	            int sum = 0;
	            for(int k = 0; k < R; k++)
	            {
	                sum += temp[k];
	                if(max_sum < sum)
	                    max_sum = sum;
	                if(sum < 0)
	                    sum = 0;
	            }
	        }
	    }
	    cout<<max_sum<<endl;
	}
	
	
	return 0;
}
