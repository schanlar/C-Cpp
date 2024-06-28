#include <stdio.h>

void fοο(int a){
    if (a == 0){
        return;
    }
    a+=1;
    printf("%d\n",a);
    fοο(a);
}

int main(){
    int x = 5;
    fοο(x);
    return 0;
}