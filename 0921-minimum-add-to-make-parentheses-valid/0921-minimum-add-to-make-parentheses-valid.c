int minAddToMakeValid(char* s) {
    int a = 0;
    int b = 0;
    for(int i = 0; s[i] !='\0'; i ++){
        if (s[i] == '(') a++;
        if (s[i] == ')') {
            if (a > 0){
                a--;
            }else{
                b++;
            }
            
        }
    }
    return a+b;
}