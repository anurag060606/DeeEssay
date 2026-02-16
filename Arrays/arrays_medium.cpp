#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    map<int,int> prefixSum;
    int sum;
    int count=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k){
            count++;
        }
        if(prefixSum.find(sum-k)!=prefixSum.end()){
            count+=prefixSum[sum-k];
        }
        prefixSum[sum]++;
    }
    return count;
}


void dutchNationalFlag(vector<int> &arr){
	int high=arr.size()-1;
	int low=0;
	int mid=0;
	while(high>=mid){
		if(arr[mid]==0){
			swap(arr[low],arr[mid]);
			mid++;
			low++;
		}else if(arr[mid]==1){
			mid++;
		}else if(arr[mid]==2){
			swap(arr[mid],arr[high]);
			high--;
		}
	}

}
int majorityElement(vector<int>&nums){
	int majorityElem=nums[0];
	int countMaj=1;
	for(int i=1;i<nums.size();i++){
		if(majorityElem==nums[i]){
			countMaj++;
		}else{
			countMaj--;
		}
		if(countMaj==0){
			majorityElem=nums[i];
			countMaj=1;
		}
	}
	//verificication take example of 1, 2, 3 ,4
	int cntVerf=0;
	for(int i=0;i<nums.size();i++ ){
		if(nums[i]==majorityElem){
			cntVerf++;
		}
	}
	if(cntVerf>(nums.size()/2))
		return majorityElem;
	return -1;
}

int kadaneAlgorithm1(vector<int>&nums){
	long long maxSum=INT_MIN;
	long long currSum=0;
	for(int i=0;i<nums.size();i++){
		currSum+=nums[i];
		if(currSum<0){
			currSum=0;
		}
		if(currSum>maxSum){
			maxSum=currSum;
		}

	}
	return maxSum;
} //only for positive

int kadaneAlgorithm2(vector<int>&nums){
	long long maxSum=nums[0];
	long long currSum=nums[0];
	for(int i=1;i<nums.size();i++){
		currSum=max((long long)nums[i], currSum+nums[i]);
		maxSum=max(currSum, maxSum);


	}
	return maxSum;
} //general case

vector<long long> kadaneAlgorithm3(vector<int>&nums){
	long long maxSum=nums[0];
	long long currSum=nums[0];
	int startIndx=0, endIndx=0,tempIndx;
	for(int i=1;i<nums.size();i++){
		if(currSum+nums[i]<nums[i]){
			tempIndx=i;
			currSum=nums[i];
		}else
			currSum+=nums[i];

		if(currSum>maxSum){
			maxSum=currSum;
			startIndx=tempIndx;
			endIndx=i;
		}
	}
	return {(long long)startIndx,(long long)endIndx,maxSum};
} //general case return start and end indx of sub array

int maxProfit1(vector<int>&prices){
	int maxDiff=INT_MIN;
	for(int i=0;i<prices.size();i++){
		for(int j=i+1;j<prices.size();j++){
			if(prices[j]-prices[i]>maxDiff){
				maxDiff=prices[j]-prices[i];
			}
		}
	}
	return (maxDiff>0?maxDiff:0);
}//stock buy and sell

int maxProfit2(vector<int>&prices){
	int minPrice=INT_MAX;
	int maxDiff=INT_MIN;
	for(int i=0;i<prices.size();i++){
		if(prices[i]<minPrice)
			minPrice=prices[i];
		if(prices[i]-minPrice>maxDiff)
			maxDiff=prices[i]-minPrice;
	}
	return (maxDiff>0?maxDiff:0);
}

vector<int>rearrangeArray1(vector<int>&nums){
	int n=nums.size();
	int sign =1;
	for(int i=0;i<n;i++){
		int j=i+1;
		if(sign==1 && nums[i]<0){
			while(j<n && nums[j]<0)
				j++;
			swap(nums[i],nums[j]);
		}else if(sign==-1 && nums[i]>0){
			while(j<n && nums[j]>0)
				j++;
			swap(nums[i],nums[j]);
		}
		sign=sign * -1;
	}
	return nums;
}//relative order is not preserved

