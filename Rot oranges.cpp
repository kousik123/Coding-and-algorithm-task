#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
int arr[101][101];
int v[101][101];
int l[101][101];
bool safe(int x,int y,int n,int m){
    return x>=0 && x<n && y>=0 && y<m;
}
void bfs(queue< pair<int,int> >Q,int n,int m){
    int row[]={-1,0,0,1};
    int col[]={0,-1,1,0};
    while(!Q.empty()){
        auto p=Q.front();
        Q.pop();
        for(int k=0;k<4;k++){
            if(safe(p.first+row[k],p.second+col[k],n,m) && v[p.first+row[k]][p.second+col[k]]==0 && arr[p.first+row[k]][p.second+col[k]]==1){
                Q.push(make_pair(p.first+row[k],p.second+col[k]));
                v[p.first+row[k]][p.second+col[k]]=1;
                l[p.first+row[k]][p.second+col[k]]=l[p.first][p.second]+1;
                arr[p.first+row[k]][p.second+col[k]]=arr[p.first][p.second]+1;
            }
        }
    }
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n,m,i,j;
        int toranges = 0, roranges = 0;
        memset(v,0,sizeof(v));
        memset(l,0,sizeof(l));
        queue< pair<int,int> >Q;
        cin>>n>>m;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j] > 0)
                    toranges++;
            }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(v[i][j]==0 && arr[i][j]==2){
                    Q.push(make_pair(i,j));
                    v[i][j]=1;
                }
            }
        }
        bfs(Q,n,m);
        int f=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(v[i][j]==0 && arr[i][j]==1){
                    f=1;
                    
                    break;
                }
                
            }
            if(f==1)
                    break;
        }

        int maxx=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(l[i][j]>maxx)
                {
                    maxx=l[i][j];
                }
                if(v[i][j] > 0)
                {
                    roranges++;
                }

               
            }
           
        }

        cout<<"time frame : "<<maxx<<endl;
        cout<<"fresh oranges : "<<toranges-roranges<<endl;
        cout<<"rotten oranges : "<<roranges<<endl;

       
    }
    return 0;
}
