#include <iostream>

int n11 = 100; 		// data definition statement, normal initialization 
int n14(100); 		// data definition statement, normal initialization
int n12 = {100}; 	// data definition statement, list initialization 
int n13{100}; 		// data definition statement, list initialization 
 

double d_num = 34634435.345352; 

int n21 = d_num; 	// ok, possible data loss 
int n21(d_num); 		// ok, possible data loss 

//int n23{d_num}; 		// not ok. compile time error 
//int n24 = {d_num}; 		// not ok. compile time error 

int main(){

	return 0; 
}

/* 
void f(void) 
{
	int n = 10; 
	Date d(1, 1, 1970); 
	int n = 10; 
	int n(10); 	
	
	int a[5] = {10, 20, 30, 40, 50}; 

	int n = {100}; 
	int n{100}; 

	int n = 10; 
	int n(10); 
	int n = {100}; 
	int n{100}; 
}
*/ 