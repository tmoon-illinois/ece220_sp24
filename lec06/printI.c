#include <stdio.h>

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);


    // row = i, col = j
    int i, j;

    for(i= 0; i < n; i++    ){
        for(j=0; j< n; j++){
            if( i==j){
                printf("1 ");
                if(j==1)
                    break;
            }
            else
                printf("0 ");
        }
        printf("\n");
        if ( i==1  )
            break;
    
    }

    return 0;
}
