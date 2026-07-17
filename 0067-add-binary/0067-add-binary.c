char* addBinary(char* a, char* b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int i = len1 - 1;
    int j = len2 - 1;
    int maxLen = (len1 > len2) ? len1 : len2;
    int carry = 0;
    char teamp[(maxLen+2)];
    int index = 0;
    while(i >= 0 || j >= 0 || carry > 0){
        int sum = carry;
        if(i >= 0)sum += a[i--] - '0';
        if(j >= 0)sum += b[j--] - '0';
        teamp[index++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    char* result = malloc(index+1);
    index--;
    int left = 0;
    while(index>=0){
        result[left++] = teamp[index--];
    }
    result[left] = '\0';
    return result;
}