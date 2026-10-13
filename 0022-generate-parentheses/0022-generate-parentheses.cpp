class Solution {
private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: if the current string reaches a length of 2 * n, we've formed a valid combination.
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // If we can still use more opening brackets, add '('
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // If the number of closing brackets is less than opening brackets, add ')'
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};