#include <bits/stdc++.h>
using namespace std;

#define BOLT ios_base::sync_with_stdio(0)
#define newline cout << "\n"
#define eline cerr << "\n"
#define LL_MAX 9223372036854775807
#define LL_MIN -9223372036854775808
#define PI acos(-1)
#define IN_FILE freopen("input.txt", "r", stdin)
#define OUT_FILE freopen("output.txt", "w", stdout)

// g++ -o contest contest.cpp


void USEFILE(){
    IN_FILE;
    OUT_FILE;
}



void solve(int kase){
    string s;
    getline(cin,s);
    int w;
    cin >> w;
    cin.ignore();
    

    vector<string>words;
    string temp = "";


    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == ' '){
            words.push_back(temp);
            if(temp.size() > w){
                cout << "Impossible\n";
                return;
            }
            temp = "";
        }else{
            temp += s[i];
        }
    }
    words.push_back(temp);


    string line = "";
    vector<string>ans;

    for(int i = 0 ; i < words.size(); i++){
        if(line.size() == 0){
            line+=words[i];
        }
        else if(line.size() + 1 + words[i].size() <= w){
            line += " " + words[i];
        }else{
            ans.push_back(line);
            line = words[i];
        }
    }
    ans.push_back(line);

    cout << "LEFT ALIGN: \n";
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i];
        newline;
    }
    newline;
    cout << "RIGHT ALIGN: \n";
    for(int i = 0 ; i < ans.size() ; i++){
        cout << setw(w) << ans[i];
        newline;
    }
    newline;



}

int main(){
    BOLT;
    USEFILE();
    int t, kase = 0;
    cin >> t;
    cin.ignore();
    while(t--)
         solve(++kase);
    // solve(0);

return 0;
}
