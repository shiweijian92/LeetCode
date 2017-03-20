int singleNumber(int* nums, int numsSize) 
{
    int i = 0;
    int xor = 0;
    
    for(i = 0; i < numsSize; i++)
        xor = xor ^ nums[i];    
    return xor;
}