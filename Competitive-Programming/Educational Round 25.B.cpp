#include <iostream>

using namespace std;

char a[10][10];

         bool check_horizontal(int i,int j){
                 int cnt1=0,cnt2=0;

                 int k=0;
                 while(k<5){
                    if(a[i][j+k]=='.'){
                         cnt1++;
                    }
                    if(a[i][j+k]=='X'){
                         cnt2++;
                    }
                    k++;
                 }

                 if(cnt1==1 && cnt2==4){
                     return true;
                 }

                 return false;

              }

              bool check_vertical(int i,int j){
                 int cnt1=0,cnt2=0;

                 int k=0;
                 while(k<5){
                    if(a[i+k][j]=='.'){
                         cnt1++;
                    }
                    if(a[i+k][j]=='X'){
                         cnt2++;
                    }
                    k++;
                 }

                 if(cnt1==1 && cnt2==4){
                     return true;
                 }

                 return false;
              }

              bool check_diagonal(int i,int j){
                 int cnt1=0,cnt2=0;

                 int k=0;
                 while(k<5){
                    if(a[i+k][j+k]=='.'){
                         cnt1++;
                    }
                    if(a[i+k][j+k]=='X'){
                         cnt2++;
                    }
                    k++;
                 }

                 if(cnt1==1 && cnt2==4){
                     return true;
                 }

                 return false;
              }

              bool check_diagonal_2(int i,int j){
                 int cnt1=0,cnt2=0;

                 int k=0;

                 while(k<5 && j-k>=0){
                    if(a[i+k][j-k]=='.'){
                         cnt1++;
                    }
                    if(a[i+k][j-k]=='X'){
                         cnt2++;
                    }
                    k++;
                  }

                 if(cnt1==1 && cnt2==4){
                     return true;
                  }

                 return false;
              }




int main()
{
    for(int i=0;i<10;i++){
       for(int j=0;j<10;j++){
           cin >> a[i][j];
         }
      }

      bool res = false;

      for(int i=0;i<10;i++){
          for(int j=0;j<10;j++){
               if(i>5){
                  if(check_horizontal(i,j)){
                          res=true;break;
                   }
               }
               else if(j>5){
                  if(check_diagonal_2(i,j) || check_vertical(i,j)){
                           res=true;break;
                         }
                 }
               else if(check_vertical(i,j) || check_horizontal(i,j) || check_diagonal(i,j) || check_diagonal_2(i,j)){
                         res=true;break;
               }
           }
          if(res) break;
      }






      if(res)
           cout << "YES";
      else{
           cout << "NO";

         }


    return 0;
}
