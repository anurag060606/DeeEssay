#include<bits/stdc++.h>
using namespace std;

//z
int longestSubarray(vector<int>&nums){
	map<int,int>prefixSum;
	long long sum=0;
	int len, maxlen=0;
	for(int i=0;i<nums.size();i++){
		sum+=nums[i];
		if(sum==0){
			maxlen=max(maxlen, i+1);
		}
		if(prefixSum.find(sum)!=prefixSum.end()){
			maxlen=max(maxlen, i-prefixSum[sum]);
		}
		if(prefixSum.find(sum)==prefixSum.end()){
			prefixSum[sum]=i;
		}
	}
	return maxlen;
}

int subarrayXOR(vector<int>&nums,int k){
	map<int,int> prefixxor;
	int count=0;
	long long currxor=0;
	prefixxor[0]=1;
	for(int i=0;i<nums.size();i++){
		currxor^=nums[i];

		if(prefixxor.find(currxor^k)!=prefixxor.end()){
			count+=prefixxor[currxor^k];
		}

		prefixxor[currxor]++;
	}
	return count;
}

void mergeSortedArray(vector<int>&a, vector<int>&b){
	int m=a.size();
	int n=b.size();
	int ptra=0;
	for(int i=0;i<n;i++){
		if(a[ptra]>b[i]){
			for(int j=m-n+i;j>=ptra;j--){
				a[j+1]=a[j];
			}
			a[ptra]=b[i];
		}else{
			ptra++;
		}
	}
}

void merge(vector<int>&nums, int low, int mid ,int high){
	int left=low, right=mid+1;
	vector<int>mergedArr;
	while(left<=mid && right<=high){
		if(nums[left]<=nums[right]){
			mergedArr.push_back(nums[left]);
			left++;
		}else{
			mergedArr.push_back(nums[right]);
			right++;
		}
	}

	while(left<=mid){
		mergedArr.push_back(nums[left]);
		left++;
	}
	while(right<=high){
		mergedArr.push_back(nums[right]);
		right++;
	}
	for(int i=0;i<mergedArr.size();i++){
		nums[low+i]=mergedArr[i];
	}

}

void mergeSort(vector<int>&nums, int low, int high){
	int mid=low+(high-low)/2;
	if(low>=high)
		return;
	mergeSort(nums, low, mid);
	mergeSort(nums, mid+1, high);

	merge(nums, low, mid, high);
}

int maxProduct(vector<int>& nums) {
    int prefix=1,suffix=1;
    int maxPrefix=INT_MIN,maxSuffix=INT_MIN;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix*=nums[i];
        suffix*=nums[n-1-i];
        maxPrefix=max(maxPrefix, prefix);
        maxSuffix=max(maxSuffix, suffix);
    } 

    return max(maxPrefix, maxSuffix);

}
int cnt=0;
void mergeMod(vector<int>&nums, int low, int mid ,int high){
	int left=low, right=mid+1;
	vector<int>mergedArr; 
	while(left<=mid && right<=high){
		if(nums[left]<=nums[right]){
			mergedArr.push_back(nums[left]);
			left++;
		}else{
			mergedArr.push_back(nums[right]);
			right++;
			cnt+=mid-left+1;
		}
	}

	while(left<=mid){
		mergedArr.push_back(nums[left]);
		left++;
	}
	while(right<=high){
		mergedArr.push_back(nums[right]);
		right++;
	}
	for(int i=0;i<mergedArr.size();i++){
		nums[low+i]=mergedArr[i];
	}

}
void mergeSortMod(vector<int>&nums, int low, int high){
	int mid=low+(high-low)/2;
	if(low>=high)
		return;
	mergeSortMod(nums, low, mid);
	mergeSortMod(nums, mid+1, high);
	mergeMod(nums, low, mid, high);
}


int countInversion(vector<int> &nums){
	mergeSortMod(nums, 0 ,nums.size()-1);
	return cnt;
}


int main(int argc, char const *argv[])
{
	//vector<int> vec1={6, -2, 2, -8, 1, 7, 4, -10};
	//cout<<longestSubarray(vec1);
	//vector<int> vec={5, 6, 7, 8, 9};
	//cout<<subarrayXOR(vec, 5);
	// vector<int>veca={-5, -2, 4, 5, 0, 0, 0};
	// vector<int>vecb={-3, 1, 8};
	// mergeSortedArray(veca,vecb);
	// for(auto x:veca)
	// 	cout<<x<<", ";
	vector<int> lol={5,4,3,2,1};
	cout<<countInversion(lol);
	return 0;


}