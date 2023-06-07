#include <iostream>

using namespace std;

int main()
{
    string a,b;int la,lb;long long sum=0;
    cin>>a>>b;
    la = a.length();
    lb = b.length();

    int prex[lb],prey[lb];

    if(b[0]=='0')
        prex[0]=1;
    else
        prex[0]=0;


    for(int i=1;i<lb;i++){
        if(b[i]=='0')prex[i] = prex[i-1]+1;
        else prex[i] = prex[i-1];
      }

     for(int i=0;i<lb;i++){
           prey[i] = i+1 - prex[i];
     }


     for(int i=0;i<la;i++){

           if(a[i]=='1'){
                if(i==0) sum = sum + prex[lb-la+i];
                else
                    sum = sum + prex[lb-la+i] - prex[i-1];
           }
           else{
                if(i==0) sum = sum + prey[lb-la+i];
                else
                    sum = sum + prey[lb-la+i] - prey[i-1];
           }

     }


    cout << sum;



    return 0;
}
