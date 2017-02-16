char* longestPalindrome(char* s) 
{
    int i, j, k;
    int length = strlen(s);
    int max_l = 0;
    int start = 0, end = 0;
    char* result = NULL;
    
    for(i = 0; i <= 2 * length - 2; i++)
    {
        if(i % 2 == 0)
        {
            for(j = 0; (i/2 - j) >= 0 && (i/2 + j) < length; j++)
            {
                if(s[i/2 + j] != s[i/2 - j])
                    break;
            }
            j--;
            if((j * 2 + 1) > max_l)
            {
                max_l = j * 2 + 1;
                start = i / 2 - j;
                end = i / 2 + j;
            }
        }
        else if(i % 2 == 1)
        {
            for(k = 0; ((i-1)/2 - k) >= 0 && ((i+1)/2 + k) < length; k++)
            {
                if(s[(i+1)/2 + k] != s[(i-1)/2 - k])
                    break;
            }
            k--;
            if((k + 1) * 2 > max_l)
            {
                max_l = (k + 1) * 2;
                start = (i - 1) / 2 - k;
                end = (i + 1) / 2 + k;
            }
        }
    }
    result = (char*)calloc((max_l + 1), sizeof(char));
    memcpy(result, (s + start), max_l);
    return result;
}