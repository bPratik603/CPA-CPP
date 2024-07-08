#include <iostream>

void use_case_1(void);
void use_case_2(void);
void use_case_3(void);

int main(void){
    use_case_1();
    use_case_2();
    use_case_3();
}

void use_case_1(){
    int n;
    int f;

    n = (int)'A';
    f = (float)((int)'A');

    n = static_cast<int>('A');
    f = static_cast<float>(static_cast<float>('A'));

    std::cout<<"n:" <<n<<std::endl<<"f:"<<f<<std::endl;
}