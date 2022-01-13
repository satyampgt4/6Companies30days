#include <bits/stdc++.h>
using namespace std;


struct TrieNode
{
    struct TrieNode *children[26];
    bool isEndOfWord ;
    int count  ;
    TrieNode() {
        isEndOfWord =0;
        count  =0;
        for(int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
};
class Solution{
public:
    TrieNode *tri = new TrieNode();
    void addstr(TrieNode *t,int i, string s)
    {
        
        if(s.size()==i+1)
        {
            t->isEndOfWord = 1;
            return;
        }
        t->count++;
        if(!(t->children[s[i]-'a']))
            t->children[s[i]-'a'] = new TrieNode();
        addstr(t->children[s[i]-'a'],i+1,s);
    }
    void check(TrieNode *t,string s,vector<string>&v,int i,int j,string r)
    {
        
        if(i>j)
        {
            if(t->isEndOfWord)
            {
                v.push_back(r);
            }
            if(t->count){
                for(int k =0; k<26; k++)
                {
                    char x = 'a'+k;
                    string temp = r+x;
                    if(t->children[k])
                        check(t->children[k],s,v,i+1,j,temp);
                }
            }
        }
        else
        {
            if(t->children[s[i]-'a'])
                        check(t->children[s[i]-'a'],s,v,i+1,j,r+s[i]);
        }
        // else
        // {
            
        //     // cout<<r<<" "<<s[i]<<" "<<i<<" "<<j<<" "<<t->count<<"\n";
        // }
        
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        
        for(int i =0; i<n;i++)
        {
            addstr(tri,0,contact[i]);   
        }
        vector<vector<string>> ans;
        for(int i =0; i<s.size(); i++)
        {
            vector<string>v;
            check(tri,s,v,0,i,"");
            if(v.size())
            {
                
                sort(v.begin(),v.end());
                ans.push_back(v);
            }
            else
            {
                ans.push_back({"0"});
            }
            
            // cout<<v.size();
        }
        return ans;
        
        // code here
    }
};