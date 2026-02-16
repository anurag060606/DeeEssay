#include<bits/stdc++.h>
using namespace std;
class Solution{
public:

	long long mod=1e9 +7;
	double fastPov(double x, int n){
		if(n<0){
			n=-n;
			x=1/x;
		}
		double base=x;
		double ans=1;
		while(n>0){
			if(n%2==1){
				ans=ans*base;
			}
			base=base*base;
			n/=2;
		}
		return ans;
	}

	long long fastPov(int x, long long n){
	    
	    long long base=x;
	    long long ans=1;
	    while(n>0){
	        if(n%2==1){
	            ans=(ans*base)%mod;
	        }
	        base=(base*base)%mod;
	        n/=2;
	    }
	    return ans;
	}

	int countGoodNumbers(long long n) 
	{   
	    long long evenIndxCount=((n+1)/2);
	    long long oddIndxCount=n/2;
	    long long ans=(fastPov(5, evenIndxCount) *fastPov(4, oddIndxCount))%mod;
	    return ans %mod;
	}

	void insertStack(stack<int> &s, int x){
		if(s.empty() || s.top()<=x){
			s.push(x);
			return;
		}
		int temp=s.top();
		s.pop();
		insertStack(s, x);
		s.push(temp);
	}

	void sortStack(stack<int> &s){
		if(s.empty())
			return;
		int x=s.top();
		s.pop();
		sortStack(s);
		insertStack(s, x);

	}

	void bfreverseStack(stack <int> &st){
		stack<int> temp;
		while(!st.empty()){
			temp.push(st.top());
			st.pop();
		}
		st=temp;
		return;

	}

	void reverseHelper(stack<int>&st, int x){
		if(st.empty()){
			st.push(x);
			return;
		}
		int temp=st.top();
		st.pop();
		reverseHelper(st, x);
		st.push(temp);

	}
	void opreversestack(stack<int> &st){

		if(st.empty())
			return;
		int temp=st.top();
		st.pop();
		opreversestack(st);
		reverseHelper(st, temp);
	}


	void generate(int n, string curr, vector<string>&result){
		if(curr.length()==n){
			result.push_back(curr);
			return ;
		}else{
			generate(n, curr+'0',result);
			if(curr.empty() || curr.back()!='1')
				generate(n, curr+'1', result);
		}
	}

	void generateThree(int n , string curr, vector<string>& result){
		//no three consecutive 1s
		if(curr.length()==n){
			result.push_back(curr);
			return;
		}

		generateThree(n, curr+'0', result);

		if(curr.empty() || curr.length()<2 || curr.substr(curr.size()-2)!="11"){
			generateThree(n, curr+'1',result);
		}
	}
	void generateParans(string curr, int n, vector<string> &result, int open,int close){
		if(open ==n && close==n){
			result.push_back(curr);
			return;
		}

		if(open<n){
			generateParans(curr+'(', n, result,open+1, close);
		}

		if(close<open){
			generateParans(curr+')', n, result,open, close+1);

		}
	}


	void permute(string &s,
				string &curr,
				vector<bool>&used,
				vector<string> &result){

		if(curr.size()==s.size()){
			result.push_back(curr);
			return;
		}

		for(int i=0;i<s.size();i++){
			if(used[i]) continue;

			used[i]=true;
			curr.push_back(s[i]);

			permute(s, curr, used, result);

			curr.pop_back();
			used[i]=false;
		}
	}

	vector<string> allPerms(string s){
		vector<string> result;
		string curr;
		vector<bool> used(s.size(),false);

		permute(s, curr, used, result);
		return result;
	}

	// void generatesubSeq(string &s, string &curr, vector<string> &result, int i){
	// 	if(i==s.size()){
	// 		result.push_back(curr);
	// 		return;
	// 	}

	// 	for(int x=i;x<s.size();x++){
	// 		curr.push_back(s[x]); //append
	// 		generatesubSeq(s, curr, result,x+1);

	// 		curr.pop_back(); //skip
	// 		generatesubSeq(s, curr, result, x+1);
	// 	}
	// }

	// vector<string> subSequence(string &s){
	// 	vector<string> result;
	// 	string curr;
	// 	generatesubSeq(s, curr, result, 0);

	// 	return result;
	// }

	void subSequence( vector<string>&result,string &s, string &curr, int i ){
		if(i==s.size()){
			result.push_back(curr);
			return;
		}

		curr.push_back(s[i]);
		subSequence(result, s, curr, i+1);

		curr.pop_back();
		subSequence(result, s, curr, i+1);

	}
};



int main()
{
	Solution sol;
	stack<int> st;
	st.push(10);
	st.push(90);
	st.push(2);
	st.push(9);
	st.push(12);
	st.push(5);

	// stack<int> temp = st;
	// cout<<"Before sorting: "<<endl;
	// while(!temp.empty()){
	//     cout << temp.top() << endl;
	//     temp.pop();
	// }

	// sol.sortStack(st);
	// cout<<"After sorting: "<<endl;
	// temp=st;
	// while(!temp.empty()){
	//     cout << temp.top() << endl;
	//     temp.pop();
	//}

	// cout<<"Before reversing: "<<endl;

	// stack<int> temp = st;
	// while(!temp.empty()){
	//     cout << temp.top() << endl;
	//     temp.pop();
	// }
	// sol.opreversestack(st);
	// cout<<"After reversing: "<<endl;
	// temp=st;
	// while(!temp.empty()){
	//     cout << temp.top() << endl;
	//     temp.pop();
	// }
	// vector<string> result;
	// sol.generateThree(4, "", result);
	// for(auto x: result){
	// 	cout<<x<<endl;
	// }
	// vector<string> result;
	// sol.generateParans("",3, result, 0, 0);
	// for(auto x:result){
	// 	cout<<x<<endl;
	// }
	// string s= "abc";

	// vector<string> res;
	// res=sol.allPerms(s);
	// for(auto x:res){
	// 	cout<<x<<endl;
	// }

	string s= "abc";

	vector<string> res;
	string sss="";
	sol.subSequence(res, s,sss , 0);
	for(auto x:res){
		cout<<x<<endl;
	}
}