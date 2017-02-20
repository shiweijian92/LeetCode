bool isPalindrome(int x) 
{
    long resultl = 0;
    long xl = x;
    int r = 0;
    
    if(x < 0)
        return false;
    while(x != 0)
    {
        r = x % 10;
        x = x / 10;
        resultl = resultl * 10 + r;
    }
    if(resultl != xl)
        return false;
    else
        return true;
}