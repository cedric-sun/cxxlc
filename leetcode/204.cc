// cesun, 9/22/20 10:43 PM.


#define MAXN 1'500'000
static bool isNotPrime[MAXN]; // thank you .bss
static int prime[MAXN / 10]; // 105097565/(1<<31) = 0.0489
static int nPrime;

static int nPrimeLT[MAXN + 1];

void linear_sieve()  __attribute__((constructor));

void linear_sieve() {
    for (int i = 2; i < MAXN; ++i) {
        nPrimeLT[i + 1] = nPrimeLT[i];
        if (!isNotPrime[i]) {
            prime[nPrime++] = i;
            nPrimeLT[i + 1]++;
        }
        int k;
        for (int j = 0; j < nPrime && (k = i * prime[j]) < MAXN; ++j) {
            isNotPrime[k] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

class Solution {
public:
    int countPrimes(int n) {
        return nPrimeLT[n];
    }
};
