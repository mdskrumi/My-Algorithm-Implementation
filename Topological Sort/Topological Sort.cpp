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

vector<int>graph[200+5];
int visited[200+5];
stack<int>sorted_graph;

void clean(int n){
    for(int i = 0 ; i < n ; i++){
        graph[i].clear();
        visited[i] = 0;
        if(!sorted_graph.empty()){
            sorted_graph.pop();
        }
    }
}
void topSort(int u){
    visited[u] = 1;
    for(int v = 0 ; v < graph[u].size() ; v++){
        if( visited[graph[u][v]] == 0 ){
                topSort(graph[u][v]);
        }
    }
    sorted_graph.push(u);
}

int main(){
    BOLT;
    int t = ini(), n = ini(), m = ini();
    clean(n);
    for(int i = 0 ; i < m ; i++)
        graph[ini()].pb(ini());

    for(int i = 1 ; i <= n ; i++)
        if(visited[i]==0)
            topSort(i);

    while(!sorted_graph.empty()){
        cout << sorted_graph.top() << " " ;
        sorted_graph.pop();
    }

return 0;
}

