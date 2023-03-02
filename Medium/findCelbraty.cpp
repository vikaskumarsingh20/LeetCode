 Algorithm
Set the candidate res to 0. The principle is to traverse once. For the traversed person i, if the candidate res knows i, set the candidate res to i. After completing the traversal, check whether the candidate res is really a celebrity, if it is found not to be a celebrity, return -1, if there is no conflict, return res.

It can also further reduce the amount of API calls. The method of finding candidates is the same as above, but it is divided into two sections when verifying.

First verify everyone in front of the candidate. If the candidate knows anyone, or anyone does not know the candidate, return -1 directly.
Then verify the people behind the candidate. At this time, you only need to verify whether anyone does not know the candidate.
Because we have ensured that the candidate will not know anyone before candidate


   TIME COMPLEXITY:(n)
   SPACE COMPLEXITY:(1)
//code
bool knows(int a, int b);
class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (knows(res, i)) res = i;
        }
        for (int i = 0; i < n; ++i) {
            if (res != i && (knows(res, i) || !knows(i, res))) return -1;
        }
        return res;
    }
};
