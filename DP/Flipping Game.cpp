
/*
   Time Complexity: O(N)
   Space Complexity: O(N) | N: Size of the array b.
*/

#include <iostream>

using namespace std;

     int max_contiguous_seq(int a[], int siz){

                 int max_val=a[0];
                 int max_int=a[0];

                 for(int i=1;i<siz;i++){

                    max_int = max(a[i], a[i]+max_int);
                    max_val = max(max_val,max_int);
                 }

                 return max_val;
            }


int main()
{
    int n;cin>>n;
    int a[n],b[n];
    int tot=0,tot_zeros=0,r;

    for(int i=0;i<n;i++){
       cin>>a[i];

       if(a[i]==0){
           b[i]=1;
           tot += b[i];
       }else{
           b[i]=-1;
           tot += b[i];
           tot_zeros+=1;
       }
     }

     r = max_contiguous_seq(b,n);

     //Number of -1's outside the move
     int t = (r-tot);
     //The number of -1's inside the move
     int tt = tot_zeros - t;


     cout << r + (tt) + t;


    return 0;
}
