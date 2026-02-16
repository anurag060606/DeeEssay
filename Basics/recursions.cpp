#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
	if(n==0) return 1;

	return n*factorial(n-1);
}

void reverseArr(vector<int>&arr,int left, int right)
{
	if(left>=right) return;
	swap(arr[left],arr[right]);
	reverseArr(arr, left+1,right-1);
}

bool palindromeTest(string &s,int i)
{
	if(i>s.length()/2)
		return true;
	if(s[i]!=s[s.length()-i-1]) return false;

	return palindromeTest(s, i+1);
}

int fibonacciNumber(int n)
{
	if(n==0) return 1;
	if(n==1) return 1;
	return n+fibonacciNumber(n-1);
}

int main()
{
	/*cout<<factorial(5);
	cout<<"\nOriginal array: \n";
	vector<int> arr={1,2,3,4,5,6,7,8,9};
	for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
	reverseArr(arr,0,8 );
	for(int i=0;i<9;i++)
	{
		cout<<arr[i]<<", ";
	}*/
	string s="madam";

	cout<<endl<<palindromeTest(s,0);
	cout<<endl<<fibonacciNumber(10);
	return 0;
}