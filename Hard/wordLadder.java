                  //C++ CODE
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //bfs appraoch as level wise 
        //set also works
        unordered_set<string>s(wordList.begin(),wordList.end());//stores all word 
        queue<pair<string,int>>q;
        //push beginWord with step=1 in queue
        int step=1; 
        q.push({beginWord,step}); 
         //erase beginWord from set 
         s.erase(beginWord);
         
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second ; 
            q.pop();
            //see if end word found 
            if(word==endWord){
                return step;
            }
            for(int i=0;i<word.size();i++){
                char original = word[i] ; 

                //replace ch with a to z and see which word exist in set 
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    //see if word exist in set 
                    if(s.find(word)!=s.end()){
                        //it exist remove from set as found 
                        s.erase(word); 
                     /* we can return answer from here as well 
                        //see if end word found 
                     if(word==endWord){
                       return step+1; //counted this step as well
                     }
                     */
                        //push in queue with increment in step 
                        q.push({word,step+1});
                    }
                }
                //replace word[i] after we are done with changing it from a to z by original char which was there in it
            word[i] = original;   
            }
        }
        return 0;//if not found
    }
};




/*

                                  BFS  JACA CODE
Time Complexity: O(M2×N)O({M}^2 \times N)O(M^2×N), where MMM is the length of each word and NNN is the total number of words in the input word list.

Space Complexity: O(M2×N)O({M}^2 \times N)O(M^2×N).

*/
class Solution {
   public int ladderLength(String beginWord, String endWord, List<String> wordList) {
       //word is not contains return 0
        if (!wordList.contains(endWord)) return 0;
        HashMap<String, Boolean> visitedMap = new HashMap<String, Boolean>();
        // take hashmap and push all string in hashtable one by one an marked as false
       for(int i = 0; i <wordList.size(); i++)
            visitedMap.put(wordList.get(i), false);
       
        Queue<String> q = new LinkedList<String>();
        int length = 1;
        q.add(beginWord); // push beginWord
        visitedMap.put(beginWord, true);
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                String w = q.poll(); // pop beginWord and find all possbile
                if (w.equals(endWord)) 
                     return length; // if matched return it 
                wordMatch(w, visitedMap, q); //otherwise call function
            }
            length++;
        }
        return 0;
    }
    

    
    public void wordMatch(String w, HashMap<String, Boolean> visitedMap, Queue<String> q) {
        for (int i = 0; i < w.length(); i++) {
            char[] word = w.toCharArray(); // to convert string to char
            for (int j = 0; j < 26; j++) {
                char c = (char) ('a' + j);
                word[i] = c;
                String s = String.valueOf(word);
                if (visitedMap.containsKey(s) && visitedMap.get(s) == false) {
                    q.add(s);
                    visitedMap.put(s, true);
                }
            }
        }
    }
}
