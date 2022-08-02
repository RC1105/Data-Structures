#include "bits/stdc++.h"
using namespace std;
class TrieNode{
      public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childcnt;
        TrieNode(char ch){
            data=ch;
            for(int i=0; i<26;i++){
                children[i]=NULL;
            }
            childcnt=0;
            isTerminal=false;
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie(){
            root=new TrieNode('\0');
        }
        void insertUtil(TrieNode* root, string word){
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            int idx=word[0]-'a';
            TrieNode* child;
            if(root->children[idx]!=NULL){
                child=root->children[idx];
            }
            else{
                child=new TrieNode(word[0]);
                root->childcnt++;
                root->children[idx]=child;
                
            }
            insertUtil(child,word.substr(1));

        }
        void insertWord(string str){
            insertUtil(root,str);
        }
        void lcp(string str, string &ans){
            for(int i=0; i<str.length();i++){
                char ch=str[i];
                if(root->childcnt==1){
                    ans+=ch;
                    root=root->children[int(ch-'a')];
                }
                else{
                    break;
                }
                if(root->isTerminal){
                    break;
                }
            }
        }
};

int main(){
    Trie *t= new Trie();
    t->insertWord("raghav");
    t->insertWord("raghzu");
    t->insertWord("raghu");
    t->insertWord("ragham");
    string ans="";
    t->lcp("raghav",ans);
    cout<<ans;
    return 0;
}
