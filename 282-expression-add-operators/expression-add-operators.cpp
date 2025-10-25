class Solution {
public:
    void op(string& num, int& target,vector<string>& result, string path,int index,long eval , long residual){
        if(index==num.size()){
            if(eval==target){
                result.push_back(path);
                return;
            }
        }

        string currentstr;
        long numm=0;
        for(int j=index; j<num.length();j++){

            if(j>index && num[index]=='0') return;
            currentstr+=num[j];
            numm=numm*10 + num[j]-'0';
            if(index==0){
                op(num,target,result,path+currentstr,j+1,numm,numm);
            }
            else{
                op(num,target,result,path+"+"+currentstr,j+1,eval+numm,numm);
                op(num,target,result,path+"-"+currentstr,j+1,eval-numm,-numm);
                op(num,target,result,path+"*"+currentstr,j+1,eval-residual+residual*numm,residual*numm);
            }
        }
    }


    vector<string> addOperators(string num, int target) {
        vector<string> result;
        int index=0;
        op(num,target,result,"",index,0,0);
        return result;
    }
};