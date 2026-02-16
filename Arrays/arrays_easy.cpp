#include <bits/stdc++.h>
using namespace std;

void secondSmallestLargest(vector<int> arr)
{

	int largest=INT_MIN;
	int secondLargest=INT_MIN;
	int smallest=INT_MAX;
	int secondSmallest=INT_MAX;

	for(int i=0;i<arr.size();i++)
	{

		if(arr[i]>largest){
			secondLargest=largest;
			largest=arr[i];
		}
		else if(arr[i]<largest && arr[i]>secondLargest){
			secondLargest=arr[i];
		}
		if(arr[i]<smallest){
			secondSmallest=smallest;
			smallest=arr[i];
		}
		else if(arr[i]>smallest && arr[i]<secondSmallest){
			secondSmallest=arr[i];
		}
	}

	if (secondSmallest == INT_MAX || secondLargest == INT_MIN)
        cout << -1;
    else
        cout << secondSmallest << " " << secondLargest;
}

bool sortedArray(vector<int>arr)
{
	for(int i=1;i<arr.size();i++){
		if(arr[i]-arr[i-1]<0)
			return false;
	}
	return true;
}

void removeDuplicatesBrute(vector<int>&arr){
	unordered_set<int> existing;
	int elemCount=0;
	for(int num:arr){
		if(existing.find(num)==existing.end()){
			existing.insert(num);
			elemCount++;
		}
	}
	int i=0;
	for(int x:existing){
		arr[i]=x;
		i++;
	}
}

void removeDuplicates(vector<int>&arr)
{
	if(arr.size()==0) return;

	int k = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[k - 1])
        {
            arr[k] = arr[i];
            k++;
        }
    }
}

void printVector(vector<int>arr)
{
	cout<<endl;
	for(auto x:arr){
		cout<<x<<", ";
	}
	cout<<endl;
}

void rotateArrayLeft(vector<int>&arr)
{
	if (arr.size() <= 1) return;
	int first=arr[0];
	for(int i=0;i<arr.size()-1;i++){
		arr[i]=arr[i+1];
	}
	arr[arr.size()-1]=first;
}

void rotateArrayRight(vector<int>&arr)
{
	if (arr.size() <= 1) return;
	int first=arr[arr.size()-1];
	for(int i=arr.size()-1;i>0;i--){
		arr[i]=arr[i-1];

	}
	arr[0]=first;
}

//bruteforce of rotating n times

void rotateArrayLeftn(vector<int>&arr, int n)
{
	for(int i=0;i<n;i++){
		rotateArrayLeft(arr);
	}
}

void rotateArrayRightn(vector<int>&arr, int n)
{
	for(int i=0;i<n;i++){
		rotateArrayRight(arr);
	}
}

//optimal of rotating n times
/*
first find normalised rotations n=n%length of array
reverse the entire array 
reverse the first n elements of array again
*/

void rotateArrayRightnOpt(vector<int>){}

void moveZero(vector<int>&arr)
{
	int slow=0;
	for(int fast=0;fast<arr.size();fast++)
	{
		if(arr[fast]!=0){
			swap(arr[slow],arr[fast]);
			slow++;
		}

	}

}

int missingNumber1(vector<int>arr,int n)
{
	int sum=0;
	for(int i=0;i<arr.size();i++){
		sum+=arr[i];
	}
	return ((n*n+n)/2)-sum;
}

int missingNumber2(vector<int>arr,int n)
{
	int actualXor=0;
	int expectedXor=0;
	for(int i=0;i<arr.size();i++){
		actualXor^=arr[i];
		expectedXor^=(i+1);
	}
	expectedXor^=n;

	return actualXor^expectedXor;
}

