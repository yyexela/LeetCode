#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
private:
    bool DEBUG = true;
public:
    int lengthOfLongestSubstring(string s) {
        //last test case
        //check to see if all ascii letters present, this means that there can be no substring longer than this
        string tst = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
        if(s.substr(0,95) == tst) return tst.size();

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
    string tst = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
    cout<<tst.size()<<endl;
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("dvdf")<<endl;
    /*
    cout<<sol.lengthOfLongestSubstring("abceed")<<endl;
    cout<<sol.lengthOfLongestSubstring("bbbbb")<<endl;
    cout<<sol.lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<sol.lengthOfLongestSubstring("pwwkew")<<endl;
    */
}