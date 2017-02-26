int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low, j = low;
    int temp = 0;
    
    for(i = low; i < high; i++)
    {
        if(arr[i] <= pivot)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    temp = arr[j];
    arr[j] = arr[high];
    arr[high] = temp;
    return j;
}

void quicksort(int arr[], int low, int high)
{
    int pivot = 0;
    if(low < high)
    {
        pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int threeSumClosest(int* nums, int numsSize, int target) 
{
    int i = 0, j = 0, k = 0;
    int sum = 0;
    int min_diff = INT_MAX;
    int result;
    
    quicksort(nums, 0, numsSize - 1);
    if(nums[0] + nums[1] + nums[2] > target)
        return (nums[0] + nums[1] + nums[2]);
    if(nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] < target)
        return (nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3]);
    for(i = 0; i < numsSize - 2; i++)
    {
        j = i + 1; 
        k = numsSize - 1;
        while(j < k)
        {
            sum = nums[i] + nums[j] + nums[k];
            if(sum < target)
            {
                j++;
                if(abs(sum - target) < min_diff)
                {
                    result = sum;
                    min_diff = abs(sum - target);
                }
            }
            else if(sum > target)
            {
                k--;
                if(abs(sum - target) < min_diff)
                {
                    result = sum;
                    min_diff = abs(sum - target);
                }
            }
            else
                return target;
        }
    }
    return result;
}