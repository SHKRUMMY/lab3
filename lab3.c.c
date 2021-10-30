#include <stdio.h>
#include <math.h>
 
int main(){
    int arr[11];
    int num, key;
    printf("Type your number\n");
    scanf("%d ", &num);
    printf("Type the key-number 1-10:");
        scanf("%d ", &key);

    if (num == 0){
        printf("0\nYES, You are lucky!");
    }
    else
    {
        int lenOfarray = 0;
        while(num > 0){
            arr[lenOfarray] = num%10;
            num /= 10;
            lenOfarray ++;
        }
        // The number in array is inversed now(123->321). We are inversing the array
        int left = 0, right = lenOfarray - 1;
        while (left<right){
            //  a[l] and a[r] change their "places":
            // may a[l] = x, a[r] = y
            arr[left] += arr[right]; //  a[l] = (x+y)
            arr[right] = arr[left] - arr[right]; // a[r] = (x+y) - y = x
            arr[left] -= arr[right];// a[l] = (x+y) - x = y
            // Now a[l] = y, a[r] = x
 
            /// Go to next pair of symbols.
            left ++;
            right --;
        }
        int used[11] = {0}; // used[i] = 0, if the symbol with index i was not used yet used[i] = 1, if was used.
        int count = 0, new = 0, i = 0, j = 0;
        while(count < lenOfarray)
        {
            if (i == lenOfarray)
            {
                // if we "left" the array we come back
                i = 0;
            }
            if (used[i] == 0)
            {
                
                j ++;
                if (j % key == 0)
                {
                    //j-index of the number. If it %k==0 i->used 
                    new = new*10 + arr[i];
                    count ++;
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
