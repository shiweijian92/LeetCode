int min(int a, int b)
{
    if(a >= b)
        return b;
    else
        return a;
}


int maxArea(int* height, int heightSize) 
{
    int i, j;
    int maxArea = 0;
    int maxHeight = 0;
    int Area = 0;
    
    for(i = 0; i < heightSize - 1; i++)
    {
        if(maxHeight >= height[i])
            continue;
        else
            maxHeight = height[i];
        for(j = heightSize - 1; j > i; j--)
        {
            Area = (j - i) * min(height[i], height[j]);
            maxArea = Area > maxArea? Area : maxArea;
            if(height[j] >= height[i])
            {
                heightSize = j + 1;
                break;
            }
        }
    }
    return maxArea;    
}