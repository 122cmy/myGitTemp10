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
    cout<<"��װ�������Ϊ:";
    cin>>num;
    cout<<"�����������Ϊ:";
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
 
    cout<<"�����:"<<endl;
    for(int i=0;i<num;i++){ 
    cout<<good[i].weight<<" ";
    } 
    cout<<endl;
 
    for(int i=0;i<num&&good[i].weight<=maxweight;i++)
    {
        maxweight-=good[i].weight;
        good[i].flag=true;
    }
    cout<<"ѡ�������Ϊ:"<<endl;
    for(int i=0;i<num&&good[i].flag==true;i++){
       cout<<good[i].weight<<" ";
    }
    cout<<endl;
    for(int i=0;i<num&&good[i].flag;i++){
    	max+=good[i].weight;
	}
	cout<<"���װ������Ϊ:"<<max<<endl; 
 
}
