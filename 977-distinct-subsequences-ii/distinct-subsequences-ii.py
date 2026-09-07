class Solution:
    def distinctSubseqII(self, s: str) -> int:
        n = len(s)

        dp = [1] * (n+1)
        lastOcc = {}    #map for the last occurence of the character

        for i in range(n):

            dp[i+1] = dp[i] * 2
            if s[i] in lastOcc:
                    dp[i+1] -= dp[lastOcc[s[i]]]
            
            lastOcc[s[i]] = i
        
        return (dp[-1] - 1) % (10**9+7)
        