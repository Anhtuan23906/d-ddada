#include <stdio.h>
#include <math.h>

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod; 

    while (exp > 0) {
        
        if (exp & 1) { 
            res = (res * base) % mod;
        }

        
        base = (base * base) % mod;

        
        exp >>= 1; 
    }
    return res;
}

int main() {
    
    int a_base = 4;
    int n_exponent = 1000;
    int p_modulus = 9901;

    printf("Bai toan: (a_1000 + b_1000 + c_1000 + d_1000) mod 9901\n");
    printf("Theo cong thuc: S_n = (-4)^n.\n");
    printf("Ta can tinh: (-4)^%d mod %d = %d^%d mod %d\n", 
           n_exponent, p_modulus, a_base, n_exponent, p_modulus);

    
    long long result = power(a_base, n_exponent, p_modulus);

  
    printf("\n------------------------------------------------\n");
    printf("Ket qua cuoi cung:\n");
    printf("4^1000 mod 9901 = %lld\n", result);
    printf("------------------------------------------------\n");

    return 0;
}