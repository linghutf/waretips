#include <iostream>
#include <algorithm>
#include <vector>

void tryGetMaxValue(std::vector<int> const & needs,std::vector<int> const & values,std::vector<bool> & used,int curNeed,int maxNeed,int curPos);

int main(int argc, char *argv[])
{
    int N,M;
    int need,value;
    std::cin>>N>>M;
    std::vector<int> needs(N,0),values(N);
    for(int i=0;i<N;++i){
        std::cin>>need>>value;
        needs.push_back(need);
        values.push_back(value);
    }
    std::vector<bool> used(N,false);
    tryGetMaxValue(needs,values,used,0,M,0);

    return 0;
}

void tryGetMaxValue(std::vector<int> const & needs,std::vector<int> const & values,std::vector<bool> & used,int curNeed,int maxNeed,int curPos)
{
    //结束条件
    if(curPos == needs.size()){
        int num = 0;
        for(int i=0;i<values.size();++i){
            num += used[i]*values[i];
        }
        std::cout<<num<<std::endl;
    }else{
        for(int i=0;i<needs.size();++i){

            if(curNeed+needs[i]<maxNeed){
                used[i] = true;
                tryGetMaxValue(needs,values,used,curNeed+needs[i],maxNeed,i+1);
                used[i] = false;
            }/*else if(curNeed+needs[i]>maxNeed){
                tryGetMaxValue(needs,values,used,curNeed,maxNeed,i);
            }*/
        }
    }
}
