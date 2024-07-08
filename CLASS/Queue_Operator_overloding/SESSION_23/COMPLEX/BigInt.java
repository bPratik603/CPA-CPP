BigInt 

class BigIntDemo{
    public static void main(String[] args){
        BigInt n1 = new BigInt(1000000); 
        BigInt n2 = new BigInt(234534635); 
        BigInt n3 = n1.add(n2); 
        BigInt n4 = n1.add(n2).add(n3); 
    }
}

/*  
            C   Java         C++                Python/Perl/JS  Go 
instance    1   1 (built)    1                  0               1 
pointer     1   0            1                  0               1 
reference   0   1 (class)    1 (lvalue ref)     1               0 
                             1 (rvalue ref)

                             T var; 
                             T* var; 
                             T& var; 
                             T&& var; 
*/ 

