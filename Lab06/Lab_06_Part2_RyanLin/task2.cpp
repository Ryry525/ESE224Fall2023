#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

string longestCommonPrefix(vector<string>& strs){
    if (strs.empty()){
        return "";
    }
    int minLen = INT_MAX;
    for(const string& str : strs){
        minLen = min(minLen, static_cast<int>(str.size()));
    }
    for (int i =0; i < minLen; ++i){
        char sameChar = strs[0][i];
        for (const string& str : strs){
            if ( str[i] != sameChar){
                return str.substr(0,i);
            }
        }
    }
    return strs[0].substr(0,minLen);
}

int main(){
    vector<string> strs;
    string str;
    cout << "Enter strings (press Enter on empty line to stop): ";
    while (true){
        getline(cin, str);
        if(str.empty()){
            break;
        }
        strs.push_back(str);
    }
    if(strs.empty()){
        cout << "No input strings provided." <<endl;
    }
    else{
        string commonPrefix = longestCommonPrefix(strs);
        cout << "Longest Common Prefix: " << commonPrefix << endl;
    }
    return 0;
}