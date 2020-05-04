#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;
int N;
int main()
{
    scanf("%d",&N);
    int cnt = 0;
    double sum = 0.0;
    for(int i=0;i<N;i++)
    {
        string input;
        cin>>input;
        bool legal = true;
        if(input[0]!='-'&&input[0]!='.'&&!isdigit(input[0]))
        {
            cout<<"ERROR: "<<input<<" is not a legal number"<<endl;
            continue;
        }
        int start = 0;
        if(input[0]=='-')
        start=1;
        bool decimal = false;
        int decNum = 0;
        for(int i=start;i<input.length();i++)
        {
            if(isdigit(input[i]))
            {
                if(decimal)
                {
                    decNum++;
                    if(decNum>2)
                    {
                        legal = false;
                        break;
                    }
                }
                continue;
            }
            if(!decimal&&input[i]=='.')
            {
                decimal = true;
                continue;
            }
            else{
                legal = false;
                break;
            }
        }
        if(!legal)
        {
            cout<<"ERROR: "<<input<<" is not a legal number"<<endl;
        }
        else{
            double tmp = atof(input.c_str());
            if(tmp>1000||tmp<-1000)
            {
                cout<<"ERROR: "<<input<<" is not a legal number"<<endl;
            }
            else{
                cnt++;
                sum+=atof(input.c_str());
            }
        }
    }
    if(cnt>0)
    {
        cout<<"The average of "<<cnt<<(cnt==1?" number":" numbers")<<" is ";
        if(cnt==1)
            printf("%.2f\n",sum);
        else printf("%.2f\n",sum/cnt);
    }
    else printf("The average of 0 numbers is Undefined\n");
    return 0;
}


