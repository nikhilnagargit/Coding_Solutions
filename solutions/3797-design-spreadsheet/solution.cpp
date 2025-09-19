class Spreadsheet {
    pair<int,int> decodecell(string& s){
        int a = s[0]-'A';
        int b = stoi(s.substr(1));
        return {b-1,a};
    }
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        grid = vector<vector<int>>(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        //decore cell to row and col
        auto [row, col] = decodecell(cell);
        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto [row, col] = decodecell(cell);
        grid[row][col] = 0;
    }
    
    int getValue(string formula) {
        int i=1;
        string firstcell="";
        while(formula[i]!='+'){
            firstcell+=formula[i];
            i++;
        }
        i++;
        string secondcell = formula.substr(i);
        int a = 0;
        int b = 0;
        if(firstcell[0]<'0' or firstcell[0]>'9'){
            auto [row1,col1] = decodecell(firstcell);
            if(row1<grid.size() and row1>=0)
            a = grid[row1][col1];

        }
        else{
            a = stoi(firstcell);
        }
        if(secondcell[0]<'0' or secondcell[0]>'9'){
            auto [row2,col2] = decodecell(secondcell);
            if(row2<grid.size() and row2>=0)
            b = grid[row2][col2];
        }
        else{
            b = stoi(secondcell);
        }
        return a+b;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
