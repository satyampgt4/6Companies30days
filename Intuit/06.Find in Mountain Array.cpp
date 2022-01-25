#include<bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int left  =0;
        // vecotor
        int right = mountainArr.length()-1;
        int n = right;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            
            if(!mid)
                mid++;
            int lm = mountainArr.get(mid-1);
            int m = mountainArr.get(mid);
            int rm = mountainArr.get(mid+1);
            if(lm<m&& rm<m)
            {
                left = mid, right = mid;
                break;
            }
            else if(lm<m&& rm>m)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        
        int i  =0;
        while(i<=right)
        {
            int mid = i +(right-i)/2;
            int m = mountainArr.get(mid);
            
            if(m==target)
                return mid;
            else if(m<target)
            {
                i = mid +1;
            }
            else
            {
                right = mid-1;
            }
        }
        i  =n;
        while(left<=i)
        {
            int mid = left +(i-left)/2;
            
            int m = mountainArr.get(mid);
            if(m==target)
                return mid;
            else if(m<target)
            {
                i = mid -1;
            }
            else
            {
                left = mid+1;
            }
            
        }
        return -1;
    }
};