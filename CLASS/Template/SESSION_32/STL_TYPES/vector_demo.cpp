#include <iostream> 	// istream, ostream, iostream, cin, cout 
#include <cstdlib> 		// 
#include <string>		// string data type
#include <vector>		// vector 

template <typename T> 
void show_vector_by_index(	std::vector<T>& vec, 
							const char* msg	){
	std::cout << msg << std::endl; 
	for(std::vector<T>::size_type i = 0; 
		i != vec.size(); 
		++i)
		std::cout << "vec[" << i << "]:" << vec[i] << std::endl; 
	std::cout << "---------END---------" << std::endl; 
}

template <typename T>
void show_vector_by_iterator(std::vector<T>& vec, const char* msg){
	std::cout << msg << std::endl;
	for(std::vector<T>::iterator iter = vec.begin(); 
		iter != vec.end(); 
		++iter)
		std::cout << "*iter:" << *iter << std::endl; 
	std::cout << "---------END---------" << std::endl; 
}	

void vectors_of_different_types(); 
void vector_assignment_and_swap(); 
void vector_and_size(); 
void vector_all_iterators(); 
void vector_relational_operators(); 
void vector_add_elements(); 
void vector_element_access(); 

int main(){
	vectors_of_different_types(); 
	vector_assignment_and_swap(); 
	vector_and_size(); 
	vector_all_iterators(); 
	vector_relational_operators(); 
	vector_add_elements(); 
	//vector_element_access();

	return EXIT_SUCCESS; 
}

void vectors_of_different_types(){
	// empty vector of chars
	std::vector<char> cvec; 	 
	std::vector<int> ivec1{10, 20, 30}; 
	std::vector<int> ivec2(ivec1); 

	show_vector_by_index(cvec, "Empty char vector"); 
	show_vector_by_index(ivec1, "Vector of int initialized using list syntax"); 
	show_vector_by_index(ivec2, "Vector initialized from another vector"); 

	show_vector_by_iterator(ivec1, "Vector of int initialized using list syntax"); 
	show_vector_by_iterator(ivec2, "Vector of int initialized from another vector"); 

	std::vector<int> ivec3{100, 200, 300, 400, 500, 600, 700, 800}; 
	std::vector<int>::iterator iter1 = ivec3.begin() + 1; 
	std::vector<int>::iterator iter2 = ivec3.begin() + 5; 

	std::vector<int> ivec4(iter1, iter2); 
	show_vector_by_iterator(ivec3, "Showing vector3 using iterator"); 
	show_vector_by_iterator(ivec4, "Showing vector4 which is initialized from vetor iterators"); 

	std::vector<int> ivec5(10); 		// vector of 10 elements initialized to 0 
	std::vector<int> ivec6(5, 100); 	// vector of 5 elements each initialized to 100 	
}

void vector_assignment_and_swap(){
	std::vector<int> ivec1{100, 200, 300, 400, 500, 600, 700, 800}; 

	show_vector_by_index(ivec1, "Showing initial state of vector"); 
	// assignment using index 
	ivec1[0] = 1000; 
	ivec1[2] = 3000; 
	show_vector_by_index(ivec1, "Showing state of vector after assignment using index"); 

	std::vector<int>::iterator iter = ivec1.begin() + 1; 
	*iter = 2000; 
	show_vector_by_index(ivec1, "Showing state of vector after assignment using iterator"); 

	std::vector<int> ivec2{-100, -200, -300, -400, -500}; 
	show_vector_by_index(ivec1, "ivec1 before swap"); 
	show_vector_by_index(ivec2, "ivec2 before swap"); 

	swap(ivec1, ivec2); 

	show_vector_by_index(ivec1, "ivec1 after swap"); 
	show_vector_by_index(ivec2, "ivec2 after swap"); 

	std::vector<int> ivec3{1000, 2000, 3000, 4000, 5000}; 
	show_vector_by_index(ivec3, "ivec3 before assignment"); 
	ivec3 = {100, 200}; 
	show_vector_by_index(ivec3, "ivec3 after assignment"); 

	ivec3 = {1000, 2000, 3000, 4000, 5000}; 

	std::vector<int> ivec4{-10, -20, -30, -40, -50, -60, -70}; 
	std::vector<int>::iterator iter1 = ivec4.begin() + 1; 
	std::vector<int>::iterator iter2 = ivec4.end() - 1; 
	show_vector_by_index(ivec3, "ivec3 before assignment"); 
	ivec3.assign(iter1, iter2); 
	show_vector_by_index(ivec3, "ivec3 after .assign 1"); 
	ivec3.assign({100, 200, 300, 400, 500}); 
	show_vector_by_index(ivec3, "ivec3 after .assign 2"); 
	ivec3.assign(4, -100); 
	show_vector_by_index(ivec3, "ivec3 after .assign 3"); 

	// 	.assign invalidates iterators, references, pointers into the containers 
	// 	apart from string they remain valid after swap 
	// 	apart from array they remain outer container objects are swapped not inner contents 

}

void vector_and_size(){
	std::vector<int> ivec1{100, 200, 300, 400, 500}; 

	std::cout << "ivec1.size():" << ivec1.size() << std::endl; 
	std::cout << "ivec1.max_size():" << ivec1.max_size() << std::endl; 
	if(ivec1.empty() == false)
		std::cout << "ivec1 is not empty" << std::endl; 
}

void vector_all_iterators(){
	std::vector<int>ivec{100, 200, 300, 400, 500, 600, 700, 800}; 
	std::cout << "all iterators:" << std::endl; 
	// forward read only iterator 
	for(std::vector<int>::const_iterator citer = ivec.cbegin(); 
		citer != ivec.cend(); 
		++citer){
		std::cout << "*citer = " << *citer << std::endl; 
		// *citer = *citer + 5; 	// Compile time error 
	}

	// forward read/write iterator 
	for(std::vector<int>::iterator iter = ivec.begin(); 
		iter != ivec.end(); 
		++iter){
		*iter += 5; 
		std::cout << "*iter = " << *iter << std::endl; 
	}

	// reverse read only iterator 
	for(std::vector<int>::const_reverse_iterator criter = ivec.crbegin(); 
		criter != ivec.crend(); 
		++criter){
		std::cout << "*criter = " << *criter << std::endl; 
		// *criter = *criter - 5; 	// Compile time error 
	}

	// reverse read / write iterator 
	for(std::vector<int>::reverse_iterator riter = ivec.rbegin(); 
		riter != ivec.rend(); 
		++riter){
		*riter -= 5; 
		std::cout << "*riter = " << *riter << std::endl; 
	}
}

void vector_relational_operators(){
	std::vector<int> ivec1{10, 20, 30, 40}; 
	std::vector<int> ivec2{10, 20, 30, 40, 50, 60}; 
	std::vector<int> ivec3{100, 200, 300, 400}; 
	std::vector<int> ivec4(ivec1); 

	if(ivec1 < ivec2) 
		std::cout << "less" << std::endl; 

	if(ivec3 > ivec2)
		std::cout << "greater" << std::endl; 

	if(ivec1 == ivec4)
		std::cout << "equal" << std::endl; 

	if(ivec1 != ivec2)
		std::cout << "inequal" << std::endl; 
}

void vector_add_elements(){
	std::vector<int> ivec; 
	ivec.push_back(10); 
	ivec.push_back(20); 
	ivec.push_back(30); 
	show_vector_by_index(ivec, "after push_back");
}