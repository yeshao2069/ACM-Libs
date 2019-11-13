#include <iostream>
using namespace std;
 
int main()
{
    int k, i, m, bad, p;
    int save[14] = {0};
    while(cin>>k && k != 0 && k < 14) {
        if(save[k] != 0) {
            cout<<save[k]<<endl;
            continue;
        }
        for(m = k;;m++) {
            i = 0;
            bad = 0;
            p = 2 * k;
            while(bad != k) {
                i += m;
                i %= p;
                if(i >= k) {
                    bad++;
                    p--;
                }
                else {
                    break;
                }
            }
            if(bad == k) {
                save[k] = m+1;
                break;
            }
        }
        cout<<save[k]<<endl; /*程序中题目的要求是1 2 3 ... n,代码从0开始的*/
    }
    return 0;
}