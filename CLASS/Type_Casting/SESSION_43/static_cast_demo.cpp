#include <iostream> 

void use_case_1(void); 
void use_case_2(void); 
void use_case_3(void); 

int main(void){
    use_case_1(); 
    use_case_2(); 
    use_case_3(); 
    return (0); 
}

void use_case_1(void){
    // int n = 'A'; 
    // type('A') == char 
    // type(n) == int 
    // int n = (int)'A'; 

    int n; 
    float f; 
    n = (int)'A'; 
    f = (float)((int)'A'); 

    n = static_cast<int>('A');
    f = static_cast<float>(static_cast<int>('A'));  

    std::cout << "n:" << n << std::endl << "f:" << f << std::endl; 
}

void use_case_2(void){
    int* p = NULL; 

    // p = malloc(sizeof(int)); // In C++, void* cannot be implicitly converted to int* 

    p = (int*)malloc(sizeof(int)); 
    free(p); 
    p = NULL; 

    p = static_cast<int*>(malloc(sizeof(int))); 
    free(p); 
    p = NULL; 
}

void use_case_3(void){
    class B1{
        public: 
            virtual void f() = 0; 
    }; 

    class B2{
        public: 
            virtual void g() = 0; 
    };

    class B3{
        public: 
            virtual void h() = 0; 
    }; 

    class D : public B1, public B2, public B3{
        public: 
            void f(){
                std::cout << "In D::f()" << std::endl; 
            }

            void g(){
                std::cout << "In D::g()" << std::endl; 
            }

            void h(){
                std::cout << "In D::h()" << std::endl; 
            }
    }; 

    D objD; 

    D* pD = &objD; 
    B1* pB1 = &objD; 
    B2* pB2 = &objD; 
    B3* pB3 = &objD; 

    std::cout   << "pB1:" << std::hex << pB1 << std::endl
                << "pB2:" << std::hex << pB2 << std::endl
                << "pB3:" << std::hex << pB3 << std::endl; 

    std::cout   << "&vptr(B1):" << std::hex << static_cast<B1*>(&objD) << std::endl
                << "&vptr(B2):" << std::hex << static_cast<B2*>(&objD)<< std::endl
                << "&vptr(B3):" << std::hex << static_cast<B3*>(&objD)<< std::endl; 

    std::cout << "pD:" << std::hex << pD << std::endl; 

    
}
