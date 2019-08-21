//Secant Method to find the roots of a polynomial.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float fun(float [], int, float );

int main()
{

    float a,b; //range vaules 
    float c; //root value

    int o; //order of the polynomial

    float temp;
    bool found=false;
    int res=0;
    int count=0;
    int n;

    printf("Enter order of the polynomial \n");
    scanf("%d",&o);

    float cofs[o];

    printf("Enter the %d coefficients:", o+1);

    for(int i=0;i<=o;i++)
        scanf("%f", &cofs[i]);

    printf("Enter lower limit: \n");
    scanf("%f",&a);

    printf("Enter upper limit: \n");
        scanf("%f",&b);
        

    if(fabs(fun(cofs,o,a))<fabs(fun(cofs,o,b))){
        temp = a;
        a = b;
        b = temp;
    }

    while(found==false)
        {
            c = b-fun(cofs,o,b) * ((a-b) / (fun(cofs,o,a)-fun(cofs,o,b)));

            count++;

            a=b;
            b=c;

            if(fabs(fun(cofs,o,c))<0.000001){
                printf("Found root at: %d iteration \n", count);
                found=true;
            }
        }

    printf("Root value is: \n %f",c);
    return 0;
}

float fun (float arr[], int b, float c)
{
    float res=0;
    for(int i=b;i>=0;i--)
        res = pow(c,i)*(arr[b-i]) + res;
    
    return res;
}