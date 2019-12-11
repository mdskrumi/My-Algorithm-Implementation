#include<bits/stdc++.h>
#include<ctype.h>
#include<string.h>

#include<stdio.h>

#define TAKING         freopen("input.txt" , "r" , stdin);
#define MAKING         freopen("output.txt","w" , stdout);

#define     ll         long long
#define     sf         scanf
#define     pf         printf
#define     pb         push_back
#define     mp         make_pair
#define     DOS        10000000000
#define     OO         0xfffffff
#define     nl         "\n"
#define     BOLT       ios_base::sync_with_stdio(0)

#define     all(x)     x.begin(), x.end()
#define     rall(x)    x.rbegin(), x.rend()
#define     fi         first
#define     se         second
#define     sz(v)      (int)(v).size()

using namespace std;

inline int ini(){int n;cin >> n;return n;}
inline ll inl(){ll n;cin >> n;return n;}
inline double ind(){double n;cin >> n;return n;}
inline string ins(){string n;cin >> n;return n;}
inline string insl(){string n;getline(cin,n);return n;}


inline int string_to_int(string s){int n;stringstream ss;ss << s;ss >> n;return n;}    // Same for double and long long
inline string int_to_string(int n){string s;stringstream ss;ss << n;ss >> s;return s;} // Same for double and long long
inline long long string_to_Long_Long(string s){ll res = 0;for(int i = 0 ; i < s.size() ; i++){res = res*10 + (s[i]-'0');}return res;}


vector<int>graph[200];
int parent[200];
int vis[200] = {0};
bool cycle = false;

void Find_Cycle(int u){
    vis[u] = 1;
    for(int i = 0 ; i < graph[u].size() ; i++){
        if(vis[graph[u][i]] == 0){
            parent[graph[u][i]] = u;
            Find_Cycle(graph[u][i]);
        }
        else if(vis[graph[u][i]] == 1 && parent[u] != graph[u][i]){
            cycle = true;
        }
    }
    vis[u] = 2;

}
int main(){
    BOLT;
    int node = ini() , edgeNum = ini();
    for(int i = 0 ; i < edgeNum ; i++){
        int u = ini() , v = ini();
        graph[u].pb(v);
        graph[v].pb(u);
    }
    Find_Cycle(0);
    if(cycle) cout << "Cycle Found\n";
    else cout << "Cycle Not Found\n";

return 0;
}





