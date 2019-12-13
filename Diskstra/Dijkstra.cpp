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
inline long long string_to_Long_Long(string s){ll res = 0;for(int i = 0 ; i < s.size() ; i++){res = res*10 + (s[i]-'0');}return res;}

typedef vector <int> 	   	 vi;
typedef pair <int,long long> 	pii;

vector<pair<int ,long long> >graph[100000+5];
long long cost[100000+5];
int parent[100000+5];

void clean(int n){
    for(int i = 0 ; i <= n ; i++){
        graph[i].clear();
        cost[i] = INT_MAX;
        parent[i] = i;
    }
}

void dijkstra(int s){
    cost[s] = 0;
    priority_queue< pii , vector<pii> , greater<pii> >q;
    q.push({0,s});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        for(int i = 0 ; i < graph[u].size() ; i++){
            if(cost[graph[u][i].first] > cost[u] + graph[u][i].second){
                cost[graph[u][i].first] = cost[u] + graph[u][i].second;
                q.push({cost[graph[u][i].first],graph[u][i].first});
                parent[graph[u][i].first] = u;
            }
        }
    }
}

stack<int> get_road_from(int d){
    stack<int>road;
    road.push(d);
    while(parent[d] != d){
        d = parent[d];
        road.push(d);
    }
return road;
}

int main(){
    BOLT;
    int n = ini(), m = ini();
    clean(n);
    for(int i = 0; i < m ;i++){
        int u = ini() , v = ini() , w = ini();
        graph[u].pb({v,w});
        graph[v].pb({u,w});
    }

    int source = ini() , destination = ini();
    dijkstra(source);

    if(cost[destination]==INT_MAX){
        cout << "Not Visited From The Given Source" << nl;
    }
    else {
        stack<int> road = get_road_from(destination);
        while(!road.empty()){
            if(road.size()==1){
                cout << road.top();
            }else
            cout << road.top()<< " ";
            road.pop();
        }
    }
return 0;
}



