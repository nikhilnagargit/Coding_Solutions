class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int counter = 0 ;
        for(int i=0;i < matrix.size();i++){
            for(int j=0;j < matrix[0].size();j++){
                int temp = counter;
                // cout<<"i:"<<i<<",j:"<<j<<" ->";
                int side = 2;
                int next = true;
                if(matrix[i][j]==1) counter++;
                else next = false;
                while(next and i+side <= matrix.size() and j+side <= matrix[0].size()){
                
                        for(int a=j;a<j+side;a++){
                            if(matrix[i+side-1][a]!=1){
                                next = false;
                                bool leftright = false;
                                break;
                            }
                        }
                 
                        for(int b=i;b<i+side;b++){
                            if(matrix[b][j+side-1]!=1){
                                next = false;
                                break;
                            }
                        }
                        if(next)
                        counter++;
                        side++;
                }

                // cout<<counter-temp<<endl;
            }
        }
    return counter;
    }
};
