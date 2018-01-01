//
// Created by beans on 2017/12/21.
//

#include <iostream>

using namespace std;

const int Max_Distance = 100;
int** EXTEND_SHORTEST_PATHS(int **L,int **W,int n){
    int** Lp = 0;
    Lp = new int*[n];
    for (int h = 0; h < n; h++)
        Lp[h] = new int[n];


    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            Lp[i][j] = Max_Distance;
            for(int k = 0;k<n;k++)
                Lp[i][j] = min(Lp[i][j],L[i][k]+W[k][j]);
        }
    }
    return Lp;
}
int** SLOW_ALL_PAIRS_SHORTEST_PATHS(int **W,int n){


    int total_loop_number = n-1;
    int ***total_L = 0;
    total_L = new int**[total_loop_number];
    for(int i = 0;i<total_loop_number;i++){
        total_L[i] = new int*[n];
        for(int j = 0;j<n;j++)
            total_L[i][j] = new int[n];
    }

    //memcpy(total_L[0],W, sizeof(W));


    for(int i  = 0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            total_L[0][i][j] = W [i][j];
            cout << total_L[0][i][j] << " ";

        }
        cout << endl;
    }

    for(int m = 1;m<n-1;m++){
        total_L[m] = EXTEND_SHORTEST_PATHS(total_L[m-1],W,n);
    }

    return total_L[total_loop_number-1];
}

int** FASTER_ALL_PAIRS_SHORTEST_PATHS(int **W,int n){


    int tmp = 1;
    while(tmp<n-1){
        tmp*=2;
    }
    cout << tmp << endl;
    int total_loop_number = tmp+1;
    int ***total_L = 0;
    total_L = new int**[total_loop_number];
    for(int i = 0;i<total_loop_number;i++){
        total_L[i] = new int*[n];
        for(int j = 0;j<n;j++)
            total_L[i][j] = new int[n];
    }

    //memcpy(total_L[0],W, sizeof(W));


    for(int i  = 0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            total_L[1][i][j] = W [i][j];
            cout << total_L[0][i][j] << " ";

        }
        cout << endl;
    }

    int m = 1;
    while(m<n-1){
       // m*=2;
        total_L[2*m] = EXTEND_SHORTEST_PATHS(total_L[m],total_L[m],n);
        m*=2;
    }
    return total_L[m];

}

int main(){
    int n = 5;





    int fuck[5][5] = {
            {0,3,8,100,-4},
            {100,0,100,1,7},
            {100,4,0,100,100},
            {2,100,-5,0,100},
            {100,100,100,6,0}
    };
    int **W = 0;
    W = new int*[n];
    for(int i = 0;i<n;i++){
        W[i] = new int[n];
        for(int j = 0;j<n;j++){
            W[i][j] = fuck[i][j];
        }
    }

    int **tmp = FASTER_ALL_PAIRS_SHORTEST_PATHS(W,n);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++)
            printf("%4d ",tmp[i][j]);
        cout << endl;
    }


}