

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <iostream>

#define EQUAL   1   //EQUAL表示c[i][j]是由c[i-1][j-1]+1来的=====此时两个序列有相同的字符
#define UP      2   //UP表示c[i][j]是由c[i-1][j]来的============此时两个序列没有相同的字符
#define LEFT    3   //LEFT表示c[i][j]是由[ci][j-1]来的==========此时两个序列没有相同的字符
using namespace std;

/**************************************************************
函数：int Lcs_length( char *str1, char *str2, int **c, int **b)
输入： str1:   待比较字符串1
        str2:   待比较字符串2
        **c:    储存最大公共子序列长度
        **b:    储存最大公共子序列检索路径

返回值：str1和str2最大公共子序列
时间复杂度：O(mn)
空间复杂度：O(mn)
***************************************************************/
int Lcs_length( char *str1, char *str2, int **c, int **b)
{
    int len1 = strlen(str1),
            len2 = strlen(str2);
    int i,j;
    for( i = 1; i <= len1; i++)
        c[i][0] = 0;
    for ( j = 0; j <= len2; j++)
        c[0][j] = 0;
    for(  i = 1; i <= len1; i++)
        for( j = 1; j <= len2; j++)
        {
            /*******************************
            使用i-1和j-1
            算法导论书上写的是比较str1[i]和str[j]，但是算法导论书上的两个序列下标是由1开始的
            这里使用i-1以及j-1是由于数组的下标从0开始
            ********************************/
            if( str1[i-1] == str2[j-1] )
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = EQUAL;
            }
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = UP;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = LEFT;
            }
        }
    return c[len1][len2];
}

/**************************************************************
函数：void Print_Lcs( char *str, int **b, int i, int j
        str:    待比较字符串1
        **b:    储存最大公共子序列检索路径
        i:      待比较字符串1的长度
        j:      待比较字符串2的长度

返回值：无
打印值：输出字符串1和字符串2的最长公共子序列
时间复杂度：O(m+n)
空间复杂度：O(m+n)
***************************************************************/

stack<char> fuckprint;
void Print_Lcs( char *str, int **b, int i, int j)
{
    if( i == 0 || j == 0){

        return;
    }

    if( b[i][j] == EQUAL)
    {
        Print_Lcs(str, b, i - 1, j - 1);
        printf("%c ", str[i-1]);
        fuckprint.push(str[i-1]);
    }
    else if ( b[i][j] == UP )
        Print_Lcs(str, b, i - 1, j);
    else
        Print_Lcs(str, b, i , j - 1);
}

/**************************************************************
函数：void Find_Lcs( char *str1, char *str2)
        str1:   待比较字符串1
        str2:   待比较字符串2
返回值：无
打印值：输出最大公共子序列长度以及最大公共子序列
时间复杂度：O(mn)
空间复杂度：O(mn)
***************************************************************/
void Find_Lcs( char *str1, char *str2)
{
    int i,j,length;
    int len1 = strlen(str1),
            len2 = strlen(str2);
    //申请二维数组
    int **c = (int **)malloc(sizeof(int*) * (len1 + 1));
    int **b = (int **)malloc(sizeof(int*) * (len1 + 1));
    for( i = 0; i<= len1; i++ )  ////这个等号之前没加，导致内存泄漏
    {
        c[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        b[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    //将c[len1][len2]和b[len1][len2]初始化为0
    for ( i = 0; i<= len1; i++)
        for( j = 0; j <= len2; j++)
        {
            c[i][j] = 0;
            b[i][j] = 0;
        }

    //计算LCS的长度
    length = Lcs_length(str1, str2, c, b);
    printf("The number of the Longest-Common-Subsequence is %d\n", length);

    for ( i = 0; i<= len1; i++) {
        printf("    ");
        for (j = 0; j <= len2; j++) {
            switch(b[i][j]){
                case 1:
                    printf("  ↖ ");
                    break;
                case 2:
                    printf("  ↑ ");
                    break;
                case 3:
                    printf("  ← ");
                    break;
            }

            // b[i][j] = 0;
        }
        printf("\n");
        for (j = 0; j <= len2; j++) {
            printf("%3d ", c[i][j]);

            // b[i][j] = 0;
        }
        printf("\n");


    }

    for(int i = 0;i <= len2;i++){
        //cout << c[len1][i]<<endl;
        if(c[len1][i] == length) {

            //利用数组b输出最长子序列
            printf("The Longest-Common-Subsequence is: ");
            Print_Lcs(str1, b, len1, i);
            cout << endl;
        }

    }





    //动态内存释放
    for ( i = 0; i <= len1; i++)
    {
        free(c[i]);
        free(b[i]);
    }
    free(c);
    free(b);
}

int main()
{
    //实际长度需+1 前后颠倒
    char x[9] = "10010101";
    char y[10] = "010110110";
    Find_Lcs(x,y);

}