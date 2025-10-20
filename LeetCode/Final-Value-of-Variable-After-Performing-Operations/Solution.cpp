class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        if(operations.empty()) return 0;
        int fnal = 0;
        int X =0;
        for(int i=0;i<n;i++){
            if(operations[i]=="--X"){
                fnal--;
                X=X+fnal;
            }
            else if(operations[i]=="X--"){
                X = X + fnal;
                fnal--;
            }
            else if(operations[i]=="++X"){
                fnal++;
                X = X+fnal;
            }
            else{
                X= X+fnal;
                fnal++;
            }
        }
        return fnal;
    }
};