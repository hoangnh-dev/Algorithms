int strStr(char* haystack, char* needle) {
    int lenH = strlen(haystack);
    int lenN = strlen(needle);
    for(int i = 0; i <= lenH - lenN; i++){
        int j = 0;
         while (j < lenN && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == lenN) {
            return i;
        }
    }
    return -1;
}