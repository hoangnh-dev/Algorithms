char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    int count = 0;
    char* result = malloc((n + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (count > 0){
                result[index++] = s[i];
            }
            count ++;
        } else if (s[i] == ')') {
            count --;
            if (count > 0){
                result[index++] = s[i];
            }
        }
    }
    result[index] = '\0';
    return result;
}