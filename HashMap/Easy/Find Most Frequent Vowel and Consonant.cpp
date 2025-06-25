// Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
// Find the consonant (all other letters excluding vowels) with the maximum frequency.
// Return the sum of the two frequencies.



#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxFreqSum(string s) {
            // two frequency array 
          unordered_map<char , int> vowels;
          unordered_map<char , int> constant;
          string vowel = "aeiou";
            
           for(auto ch: s){
               if(vowel.find(ch) != string::npos){
                   vowels[ch]++;
               }else{
                   constant[ch]++;
               }
           }
            int max_vowels = 0;
            for(auto &pair : vowels){
                max_vowels = max(max_vowels, pair.second);
            }
            int max_constant = 0; 
            for(auto &pair : constant){
                max_constant = max(max_constant, pair.second);
            }
            return max_vowels+max_constant;
           
        } 
    };