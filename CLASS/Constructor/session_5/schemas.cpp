void f1(){
    int n; 

    for(){
        // n is available here 
        for(){
            // n is available here
            if(){
                // n is available here
            }
        }
    }
    // n is available here
}

void f2(void){
    int n; 
    // n ok 
    for(){
        int m;  // n, m ok  
        for(){
            // n, m ok 
            if(){
                // n, m, ok 
            }
        }
    }

    try{
        int x; 
    }catch{
        int y; 
    }
}

class X{
    private: 
        int m1; 
    protected: 
        int m2; 
    public: 
        int m3; 
}; 


1.cpp 

class X1{
public: 
    static int i; 
}; 

2.cpp 

class X2{
public: 
    static int i; 
}; 


3.cpp 
class X3{
public: 
    static int i; 
}; 