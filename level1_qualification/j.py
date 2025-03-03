n = int(input())
ans = 0
prev = 0
for i in range(n):
   if (i >= n-i):
      ans += (i)/(n-i+1)
      prev = i
   

print(ans)