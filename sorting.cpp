#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr,int n)
{
	for(int i=0;i<n;i++){
		cout<<arr[i]<<", ";
	}
}

void printVector(const vector<int>& v) {
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void selectionSort(int* arr, int n)
{
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[i]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

void bubbleSort(int* arr, int n)
{
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=i-1;j++){
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}

void insertionSort(int* arr, int n)
{
	for(int i=1;i<n;i++){
		int j=i;
		if(arr[i]<arr[i-1]){
			while(j>0 && arr[j-1]>arr[j]){
				swap(arr[j-1],arr[j]);
				j--;
			}
		}
	}
}


void merge(vector<int> &arr, int low, int mid, int high)
{
	int pointer1=low;
	int pointer2=mid+1;
	vector<int> temp;
	while(pointer1<=mid && pointer2<=high){
		if(arr[pointer1]<=arr[pointer2]){
			temp.push_back(arr[pointer1]);
			pointer1++;
		}else{
			temp.push_back(arr[pointer2]);
			pointer2++;
		}
	}
	while(pointer1<=mid){
		temp.push_back(arr[pointer1++]);
	}

	while(pointer2<=high){
		temp.push_back(arr[pointer2++]);
	}

	for(int i=low;i<=high;i++){
		arr[i]=temp[i-low];
	}

}

void mergeSort(vector<int> &arr, int low, int high)
{
	if(high<=low)
		return;
	int mid=(low+high)/2;
	mergeSort(arr,low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr,low,mid, high);

}


int partition(vector<int>&arr, int low, int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<=high-1;j++){
		if(arr[j]<=pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[++i], arr[high]);
	return i;

}

void quickSort(vector<int>&arr, int low, int high)
{
	//pick pivot
	//put it at right place by keeping lower elements on the left and higher elements on the right
	//now perform quick sort on right and left segments as well
	if(low<high){
		//the array has more than one elements
		//if array has just one element low=high and we dont need to place it at right location and sort it's left and right parts
		int pivotIndex=partition(arr, low, high);

		quickSort(arr, low, pivotIndex-1);
		quickSort(arr, pivotIndex+1, high);
	}
}

void recursiveInsertionSort(vector<int>&arr,int i, int n)
{
	if(i==n)
		return;
	int j=i;
	int temp=arr[i];
	while(j>0 && arr[j-1]>=temp){
		arr[j]=arr[j-1];
		j--;
	}
		arr[j]=temp;
	recursiveInsertionSort(arr, i+1,n);
}

void recursiveBubbleSort(vector<int>&arr,int n){
	if(n==1) return;
	for(int i=0;i<n;i++){
		if(arr[i-1]>arr[i]){
			swap(arr[i],arr[i-1]);
		}
	}
	recursiveBubbleSort(arr, n-1);
}

int main()
{
	int arr[] = {13, 46, 24, 52, 20, 9};
	//cout<<"\nBefore sorting \n";
	//printArray(arr,6);
	//cout<<"\nAfter sorting \n";
	//selectionSort(arr,6);
	//bubbleSort(arr,6);
	//insertionSort(arr,6);
	//printArray(arr);

	vector<int> arr2={13, 46, 24, 52, 20, 9};
	cout<<"\nBefore sorting \n";
	printVector(arr2);
	//mergeSort(arr2, 0,5);
	//quickSort(arr2,0,5);
	//recursiveInsertionSort(arr2,1,6);
	recursiveBubbleSort(arr2, 6);
	cout<<"\nAfter sorting \n";
	printVector(arr2);

}