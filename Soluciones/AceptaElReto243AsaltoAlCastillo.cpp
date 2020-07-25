#include <cstdio>
#include <cmath>
 
#define gc getchar_unlocked
 
using namespace std;
 
inline int readInt();
 
int main() {
    int num, count, i;
    double raiz;
 
    num = readInt();
 
    while (num > 0) {
        if (num > 3) {
            i = 2;
            count = 2;  //Todo numero es divisible por si mismo y por 1
 
            raiz = sqrt(num);
            if (raiz == floor(sqrt(num))) count++;
 
            for (i; i < raiz; i++)
                if (num % i == 0) count += 2;
 
            printf("%i\n", count);
        } else if (num > 1) printf("2\n"); //num == 2, 3
        else printf("1\n"); // num == 1
 
        num = readInt();
    }
 
    return 0;
}
 
int readInt() {
    char ch = gc();
    int num = 0;
 
    while (ch < '0' || ch > '9') ch = gc();
 
    while (ch >= '0' && ch <= '9') {
        num = 10 * num + ch - 48;
        ch = gc();
    }
 
    return num;
}
