#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> hashTab;
    for(auto x: s){
        hashTab[x]++;
    }
    vector<string> buckets(s.size()+1);

    for(auto c:hashTab){
    	buckets[c.second].push_back(c.first);

    }
    string result;
    for(int f=s.size();f>0;f--){
    	for(char c:buckets[f]){
    		result.append(f,c);
    	}
    }
    return result;
}


int maxDepth(string s) {
    int depth=0;
    int maxDepth=0;
    for(char x:s){
        if(x=='('){
            depth++;
            maxDepth=max(maxDepth, depth);
        }else if(x==')'){
            depth--;
        }
    }
    return maxDepth;
}

int value(char &x){
    static unordered_map<char, int>equivalence={
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
    };
    return equivalence[x];
}

int romanToInt(string s) {
    int num=0;
    for(int i=0;i<s.size()-1;i++){
        if(value(s[i])<value(s[i+1])){
            num-=value(s[i]);
        }else{
            num+=value(s[i]);
        }
    }
    num+=value(s[s.size()-1]);
    return num;
}

int myAtoi(string s) {
    int i = 0, sign = 1;
    long res = 0;
    while (i < s.size() && s[i] == ' ') i++;
    if (i == s.size()) return 0;

    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }
    while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
        res = res * 10 + (s[i] - '0');
        if (sign * res > INT_MAX) return INT_MAX;
        if (sign * res < INT_MIN) return INT_MIN;
        i++;
    }
    return (int)(sign * res);
}

int atMostKDistinct(string s, int k){
	int left=0, ans=0;
	unordered_map <char, int>freq;
	for(int right=0; right<s.size();right++){
		freq[s[right]]++;

		while(freq.size()>k){
			freq[s[left]]--;
			if (freq[s[left]] == 0) freq.erase(s[left]);
			left++;
		}
		ans+=right-left+1;
	}
	return ans;
}


int countNumberofSubstrings(string s, int k){
	return atMostKDistinct(s, k) - atMostKDistinct(s, k-1);
}



int longestPalindrome(string s) {
    int maxLen=0;
    for(int i=0;i<s.size();i++){
        int evenLen=0, oddLen=0;
        int j=0;
        //odd length palindrome check
        while(i+j<s.size() && i-j>0){
            if(s[i+j]==s[i-j])
                j++;
            else
            	break;
        }
        oddLen=2*j+1;
        j=0;
        //even lenth palindrome check
        while(i+j+1<s.size() && i-j>0){
            if(s[i+1+j]==s[i-j])
                j++;
            else
            	break;
        }
        evenLen=2*j+2;
        maxLen=max(maxLen, max(evenLen, oddLen));
    }
    return maxLen;
}

string longestPalindrome(string s) {
    int maxLen=0;
    string result;
    for(int i=0;i<s.size();i++){
        int evenLen=0, oddLen=0;
        int j=0;
        //odd length palindrome check
        while(i+j<s.size() && i-j>=0){
            if(s[i+j]==s[i-j])
                j++;
            else
            	break;
        }
        oddLen=2*j-1;

        if(oddLen>maxLen){
            maxLen=oddLen;
            result=s.substr(i-j+1, maxLen);
        }

        j=0;
        //even lenth palindrome check
        while(i+j+1<s.size() && i-j>=0){
            if(s[i+1+j]==s[i-j])
                j++;
            else
            	break;


        }
        evenLen=2*j;
        if(evenLen>maxLen){
            maxLen=evenLen;
            result=s.substr(i-j+1, maxLen);
        }
    }
    return result;
}

int beautySum(string s) {
    vector<string> strings;
    unordered_map<char, int> freqTab;
    int sum=0;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            strings.push_back(s.substr(i, j-i+1));
            
        }
    }
    
    for(int i=0;i<strings.size();i++){
        freqTab.clear();
        for(auto c:strings[i]){
            freqTab[c]++;
        }

        int maxFreq=INT_MIN;
        int minFreq=INT_MAX;
        for(auto x:freqTab){
            if(x.second>maxFreq){
                maxFreq=x.second;
            }
            if(x.second<minFreq){
                minFreq=x.second;
            }
        }
        sum+=maxFreq-minFreq;
    }
    return sum;
}

int beautySum2(string s) {
    vector<string> strings;
    unordered_map<char, int> freqTab;
    int sum=0;
    for(int i=0;i<s.size();i++){
        freqTab.clear();
        for(int j=i;j<s.size();j++){
            freqTab[s[j]]++;
        }
        int maxFreq=INT_MIN;
        int minFreq=INT_MAX;
        for(auto x:freqTab){
            if(x.second>maxFreq){
                maxFreq=x.second;
            }
            if(x.second<minFreq){
                minFreq=x.second;
            }
        }
        sum+=maxFreq-minFreq;
    }
    return sum;
}

int main()
{
	// string s="giganigga";
	// cout<<frequencySort(s);
	// string sx="aabcbcdbca";
	// cout<<countNumberofSubstrings(sx, 2);

	string s="babad";
	cout<<longestPalindrome(s);

}