#include <string.h> 
namespace std{
    class string{
        private: 
            char* cp; 
        public: 
            typedef unsigned long long size_type; 
            string() : cp(0){

            }

            string(char* p_str){
                size_t n = strlen(p_str); 
                cp = new char[n+1]; 
                strncpy(cp, p_str, n); 
                cp[n] = '\0'; 
            }

            string(const string& other_str){
                size_t n = strlen(other_str.cp); 
                cp = new char[n+1]; 
                strncpy(cp, other_str.cp, n+1); 
            }

            size_type size() const{
                return strlen(cp); 
            }

            char& operator[](size_type i){
                return *(cp+i); 
            }

            class iterator{
                private: 
                    char* p;
                public: 
                    iterator(char* _p = 0) : p(_p){
                    }

                    iterator operator++(){
                        ++p; 
                        return *this; 
                    }

                    iterator operator--(){
                        --p; 
                        return *this;
                    }

                    iterator operator++(int){
                        iterator tmp(p); 
                        ++p; 
                        return tmp; 
                    }

                    iterator operator--(int){
                        iterator tmp(p); 
                        --p; 
                        return tmp; 
                    }

                    bool operator==(const iterator& other){
                        return p == other.p; 
                    }

                    bool operator!=(const iterator& other){
                        return p != other.p; 
                    }
            }; 

            iterator begin(){
                return iterator(cp); 
            }

            iterator end(){
                return iterator(cp + strlen(cp)); 
            }

            ~string(){
                delete[] cp; 
                cp = 0; 
            }

            const char* c_str() const{
                return cp; 
            }
    }; 
}

/* 
namespace std{
    class string{
        public: 
            typedef unsigned long long size_type; 
            string(){

            }

            string(const char* p_str){

            }

            string(const string& other){

            }

            char& operator[](size_type i){
                return 
            }
    }; 
}


*/