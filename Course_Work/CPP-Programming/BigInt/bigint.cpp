/*TYRONE K HARMON JR.	*
*CSC 16 BIG INT PROJECT	*
*OCTOBER 31ST, 2016 	*
*                       */

#ifndef BIGINT_H_
#define BIGINT_H_
#include<iostream>
#include<string>
using namespace std;
class BigInt
{
public:
BigInt(unsigned int numOfDigits=DefaultNumOfDigits);
BigInt(const BigInt &bi);
BigInt &operator =(const BigInt &bi);
int getSize() const { return m_digitArraySize; }
bool isPositive() const { return m_isPositive; }
char operator[](int index) const { return m_digitArray[index]; }
char &operator[](int index) { return m_digitArray[index]; }
// arithmetic operators
BigInt operator + (const BigInt &rhs) const;
BigInt operator - (const BigInt &rhs) const;
BigInt operator * (const BigInt &rhs) const;
BigInt operator / (const BigInt &rhs) const;
// relational operators
bool operator==(const BigInt& rhs) const;
bool operator!=(const BigInt& rhs) const;
bool operator<(const BigInt& rhs) const;
bool operator<=(const BigInt& rhs) const;
bool operator>(const BigInt& rhs) const;
bool operator>=(const BigInt& rhs) const;
~BigInt();
private:
 // private utility functions
void allocateDigitArray(unsigned int size, bool init=true);
void freeDigitArray();
// A static class member is shared across all instances of the class.
 // It is allowed to declare and initialize static members in pre C++11!
static const unsigned int DefaultNumOfDigits = 10;
// data
char *m_digitArray;
unsigned int m_digitArraySize;
bool m_isPositive;
};
ostream &operator<<(ostream &os, const BigInt &bi);
istream &operator>>(istream &is, BigInt &bi);
#endif /* BIGINT_H_ */
//Each array has two capacities 
//One for chararacter capacity, and another to hold positive/negative sign
char BigInt[a][b];  //Here I am creating 3 arrays for First number 
char BigInt2[c][d]; // Second Number
char BigInt3[e][f];// and the result after operation 

