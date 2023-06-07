#include <iostream>
#include <string.h>

using namespace std;

int n;

void swap_p(char* x, char* y){
        char tmp;
        tmp = *x;
        *x = *y;
        *y = tmp;
      }

void permutations(char *s,int i){
      int k;
      if(i == n-1){
          cout << s << endl;
      }else{
         for(k=i; k<=(n-1); k++){
              swap_p(s+i,s+k);
              permutations(s,i+1);
              //backtrack
              swap_p(s+i,s+k);
           }
       }
}

int main()
{
    //TEST
    char str[] = "YAZRAN";
    n = strlen(str);
    permutations(str,0);
    return 0;
}
