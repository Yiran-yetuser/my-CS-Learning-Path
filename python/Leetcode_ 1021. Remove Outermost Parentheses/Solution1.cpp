class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        cnt = 0
        ans = []
        for i in s:
            if i == '(':
                cnt+=1
                if cnt == 1:
                    continue
            else:
                cnt-=1
                if cnt == 0:
                    continue
            ans.append(i)
        
        res = ''.join(ans)
            
        return res
