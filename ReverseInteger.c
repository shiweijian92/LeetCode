int reverse(int x) 
{
    int sign = 0;
    int n = 0;
    int i = 0;
    char temp;
    int result = 0;
    long resultc = 0;
    char buffer[12];
    char* s = NULL;
    sign = x < 0? 1 : 0;
    x = abs(x);
    n = sprintf(buffer, "%d", x);
    for(i = 0; i < n; i++)
        resultc += (buffer[i] - 48) * pow(10, i);
    if(sign)
    {
        if(resultc > 2147483648)
            return 0;
    }
    else
    {
        if(resultc > 2147483647)
            return 0;
    }
    result = sign? resultc * (-1) : resultc;
    return result;
}