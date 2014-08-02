#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned int LL;

int N, S1, S2;
const int maxn = 32;

LL mat1[maxn], mat2[maxn], mat[maxn];

LL bitcnt[1<<17];

inline void prt(LL mat[], int n, int m) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            printf("%d ", !!(mat[i] & (1U<<j)));
        }
        cout << endl;
    }
}

void multi(LL a[], LL b[], LL c[], int n) {
    static LL res[maxn], _b[maxn];

    memset(res, 0, sizeof(res));
    memset(_b, 0, sizeof(_b));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            _b[j] |= (LL)(!!(b[i] & (1U<<j))) << i;
        }
    }
    //prt(_b, n, n);
    //prt(b, n, n);
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            LL m = a[i] & _b[j];
            res[i] |= (bitcnt[m & ((1U<<16) - 1U)] ^ bitcnt[m >> 16]) << j;
        }
    }
    for (int i = 0;i < n;i++) {
        c[i] = res[i];
    }
}

inline void prt2(LL m, int n) {
    for (int i = 0;i < n;i++) {
        printf("%d ", !!(m & (1<<i)));
    }
    cout << endl;
}


inline LL gaosi(LL a[maxn], int n) {
    LL static m[maxn];
    for (int i = 0;i < n;i++) {
        m[i] = a[i];
    }
    for (int i = 0;i < n;i++) {
        for (int j = i;j < n;j++) {
            if (m[j] & (1U<<i)) {
                swap(m[i], m[j]);
                break ;
            }
        }
        for (int j = 0;j < n;j++) if (i != j && (m[j] & (1U<<i))) {
            m[j] ^= m[i];
        }
    }
    
    LL res = 0;
    for (int i = 0;i < n;i++) {
        res |= (LL)(!!(m[i] & (1U<<n))) << i;
    }
    return res;
}

int main() {
    for (int m = 0;m < (1<<17);m++) {
        bitcnt[m] = 0;
        for (int t = m;t;t >>= 1) {
            bitcnt[m] ^= t & 1;
        }
    }
    while (~scanf("%d%d%d", &N, &S1, &S2)) {
        memset(mat1, 0, sizeof(mat1));
        memset(mat2, 0, sizeof(mat2));
        mat1[0] |= 1<<0;
        mat2[0] |= 1<<0;
        for (int i = 1;i <= N-1;i++) {
            mat1[i] |= 1U<<(i+1);
        }
        for (int i = 1;i <= N;i++) {
            mat2[i] |= 1U<<i;
        }
        for (int i = 0;i < S1;i++) {
            int s1;
            scanf("%d", &s1);
            mat1[N] |= 1U<<s1;
        }
        for (int i = 0;i < S2;i++) {
            int s2;
            scanf("%d", &s2);
            mat2[s2] |= 1U<<0;
        }
        multi(mat2, mat1, mat, N+1);
        LL s = 1, t = 1;
        for (int i = 1;i <= N;i++) {
            LL c;
            scanf("%u", &c);
            s |= c<<i;
        }
        for (int i = 1;i <= N;i++) {
            LL c;
            scanf("%u", &c);
            t |= c<<i;
        }
        map<LL, LL>hash;
        int n1 = N/2, n2 = N - N/2;
        LL curr = s;
        for (int i = 0;i < (1<<n2);i++) {
        //    prt2(curr, N+1);
            if (hash.find(curr) == hash.end()) {
                hash[curr] = i;
            }
            LL next = 0;
            for (int i = 0;i <= N;i++) {
                for (int j = 0;j <= N;j++) {
                    next ^= (LL)(!!(mat[i]&curr&(1U<<j))) << i;
                }
            }
            curr = next;
        }
        static LL pw[maxn];
        memset(pw, 0, sizeof(pw));
        for (int i = 0;i <= N;i++) {
            pw[i] = mat[i];
        }
        for (int i = 0;i < n2;i++) {
            multi(pw, pw, pw, N+1);
        }
        static LL ip[maxn];
        memset(ip, 0, sizeof(ip));
        for (int i = 0;i <= N;i++) {
            ip[i] |= 1U<<i;
        }
        LL ans = ~0U>>1;
        for (int i = 0;i <= (1<<n1);i++) {
            for (int j = 0;j <= N;j++) {
                ip[j] ^= ip[j] & (1U<<(N+1));
            }
            for (int j = 0;j <= N;j++) {
                ip[j] |= (LL)(!!(t & (1U<<j))) << (N+1);
            }
            LL ask = gaosi(ip, N + 1);
            if (hash.find(ask) != hash.end()) {
                ans = min((LL)ans, (LL)((1U<<n2)*i + hash[ask]));
            }
            multi(ip, pw, ip, N+1);
        }
        if (ans < (LL)(~0U>>1)) {
            printf("%u\n", ans);
        } else {
            puts("poor sisyphus");
        }
    }
    return 0;
}
