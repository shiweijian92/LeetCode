/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRepeatedDnaSequences(char*s, int* returnSize)
{
    int size = strlen(s);
    if(size < 11) return NULL; //at least 11 letters;
    int hashTable[1 << 20] = {0}; //allocate a hash map array for 20-bit key;
    int hashNum = 0;
    int index = 0;
    char** sArray = (char**)malloc(sizeof(char*) * size);
    
    for(int i = 0; i < 9; i++) //the head of the first key;
        hashNum = hashNum << 2 | (*(s+i) - 'A' + 1) % 5;
    for(int i = 9; i < size; i++) //one step forward, one different string will be covered by the key simply;
    {
        if(hashTable[hashNum = (hashNum << 2 | (*(s+i) - 'A' + 1) % 5) & 0x000fffff]++ == 1) //each repeated substring will only be collected once;
        {
            sArray[index] = (char*)malloc(11 * sizeof(char));
            strncpy(sArray[index], s+i-9, 10);
            sArray[index++][10] = '\0';
        }
    }
    *returnSize = index;
    return sArray;
}