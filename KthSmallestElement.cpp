Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4
Output:
7
15




#include <iostream>
#include<algorithm>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int quickSelect(int arr[], int low, int high)
{
    int pivot = high, i = low;
    for(int j = low; j < high; j++)
    {
        if(arr[pivot] >= arr[j])
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[pivot]);
    return i;
}

void quickSort(int arr[], int low, int high, int k)
{
    if(low <= high)
    {
        int pivot = quickSelect(arr, low, high);
        if(pivot == k)
        {
            cout<<arr[pivot];
        }
        else if(pivot > k)
            quickSort(arr, low, pivot - 1, k);
        else
            quickSort(arr, pivot + 1, high, k);
    }
}

int main() {
	
	int t, n, k;
	cin >>t;
	while(t--)
	{
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    cin>>k;
	    random_shuffle(arr, arr + n);
	    quickSort(arr, 0, n - 1, k - 1);  
	    cout<<endl;
	}
	return 0;
}
