#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int target, int low, int high){
	
	if(low>high)
		return low;
	int mid=low+(high-low)/2;
	if(nums[mid]<target){
		return lowerBound(nums, target ,mid+1, high);
	}else{
		return lowerBound(nums, target, low, mid-1);
	}
}


int upperBound(vector<int>& nums, int target,int low, int high ){
	if(low>high){
		return low;
	}
	int mid=low+(high-low)/2;
	if(nums[mid]>target){
		return upperBound(nums,target, low, mid-1);
	}else{
		return upperBound(nums, target, mid+1, high);
	}
}

int insertPos(vector<int>&nums, int target){

	int low=0, high=nums.size()-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(nums[mid]<target){
			low=mid+1;
		}else {
			high=mid-1;
		}
	}
	return low;
}

vector<int> floorCeil(vector<int>&nums,int target){
	int floorx=-1,ceilx=-1;
	int high=nums.size()-1, low=0;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(nums[mid]<=target){
			floorx=mid;
			low=mid+1;
		}else {
			high=mid-1;
		}

	}
	high=nums.size()-1, low=0;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(nums[mid]>=target){
			ceilx=mid;
			high=mid-1;
		}else {
			low=mid+1;
		}
	}
	vector<int> ans={floorx, ceilx};
	return ans;

}

vector<int> firstlastOccurence(vector<int>&nums,int target){
	int first=-1, last=-1;
	int low=0, high=nums.size()-1;

	while(low<=high){
		int mid=low+(high-low)/2;
		if(nums[mid]==target){
	    	first=mid;
	      	high=mid-1;
	     }else if(nums[mid]>target){
	     	high=mid-1;
	     }else{
	     	low=mid+1;
	     }
	}
	low=0, high=nums.size()-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(nums[mid]==target){
			last=mid;
		  	low=mid+1;
		}else if(nums[mid]>target){
			high=mid-1;
		}else{
		 	low=mid+1;
		}
	}
	vector<int>ans;
	ans.push_back(first);
	ans.push_back(last);
	return ans;
}

int countOccurence(vector<int>&nums, int target){
	vector<int> ans=firstlastOccurence(nums, target);
	int first= ans[0];
	int last=ans[1];
	return last-first;
}

int findMinRotated(vector<int>&nums){
	int low=0, high=nums.size();
	while(low<=high){
		int mid=low+(high-low)/2;
		if(nums[mid]>nums[high]){
			low=mid+1;
		}else{
			high=midl
		}

	}
	return nums[low];
}

int timesRotated(vector<int>&nums){
	int low=0, high=nums.size();
	while(low<=high){
		int mid=low+(high-low)/2;
		if(nums[mid]>nums[high]){
			low=mid+1;
		}else{
			high=midl
		}

	}
	return low;
}
int singleElem(vector<int>&nums){
	int low=0, high=nums.size()-1;
	while(low<high){
		int mid=low+(high-low)/2;
		if(mid>0 && mid<nums.size()){
			if((nums[mid]==nums[mid+1] && mid%2==0 )|| (nums[mid]==nums[mid-1] && mid%2==1)){
				low=mid+1;
			}else if((nums[mid]==nums[mid-1] && mid%2==0 )|| (nums[mid]==nums[mid+1] && mid%2==1)){
				high=mid-1;
			}else{
				return nums[mid];
			}
		}else{
			return nums[mid];
		}
	}
	return nums[low];
}

int peakElem(vector<int>&nums){
	int low=0, high	=nums.size()-1;

	while(low<high){
		int mid=low+(high-low)/2;
		if(nums[mid]>nums[mid+1]){
			high=mid;
		}else{
			low=mid+1;
		}
	}
	return low;
}


int main()
{


	return 0;
}