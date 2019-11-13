#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
    return(*(int *)a-*(int *)b);
    }
int main(){
    char str[100];
    int num[26]={2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};
    int n, a[100005], l, sum, i, k, flag, t, s, j, p;
    scanf("%d", &n);
    getchar();
    k = 0;
    while (k!=n){
        gets(str);
        l = strlen(str);
        sum = 0;
        for (i=0; i<l; i++){
            if (str[i]>= '0' && str[i] <= '9'){
                sum = sum*10 + str[i]-'1'+1;
                continue;
            }
            if (str[i]>='A' && str[i]<='Z'){
                if (str[i] == 'Q' || str[i] == 'Z') continue;
                sum = sum * 10 + num[str[i]-'A'];
            }
        }
        a[k] = sum;
        k++;
    }
    a[k] = -1;
    qsort(a, k, sizeof(a[0]), cmp);
    t = a[0];
    flag = 0;
    i = 1;
    s = 1;
    while (i!=k+1){
        if (t == a[i]){
            s++;
            flag = 1;
        }else {
            if (s>1){
                p = 1000000;
                for(j=1; j<=3; j++){
                    printf("%d", t/p);
                    t = t%p;
                    p = p/10;
                }
                printf("-");
                
                p = 1000;
                for (j=1; j<=4; j++){
                    printf("%d", t/p);
                    t = t%p;
                    p = p/10;
                }
                printf(" %d\n", s);
            }
            t = a[i];
            s=1;
        }
        i++;
    }
    if (flag == 0){
        printf("No duplicates.\n");
    }
    return 0;
}