class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int rBan = 0, dBan = 0;
        int rCount = 0, dCount = 0;
        for (char c : senate) {
            q.push(c);
            if (c == 'R') rCount++;
            else dCount++;
        }
        while (rCount > 0 && dCount > 0) {
            char c = q.front();
            q.pop();
            if (c == 'R') {
                if (rBan > 0) {
                    rBan--;
                    rCount--;
                    continue;
                }
                dBan++;
                q.push(c);
            } else {
                if (dBan > 0) {
                    dBan--;
                    dCount--;
                    continue;
                }
                rBan++;
                q.push(c);
            }
        }

        if (rCount > 0) return "Radiant";
        else return "Dire";
    }
};