#include<bits/stdc++.h>
using namespace std ;
bool Can_place(int mat[][9],int i ,int j,int n , int num)
{
    for(int x=0 ; x<n ; x++)
    {
        if(mat[x][j]==num || mat[i][x]==num)
        {
            return false ;
        }
    }
    int rn = sqrt(n) ;
    int sx = (i/rn)*rn ;
    int sy = (j/rn)*rn ;
    for(int p = sx ; p<sx+rn ; p++)
    {
        for(int q=sy ; q<sy+rn ; q++)
        {
            if(mat[p][q]==num)
            {
                return false ;
            }
        }
    }
    return true ;
}
bool sudoku_solver(int mat[][9] ,int i , int j , int n)
{
    if(i==n)
    {
        // Print Matrix
        for(int p =0 ; p<n ; p++)
        {
            for(int q=0 ; q<n ; q++)
            {
                cout << mat[p][q] << " " ;
            }
            cout << endl ;
        }
        return true;
    }
    if(j==n)
    {
        return sudoku_solver(mat,i+1,0,n);
    }
    if(mat[i][j]!=0)
    {
        return sudoku_solver(mat,i,j+1,n) ;
    }
    for(int num=1 ; num<=n ; num++)
    {
        if(Can_place(mat,i,j,n,num))
        {
            mat[i][j] = num ;
            bool could_solve = sudoku_solver(mat,i,j+1,n) ;
            if(could_solve)
            {
                return true ;
            }
        }
    }
    mat[i][j] = 0;
    return false ;
}
int main()
{
    int mat[9][9] ;
    for(int i=0 ; i<9 ; i++)
    {
        for(int j=0 ;j<9 ; j++)
        {
            cin >> mat[i][j] ;
        }
    }
    sudoku_solver(mat,0,0,9) ;
}
