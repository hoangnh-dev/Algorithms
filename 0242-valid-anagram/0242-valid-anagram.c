

bool isAnagram(char* s, char* t) {
    int count[26] = {0};
    int len = 0;
    while(*s){
        count[*s - 'a']++;
        len++;
        s++;
    }
    while(*t){
        count[*t - 'a']--;
        len--;
        if (count[*t - 'a'] < 0) return false;
        t++;
    }
    return len == 0;
}