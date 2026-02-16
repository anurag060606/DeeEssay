#include <bits/stdc++.h>
using namespace std;

string removeOutermostParan(string s){
	vector<string> primitives;
	stack <char> st;
	string curr;
	for(char x:s){
		curr.push_back(x);
		if(x=='('){
			st.push('(');
		}else{
			if(!st.empty())
				st.pop();
			if(st.empty()){
				primitives.push_back(curr);
				curr.clear();		
			}
		}
	}
	curr.clear();

	for(auto &x:primitives){
		if(x.length()>=2){
			x.erase(x.begin());
			x.pop_back();
		}
		curr+=x;
	}

	return curr;
}

string removeOutermostParan2(string &s){
	string result;
	int level=0;

	for(char &x:s){
		if(x=='('){
			if(level>0){
				result+=x;
			}
			level++;
		}else{
			level--;
			if(level>0){
				result+=x;
			}

		}
	}
	return result;
}

string reverseWords(string s){
	stack<string> words;
	for(int i=0;i<s.length();i++){
		if(s[i]==' '){
			continue;
		}else{
			string currWord;
			int j=0;
			while( i + j < s.length() && s[i+j]!=' '){
				currWord+=s[i+j];
				j++;
			}
			words.push(currWord);
			currWord.clear();
			i=i+j-1;
		}
	}
	string result;
	while(!words.empty()){
		result+=words.top();
		result+=" ";
		words.pop();
	}
	result.pop_back();
	return result;
}


string reverseWords2(string s){
	string result;
	string currWord;
	int indx=s.length()-1;
	while(indx>=0){
		if(s[indx]!=' '){
			currWord+=s[indx];
		}else{
			if(!currWord.empty()){
				if(result.length()!=0)
					result.push_back(' ');
				for(int i=currWord.length()-1;i>=0;i--){
					result.push_back(currWord[i]);
				}
				
				currWord.clear();
			}

		}
		indx--;
	}
	if(!currWord.empty()){
        if(!result.empty()) result.push_back(' ');
        for(int i = currWord.length() - 1; i >= 0; i--){
            result.push_back(currWord[i]);
        }
    }
	return result;
}

string largestOddNumber(string num){

	//create a prefix
	//check each created prefix
	//create next prefix
	//check the prefix

	for(int i=num.length()-1; i>=0;i--){
		int lastDigit=num[i]-'0';
		if(lastDigit%2==1){
			return num.substr(0, i+1);
		}	
	}
	return "";

}

string longestCommonPrefix(vector<string>&strs){
	int indx=0;
	string result;
	while(true){
		if(indx>=strs[0].length()){
				return result;
		}
		char ch=strs[0].at(indx);
		for(string &str: strs){
			if(indx>=str.length()){
				return result;
			}
			if(str.at(indx)!=ch){
				return result;
			}
		}
		result.push_back(ch);
		indx++;
	}
	return result;
}

string longestCommonPrefix2(vector<string>&str){
	if (str.empty()) return "";
	sort(str.begin(),str.end());
	string first=str[0];
	string last=str[str.size()-1];
	string ans="";

	int minLength=min(first.size(), last.size());

	for(int i=0;i<minLength;i++){
		if(first[i]!=last[i]) break;
		ans+=first[i];
	}
	return ans;
}

bool isIsomorphic(string s, string t) {
    if(s.length()!=t.length()) return false;
    map<char, char> pairings;
    for(int i=0;i<s.length();i++){
        auto it=pairings.find(s[i]);
        if(it==pairings.end()){
            for(auto x:pairings){
                if(x.second==t[i])
                    return false;
            }
            pairings.insert({s[i], t[i]});
        }else{
            if(it->second!=t[i]){
                return false;
            }
        }
    }
    return true;  
}

bool rotateString(string s, string goal){
	return false;
}



int main()
{
	// string s= "((()))";
	// string ss="(()())(())(()(()))";
	// cout<<"Original: "<<ss; 
	// cout<<"Answer: "<<removeOutermostParan(ss);

	// string s="the sky is fucikng pink";
	// cout<<reverseWords2(s);
	// vector<string> strs={"flower","f","flight"};
	// cout<<longestCommonPrefix(strs);

	cout<<isIsomorphic("badc", "baba");
}