#include<bits/stdc++.h>
using namespace std;

void subsequenceSumHelper(vector<int>&nums,int currSum,vector<int>&curr,  vector<vector<int>>&result, int target, int indx){
	if(indx==nums.size()){
		if(currSum==target)
			result.push_back(curr);
		return;
	}
	currSum+=nums[indx];
	curr.push_back(nums[indx]);
	subsequenceSumHelper(nums, currSum, curr, result, target, indx+1);
	currSum-=nums[indx];
	curr.pop_back();
	subsequenceSumHelper(nums, currSum, curr, result, target, indx+1);
}

vector<vector<int>> subsequenceSum (vector<int>&nums, int target){

	vector<vector<int>> result;
	vector<int>curr;
	subsequenceSumHelper(nums, 0, curr, result, target, 0);
	return result;
}

void combinationSum2helper(int indx, int target,
        vector<int>& nums,
        vector<int>& curr,
        vector<vector<int>>& result) {

    if(target == 0) {
        result.push_back(curr);
        return;
    }

    for(int i = indx; i < nums.size(); i++) {
        if(i > indx && nums[i] == nums[i-1])
            continue;

        if(nums[i] > target)
            break;

        curr.push_back(nums[i]);
        combinationSum2helper(i+1, target - nums[i], nums, curr, result);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
   	vector<vector<int>> result;
    vector<int>curr;
    sort(candidates.begin(), candidates.end());
    combinationSum2helper(0, target, candidates, curr, result);
    return result;
}

void subsetSumBFhelper(int indx, int sum , vector<int>&nums, vector<int>&result){
	if(indx==nums.size()){
		result.push_back(sum);
		return;
	}
	subsetSumBFhelper(indx+1, sum+nums[indx], nums, result);
	subsetSumBFhelper(indx+1, sum, nums, result);
}

vector<int>subsetSumBF(vector<int>&nums){

	vector<int>result;
	subsetSumBFhelper(0, 0, nums, result);
	sort(result.begin(), result.end());
	return result;
}

void subsetSum2helper(vector<int>&nums, vector<int>&curr, vector<vector<int>>&result, int indx){

	if(indx==nums.size()){
		result.push_back(curr);
		return;
	}

	for(int i=indx;i<nums.size();i++){
		if(i>indx && nums[i-1]==nums[i]) continue;
		curr.push_back(nums[i]);
		subsetSum2helper(nums,curr, result, i+1);
		curr.pop_back();
	}
}

vector<vector<int>> subsetSum2(vector<int>&nums){
	//there are duplicates in the array so there will be duplicates in the subset if we use the ordinary take leave approach use combination sum2 approach
	vector<vector<int>> result;
	vector<int>curr;
	subsetSum2helper(nums, curr, result, 0);
	return result;
}

void combinationSum3helper(vector<int>&nums, vector<vector<int>>&result,vector<int>&curr,int currSum,  int n, int k, int indx){
    if(curr.size()>=k || indx>=nums.size()){
        if(currSum==n && curr.size()==k){
            result.push_back(curr);
        }
        return;
    }
    curr.push_back(nums[indx]);
    combinationSum3helper(nums, result, curr, currSum+nums[indx], n, k, indx+1);
    curr.pop_back();
    combinationSum3helper(nums, result, curr, currSum, n, k, indx+1);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>nums={1,2,3,4,5,6,7,8,9};
    vector<vector<int>> result;
    vector<int> curr;
    combinationSum3helper(nums, result, curr,0, n, k, 0 );
    return result;        
}

vector<string> letterCombinations(string digits) {
    vector<string>res={""};
    vector<string>corres={"abc", "def", "ghi","jkl", "mno", "pqrs","tuv","wxyz"};
    
    for(char d : digits) {
        vector<string> temp;
        string letters = corres[d - '2'];

        for(string s : res) {
            for(char c : letters) {
                temp.push_back(s + c);
            }
        }

        res = temp;
    }

    return res;
}



int main()
{
	// vector<int> nums={4, 2, 10, 5, 1, 3};//{4, 9, 2, 5, 1};
	// vector<vector<int>>res;
	// res=subsequenceSum(nums, 5);
	// for(auto x: res){
	// 	for(auto y:x){
	// 		cout<<y<<", ";
	// 	}
	// 	cout<<endl;
	// }

	// vector<int>nums={5,2,1};
	// vector<int>result;
	// result=subsetSumBF(nums);
	// for(auto x:result){
	// 	cout<<x<<", ";
	// }

	for(auto x:combinationSum3(3, 7)){
		cout<<"{";
		for(auto y:x){
			cout<<y<<", ";
		}
		cout<<"}";
	}
	
	//the
	return 0;
}