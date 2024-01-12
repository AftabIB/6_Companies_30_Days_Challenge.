class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<int> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int vCount = 0;
        int mid = s.length()/2;
        for(int i=0;i<mid;i++)
        {
            int setA = s[i];
            int setB = s[mid + i];
            if(vowels.count(setA))  vCount++;
            if(vowels.count(setB))  vCount--;
        }

        return vCount == 0;
    }
};