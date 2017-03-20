int majorityElement(int* nums, int numsSize) 
{
    int i, j;
    int int_bits = sizeof(int) * 8;
    int sum = 0;
    int result = 0;

    for(i = 0; i < int_bits; i++)
    {
        for(j = 0; j < numsSize; j++)
        {
            if(nums[j] & (1 << i))
                sum++;
        }
        if(sum > numsSize / 2)
            result |= (1 << i);
        sum = 0;
    }
    return result;
}
