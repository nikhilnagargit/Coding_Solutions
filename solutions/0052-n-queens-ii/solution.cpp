class Solution {
public:
    int matrix[10][10];
    bool safe[10][10];
    
    bool is_safe(int i,int j, int n){
        
    
        
//         check this row
        for(int a=0;a<i;a++){
            if(matrix[a][j]==1){
                return false;
            }
        }

        for(int a=0;a<j;a++){
            if(matrix[i][a]==1){
                return false;
            }
        }
        
        int I= i;
        int J = j;
        while(I>=0 and I<=n and J>=0 and J<=n){
            if(matrix[I][J]==1){
                return false;
            }
            I--;
            J--;   
        }
        I=i;
        J=j;
        while(I>=0 and I<=n and J>=0 and J<=n){
            if(matrix[I][J]==1){
                return false;
            }
            I--;
            J++;
        }
        return true;
    }
    
    int solve(int n,int row,int count){
        
        if(n==row){
            return 1;
        }    
    
        for(int i=0;i<n;i++){
            if(is_safe(row,i,n)){
 
                matrix[row][i] = 1;
                 if(row == n-1)
                      count += 1;
                 else
                      count = solve(n,row+1,count);
                
                matrix[row][i] = 0;       
            }
        }
        return count;
        
    }
    
    int totalNQueens(int n) {
        return solve(n,0,0);
    }
};
