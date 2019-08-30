//Newton Raphson Method to find the roots of a polynomial.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fun(double [], int, double );
double der(double [], int, double );

int main()
{

    //double pi=3.14;
    double c; //root value
    double d,f;
    int o; //order of the polynomial

    //double temp;
    bool found=false;
    int res=0;
    int count=0;
    //int n;

    printf("Enter order of the polynomial \n");
    scanf("%d",&o);

    double cofs[o];

    printf("Enter the %d coefficients:", o+1);

    for(int i=0;i<=o;i++)
        scanf("%lf", &cofs[i]);

    printf("Enter a value: \n");
    scanf("%lf",&c);
        

    while(found==false)
        {
            f=fun(cofs,o,c);
            d=der(cofs,o,c);

            c = c - (f)/(d);

            count++;

        if(abs(fun(cofs,o,c))<pow(10,-6)){
            printf("Found root at: %d iteration \n", count);
            found=true;
}
    printf("Root value is: \n %lf",c);
    return 0;
}
}
double fun (double arr[], int b, double c)
{
    double res=0;
    for(int i=b;i>=0;i--)
        res = pow(c,i)*(arr[b-i]) + res;
    
    return res;
}

double  der (double arr[], int b, double c)
{
    double res=0;
    for(int i=b;i>=0;i--)
        res = pow(c,i-1) * (i) * (arr[b-i]) + res;

    return res;
}
