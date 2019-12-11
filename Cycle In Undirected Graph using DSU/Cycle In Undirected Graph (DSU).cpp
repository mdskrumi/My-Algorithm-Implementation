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


struct Edge{
    int u , v;
};
Edge edges[200];
int parent[200];

int find_Parent(int i){
    if(parent[i] == i)
        return i;
    return find_Parent(parent[i]);
}

void Find_Cycle(int node , int edgeNum ){

    for(int i = 0 ; i < node ; i++){
        parent[i] = i;
    }

    for(int i = 0 ; i < edgeNum ; i++){
        int p1 = find_Parent(edges[i].u);
        int p2 = find_Parent(edges[i].v);
        if(p1 == p2){
            cout << "Cycle Detected!\n";
            return;
        }
        parent[p2] = p1;
    }

    cout << "No Cycle Detected!\n";
}


int main(){
    BOLT;
    int node = ini() , edgeNum = ini();
    for(int i = 0 ; i < edgeNum ; i++){
        edges[i].u = ini();
        edges[i].v = ini();
    }
    Find_Cycle(node,edgeNum);

return 0;
}





