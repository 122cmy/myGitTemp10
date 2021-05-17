#include <iostream>
using namespace std;
typedef struct Good
{
    double weight;
    bool flag;
}Good;
int main()
{
	double max=0.0;
    int num;
    double maxweight;
    cout<<"集装箱的数量为:";
    cin>>num;
    cout<<"船的最大容量为:";
    cin>>maxweight;
    Good *good=new Good[num];
    for(int i=0;i<num;i++)
    {
        good[i].flag=false;
        cin>>good[i].weight;
    }
 
    double temp;
    for(int i=0;i<num-1;i++){                     
        for(int j=0;j<num-i-1;j++){
            if(good[j].weight>good[j+1].weight)
            {
                temp=good[j].weight;
                good[j].weight=good[j+1].weight;
                good[j+1].weight=temp;
            }
        }
    }
 
    cout<<"排序后:"<<endl;
    for(int i=0;i<num;i++){ 
    cout<<good[i].weight<<" ";
    } 
    cout<<endl;
 
    for(int i=0;i<num&&good[i].weight<=maxweight;i++)
    {
        maxweight-=good[i].weight;
        good[i].flag=true;
    }
    cout<<"选择的重量为:"<<endl;
    for(int i=0;i<num&&good[i].flag==true;i++){
       cout<<good[i].weight<<" ";
    }
    cout<<endl;
    for(int i=0;i<num&&good[i].flag;i++){
    	max+=good[i].weight;
	}
	cout<<"最大装载重量为:"<<max<<endl; 
 
}
