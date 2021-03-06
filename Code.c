#include<stdio.h>

int helper(int* nums, int numsSize, int xor_total, int *sum) {
  if (numsSize == 0) 
  {
    return xor_total;
  }
  
for (int i = 0; i <= numsSize; ++i) 
{
        if (i < numsSize) 
        {
        xor_total ^= nums[i];
        }
    
        *sum += helper(nums+i+1, numsSize-i-1, xor_total, sum);
    
        if (i < numsSize) 
        {
                xor_total ^= nums[i];
        }
  }
  
  return 0;
}

int subsetXORSum(int* nums, int numsSize)
{
        int sum  = 0;
        helper(nums, numsSize, 0, &sum);
        return sum;
}

int main()
{
        int numsSize;
        scanf("%d",  &numsSize);
        int nums[numsSize];
        for(int i = 0; i < numsSize; ++i)
                scanf("%d", &nums[i]);
        printf("%d", subsetXORSum(nums, numsSize));
        return 0;
}
