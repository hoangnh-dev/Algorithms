int lengthOfLastWord(char* s) {
   int len = strlen(s);
   int count = 0;
   for(int i = len-1; i>=0 ; i --) {
        if (s[i] == ' ' && count >0) break;
        else if(s[i] != ' ') count++;
   }
   return count;
}