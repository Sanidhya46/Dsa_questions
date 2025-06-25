//https:/leetcode.com/contest/biweekly-contest-156/problems/minimum-operations-to-convert-all-elements-to-zero/description/
// You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.
// The key is to recognize that every time we encounter a new distinct value (greater than the current stack's top), we push it into the stack and count it as a new operation.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int ops = 0;
        for (int x : nums) {
            // Pop all values strictly greater than x
            while (!st.empty() && st.top() > x) {
                st.pop();
            }
            // If x>0 and it's a new segment (not equal to current stack top), push and count
            if (x > 0 && (st.empty() || st.top() < x)) {
                st.push(x);
                ++ops;
            }
            // Else x==0 or x==st.top(): do nothing
        }
        return ops;
    }
};