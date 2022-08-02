#include "bits/stdc++.h"
using namespace std;
class TrieNode{
      public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            data=ch;
            for(int i=0; i<26;i++){
                children[i]=NULL;
            }
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
                root->children[idx]=child;
            }
            insertUtil(child,word.substr(1));

        }
        bool searchUtil(TrieNode* root, string str){
            if(str.length()==0){
                return root->isTerminal;
            }
            TrieNode* child;
            int idx=str[0]-'a';
            if(root->children[idx]!=NULL){
                child=root->children[idx];
            }
            else{
                return false;
            }
            return searchUtil(child,str.substr(1));
        }
        
        void insertWord(string str){
            insertUtil(root,str);
        }
        bool searchWord(string str){
            return searchUtil(root,str);
        }
        

};

int main(){
    Trie *t= new Trie();
    t->insertWord("raghav");
    
    int ans=t->searchWord("raghav");
    if(ans){
        cout<<"Word found in trie"<<endl;
    }
    else{
        cout<<"No!!"<<endl;
    }
    
}