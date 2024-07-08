/* 
// In the definition statement of ptr, 
// SubType will be considered to be a static member 
// without 'typename' qualifier. 
// Whenever you want to convey C++ compiler that the 
// name depending on template type parameter is a typename 
// and not an object then the statement must be qualified 
// by the 'typename' qualifier as shown in uncommented code 
template <typename T> 
class TestClass{
    private: 
        T::SubType * ptr; 
}; 

class CC{
    public: 
        class SubType{

        }; 
}; 

int main(void){
    TestClass<CC> t; 

    return 0; 
}
*/


template <typename T> 
class TestClass{
    private: 
        typename T::SubType * ptr; 
}; 

class CC{
    public: 
        class SubType{

        }; 
}; 

int main(void){
    TestClass<CC> t; 

    return 0; 
}