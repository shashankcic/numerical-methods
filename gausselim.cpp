#include<stdio.h>

int main()
{
    int o;
    printf("Enter the order of the matrix \n");
    scanf("%d",&o);
    float mat [o] [o];
    float smat [o];
    float temp [o];
    float temp1;
    float coff;

    printf("Enter the matrix (%d elements) \n",o*o);
    for(int i=0;i<o;i++)
    {
        for(int j=0;j<o;j++)
        {
            scanf("%f",&mat[i][j]);
        }
    }

    printf("Enter the solution matrix (%d elements) \n",o);
    for(int i=0;i<o;i++)
    {
            scanf("%f",&smat[i]);
    }

    for(int i=0;i<o;i++)
    {
        for(int j=0;j<o;j++)
        {
            printf("%f ",mat[i][j]);
        }
        printf("| %f ",smat[i]);
        printf("\n");
    }


int max =0;
int idx;
    for(int k=1;k<o;k++)
    {
        for(int f=0;f<o;f++)
        if(mat[f][k-1]>max)
        {
            max = mat[f][k-1];
            idx = f;
        }

        if(idx>k-1)
        {
        for(int f = 0;f<o;f++)
        {
            temp[f] = mat[k-1][f];
            mat[k-1][f] = mat[idx][f];
            mat[idx][f] = temp [f];
        }
        temp1 = smat[k-1];
            smat[k-1] = smat[idx];
            smat[idx] = temp1;
        }


        for(int i=k;i<o;i++)
        {
            coff = mat[i][k-1];
            for(int j=0;j<o;j++)
            {
                mat[i][j] =  mat[i][j] - mat[k-1][j]*(coff/mat[k-1][k-1]);
            }
            smat[i] = smat[i] - smat[k-1]*(coff/mat[k-1][k-1]);
        }
    }

    printf("Processed \n");
     for(int i=0;i<o;i++)
    {
        for(int j=0;j<o;j++)
        {
            printf("%f ",mat[i][j]);
        }
        printf("| %f ",smat[i]);
        printf("\n");
    }

    float x[o];
    float sum;
    for(int i = o-1;i>=0;i--)
    {
        sum = 0;
        for(int j=i+1;j<o;j++)
        sum = sum + mat[i][j]*x[j];
        x[i] = (smat[i] - sum)/mat[i][i];
    }
printf("Solutions \n");
for(int i=0;i<o;i++)
    printf("%f ",x[i]);

    return 0;

}
