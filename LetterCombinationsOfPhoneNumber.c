/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char* empty[1] = {""}; 
const char* letter[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int n = 0;
int digitslen = 0;

void letterPermute(char* digits, int* returnSize, char **result, char *temp, int l, int r)
{
    int digit = 0;
    int len = 0;
    int i = 0;
    
    if(l > r)
    {
        memcpy(result[n], temp, digitslen); 
        n++;
        return;
    }
    digit = digits[l] - 48;
    len = strlen(letter[digit]);
    for(i = 0; i < len; i++)
    {
        temp[l] = letter[digit][i];
        letterPermute(digits, returnSize, result, temp, l + 1, r);
    }
}

char** letterCombinations(char* digits, int* returnSize) 
{
    char **result = NULL;
    char *temp = 0;
    int i = 0;
    int digit =0;
    
    n = 0;
    digitslen = 0;
    *returnSize = 0;
    digitslen = strlen(digits);
    if(digitslen == 0)
        return empty;
    *returnSize = 1;
    for(i = 0; i < digitslen; i++)
    {
        digit = digits[i] - 48;
        *returnSize *= strlen(letter[digit]);
    }
    if(returnSize == 0)
        return empty;
    result = (char**)malloc((*returnSize) * sizeof(char *));
    temp = (char*)calloc(digitslen + 1, sizeof(char));
    for(i = 0; i < *returnSize; i++)
        result[i] = (char*)calloc(digitslen + 1, sizeof(char));
    letterPermute(digits, returnSize, result, temp, 0, digitslen - 1);
    return result;
}