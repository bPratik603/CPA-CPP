#include <iostream> 
#include <vector> 

class Employee{
    private:    
        double sal; 
        double bonus_percentage; 
    public: 
        Employee() : sal(5000.0), bonus_percentage(2.0){

        }

        virtual double get_salary() const {
            return sal; 
        }

        double get_bonus_percentage() const {
            return bonus_percentage; 
        }
}; 

class Manager : public Employee{
    private: 
        double bonus_percentage; 
    public: 
        Manager() : bonus_percentage(4.0){

        }

        double get_salary() const {
            return 1.05 * Employee::get_salary(); 
        }

        double get_bonus_percentage() const {
            return bonus_percentage; 
        }
}; 

class GeneralManager : public Manager{
    private: 
        double bonus_percentage; 
    public: 
        GeneralManager() : bonus_percentage(6.0){

        }

        double get_salary() const {
            return 1.1 * Manager::get_salary(); 
        } 

        double get_bonus_percentage() const {
            return bonus_percentage; 
        }
}; 

class HRManager : public Manager{
    private: 
        double bonus_percentage; 
    public: 

        HRManager() : bonus_percentage(6.0){
            
        }

        double get_salary() const {
            return 1.1 * Manager::get_salary(); 
        } 

        double get_bonus_percentage() const {
            return bonus_percentage; 
        }
}; 

class ProjectManager : public Manager{
    private: 
        double bonus_percentage; 
    public: 
        ProjectManager() : bonus_percentage(6.0){

        }

        double get_salary() const {
            return 1.1 * Manager::get_salary(); 
        } 

        double get_bonus_percentage() const {
            return bonus_percentage; 
        }
}; 

double compute_overhead(std::vector<Employee*>& emp_vec); 

int main(void){
    std::vector<Employee*> emp_vec; 

    for(int i = 0; i < 100; ++i){
        switch(rand() % 5){
            case 0: 
                emp_vec.push_back(new Employee); 
                break; 

            case 1: 
                emp_vec.push_back(new Manager); 
                break; 

            case 2: 
                emp_vec.push_back(new GeneralManager); 
                break; 

            case 3: 
                emp_vec.push_back(new HRManager); 
                break; 

            case 4: 
                emp_vec.push_back(new ProjectManager); 
                break; 
        }
    }

    double overhead = compute_overhead(emp_vec); 
    std::cout << "overhead:" << overhead << std::endl; 

    return (0); 
}

double compute_overhead(std::vector<Employee*>& emp_vec){
    double overhead = 0.0; 
    double sal = 0.0; 
    double bonus_amount = 0.0; 

    for(
        std::vector<Employee*>::iterator iter = emp_vec.begin(); 
        iter != emp_vec.end(); 
        ++iter 
    ){
        sal = (*iter)->get_salary(); 
        overhead += sal * (*iter)->get_bonus_percentage()/100.00; 
    }

    return overhead;    
}