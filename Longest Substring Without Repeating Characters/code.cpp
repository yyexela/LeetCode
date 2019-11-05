#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
private:
    bool DEBUG = true;
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int max = 0;
        int count = 0;

        while(s.size() > max){
            for(int i = 0; i < s.size(); ++i){
                if(DEBUG) cout<<"Adding: "<<s[i]<<endl;
                auto search = map.find(s[i]);
                if(search != map.end()){
                    // size: i - index
                    if(DEBUG) cout<<"Found "<<s[i]<<" twice"<<endl;
                    if(max < count) max = count;
                    count = 0;
                    map.clear();
                }
                map.insert({s[i],i});
                ++count;
            }
            if(max < count) max = count;
            if(DEBUG) cout<<"Stepping string"<<endl;
            //reset
            map.clear();
            count = 0;
            s = s.substr(1);
            if(DEBUG) cout<<"New str: "<<s<<endl;
        }
        return max;
    }
};

int main(){
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("dvdf")<<endl;
    /*
    cout<<sol.lengthOfLongestSubstring("abceed")<<endl;
    cout<<sol.lengthOfLongestSubstring("bbbbb")<<endl;
    cout<<sol.lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<sol.lengthOfLongestSubstring("pwwkew")<<endl;
    */
}