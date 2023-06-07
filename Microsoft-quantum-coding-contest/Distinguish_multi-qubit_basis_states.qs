namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {


       body {
            for (i in 0..Length(qs)-1) {
                if (M(qs[i]) == Zero) {
                    if (bits0[i]) {
                        return 1;
                    }
                    if (bits1[i]) {
                        return 0;
                    }
                } else {
                    if (!bits0[i]) {
                        return 1;
                    }
                    if (!bits1[i]) {
                        return 0;
                    }
                }
            }
            return 0;
        }
 }
}

