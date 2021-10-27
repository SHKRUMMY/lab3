#include <stdio.h>
#include <math.h>
 
int main(){
    int a[11];
    int n, k;
    printf("Type your number\n");
    scanf("%d ", &n);
    printf("Type the key-number 1-10:");
        scanf("%d ", &k);

    if (n == 0){
        printf("0\nYES, You are lucky!");
    }
    else
    {
        int lenOfN = 0;
        while(n > 0){
            a[lenOfN] = n%10;
            n /= 10;
            lenOfN ++;
        }
        // The number in array is inversed now(123->321). We are inversing the array
        int l = 0, r = lenOfN - 1;
        while (l<r){
            //  a[l] and a[r] change their "places":
            // may a[l] = x, a[r] = y
            a[l] += a[r]; //  a[l] = (x+y)
            a[r] = a[l] - a[r]; // a[r] = (x+y) - y = x
            a[l] -= a[r];// a[l] = (x+y) - x = y
            // Now a[l] = y, a[r] = x
 
            /// Go to next pair of symbols.
            l ++;
            r --;
        }
        int used[11] = {0}; // used[i] = 0, if the symbol with index i was not used yet used[i] = 1, if was used.
        int cnt = 0, new = 0, i = 0, j = 0;
        while(cnt < lenOfN)
        {
            if (i == lenOfN)
            {
                // if we "left" the array we come back
                i = 0;
            }
            if (used[i] == 0)
            {
                
                j ++;
                if (j % k == 0)
                {
                    //j-index of the number. If it %k==0 i->used 
                    new = new*10 + a[i];
                    cnt ++;
                    used[i] = 1;// is used
                }
            }
            i ++;
        }
        printf("Your new transformed number is %d\n", new);
        if (new%3 == 0) printf("YES, You are lucky!\n");
        else printf("NO, you are unlucky\n");
    }
    return 0;
}
