int ch[32*N][2];
long long val[32*N];
int sz;

void init(){
    memset(ch[0],0,sizeof(ch[0]));
    sz=1;
}

void inst(long long a){
    int u=0;
    for(int i=32;i>=0;i--){
        int c=((a>>i)&1);
        if(!ch[u][c]){
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz]=0;
            ch[u][c]=sz++;
        }
        u=ch[u][c];
    }
    val[u]=a;
}
long long query(long long a){
    int u=0;
    for(int i=32;i>=0;i--){
        int c=((a>>i)&1);
        if(ch[u][c^1]) u=ch[u][c^1];
        else u=ch[u][c];
    }
    return val[u];
}