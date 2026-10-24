int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    
    // Allocate 2D DP table: (m + 1) rows by (n + 1) columns
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    
    // Base cases: converting empty string to/from word1 or word2
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    
    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int insert_op = dp[i][j - 1];
                int delete_op = dp[i - 1][j];
                int replace_op = dp[i - 1][j - 1];
                
                int min_val = insert_op < delete_op ? insert_op : delete_op;
                min_val = min_val < replace_op ? min_val : replace_op;
                
                dp[i][j] = 1 + min_val;
            }
        }
    }
    
    int result = dp[m][n];
    
    // Free allocated memory to prevent memory leaks
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}