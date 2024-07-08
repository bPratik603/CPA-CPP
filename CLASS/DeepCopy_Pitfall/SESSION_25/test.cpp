/// #include <string> 

namespace std
{
    class string 
    {
        private: 
            char* p; 

        public: 
            string(const string &)
            {

            }

            string& operator=(const string& other)
            {

            }
    }; 
} 


class X 
{
    private: 
        std::string s; 
        int num; 
        char s; 
}; 