#include "mat.hpp"
#include <iostream>
#include <string>
#include <vector>
const int low_char = 33;
const int bigest_char = 126;

using namespace std;
namespace ariel {
    

    string mat(int col, int row, char firstch, char secondch) {
        int temp2 = 0;
        if (row>col){
            temp2 =row;
            row =col;
            col = temp2;
        }
        if (col <= 0 || row <= 0 ||  col % 2 == 0 || row % 2 == 0) {
            throw runtime_error("The cloom and the rows cant be odd or zero");
        }
        
        if (firstch<low_char||firstch>bigest_char||secondch<low_char||secondch>bigest_char){
            throw runtime_error("char not printable!");}
        
        
        vector<vector<char>> matrix(row,vector<char>(col));
        int helpar = 0;
        int temp = 0;
        for (int r = 0; r<=row/2;r++){
            for (int c =temp; c<col-helpar;c++){
                if(c == temp){
                for (int i = 0; i <= helpar; i++)
                {
                    
                    if (i % 2 == 0){
                        matrix[r][i] = firstch;
                        matrix[r][col-i-1]= firstch;
                    }
                   if (i % 2 == 1){
                        matrix[r][i] = secondch;
                        matrix[r][col-1-i] = secondch;
                        
                   }
                    c = helpar;
                    }}
               if (r% 2 == 0){
                    matrix[r][c] =firstch;
                }
                if (r% 2 == 1){
                    matrix[r][c] =secondch;
                }
            }
            helpar = helpar +1;
            temp =temp+1;
        }
        for (int r = ((row/2)-1); r>=0;r--){
            for (int c =0; c<col;c++){
                matrix[row-1-r][c] = matrix[r][c];
        }
        }
    
    string ans ;
    for(int m = 0 ; m<row;m++){
        for (int n =0; n<col;n++){
            ans +=matrix[m][n];
        }
        if(m != row){
            ans += '\n';}
    }
    return ans;
}
}