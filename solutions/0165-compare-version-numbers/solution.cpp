class Solution {
public:
    
    int compareVersion(string version1, string version2) {
        // cout<<version1<<","<<version2<<endl;
        if(version1.size()==0 and version2.size()==0){
            return 0;
        }
        string part1 = "";
        string part2 = "";
        
        int i=0;
        while(i<version1.size() and version1[i]!='.'){
            part1 += version1[i];
            i++;
        }
        if(i!=version1.size())
        version1 = version1.substr(i+1);
        else
        version1 = "";

        i=0;
        while(i<version2.size() and version2[i]!='.'){
            part2 += version2[i];
            i++;
        }
        if(i!=version2.size())
        version2 = version2.substr(i+1);
        else
        version2 = "";

        if(part1=="") part1 = "0";
        if(part2=="") part2 = "0";
        // cout<<part1<<","<<part2<<endl;
//    cout<<stoi(part1)<<","<<stoi(part2)<<endl;
    //  cout<<"------------"<<endl;
        if(stoi(part1)<stoi(part2)) return -1;
        if(stoi(part1)>stoi(part2)) return 1;

        return compareVersion(version1,version2);
    }
};
