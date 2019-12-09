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

struct edge{
    int u , v , w;
    edge(int a , int b , int c){
        u = a;
        v = b;
        w = c;
    }
};

bool operator<(edge a , edge b){
    return a.w < b.w;
}

int parent[10000];
void init_parent(int n){for(int i = 0 ; i <=n ; i++) parent[i]=i;}
int find_parent(int n){return (parent[n] == n) ? n : find_parent(parent[n]);}

vector<edge>graph;
vector<edge>resultGraph;

int main(){
    BOLT;
    int t, n ,e;
    cin >> t ;
    while(t--){
        cin >> n >> e;
        for(int i = 0 ; i < e ; i++){
            int a , b , c;
            cin >> a >> b >> c;
            graph.pb(edge(a,b,c));
        }
        sort(graph.begin() , graph.end());
        init_parent(n);
        for(int i = 0 ; i < graph.size() ; i++){
            int p1 = find_parent(graph[i].u);
            int p2 = find_parent(graph[i].v);
            if(p1 != p2 ){
                parent[p2] = p1;
                resultGraph.pb(graph[i]);
            }
        }
        for(int i = 0 ; i < resultGraph.size() ; i++){
            cout << resultGraph[i].u << " " << resultGraph[i].v << " " << resultGraph[i].w << nl;
        }
        resultGraph.clear();
        graph.clear();
    }


return 0;
}