vector<int>rearrangeArray2(vector<int>&nums){
	int n=nums.size();
	int sign =1;
	int temp;
	for(int i=0;i<n;i++){
		int j=i+1;
		if(sign==1 && nums[i]<0){
			while(j<n && nums[j]<0)
				j++;
			if(j==n) break;
			temp=nums[j];
			for(int x=j;x>i;x--){
				nums[x]=nums[x-1];
			}
			nums[i]=temp;
		}else if(sign==-1 && nums[i]>0){
			while(j<n && nums[j]>0)
				j++;
			if(j==n) break;
			temp=nums[j];
			for(int x=j;x>i;x--){
				nums[x]=nums[x-1];
			}
			nums[i]=temp;
		}
		sign=sign * -1;
	}
	return nums;
}//relative order is  preserved while shifting not swaping 

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;

    for(int x : nums){
        if(x > 0) pos.push_back(x);
        else neg.push_back(x);
    }

    vector<int> ans(n);
    int p = 0, q = 0;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0)
            ans[i] = pos[p++];
        else
            ans[i] = neg[q++];
    }

    return ans;
}

void backtrack(vector<vector<int>>&result, vector<int>&perm,vector<int>&nums){
	if(perm.size()==nums.size()){
		result.push_back(perm);
		return;
	}
	for(int i=0;i<nums.size();i++){
		if(find(perm.begin(),perm.end(),nums[i])!=perm.end())
			continue;//numbers cant repeat
		perm.push_back(nums[i]);
		backtrack(result,perm,nums);
		perm.pop_back();
	}
}

vector<vector<int>> allPermutation(vector<int>&nums){
	vector<vector<int>> result;
	vector<int> perm={};
	backtrack(result, perm, nums);
	return result;
}

void nextPermutation(vector<int> &nums){
	int n=nums.size();
	int indx=-1;
	for(int i=n-2;i>=0;i--){
		if(nums[i+1]>nums[i]){
			indx=i;
			break;
		}
	}

	if(indx==-1){
		int low=0, high=n-1;
		while(high>=low){
			swap(nums[low], nums[high]);
			low++;
			high--;
		}
		return;
	}
	int indxminBeforeIndx = -1;
	for(int i = indx+1; i < n; i++){
	    if(nums[i] > nums[indx]){
	        indxminBeforeIndx = i;
	    }
	}
	swap(nums[indx],nums[indxminBeforeIndx]);
	//sort in increasing order after the swapped one
	int high=n-1, low=indx+1;
	while(high>=low){
		swap(nums[low],nums[high]);
		low++;
		high--;
	}
}

vector<int> leadersArray(vector<int>&nums){
	vector<int> result;
	int n=nums.size();
	int maxRight=INT_MIN;
	for(int i=n-1;i>=0;i--){
		if(nums[i]>maxRight){
			result.push_back(nums[i]);
			maxRight=nums[i];
		}
	}
	reverse(result.begin(), result.end());
	return result;

}

int longestConsecutiveSequence1(vector<int> &nums){
	sort(nums.begin(), nums.end());
	int maxLength=INT_MIN;
	int currLength=1;
	int i=0;
	while(i<nums.size()-1){
		if(nums[i+1]==nums[i]){
			i++;
			continue;
		}
		if(nums[i+1]==nums[i]+1){
			currLength++;
		}else{
			if(currLength>maxLength){
				maxLength=currLength;
			}
			currLength=1;
		}
		i++;
	}
	maxLength=max(maxLength,currLength);
	if(nums.empty()) return 0;
	return maxLength;
}//in place o log n+n

