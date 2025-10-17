
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
typedef __int128 i128;

ll modpow(ll a, long long e, ll mod) {
    a %= mod;
    if (a < 0) a += mod;
    ll res = 1 % mod;
    while (e > 0) {
        if (e & 1) res = (i128)res * a % mod;
        a = (i128)a * a % mod;
        e >>= 1;
    }
    return res;
}

int main(void) {
    char buf[1024];
    printf("Nhap chuoi A (cac ky tu, khong cach): ");
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    
    size_t len = strlen(buf);
    while (len > 0 && (buf[len-1] == '\n' || buf[len-1] == '\r')) {
        buf[--len] = '\0';
    }
    
    size_t start = 0;
    while (start < len && isspace((unsigned char)buf[start])) start++;
    size_t end = len;
    while (end > start && isspace((unsigned char)buf[end-1])) end--;
    if (start >= end) {
        printf("Loi: A rong.\n");
        return 0;
    }
    
    char A[512];
    int seen[256] = {0};
    size_t apos = 0;
    for (size_t i = start; i < end; ++i) {
        unsigned char c = (unsigned char)buf[i];
        if (!seen[c]) {
            A[apos++] = (char)c;
            seen[c] = 1;
        }
    }
    A[apos] = '\0';
    if (apos == 0) {
        printf("Loi: A rong sau khi loai tru.\n");
        return 0;
    }
    ll k = (ll)apos;
    printf("Da chuyen A thanh cac ky tu duy nhat: \"%s\"\n", A);
    printf("|A| = %lld\n", k);

    printf("Nhap n de tinh a_n = |A|^n (n >= 0): ");
    long long n;
    if (scanf("%lld", &n) != 1) return 0;
    if (n < 0) {
        printf("n phai khong am.\n");
        return 0;
    }

    
    int can_print_an = 1;
    i128 prod = 1;
    for (long long i = 0; i < n; ++i) {
        prod *= (i128)k;
        if (prod > (i128)LLONG_MAX) {
            can_print_an = 0;
            break;
        }
    }
    if (can_print_an) {
        ll an = (ll)prod;
        printf("a_%lld = %lld\n", n, an);
    } else {
        printf("a_%lld = %lld^%lld (rất lớn, không in trực tiếp)\n", n, k, n);
    }

    const ll MOD = 9901;
    ll a1000mod = modpow(k % MOD, 1000, MOD);
    printf("a1000 mod 9901 = %lld\n", a1000mod);

    
    const long long m = 100; 
    const int L = 10;
   
    i128 total = 1;
    for (int i = 0; i < L; ++i) total *= (i128)k;
    
    if (total < (i128)m) {
       
        if (total <= (i128)LLONG_MAX) {
            printf("S10 chi co %lld phan tu, khong co phan tu thu %lld.\n", (long long)total, m);
        } else {
            printf("S10 co it hon %lld phan tu (nhung con rat lon), khong co phan tu thu %lld.\n", m, m);
        }
    } else {
        
        long long idx = (long long)(m - 1);
        int digits[L];
        for (int i = 0; i < L; ++i) digits[i] = 0;
        long long tmp = idx;
        for (int pos = L - 1; pos >= 0; --pos) {
            digits[pos] = (int)(tmp % k);
            tmp /= k;
        }
        if (tmp != 0) {
            printf("Loi: m-1 >= k^L, khong the lay phan tu.\n");
        } else {
            char res[L+1];
            for (int i = 0; i < L; ++i) res[i] = A[digits[i]];
            res[L] = '\0';
            printf("Phan tu thu %lld cua S10 (theo thu tu tu dien) la: %s\n", m, res);
        }
    }

    return 0;
}