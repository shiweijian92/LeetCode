/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
    int* result = (int*)malloc(2 * sizeof(int));
    int find;
    int i;
    int j;
    
    for(i = 0; i < numsSize; i++)
    {
        find = target - *(nums + i);
        for(j = i + 1; j < numsSize; j++)
        {
            if(*(nums + j) == find)
            {
                *result = i;
                *(result + 1) = j;
            }
        }
    }
    return result;   
}