/* The following section of code is to set the Bigint arrays and to initialize the third arrays, in preparation for all the operations that are soon to follow */
void UserNumber1(){//Gets the first BigInt number as a string to be converted later
	BigInt[a][b];
	cout<<"What is your first number? "<<endl;
	cin>>BigInt[a][b];
	/* The next Block of code is to determine whether or not we are dealing with negative numbers */
	if (Bigint[0][b]={'-'}){
	Bigint[0][1]={'0'},{'-'};
}
else{
	Bigint[][1]={{a},{'+'}};
}
//Now I shall convert every character in the array into integers
// By subtracting by 48 or '0'
for(i=0;i<Bigint[a-1];i++){
	Bigint[a][1]= {{a-'o'},{b}};
}
}
//In order to make it more user friendly
string UserOperation(){//Gets the operation the user whishes to perform 
	string operation; 
	cout<<"What operation would you like to perform? "<<endl;
	cin>>operation;
	return operation;
	
}
void UserNUmber2(){
	BigInt2[c][d];
	//just incase user forgets first number
	cout<<"Your first number is "<< Bigint<<endl;
	cout<<"What is your second number? "<< endl;
	cin>>BigInt2;

/* The next Block of code is to determine whether or not we are dealing with negative numbers */
if (Bigint2[0][1]={'-'}){
	Bigint2[0][1]={'0'},{'-'};
}
else{
	Bigint2[][1]={{c},{'+'}};
}
//Now I shall convert every character in the array into integers
// By subtracting by 48 or '0'

//second Big Int Array
for(i=0;i<Bigint2[c-1];i++){
	Bigint2[c][1]= {{c-'o'},{d}};
}
}
/* Now I am going to reverse the elements of Array BigInt3 in order for the *integer to be read in the correct order, because what I did before stores *each element from [0]up until [n-1],
    *and I wish to store them from [n-1] up until [0] */
  reverseBigInt3(BigInt3[e][1]){
	for(i=0,j=e-1;i<e/2;i++,j--)
	{
		int temp = 0;
		int temp=BigInt3[i][1];
		int BigInt3[i][1]=BigInt3[j][1];
		int BigInt3[j][1]=temp;
	}
  }   
 /*ATTEMPT IMPLEMENTING THE CODE THIS WAY INSTEAD OF THE WAY YOU STARTED
 BEFORE 12:00PM OCTOBER 31ST, 2016
Bigint(string &s){
	m_digitArraySize = S.size();
	m_digitArray = new char[S.size()];
	for(inti = 0;i<s.size();i++){
		m_digitArray[i]=S[i]-'0';
	}
}
Bigint::Bigint(const BigInt &bi){
	m_digitArraySize = bi.getsize();
	m_digitArray = new char[bi.getsize()]
}
for(int i=0;i<getsize();i++){
	m_digitArray[i]= bi.m_digitArray[i];
}
Bigint Bigint:: operator+(const Bigint &rhs){
	
}

*/
// The next block of code is to carry out the addition operator
c = 0 //For carrying 
void addition(Bigint[a][1], Bigint2[c][1]){
for(i=a-1 & g=c-1;i>=Bigint[0][1] & g>=Bigint2[0][1];i--){
	BigInt3[][1]= c+Bigint[i][1]+Bigint2[g][1];
	if (BigInt3[e][1]>10){
		int c= 1;
	}
	else{
		int c=0;
	}
}
}
//The next block of code is to carry out subtraction 
void subtraction(Bigint[a][1], Bigint2[c][1]){
for(i=a-1, g=c-1;i>=Bigint[0][1] , g>=Bigint2[0][1];i--){
	BigInt3[][1]= c+Bigint[i][1]-Bigint2[g][1];
	if (BigInt3[e][1]>0 , Bigint[i][1]<Bigint2[g][1]){
		Bigint[i][1]-=1;
		int c= 10;
	}
	else{
		int c=0;
	}
}
}
//The next block of code is to carry out multiplication
void multiplication(){
	UserNumber1();
	UserNUmber2();
	for(i=0;i<Bigint2[c][1];i++){
		addition(Bigint[a][1], Bigint[a][1]){
for(i=a-1 ;i>=Bigint[0][1];i--){
	BigInt3[][1]= c+Bigint[i][1]+Bigint[i][1];
	if (BigInt3[e][1]>10){
		int c= 1;
	}
	else{
		int c=0;
	}
}
void reverseBigInt3(BigInt3[e][1])
}
		
	}
}
//The next block of code is to carry out division
void division(){
	UserNumber1();
	UserNUmber2();
	for(i=0;i<Bigint2[c][1];i++){
subtraction(Bigint[a][1], Bigint[a][1]){
for(i=a-1 , g=c-1;i>=Bigint[0][1];i--){
	BigInt3[][1]= c+Bigint[i][1]-Bigint[i][1];
	if (BigInt3[e][1]>0 , Bigint[i][1]<Bigint[i][1]){
		Bigint[i][1]-=1;
		int c= 10;
	}
	else{
		int c=0;
	}
}
}
}
void reverseBigInt3(BigInt3[e][1])
}
		
	}
}
//The next few blocks of code are for relation operations
//First == operation
bool equalsRelation(){
	UserNumber1();
	UserNUmber2();
	for(i=o j=0;i<Bigint2[c][1] , j<Bigint[a][1];i++,j++){
	if (Bigint[j][1]==Bigint2[i]){
		return true;
	}
}
}
//Next != relation
bool NOTequalRelation(){
	UserNumber1();
	UserNUmber2();
	for(i=o j=0;i<Bigint2[c][1] , j<Bigint[a][1];i++,j++){
	if (Bigint[j][1]!=Bigint2[i]){
		return true;
	}
}
}
//Next > than operator 
bool GreaterThanRelation(){
	UserNumber1();
	UserNUmber2();
	if(Bigint[0][1]>Bigint2[0][1] , a>c){
		return true;
	}
	
	for(i=o j=0;i<Bigint2[c][1] , j<Bigint[a][1];i++,j++){
		if (Bigint[j][1]>Bigint2[i]){
		return true;
	}
}
}
bool LessThanRelation(){
	UserNumber1();
	UserNUmber2();
	if(Bigint[0][1]<Bigint2[0][1] , a<c){
		return true;
	}
	
	for(i=o j=0;i<Bigint2[c][1] , j<Bigint[a][1];i++,j++){
		if (Bigint[j][1]<Bigint2[i]){
		return true;
	}
}
}
//Next < operator 
int GiveUserValues(){
	Cout<<Bigint[a][1]<<endl;
	cout<<operation<<endl;
	cout<<Bigint2[c][1]<<endl;
	cout<<"________________"<<endl; //to separate product from items
	cout<<BigInt3[e][1]<<endl;
}

ostream & operator <<(ostream &OS, const BigInt&bi){
	for(int i=0; i<bi.getsize();i++){
		cout<<bi.m_digitArray[i];
		cout<<endl;
	}
}
/* Leave main at the bottom 
*so I can focus on defining everything above it
*so there aren't any as many compile time errors
*such as error 'blank' was not defined in this scope
*just as a precaution 
*/
main(){
	UserNumber1();
	UserOperation();
	UserNUmber2();
	reverseBigInt3(BigInt3[e][1]);
	/* The following code is used to differentiate between 
	*which operation the user would like to perform
	*on both big integers*/
	if(operation== "addition" or"Addition"){
		addition(Bigint[a][1], Bigint2[c][1]);
	}
	else if(operation=="subtraction"or"Subtraction"){
		subtraction(Bigint[a][1], Bigint2[c][1]);
	}
	else if(operation=="multiplication"or"Multiplication"){
		multiplication();
	}
	else if(operation=="division"or"Division"){
		division();
	}
	else if(operation=="equals"or"Equals"){
		if(equalsRelation()==true){
			cout<<"Your first number"<<Bigint<<"is equal to "<<Bigint2<<endl;
		}
	}
	else if(operation=="not equals"or"Not equals" or"Not Equals" or "not Equals"){
	if(NOTequalRelationequalsRelation()==true){
		cout<<"Your first number"<<Bigint<<"is equal not to "<<Bigint2<<endl;
	}
	}
	else if(operation=="greater than "or"Greater than" or"Greater Than" or "greater Than"){
	if(GreaterThanRelation()==true){
		cout<<"Your first number"<<Bigint<<"is greater than "<<Bigint2<<endl;
	}
	}
	else if(operation=="less than "or"Less than" or"Less Than" or "less Than"){
		if(LessThanRelationThanRelation()==true){
		   cout<<"Your first number"<<Bigint<<"is less than "<<Bigint2<<endl;
		}
	}
	else{
		cout<<"I do not recognize that operation please try again"<<endl;
	}
	GiveUserValues();
	
}
