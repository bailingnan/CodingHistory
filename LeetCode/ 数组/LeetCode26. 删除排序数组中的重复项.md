```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        cnt=len(set(nums))
        j=0
        for i in range(len(nums)):
            if i!=0:
                if(nums[i]==nums[i-1]):
                    continue
            nums[j]=nums[i]
            j+=1
        if(j<len(nums)):
            del(nums[j:len(nums)])
        return j
```
