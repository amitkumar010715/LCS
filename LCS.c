// #include <stdio.h>
// #include <string.h>

// int R[26][26];
// char ans[26][26];

// int LCS(char X[], char Y[], int m, int n)
// {

//     for (int i = 0; i <= m; i++)
//     {
//         R[i][0] = 0;
//     }
//     for (int j = 0; j <= n; j++)
//     {
//         R[0][j] = 0;
//     }
//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (X[i - 1] == Y[j - 1])
//             {
//                 R[i][j] = 1 + R[i - 1][j - 1];
//                 ans[i][j] = 'D';
//             }
//             else
//             {
//                 int a = R[i][j - 1];
//                 int b = R[i - 1][j];
//                 if (a >= b)
//                 {
//                     R[i][j]=a;
//                     ans[i][j] = '<'; //if a is max
//                 }
//                 else
//                 {
//                     R[i][j]=b;
//                     ans[i][j] = '^'; //if b is max
//                 }
//             }
//         }
//     }
//     return R[m][n];
// }
// void print_ans(char X[],int m,int n){
//     if (m==0||n==0)
//     {
//        return;
//     }
//     if(ans[m][n]=='D'){
//         print_ans(X,m-1,n-1);
//         printf("%c",X[m-1]);
//     }
//     else if (ans[m][n]=='^')
//     {
//         print_ans(X,m-1,n);
//     }
//     else
//     {
//         print_ans(X,m,n-1);

//     }

//     }

// int main(int argc, char const *argv[])
// {
//     int m, n, res;
//     char X[26], Y[26];
//     printf("enter the 1st string\t");
//     gets(X);
//     printf("enter the 2st string\t");
//     gets(Y);
//     m = strlen(X);
//     n = strlen(Y);
//     res = LCS(X, Y, m, n);
//     printf("length of longest common subsequence= %d ", res);
//     printf("subsequence is \t");
//     print_ans(X, m, n);
//     return 0;
// }

// *******************************2nd method without using an extra array ******************

// #include <stdio.h>
// #include <string.h>

// int R[26][26];

// int max(int a, int b)
// {
//     if (a > b)
//     {
//         return a;
//     }
//     else
//     {
//         return b;
//     }
// }
// int LCS(char X[], char Y[], int m, int n)
// {
//     for (int i = 0; i <= m; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             if (i == 0 || j == 0)
//                 R[i][j] = 0;

//             else if (X[i - 1] == Y[j - 1])

//                 R[i][j] = R[i - 1][j - 1] + 1;

//             else
//                 R[i][j] = max(R[i - 1][j], R[i][j - 1]);
//         }
//     }
//     return R[m][n];
// }

// int main(int argc, char const *argv[])
// {
//     int m, n, res;
//     char X[26], Y[26];
//     printf("enter the 1st string\t");
//     gets(X);
//     printf("enter the 2st string\t");
//     gets(Y);
//     m = strlen(X);
//     n = strlen(Y);
//     res = LCS(X, Y, m, n);
//     printf("length of longest common subsequence= %d ", res);
//     return 0;
// }

// ***************************recursive version***************************
  // this is top down approch i.e 0 to n not from nto 0;
#include<stdio.h>
#include<string.h>
int max(int a,int b){
    if (a>b)
    {
        return a;
    }
    return b;
}

int LCS(char x[],char y[],int i,int j){
if (strlen(x)==i||strlen(y)==j)
{
    return 0;
}

 int ans=0;
if (x[i]==y[j])
{
  ans= 1+LCS(x,y,i+1,j+1);
}
else
{
 ans= max(LCS(x,y,i+1,j),LCS(x,y,i,j+1));
   
}
return ans;


}
int main(int argc, char const *argv[])
{
   char x[20],y[20];
   gets(x);
   gets(y);
   printf("%d",LCS(x,y,0,0));

    return 0;
}
