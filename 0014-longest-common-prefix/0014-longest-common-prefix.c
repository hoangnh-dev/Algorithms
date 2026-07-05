char* commonPrefix(char* c1,char* c2){
    int i = 0;
    while(c1[i] != '\0' && c2[i] != '\0'){
        if (c1[i] == c2[i]) i++;
        else break;
    }
    c1[i] = '\0';
    return c1;
}
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0) return "";
    char* result = strs[0];
    for(int i = 1; i <strsSize;i++){
        result = commonPrefix(result,strs[i]);
        if(result[0] == '\0') break;
    }
    return result;
}