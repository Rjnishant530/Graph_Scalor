#include <iostream>
#include<iomanip>
#include<math.h>
#include<cmath>
#define no_of_fraction_digits 3
using namespace std;
int number(float,bool);
int main()
{
    int div[2];
    float data[2][20],maxn[2],minn[2];

    cout<<"Enter Max Value in X ";
    cin>>maxn[0];
    cout<<"Enter Max Value in Y ";
    cin>>maxn[1];
    cout<<"Enter Min Value in X ";
    cin>>minn[0];
    cout<<"Enter Min Value in Y ";
    cin>>minn[1];
    cout<<"Enter the Number of Divisions in X ";
    cin>>div[0];
    cout<<"Enter the Number of Divisions in Y ";
    cin>>div[1];
    if(minn[0]!=0)
        div[0]--;
    if(minn[1]!=0)
        div[1]--;
    float new_max[]={maxn[0]-minn[0],maxn[1]-minn[1]};
        // cout<<new_max[0]<<endl<<"   "<<new_max[1];
        //cout<<number((new_max[0])/div[0],1);
        //return 0;
        while(number((new_max[0])/div[0],1)>no_of_fraction_digits){
            new_max[0]+=(1/(pow(10,no_of_fraction_digits)));
                                           // cout<<"Next :"<<new_max[0]<<endl;
        }
                                           //cout<<new_max[0]<<endl<<"   "<<new_max[1];

        while(number((new_max[1])/div[1],1)>no_of_fraction_digits){
            new_max[1]+=(1/(pow(10,no_of_fraction_digits)));
                                          //  cout<<"Next :"<<new_max[1]<<endl;
        }
                                            //cout<<new_max[0]<<endl<<new_max[1]<<endl;
        cout<<endl<<"---------------------------"<<endl;
        cout<<"Scale \nX-axis\t"<<(maxn[0]/div[0])<<"\nY-axis\t"<<(maxn[1]/div[1])<<endl;
        cout<<endl<<"---------------------------"<<endl;
    maxn[0]=new_max[0];
    maxn[1]=new_max[1];
    cout<<endl<<"Scale for X is"<<endl;
    for(int i=0;i<div[0]+1;i++){
        cout<<((maxn[0]/div[0])*i)+minn[0]<<endl;
    }
    cout<<endl<<"---------------------------"<<endl;
    cout<<"Scale for Y is"<<endl;
    for(int i=0;i<div[1]+1;i++){
        cout<<((maxn[1]/div[1])*i)+minn[1]<<endl;
    }
    float con[]={(maxn[0]/(div[0]*10)),(maxn[1]/(div[1]*10))};
    cout<<endl<<"---------------------------"<<endl;
    cout<<"Enter the Number of Graphs";
    int h;
    cin>>h;
    cout<<endl<<"---------------------------"<<endl;
    cout<<"Enter the Number of Values   ";
    int val;
    cin>>val;
    cout<<endl<<"---------------------------"<<endl;
    bool ask=false;
    char r;
    int extra[]={0,0};
    for(int u=0;u<h;u++){
            ask=false;
            if(u>=1){
                cout<<endl<<"Do you want same values of X? "<<endl;
                cin>>r;
                if(r=='y'||r=='Y'){
                    ask=true;
                }
            }
            for(int i=0;i<val;i++){
                cout<<"Enter Value  ";
                if(ask!=true)
                cin>>data[0][i];
                cin>>data[1][i];
                cout<<endl;
            }
            if(minn[0]!=0){
                extra[0]=10;
            }
            if(minn[1]!=0){
                extra[1]=10;
            }

            for(int i=0;i<val;i++){
                cout<<"   "<<((data[0][i]-minn[0])/con[0])+(extra[0])<<"    ,     "<<((data[1][i]-minn[1])/con[1])+(extra[1])<<endl;
            }
        }

    }

int number(float val,bool frac=0){
    int numb=0,tempi=(int)val,valn;
    bool rep[]={false,false};
    float temp=val;

    if((modf(temp,nullptr)*1000)!=0){
            for(int i; (temp!=0);i++){
                temp*=10;
                numb++;
                                                    //cout<<"Before modf "<<temp<<endl;
                temp=modf(temp,nullptr);
                                                   //cout<<"Fraction "<<temp<<endl;
                    if(rep[1]==true)
                            break;
                    for(int y=1;y<9;y++){
                            valn=(100*y)+(10*y)+y;
                            if((int)(temp*1000)==valn){
                            if(rep[0]==true)
                                rep[1]=true;
                            rep[0]=true;

                            }
                    }
                    if((int)(temp*1000)==999||(int)(temp*1000)==0){
                            break;
                    }
            }
    }
    if(frac == true)                            // return number of fraction digits
        return numb;
                                                //cout<<"Count of Fraction Number"<<numb<<endl;
    if(tempi!=0){
            while(tempi!=0){
                tempi/=10;
                numb++;
            }


        }
                                                //cout<<"no_of_fraction_digits"<<numb<<endl;
    return numb;
}



