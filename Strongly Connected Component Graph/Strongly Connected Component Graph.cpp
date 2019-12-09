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

inline int checkprime(int n){
    if(n < 2)return 0;
    for(int i = 2 ; i <= sqrt(n) ; i++){
        if(n%i==0)return 0;
    }
return 1;
}


inline int getLeapYear(int year){
  if ( year%400 == 0)return 1;
  else if ( year%100 == 0)return 0;
  else if ( year%4 == 0 )return 1;
  return 0;
}


inline int getDaysInYear(int y){
    if(getLeapYear(y)){
        return 366;
    }return 365;
}


inline int getDaysInMonth(int m , int y){
    if(m == 11 || m == 4 || m == 6 || m == 9)
        return 30;
    if(m == 2 )
        return 28 + getLeapYear(y);
    return 31;
}

string getBinaryFromDecimal(int n){
    string s = "";
    while(n!=0){
        s += (char)( n%2 + 48 ) ;
        n/=2;
    }
    return s;
}

inline string delSpaces(string &str){
   str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
   return str;
}

inline int ini(){int n;cin >> n;return n;}
inline ll inl(){ll n;cin >> n;return n;}
inline double ind(){double n;cin >> n;return n;}
inline string ins(){string n;cin >> n;return n;}
inline string insl(){string n;getline(cin,n);return n;}


inline int string_to_int(string s){int n;stringstream ss;ss << s;ss >> n;return n;}    // Same for double and long long
inline string int_to_string(int n){string s;stringstream ss;ss << n;ss >> s;return s;} // Same for double and long long


inline long long string_to_Long_Long(string s){ll res = 0;for(int i = 0 ; i < s.size() ; i++){res = res*10 + (s[i]-'0');}return res;}


vector<int>graph[100];
vector<int>regraph[100];
vector<int>SSC[100];
int vis[100];
int revis[100];
stack<int>stk;


void clean(int node){
    for(int i = 0 ; i < node ; i++){
        graph[i].clear();
        regraph[i].clear();
        SSC[i].clear();
        vis[i] = -1;
        revis[i] = -1;
    }
}
void getSSC(int u , int s){
    revis[u] = 1;
    for(int i = 0 ; i < regraph[u].size() ; i++){
        if(revis[regraph[u][i]] == -1)
            getSSC(regraph[u][i] , s);
    }
    revis[u] = 2;
    SSC[s].pb(u);
}
void dfs(int u){
    vis[u] = 1;
    for(int i = 0 ; i < graph[u].size() ; i++){
        if(vis[graph[u][i]] == -1)
            dfs(graph[u][i]);
    }
    vis[u] = 2;
    stk.push(u);
}
int main(){
    int node , edge, u , v;
    sf("%d%d",&node,&edge);
    clean(node);
    for(int i = 0 ; i < edge ; i++){
        sf("%d%d",&u,&v);
        graph[u].pb(v);
        regraph[v].pb(u);
    }
    for(int i = 0 ; i < node ; i++){
        if(vis[i] == -1){
            dfs(i);
        }
    }
    int numofssc = 0;
    while(!stk.empty()){
        int u = stk.top();
        if(revis[u] == -1){
            getSSC(u , numofssc);
            numofssc++;
        }
        stk.pop();
    }


    for(int j = 0 ; j < numofssc ; j++){
            cout << "NUMBER : " << j+1 << " : ";
        for(int k = 0 ; k < SSC[j].size() ; k++){
            cout << SSC[j][k] << " ";
        }cout << endl;
    }

return 0;
}





