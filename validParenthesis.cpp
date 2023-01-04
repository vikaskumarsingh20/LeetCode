class Solution {
public:
    bool isValid(string s) {
       
     stack<char>stack;
     // interate stack
     for(int i= 0 ;i<s.length() ;i++){
         int ch = s[i];
         //insert into stack
          if( ch =='(' || ch == '{' || ch == '['){
              stack.push(ch);
          }
          // already presented elements
         else{
             if(!stack.empty()){
                 char top = stack.top();
                 if((ch == ')' && top == '(') || 
                    ( ch == '}' && top == '{') || 
                    (ch == ']' && top == '[')){
                     stack.pop();
                 }
                 else
                     return false;
             }
             else 
                 return false;
         }
          
     }
    if(stack.empty())
        return true;
    else 
        return false;
    }

};

    // Hashing solutions 
    class Solution {
public:
	bool isPushAble(char c)
	{
		if ((c == '{') || (c == '(') || (c == '['))
		{
			return true;
		}
		else
			return false;
	}
	bool isValid(string s) {
		int sSize = (int)s.size();
		if (sSize == 0 || sSize == 1)
			return false;
		
		unordered_map<char, char> hash;
		hash['}'] = '{';
		hash[')'] = '(';
		hash[']'] = '[';
		stack<char> charStack;
		for (int i = 0; i < sSize; i++)
		{
			if (isPushAble(s[i]))
				charStack.push(s[i]);
			else
				
			{
				if (!charStack.empty()) {
					if (charStack.top() == hash[s[i]])
						charStack.pop();
					else
						return false;
				}
				else
					return false;
			}
		}
		if (charStack.empty())
			return true;
		else
			return false;
	}
};
