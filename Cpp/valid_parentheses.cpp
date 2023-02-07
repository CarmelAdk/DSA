#include <string>
#include <stack>  
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        string closed[3] = {")","}", "]"};
        string opened[3] = {"(","{","["};
        stack<string> mystack;
        int length = s.size();
        while(i < length)
        {
            string* target_ptr = std::find(closed, closed + 3, string(1, s[i]));
            if (target_ptr != closed + 3)
            {
                if(mystack.empty()){
                    return false;
                }
                else {
                    int index = std::distance(closed, target_ptr);
                    if (mystack.top() != opened[index]) {
                        return false;
                    }
                    else {
                        mystack.pop();
                    }
                }
            }
            else {
                mystack.push(string(1, s[i]));
            }
            i++;
        }
        return mystack.empty();
    }
};