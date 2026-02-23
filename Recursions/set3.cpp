#include<bits/stdc++.h>
using namespace std;


bool palindromeCheck(string s){

    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1])
            return false;
    }
    return true;
}

vector<string>generatePartition(string s){
    vector<string> result;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(palindromeCheck(s.substr(i,j-i+1)))
                result.push_back(s.substr(i,j-i+1));
        }
    }
    return result;
}


int main()
{
    for(auto x: generatePartition("aab")){
        cout<<x<<endl;
    }
}