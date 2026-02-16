#include<bits/stdc++.h>
using namespace std;

int sqrt(int x){
	if (x<2) return x;

	int left=1, right=x/2;
	int ans;
	while(left<=right){
		long long mid=left+(right-left)/2;
		if(mid*mid<=x){
			ans=mid;
			left=mid+1;
		}else{
			right=mid-1;
		}

	}
	return ans;
}

int nthRoot(int x, int n){
	int low=0,high=x/n, ans=-1; 
	while(low<=high){
		long long mid=low+(high-low)/2;
		long long num=mid;
		for(int i=1; i<n;i++){
			num*=mid;
		}
		if(num<=x){
			ans=mid;
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	return ans;
}

long long countHours(vector<int>&piles, int k){
    long long hours=0;
    for(auto x:piles){
        hours+=((x+k-1)/k);
    }
    return hours;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low=1, high=*max_element(piles.begin(), piles.end());
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        long long hours=countHours(piles, mid);
        if(hours>h){
            low=mid+1;
        }else{
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}

int countBloomed(vector<int>&bloomDay, int day, int k){
	int count=0;
	int adjBloom=0;
	for(auto x:bloomDay){

		if(x<=day){
			adjBloom++;
		}else{
			adjBloom=0;
		}
		if(adjBloom==k){
			count++;
			adjBloom=0;
		}
		cout<<"Adj= "<<adjBloom<<" count= "<<count<<endl;
	}
	return count;
}

int minDays(vector<int>& bloomDay, int m, int k){
	if(bloomDay.size()<m*k) return -1;
	int low=1, high=*max_element(bloomDay.begin(), bloomDay.end()), ans=-1;
	while(low<=high){

		int mid=low+(high-low)/2;
		cout<<low<<", "<<mid<<", "<<high<<endl;
		if(countBloomed(bloomDay, mid, k)<m){
			low=mid+1;
		}else{
			ans=mid;
			high=mid-1;
		}
	}
	return ans;
}

int countSum(vector<int>&nums, int div){
	int res=0;
	for(auto x:nums){
		res+=(x+div-1)/div;
	}
	return res;
}

int smallestDivisor(vector<int>& nums, int threshold) {
	int low=1, high=*max_element(nums.begin(), nums.end());
	int ans=0;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(countSum(nums, mid)<=threshold){
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}

	}        
	return ans;
}


int countDays(vector<int>&weights, int cap){
	int days=1;
	int currWeight=0;
	for(auto x:weights){
		currWeight+=x;
		if(currWeight>cap){
			days++;
			currWeight=x;
		}
	}
	return days;
}

int shipWithinDays(vector<int>& weights, int days) {
	long long low=*max_element(weights.begin(), weights.end());
	long long high = accumulate(weights.begin(), weights.end(), 0LL);
	
	long long cap;
	while(low<=high){
		long long mid=low+(high-low)/2;
		if(countDays(weights, mid)<=days){
			cap=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return cap;

}

int findKthPositive(vector<int>& arr, int k) {
	int missCount=0;
	int missingNo=0;
	for(int i=1;i<=arr.size();i++){
		missCount+=arr[i-1]-i-missCount;
		if(missCount>=k){
			missingNo=arr[i-1];
			while(missCount>=k){
				missingNo--;
				missCount--;
			}
		}
	}
	if(missCount<k){
		missingNo=arr[arr.size()-1];
		while(missCount<k){
			missingNo++;
			missCount++;
		}
	}
	

	return missingNo;
}

bool placed(vector<int>&stalls, int cows,int dist){
	int lastPlacedIndx=0;
	cows--;
	int i=1;
	while(cows && i<stalls.size()){
		if(stalls[i]-stalls[lastPlacedIndx]<dist){
			i++;
		}else{
			lastPlacedIndx=i;
			cows--;
		}
	}
	return (cows==0);

}


int agressiveCows(vector<int>&stalls,int cows){
	sort(stalls.begin(),stalls.end());
	int high=*max_element(stalls.begin(),stalls.end()) - *min_element(stalls.begin(),stalls.end());
	int low=1;
	int ans=0;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(placed(stalls, cows, mid)){
			ans=mid;
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	return ans;
}

bool allocationPossible(vector<int>&books, int children, int allocPages){
	int pages=0;
	int allocatedChildren=0;
	for(int i=0; i<books.size();i++){
		pages+=books[i];
		if(pages>=allocPages){
			allocatedChildren++;
		}
	}
	return (allocatedChildren>=children);
}


int bookAllocation(vector<int>&books, int children){
	int low=*min_element(books.begin(),books.end());
	int high=accumulate(books.begin(),books.end(),0);
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(allocationPossible(books, children, mid)){
			ans=mid;
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	return ans;
}

bool splitPossible(vector<int>&nums, int k , long long sum){
	int currSum=0;
	int partsMade=1;
	for(int i=0;i<nums.size();i++){
		currSum+=nums[i];
		if(currSum>sum){
			partsMade++;
			currSum=nums[i];
		}
	}
	return (partsMade<=k);
}

int splitArray(vector<int>&nums, int k){
	if(k>nums.size()) return -1;
	long long low=*max_element(nums.begin(),nums.end());
	long long high=accumulate(nums.begin(),nums.end(),0LL);
	int ans=-1;
	while(low<=high){
		long long mid=low+(high	-low)/2;
		if(splitPossible(nums, k, mid)){
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}

	}
	return ans;
}

bool partitionPossible(vector<int>&boards, int k , int workEach){
	int count=1, currSum=0;
	for(auto x:boards){
		currSum+=x;
		if(currSum>workEach){
			count++;
			currSum=x;
		}
	}
	return (count>k);
}

int paintersPartition(vector<int>&boards, int k){
	//minimise the sum of each sub array basically
	long long low=*max_element(boards.begin(), boards.end());
	long long high=accumulate(boards.begin(), boards.end(), 0LL);
	int ans;
	while(low<=high){
		long long mid=low+(high-low)/2;
		if(partitionPossible(boards, k ,mid)){
			
			low=mid+1;
		}else{
			ans=mid;
			high=mid-1;
		}

	}
	return ans;
}

float gasStation(vector<int>stations, int k){
	return 0;
}



int main(){
	// vector<int> bloomDay={7,7,7,7,12,7,7};
	// cout<<minDays(bloomDay, 2, 3);
	// return 0;

	// vector<int> stalls={0, 3, 4, 7, 10, 9};
	// cout<<agressiveCows(stalls, 4);

	// vector<int> books={25, 46, 28, 49, 24};
	// cout<<bookAllocation(books, 4);

	// vector<int> vec={10, 20, 30, 40};
	// cout<<paintersPartition(vec, 2);

	vector<int>stations={1,2,3,4,5};
	cout<<gasStation(stations, 4);

}