void findUnion(vector<int>&arr1, vector<int>&arr2, vector<int>&unionArr)
{
	int maxElem=arr1.size()+arr2.size();
	int i=0,j=0;
	while(i<arr1.size() && j<arr2.size())
	{
		if(arr1[i]<arr2[j]){
			if(unionArr.empty() || unionArr.back()!=arr1[i])
				unionArr.push_back(arr1[i]);
			i++;
		}else if(arr1[i]>arr2[j] && arr2[j]!=unionArr.back()){
			if(unionArr.empty() || unionArr.back()!=arr2[j])
				unionArr.push_back(arr2[j]);
			j++;
		}else{
			if(unionArr.empty()||arr1[i]!=unionArr.back())
				unionArr.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	while(i<arr1.size()){
		if(unionArr.empty()||arr1[i]!=unionArr.back()){
			unionArr.push_back(arr1[i]);
		}
		i++;
	}
	
	while(j<arr2.size()){
		if(unionArr.empty()||arr2[j]!=unionArr.back()){
			unionArr.push_back(arr2[j]);
		}
		j++;
		
	}
}

int countMaxOne(vector<int>&arr)
{
	int max=0;
	int curr=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]==1){
			curr++;
		}else{
			if(curr>max)
				max=curr;
			curr=0;
		}
	}
	if(curr>max)
		max=curr;
	return max;
}


int longestSubarrayPositive(vector<int>&arr,int k)
{
	int maxLength=0;
	int sum=0;
	int left=0,right=0;
	for(right;right<arr.size();right++){

		//advance the window
		sum+=arr[right];

		//until the sum again is less than k decrease the sie of the window
		while(sum>k){
			sum-=arr[left];
			left++;
		}
		//while decreasing the window it may be possible that sum is k or less than k 
		//if the sum of the window is k compare it with maxlength
		if(sum==k)
			maxLength=max(maxLength,right-left+1);
		
	}
	return maxLength;
}

int longestSubarrayNegative(vector<int>&arr, int k)
{
	int maxLength=0;
	int sum=0;
	map<int,int> prefixSum;
	for(int i=0;i<arr.size();i++){
		sum+=a[i];
		//the case where the current array starting from beginning matches the sum required
		if(sum==k){
			maxLength=max(maxLength, i+1);
		}
		//the case where a sub array starting from somewhere in the middle to the current element has the sum equal to k
		if(prefixSum.find(k-sum)!=prefixSum.end()){
			int len=i-prefixSum(k-sum);
			maxLength=max(maxLength,len);
		}

		if(prefixSum.find(sum)==prefixSum.end()){
			prefixSum[sum]=i;
		}
	}
	return 0;

}



int main(int argc, char const *argv[])
{
	vector<int> arr={1,2,3,4,5,6,7,8,9};
	vector<int> arr2={5,4,6,7,8};
	//secondSmallestLargest(arr);
	//cout<<sortedArray(arr);
	//cout<<sortedArray(arr2);
	vector<int> arr3={1,1,1,2,2,3,3,3,3,4,4};
	vector<int>arr4={1, 1, 2, 1};

	//printVector(arr4);
	//removeDuplicates(arr4);
	//printVector(arr4);
	
/*	printVector(arr);	
	rotateArrayLeft(arr);
	printVector(arr);

	printVector(arr);	
	rotateArrayRight(arr);
	printVector(arr);*/

	/*printVector(arr);
	rotateArrayLeftn(arr,5);
	printVector(arr);*/

	/*vector<int>arr5={1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
	printVector(arr5);
	moveZero(arr5);
	printVector(arr5);*/

	/*vector<int>arr6={1,2,4,5};
	cout<<missingNumber2(arr6,5);*/

	/*vector<int>arr7 = {1,2,3,4,5};
	vector<int>arr8  = {2,3,4,4,5};
	vector<int>unionArr;
	findUnion(arr7, arr8, unionArr);
	printVector(unionArr);*/

	/*vector<int> arr9={1, 1, 0, 1, 1, 1};
	vector<int> arr10={1, 0, 1, 1, 0, 1};
	cout<<countMaxOne(arr9);
	cout<<countMaxOne(arr10);*/

	vector<int>arr11 = {1, 2, 3, 1, 1, 1, 1};
	cout<<longestSubarrayPositive(arr11,3);
	vector<int>arr12 = {-1,1,1};
	cout<<longestSubarrayPositive(arr12,1);



	return 0;
}