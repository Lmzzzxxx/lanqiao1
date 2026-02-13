//F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)
public int fib(int n) {
    if (n <= 1) return n;
    int[] dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 空间优化版（O(1)空间）
public int fibOptimized(int n) {
    if (n <= 1) return n;
    int prev1 = 1, prev2 = 0;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
