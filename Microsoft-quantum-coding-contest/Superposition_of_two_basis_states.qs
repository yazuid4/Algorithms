namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {

          mutable idx = -1;

          for(i in 0..Length(qs)-1){
              if(bits0[i] != bits1[i] && idx == -1){
                  set idx = i;
                }
           }
          
          H(qs[idx]);
          
          for(i in 0..idx-1){
              if(bits0[i]){ 
                  X(qs[i]);
                }
            }
          
          for(i in idx..Length(qs)-1){
              if(bits0[i] == bits1[i]){
                  if(bits0[i]){
                      X(qs[i]);
                    }
                }
              else{
                 if(i != idx){
                    if(bits0[i] != bits0[idx]){
                        CNOT(qs[idx], qs[i]);
                        X(qs[i]);
                    }
                    else{
                        CNOT(qs[idx], qs[i]);        
                    }
                 }
               }
            }
          

         
        } 
    }
}