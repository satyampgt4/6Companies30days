#include<bits/stdc++.h>
using namespace std;

string encode(string src)
{     
  string s = "";
  int n = src.size();
  char last = src[0];
  int count = 1;
  
  s+=src[0];
  for(int i =1; i<n; i++)
  {
      if(last==src[i])
        count++;
      else
      {
          last =src[i];
          s += to_string(count);
          count = 1;
          s +=last;
      }
  }
  s += to_string(count);
  
  return s;
}     