int longestConsecutiveSequence2(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) return 0; 

    int longest = 1; 

    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it; 
            while (st.find(x + 1) != st.end()) {
                x = x + 1; 
                cnt = cnt + 1; 
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

void setZeroes(vector<vector<int>> &matrix){
	int m=matrix.size();
	int n=(matrix[0]).size();
	vector<int> rows;
	vector<int> columns;
	for(int i=0; i<m;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]==0){
				rows.push_back(i);
				columns.push_back(j);
			}
		}
	}
	for(auto row:rows){
		for(int j=0;j<n;j++){
			matrix[row][j]=0;
		}
	}
	for(auto column:columns){
		for(int i=0;i<m;i++){
			matrix[i][column]=0;
		}
	}
	
	return;
}

void rotateMatrix(vector<vector<int>> &matrix){
	//transpose first
	int n=matrix.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			swap(matrix[i][j],matrix[j][i]);
		}
	}
	//reverse row 
	for(int row=0;row<n;row++){
		for(int j=0;j<n/2;j++){
			swap(matrix[row][j],matrix[row][n-j-1]);
		}
	}
}

int subarraySum(vector<int>&nums, int k){
	unordered_map<int,int>prefixSum;
	int currSum=0;
	int count=0;
	for(int i=0;i<nums.size();i++){
		currSum+=nums[i];

		if(currSum==k)
			count++;
		int remainder=currSum-k;
		if(prefixSum.find(remainder)!=prefixSum.end()){
			count+=prefixSum[remainder];
		}

		prefixSum[currSum]++;
	}
	return count;
}
void rotate(vector<vector<int>>& matrix) {
    //transpose first
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reverse row 
    for(int row=0;row<n;row++){
        for(int j=0;j<n/2;j++){
            swap(matrix[row][j],matrix[row][n-j-1]);
        }
    }
}

int main()
{
	// vector<int> nums = {2, 0, 2, 1, 1, 0};
	// dutchNationalFlag(nums);
	// for (int val : nums)
    //     cout << val << " ";
    // vector<int>nums2={2,2,1,1,1,2,2};
    // cout<<majorityElement(nums2);
    // vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    // for(auto x:kadaneAlgorithm3(nums))
    // 	cout<<x<<", ";
    // vector<int> prices = {7,1,5,3,6,4};
    // cout<<maxProfit1(prices);
    //vector<int> nums={3,1,-2,-5,2,-4};
    //vector<int> nums={-1,1};
    //for(auto x:rearrangeArray2(nums))
    //	cout<<x<<",";

    // vector<int>nums={1,2,3};
    // for(auto perm:allPermutation(nums)){
    // 	for(auto x:perm){
    // 		cout<<x<<" ";
    // 	}
    // 	cout<<endl;
    // }

    //vector<int>nums={2,3,4,1,2,5};
    //nextPermutation(nums);
    // for(auto x:nums){
    // 	cout<<x<<", ";
    // }
    // vector<int> nums= {10, 22, 12, 3, 0, 6}; 
    // for(auto x:leadersArray(nums)){
    // 	cout<<x<<", ";
    // }
    // vector<int> nums={0,3,7,2,5,8,4,6,0,1};
    // cout<<longestConsecutiveSequence1(nums);

    // vector <vector<int>> matx={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // for(auto x:matx){
    // 	for(auto y:x){
    // 		cout<<y<<", ";
    // 	}
    // 	cout<<endl;
    // }
    // cout<<"After: "<<endl;
    // setZeroes(matx);
    // for(auto x:matx){
    // 	for(auto y:x){
    // 		cout<<y<<", ";
    // 	}
    // 	cout<<endl;
    // }

    vector<vector <int>> matx={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for(auto x:matx){
    	for(auto y:x){
    		cout<<y<<", ";
    	}
    	cout<<endl;
    }
    cout<<"After: "<<endl;
    rotateMatrix(matx);
    for(auto x:matx){
    	for(auto y:x){
    		cout<<y<<", ";
    	}
    	cout<<endl;
    }
}
