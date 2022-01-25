// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int solve(int i ,int curr, int req , const string& str)
{
    // cout<<i<<" "<<curr<<" "<<req<<"\n";
    if(curr == req+1)
    {
        int y = solve(i,curr,curr,str);
            if(y==-1)
                return req;
        
        return -1;
    }
    if(i==str.size())
    {
        return -1;
    }
    if(curr==req)
    {
        // return solve(i+1,0,req+1,str);
        int x =0;
        req++;
        for(int j =i; j<str.size(); j++)
        {
            x = x*10 + (str[j]-'0');
            if(x>req+1)
            {
                return -1;
            }
            int y = solve(j+1,x,req,str);
            if(y!=-1)
                return y;
        }
        return -1;
    }
    else if(curr<req)
    {
        curr = curr*10 + (str[i]-'0');
        return solve(i+1,curr,req,str);
    }
    return -1;
}
int missingNumber(const string& str)
{
    int x =0;
    for(int i =0; i<str.size(); i++)
    {
        x = x*10 + (str[i]-'0');
        // cout<<"-\n";
        int y = solve(i+1,0,x+1,str);
        // cout<<y<<"-";
        if(y!=-1)
            return y;
    }
    return -1;
    // Code heresolve
    
}