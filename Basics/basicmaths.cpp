#include<bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
	int digit=0;
	while(n!=0){
		n/=10;
		digit++;
	}
	return digit;
}

int reverseNumber(int n)
{
	int temp=0;
	while(n!=0){
		temp=temp*10+(n%10);
		n/=10;
	}
	return temp;
}

int gcd(int a, int b)
{
	if(a==0) return b;

	if(a>=b) return gcd(a-b, b);
	else return gcd(b-a, a);

}

bool armstrongNum(int n){
	int orgNum=n;
	int digits=countDigits(n);
	int sum=0;
	for(int i=0;i<digits;i++)
	{
		int currDigit=n%10;
		n/=10;
		sum+=pow(currDigit, digits);
	}
	return (sum==orgNum);
}

int main(int argc, char const *argv[])
{
	//cout<<countDigits(1410523);
	//cout<<reverseNumber(141052300);
	//cout<< gcd(12, 120);
	cout<<endl;
	cout<<armstrongNum(153);
	cout<<endl;
	cout<<armstrongNum(371);
	cout<<endl;
	cout<<armstrongNum(100);

	return 0;
}