//
// Created by beans_pc on 2018/1/4.
//

#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

/*
 * according to introduction to algorithm,
 * we alloc array(n+1)but make use of the last n
 * just for convinence
 */
using namespace std;
void MATRIX_CHAIN_ORDER(int *p,int n,int **m,int **s)
{
    int i;
    int row = n+1;
    //initialize our array
    for(i=1;i<=n;i++)
        *((int*)m+row*i+i) = 0;

    int l;
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=(n-l+1);i++)
        {
            int j = i+l-1;
            *((int*)m+row*i+j) = -1;
            int k;
            printf("m[%d, %d]\n",i,j);
            vector<string> tmpvector;
            int tmpcnt = 0;
            for(k=i;k<=(j-1);k++)
            {
                int tmp1 = *((int*)m+row*i+k);
                int tmp2 = *((int*)m+row*(k+1)+j);
                int q = tmp1+tmp2+p[i-1]*p[k]*p[j];
                char tmps[100];
                sprintf(tmps, "m[%d, %d] + m[%d, %d] + p%d * p%d * p%d = %d", i, k, k + 1, j, i - 1, k, j, q);
                string fuckchararray = tmps;
                tmpvector.push_back(fuckchararray);
                int old = *((int*)m+row*i+j);
                if(q<old || old == -1)
                {
                    *((int*)m+row*i+j) = q;
                    *((int*)s+row*i+j) = k;
                    tmpcnt = k-i;
                }
            }
            //cout << *((int*)m+row*i+j) << endl;
            for(vector<string>::iterator it = tmpvector.begin();it != tmpvector.end();it++){
                if(it - tmpvector.begin() == tmpcnt)
                    cout << *it <<" ☆☆☆\n";
                else
                    cout << *it<<endl;
            }
            printf("\n");
        }
    }

}

void PRINT_OPTIMAL_PARRNS(int **s,int i,int j,int row)
{
    if(i==j)
        printf("A%d",i);
    else{
        printf("(");
        PRINT_OPTIMAL_PARRNS(s,i,*((int*)s+row*i+j),row);
        PRINT_OPTIMAL_PARRNS(s,*((int*)s+row*i+j)+1,j,row);
        printf(")");
    }
}

int main()
{
    int n = 6;
    int p[7];
    p[0]=5;
    p[1]=10;
    p[2]=3;
    p[3]=12;
    p[4]=5;
    p[5]=50;
    p[6]=6;

    int m[n+1][n+1];
    int s[n+1][n+1];

    MATRIX_CHAIN_ORDER(p,n,(int**)m,(int**)s);
    printf("实际输出样式需旋转90° ==> 金字塔型\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            printf("%4d  ",m[i][j]);
        }
        printf("\n");
    }

    printf("\n实际输出样式需旋转90° ==> 金字塔型\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            printf("%4d  ",s[i][j]);
        }
        printf("\n");
    }

    PRINT_OPTIMAL_PARRNS((int**)s,1,6,7);

    return 0;
}