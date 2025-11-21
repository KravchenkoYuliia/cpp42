## C++ literal is data used for representing fixed point values that we can directly use in the code
	exemple:
		void	blabla(std::string s);
		blabla("hello"); -> "hello" is a litteral  

## Static method in class
Key points:  
	- Can be called without creating an object (like this -> ClassName::staticMethod())  
	- Only has access to static data members or other static functions.  
	- Useful when a function’s logic is independent of object state.    

## Parsing of the input
	
char:  
	- length of the input is 1  
	- is printable  
	- is not digit    

int:  
	- first elem can be `-`, `+` or digit  
	- all other only digit  
	- int limits between INT_MIN(-2147483648) and INT_MAX(2147483647)   

float:  
	- first elem can be `-`, `+` or digit  
	- if first one is `-` or `+` second one must be digit  
	- must have `.` (can be like this `1.`)  
	- must have `f` at the end  
	- float limits in cfloat between FLT_MIN(1.175494351 E - 38) and FLT_MAX(3.402823466 E + 38)  
	- can be special value `nanf`, `+inff`, `-inff`  
	
double:  
	- same parsing as for float but without `f` at the end  
	- double limits DBL_MIN(2.2250738585072014 E-308) and  DBL_MAX(1.7976931348623158 E+308)  
	- special value are `nan`, `+inf`, `-inf`  



### nan/inf  
for Double:  
	 `nan` `inf` `+inf` `-inf`

for Float  
	 `nanf` `inff` `+inff` `-inff`

