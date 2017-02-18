char* convert(char* s, int numRows) 
{
    char **Row = (char**)malloc(numRows * sizeof(char*));
    int *c = (int *)calloc(numRows, sizeof(int));
    int rp = 2 * numRows - 2;
    int len = strlen(s);
    char *result = (char *)calloc(len + 1, sizeof(char));
    int RowSize = 0;
    int i = 0;
    if(numRows <= 1)
        return s;
    RowSize = (len / rp + 1) * 2 + 1;
    for(i = 0; i < numRows; i++)
    {
        Row[i] = (char *)calloc(RowSize, sizeof(char));
    }
    i = 0;
    while(*s != '\0')
    {
        if(i < numRows)
        {
            Row[i][c[i]] = *s;
            c[i]++;
        }
        else
        {
            Row[rp - i][c[rp - i]] = *s;
            c[rp - i]++;
        }
        i = (i + 1) % rp;
        s++;
    }
    strcpy(result, Row[0]);
    for(i = 1; i < numRows; i++)
    {
        strcat(result, Row[i]);
    }
    return result;
}