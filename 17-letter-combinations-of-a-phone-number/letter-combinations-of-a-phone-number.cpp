class Solution {
public:
    vector<string> ans;
    unordered_map<char , string > ump ;
    
    void solver(string s , int ind ,int end , string digits){
        if(ind >=end){
            ans.push_back(s);
            return;
        }
    
        for(auto j :ump[digits[ind]]){
            s+=j;
            solver(s,ind+1,end,digits);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        // if(digits.size() ==1){
        //     for(auto i:ump[digits[0]]){ 
        //         string s="";
        //         s+=i;
        //         ans.push_back(s);
        //     }
        //     return ans;
        // }
        ump['2'] = "abc";
        ump['3'] = "def";
        ump['4'] = "ghi";
        ump['5'] = "jkl";
        ump['6'] = "mno";
        ump['7'] = "pqrs";
        ump['8'] = "tuv";
        ump['9'] = "wyxz";
        solver("" , 0 ,digits.size() ,digits );
        return ans;
    }
};