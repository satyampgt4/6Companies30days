#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
       
       int n = string_list.size();
       vector<vector<string>>group;
       unordered_map<string,vector<string>>map_str;
       
       for(int i =0;i<n; i++)
       {
           string temp = string_list[i];
           sort(temp.begin(),temp.end());
           
           map_str[temp].push_back(string_list[i]);
       }
   
       for(auto x:map_str)
       {
           group.push_back(x.second);
       }
       return group;
    }
};