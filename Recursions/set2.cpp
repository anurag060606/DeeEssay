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

int main()
{
	vector<int> nums={4, 2, 10, 5, 1, 3};//{4, 9, 2, 5, 1};
	vector<vector<int>>res;
	res=subsequenceSum(nums, 5);
	for(auto x: res){
		for(auto y:x){
			cout<<y<<", ";
		}
		cout<<endl;
	}
	return 0;
}