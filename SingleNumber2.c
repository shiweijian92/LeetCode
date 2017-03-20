int singleNumber(int* nums, int numsSize) 
{
    int int_bits = sizeof(int) * 8;
    int i = 0, j = 0;
    int sum = 0;
    int result = 0;
    
    for(i = 0; i < int_bits; i++)
    {
        for(j = 0; j < numsSize; j++)
        {
            if(nums[j] & (1 << i))
                sum++;
        }
        result |= (sum % 3) << i;
        sum = 0;
    }
    return result;
}