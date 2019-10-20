#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

bool DEBUG = true;

int longestSubstring(string s, int k) {
    if(k == 1) return s.size();

    unordered_map<char, int> map;
    int toFix = 0;
    int index = 0;

    for(int i = 0; i < s.size(); ++i){
        char c = s.at(i);
        if(DEBUG) cout<<"char: "<<c<<endl;
        if(map.find(c) != map.end()){
            if(DEBUG) cout<<"char found: "<<map.at(c) + 1<<endl;
            ++map.at(c);
            if(map.at(c) == k){
                --toFix;
                if(DEBUG) cout<<"toFix--: "<<toFix<<endl;
            }
            if(toFix == 0){
                if(DEBUG) cout<<"toFix == 0, index = "<<i+1<<endl;
                index = i+1;
            }
        } else {
            if(DEBUG) cout<<"inserting char"<<endl;
            map.insert({c, 1});
            ++toFix;
            if(DEBUG) cout<<"++toFix: "<<toFix<<endl;
        }
    }

    return index;
}

int main(){
    cout<<longestSubstring("ababbc", 2)<<endl;
    cout<<endl<<longestSubstring("a", 1)<<endl;
    cout<<endl<<longestSubstring("bbaaacbd", 3)<<endl;
}