   In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
  //CODE
Steps-
       1. two conditions here.
       2.if everyone are trust on one person and that person never trust on anyone so that person is know as judge.
       3. 0  means no trust ,1 means trust by everyone.
    
   /*

        Time Complexity:O(N) linear time
        Space Complexity:(N) linear space
        
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
		// indegree (in) = trusted by others
		// outdegree (out) = trust others
        vector<int> in(n + 1), out(n + 1);
		// calculate the in and out
        for (auto x : trust) in[x[1]]++, out[x[0]]++;
		// iterate each person
        for (int i = 1; i <= n; i++) {
			// the judge will be the one with indegree = n - 1 and outdegree = 0
            if (in[i] == n - 1 && out[i] == 0) {
				// found the judge
                return i;
            }
        }
        // cannot identify -> return -1
        return -1;
    }
};
