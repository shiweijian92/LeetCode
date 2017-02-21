char* longestCommonPrefix(char** strs, int strsSize) 
{
    int i, j;
    int len = 0;
    int end = 0;
    char *result = NULL;
    static char empty[] = "";
    char c = 0;
    
    if(strsSize == 0)
        return empty;
    if(strsSize == 1)
        return strs[0];
    len = strlen(strs[0]);
    result = calloc((len + 1), sizeof(char));
    for(i = 0; i < len; i++)
    {
        c = strs[0][i];
        for(j = 1; j < strsSize; j++)
        {
            if(strs[j][i] != c)
            {
                end = 1;
                break;
            }
        }
        if(end == 1)
            break;
    }
    memcpy(result, strs[0], i);
    return result;
}
