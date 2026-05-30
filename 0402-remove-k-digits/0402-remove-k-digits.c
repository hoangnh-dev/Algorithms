char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    if (len == k) return "0";
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = 0;
    for (int i = 0; i < len; i++) {
        while (top > 0 && k > 0 && stack[top - 1] > num[i]){
            top--;
            k--;
        }
        stack[top++] = num[i];
    }
    top -= k;
    int start = 0;
    while (start < top && stack[start] == '0') {
        start++;
    }
    if (start == top) return "0";
    stack[top] = '\0';
    return stack+start;
}