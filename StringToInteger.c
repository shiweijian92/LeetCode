int Is_digit(char c)
{
    if(c >= 48 && c <= 57)
        return 1;
    else
        return 0;
}

int myAtoi(char* str) 
{
    long resultl = 0;
    long resultlc = 0;
    int result = 0;
    int sign = 0;
    while(*str == ' ')
        str++;
    if(!Is_digit(*str))
    {
        if(*str == '+')
        {
            str++;
            sign = 0;
        }
        else if(*str == '-')
        {
            str++;
            sign = 1;
        }
        else
            return 0;
    }
    while(Is_digit(*str))
    {
        resultl = resultl * 10 + (*str - 48);
        resultlc = sign? resultl * (-1) : resultl;
        if(resultlc > 2147483647)
            return INT_MAX;
        if(resultlc < INT_MIN)
            return INT_MIN;
        str++;
    }
    result = sign? resultl * (-1) : resultl;
    return result;
}