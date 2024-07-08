#include <iostream>

class B{
    public:
    virtual void common() = 0;
};

class D1 : public B{
    public:
     void common(void){
        std::cout<<"In D1::f()"<<std::endl;
     }

     void d1_specific(){
        std::cout<<"In D1::d1_specific"<<std::endl;
     }
};

class D2 : public B{
    public:
    void common(void){
        std::cout<<"In D2::f()"<<std::endl;
    }

    void d2_specific(){
        std::cout<<"In D2::d2_specific"<<std::endl;
    }
};

class D3 : public B{
    public:
    void common(void){
         std::cout<<"In D3::f()"<<std::endl;
    }

    void d3_specific(){
        std::cout<<"In D3_specific()"<<std::endl;
    }
};

int main(void){
    B* pB = NULL;

    srand(time(0));

    for(int i=0;i<10;++i){
        std::cout<<"("<<i<<")"<<"----------------------"<<std::endl;
        switch(rand()%3){
            case 0:
            std::cout<<"D1"<<std::endl;
            pB = new D1;
            break;
            
            case 1:
            std::cout<<"D2"<<std::endl;
            pB = new D2;
            break;

            case 2:
            std::cout<<"D3"<<std::endl;
            pB = new D3;
            break;
        }

        pB->common();

        if(typeid(*pB) == typeid(D1))
             dynamic_cast<D1*>(pB)->d1_specific();
        else if(typeid(*pB) == typeid(D2))
             dynamic_cast<D2*>(pB)->d2_specific();
        else if(typeid(*pB) == typeid(D3))
             dynamic_cast<D3*>(pB)->d3_specific();
        else
           std::cout<<"you are a very bad, nasty type"<<std::endl;
      
      delete pB;
      pB = 0;
      std::cout<<"-----------------------"<<std::endl;
    }

    return(0);


}

