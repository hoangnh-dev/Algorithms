class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int st0 = 0;
        int st1 = 0;
        for (int i: students){
            if(i == 0) st0++;
            else st1 ++;
        }

        for (int i: sandwiches){
            if(i == 0 && st0 > 0) st0--;
            else if(i == 1 && st1 > 0) st1 --;
            else return st0 + st1;
        }
        return st0 + st1;
    }
};