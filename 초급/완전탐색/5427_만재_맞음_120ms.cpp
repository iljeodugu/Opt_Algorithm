#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
int fire[1001][1001];
int d[1001][1001];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int main() {
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        int w, h;
        cin >> w >> h;
        vector<string> a(h);
        for (int i=0; i<h; i++) {
            cin >> a[i];
        }
        
        memset(fire,-1,sizeof(fire));
        queue<pair<int,int> > q;
        int sy,sx;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (a[i][j] == '*') {    //fire
                    q.push(make_pair(i,j));
                    fire[i][j] = 0;
                } else if (a[i][j] == '@') {    //상근 위치
                    sy = i;
                    sx = j;
                } 
            }
        }

        //fire에 불이 퍼지는 거리 저장
        while(!q.empty()){
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int ny=y+dy[k];
                int nx=x+dx[k];
                if(0<=ny && ny<h && 0<=nx && nx<w){
                    if(fire[ny][nx]!=-1)    continue;
                    if(a[ny][nx]=='#')  continue;
                    if(a[ny][nx]=='@')  continue;
                    fire[ny][nx]=fire[y][x]+1;
                    q.push(make_pair(ny,nx));
                }
            }
        }

        //-1로 초기화
        memset(d, -1, sizeof(d));
        q.push(make_pair(sy,sx));
        d[sy][sx]=0;

        //불이 퍼지는 시간이 저장된 fire를 기반으로 상근이가 갈 수 있는 칸마다 시간을 기록
        while(!q.empty()){
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int ny=y+dy[k];
                int nx=x+dx[k];
                if(0<=ny && ny<h && 0<=nx && nx<w){
                    if(d[ny][nx]!=-1)   continue;
                    if(a[ny][nx]=='#')  continue;
                    if(fire[ny][nx]!=-1 && d[y][x]+1>=fire[ny][nx]) continue;
                    //불이 퍼지는 시간보다 크다면 pass
                    d[ny][nx]=d[y][x]+1;
                    q.push(make_pair(ny,nx));
                }
            }
        }
        
        //d에는 상근이가 갈수있는 칸과 시간이 기록되어있음
        //테두리에서 -1에서 갱신이 안되었다면 IMPOSSIBLE
        //갱신되었다면 최소값을 찾는다.
        int ans=1000000000;
        bool ok=false;

        for(int i=0;i<w;i++){
            if(d[0][i]!=-1){
                ok=true;
                break;
            }
        }
        for(int i=0;i<w;i++){
            if(d[h-1][i]!=-1){
                ok=true;
                break;
            }
        }
        for(int i=0;i<h;i++){
            if(d[i][0]!=-1){
                ok=true;
                break;
            }
        }
        for(int i=0;i<h;i++){
            if(d[i][w-1]!=-1){
                ok=true;
                break;
            }
        }
        if(ok==false){
            cout<<"IMPOSSIBLE"<<'\n';
        }else{
            for(int i=0;i<w;i++){
                if(d[0][i]!=-1){
                    if(ans>d[0][i]) ans=d[0][i];
                }
            }
            for(int i=0;i<w;i++){
                if(d[h-1][i]!=-1){
                    if(ans>d[h-1][i])   ans=d[h-1][i];
                }
            }
            for(int i=0;i<h;i++){
                if(d[i][0]!=-1){
                    if(ans>d[i][0]) ans=d[i][0];
                }
            }
            for(int i=0;i<h;i++){
                if(d[i][w-1]!=-1){
                    if(ans>d[i][w-1])   ans=d[i][w-1];
                }
            }
            cout<<ans+1<<'\n';
        }

    }
    return 0;
}
