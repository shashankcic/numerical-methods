//Bisection Method to find the roots of a polynomial.
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;

float fun(float [], int, float );

int main()
{

    double total_time;
    clock_t start, end;

	float a,b; //range vaules 
	float c; //root value

	int o; //order of the polynomial

	float f;
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


	while(res==0)
	    {
	        printf("Enter lower limit: \n");
	        scanf("%f",&a);

	        printf("Enter upper limit: \n");
	        scanf("%f",&b);

	        if(fun(cofs,o,a)*fun(cofs,o,b)<0)
	            res=1;
	        else
	            printf("Enter the limits again! \n");
	    }

    start = clock();

	while(found == false)
    {
        c = (b+a)/2;
        f = fun(cofs,o,c);
        if(f<0)
            a=c;    
        else
            b=c;

        count++;
        if(fabs(f)<0.000001){
            printf("Found root at: %d iteration \n", count);
            found=true;            
        }
    }

    end = clock();
    total_time = ((double) (end - start)) /  CLOCKS_PER_SEC; //calculating time taken

	printf("Root value is: \n %f",c);
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
