#include "bits/stdc++.h"
using namespace std;
string longestCommonPrefix(vector<string> vec){
    string ans="";
    bool match=true;
    for(int i=0; i<vec[0].length();i++){
        char ch=vec[0][i];
        for(int j=1; j<vec.size();j++){
            if(i>vec[j].length() ||ch!=vec[j][i]){
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans+=ch;
        }
    }
    return ans;
}
int main(){
    vector<string> vec={"coding","codingjam","codingtycoons"};
    cout<<longestCommonPrefix(vec);
}