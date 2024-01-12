class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<int> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int vowelCount = 0;
        int mid = s.length()/2;
        for(int i=0;i<mid;i++)
        {
            int charA = s[i];
            int charB = s[mid + i];
            if(vowels.count(charA))  vowelCount++;
            if(vowels.count(charB))  vowelCount--;
        }

        return vowelCount == 0;
    }
};