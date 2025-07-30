long long maxSubarraySum(const vector<int>& arr) {
    if (arr.empty()) return 0;
    
    long long maxSum = arr[0];
    long long currentSum = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        currentSum = max((long long)arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}


// Longest Palindromic Substring using Manacher's Algorithm
string longestPalindromicSubstring(const string& s) {
    if (s.empty()) return "";
    
    // Transform string: "abc" -> "#a#b#c#"
    string T = "#";
    for (char c : s) {
        T += c;
        T += "#";
    }
    
    int n = T.length();
    vector<int> P(n, 0);
    int center = 0, right = 0;
    
    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;
        
        if (i < right) {
            P[i] = min(right - i, P[mirror]);
        }
        
        // Try to expand palindrome centered at i
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && 
               T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }
        
        // If palindrome centered at i extends past right, adjust center and right
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }
    
    // Find the longest palindrome
    int maxLen = 0, centerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

// All Palindromic Substrings
vector<string> getAllPalindromes(const string& s) {
    vector<string> palindromes;
    int n = s.length();
    
    // Check for odd length palindromes
    for (int center = 0; center < n; center++) {
        int left = center, right = center;
        while (left >= 0 && right < n && s[left] == s[right]) {
            palindromes.push_back(s.substr(left, right - left + 1));
            left--;
            right++;
        }
    }
    
    // Check for even length palindromes
    for (int center = 0; center < n - 1; center++) {
        int left = center, right = center + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            palindromes.push_back(s.substr(left, right - left + 1));
            left--;
            right++;
        }
    }
    
    return palindromes;
}

// Count Palindromic Substrings
int countPalindromes(const string& s) {
    int count = 0;
    int n = s.length();
    
    // Check for odd length palindromes
    for (int center = 0; center < n; center++) {
        int left = center, right = center;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
    
    // Check for even length palindromes
    for (int center = 0; center < n - 1; center++) {
        int left = center, right = center + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
    
    return count;
}

// Longest Palindromic Subsequence (Dynamic Programming)
int longestPalindromicSubsequence(const string& s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Every single character is a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Check for palindromes of length 2 and more
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[0][n - 1];
}