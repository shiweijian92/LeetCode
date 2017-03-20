/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void Recursion(int* nums, int numsSize, int numsN, int** columnSizes, int columnN, int **result, int* returnSize, int *resultN, int *temp)
{
    if(numsN == numsSize)
    {
        (*columnSizes)[*resultN] = columnN;
        memcpy(result[*resultN], temp, sizeof(int) * columnN);
        (*resultN)++;               
        return;
    }
    Recursion(nums, numsSize, numsN + 1, columnSizes, columnN, result, returnSize, resultN, temp);
    temp[columnN] = nums[numsN];
    columnN++;
    Recursion(nums, numsSize, numsN + 1, columnSizes, columnN, result, returnSize, resultN, temp);    
}


int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) 
{
    int **result = NULL;
    int *resultN = NULL;
    int *temp = NULL;
    int i = 0;
    
    *returnSize  = pow(2, numsSize);
    *columnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    result = (int **)malloc(sizeof(int*) * (*returnSize));
    resultN = (int *)malloc(sizeof(int));
    *resultN = 0;
    for(i = 0; i < *returnSize; i++)
        result[i] = (int*)malloc(sizeof(int) * numsSize);
    temp = (int*)malloc(sizeof(int) * numsSize);
    Recursion(nums, numsSize, 0, columnSizes, 0, result, returnSize, resultN, temp);
    return result;
}