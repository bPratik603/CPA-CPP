#include <iostream> 

class MutableDemo{
    private: 
        int num; 
        mutable int getter_counter; 
    public:     
        MutableDemo(int _num) : num(_num), getter_counter(0){

        }

        int get_num() const{
            // ++cnt == ++this->cnt
            // this is a pointer to const 
            // this->getter_counter = this->getter_counter + 1; 
            // Without mutable qualifier: we would have required the following syntax 
            // const_cast<MutableDemo*>(this)->getter_counter = getter_counter + 1; 
            // the mutable qualifier is provided to avoid this type casting syntax for 
            // every member that one may wish to modify under const member function. 
            ++getter_counter;    
            return num; 
        }

        void set_num(int new_num){
            num = new_num; 
        }

        int get_counter() const{
            return getter_counter; 
        }
}; 

int main(void){
    MutableDemo mtd(100); 
    for(int i = 0; i < 5; ++i)
        std::cout << mtd.get_num() << std::endl; 

    std::cout << "Getter counter:" << mtd.get_counter() << std::endl; 

    return 0; 
}