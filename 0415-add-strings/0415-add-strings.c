char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int i = len1 - 1;
    int j = len2 - 1;
    int maxLen = (len1 > len2) ? len1 : len2;
    int carry = 0;
    char teamp[(maxLen+2)];
    int index = 0;
    while(i >= 0 || j >= 0 || carry > 0){
        int sum = carry;
        if(i >= 0)sum += num1[i--] - '0';
        if(j >= 0)sum += num2[j--] - '0';
        teamp[index++] = (sum % 10) + '0';
        carry = sum / 10;
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