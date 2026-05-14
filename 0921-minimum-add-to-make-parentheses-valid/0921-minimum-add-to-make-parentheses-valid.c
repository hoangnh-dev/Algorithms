int minAddToMakeValid(char* s) {
    int len = strlen(s);
    int op = 0;
    int cl = 0;
   
    if(len == 0) return 0;
    for(int i =0; i <len; i++){
        if(s[i] == '('){
            op++;
        }else{
            if (op > 0){
                op--;
            }else {
                cl ++;
            }
            
        }
    }
    return abs(op + cl);
}