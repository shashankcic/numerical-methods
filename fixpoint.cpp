//Fixed Point Method to find the roots of a polynomial.
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;

float fun(float [], int, float );

int main()
{

    double total_time;
    clock_t start, end;

    float a; //initial value 
    float c; //root value

    int o[2]; //order of the polynomial,

    bool found=false;
    int res=0;
    int count=0;
    int n;

    printf("Enter order of the polynomial in numerator\n");
    scanf("%d",&o[0]);

    printf("Enter order of the polynomial in denominator\n");
    scanf("%d",&o[1]);

    float cofs1[o[0]];
    float cofs2[o[1]];

    printf("Enter the %d coefficients in numerator:", o[0]+1);

    for(int i=0;i<=o[0];i++)
        scanf("%f", &cofs1[i]);

    printf("Enter the %d coefficients in numerator:", o[1]+1);

    for(int i=0;i<=o[1];i++)
        scanf("%f", &cofs2[i]);

    start = clock();

    while(found==false){
        printf("Enter initial value: \n");
        scanf("%f",&a);

        count=0;

        while(found==false)
        {
            a=fun(cofs1,o[0],a)/fun(cofs2,o[1],a);

            count++;
            
            if(fabs(a-(fun(cofs1,o[0],a)/fun(cofs2,o[1],a)))<pow(10,-6)){
                printf("Found root at: %d iteration \n", count);
                found=true;        
            }
            
            if(count>3000)
                break;
        }
    }
 
    end = clock();
    total_time = ((double) (end - start)) /  CLOCKS_PER_SEC; //calculating time taken 

    printf("Root value is: \n %f",a);
    printf("\nTime taken: %f", total_time);
    
    return 0;
}

float fun (float arr[], int b, float c)
{
    float res=0;
    for(int i=b;i>=0;i--)
        res = pow(c,i)*(arr[b-i]) + res;
    
    return res;
}
