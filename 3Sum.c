void mergesort(int *arr, int l, int r)
{
    int m;
    if(l < r)
    {
        m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge(int *arr, int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;
    int left[nl];
    int right[nr];
    int i = 0, j = 0, k = 0;
    for(i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for(i = 0; i < nr; i++)
        right[i] = arr[m + 1 + i];
    for(i = l; j < nl && k < nr; i++)
    {
        if(left[j] < right[k])
        {
            arr[i] = left[j];
            j++;
        }
        else
        {
            arr[i] = right[k];
            k++;
        }
    }
    for(; j < nl; i++, j++)
        arr[i] = left[j];
    for(; k < nr; i++, k++)
        arr[i] = right[k];
}

int** threeSum(int* nums, int numsSize, int* returnSize) 
{
    int i = 0, j = 0, k = 0;
    int n = 0;
    int find;
    int **result = (int **)malloc(20000 * sizeof(int *));
    
    mergesort(nums, 0, numsSize - 1);
    for(i = 0; i < numsSize - 2; i++)
    {
        if(nums[i] == nums[i - 1] && i > 0)
            continue;
        if(nums[i] > 0)
            break;
        find = 0 - nums[i];
        j = i + 1;
        k = numsSize - 1;
        while(j < k)
        {
            if(nums[k] < 0)
                break;
            if(nums[j] + nums[k] < find)
            {
                do j++;
                while(nums[j] == nums[j - 1] && j < k);
            }
            else if(nums[j] + nums[k] > find)
            {
                do k--;
                while(nums[k] == nums[k + 1] && j < k);
            }
            else
            {
                *(result + n) = (int *)malloc(3 * sizeof(int));
                *(result + n)[0] = nums[i];
                (*(result + n))[1] = nums[j];
                (*(result + n))[2] = nums[k];
                n++;
                do j++;
                while(nums[j] == nums[j - 1] && j < k);
                do k--;
                while(nums[k] == nums[k + 1] && j < k);
            }    
        }
    }
    *returnSize = n--;
    return result;
}