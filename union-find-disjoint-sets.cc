#define N 10

struct LSET{
    int p[N], rank[N], sz;
    void link(int x, int y) {
        if (x == y) return;
        if (rank[x] > rank[y]) p[y] = x;
        else p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
    }
    void makeset(int n) {
        sz = n;
        for (int i=0;i<sz;i++) {
            p[i] = i; rank[i] = 0; 
        }
    }
    int findset(int x) {
         if (x != p[x]) p[x] = findset(p[x]);
         return p[x];
    }
    void unin(int x, int y) {
         link(findset(x), findset(y));
    }
    void compress() {
       for (int i = 0; i < sz; i++) findset(i);
    }
};