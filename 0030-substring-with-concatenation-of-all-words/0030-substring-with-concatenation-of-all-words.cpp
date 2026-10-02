class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> need;

        for (string word : words) {
            need[word]++;
        }

        for (int offset = 0; offset < wordLen; offset++) {
            
            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string, int> window;

            while (right + wordLen <= s.size()) {
                
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (need.find(word) == need.end()) {
                    window.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                window[word]++;
                count++;

                while (window[word] > need[word]) {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                if (count == wordCount) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};