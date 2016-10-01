#include <iostream>
#include <string>
using namespace std;
double power_n(double a, int b)
{
	double answer = 1;
	for(int j=0; j<b; j++)
		answer *= a;
	return answer;
}
class calculator
{
	public:
		calculator();
		void load(double);
		void divide(double);
		void multiply(double);
		void add(double);
		void subtract(double);
		void power(double);
		void factorial(double);
		void squareroot(double);
		void nroot(int);
	private:
		double a;
};
int main()
{
	calculator c;
	string s;
	double a;
	while(true)
	{
		cout<<"CMD: ";
		cin>>s>>a;
		if(s=="load")
			c.load(a);
		else if(s=="div")
			c.divide(a);
		else if(s=="mul")
			c.multiply(a);
		else if(s=="add")
			c.add(a);
		else if(s=="sub")
			c.subtract(a);
		else if(s=="pow")
			c.power(a);
		else if(s=="fact")
			c.factorial(a);
		else if(s=="sqrt")
			c.squareroot(a);
		else if(s=="nroot")
			c.nroot(a);
		else
			cout<<"\nInvalid command";
		cout<<endl;
	}
	system("pause");
	return 0;
}
calculator::calculator()
{
	calculator::a = 0;
	cout<<"a = "<<calculator::a<<endl<<endl;
}
void calculator::load(double b)
{
	calculator::a = b;
	cout<<"a = "<<calculator::a<<endl;
}
void calculator::divide(double b)
{
	calculator::a /= b;
	cout<<"a = "<<calculator::a<<endl;
}
void calculator::multiply(double b)
{
	calculator::a *= b;
	cout<<"a = "<<calculator::a<<endl;
}
void calculator::add(double b)
{
	calculator::a += b;
	cout<<"a = "<<calculator::a<<endl;
}
void calculator::subtract(double b)
{
	calculator::a -= b;
	cout<<"a = "<<calculator::a<<endl;
}
void calculator::power(double b)
{
	double answer = 1;
	for(double j=0;j<b;j++)
		answer *= calculator::a;
	calculator::a = answer;
	cout<<"a = "<<calculator::a<<endl;
}
void calculator::factorial(double b)
{
	calculator::a = 0;
	for(double j=b;j>0;j--)
		calculator::a += j;
	cout<<"a = "<<calculator::a<<endl;
}
void calculator::squareroot(double b)//sum of odd numbers is a perfect square
{
	calculator::a = 0;
	double sum = 0;
	for(double j=1;sum<=b;j+=2,calculator::a++)
		sum += j;
	cout<<"a = "<<--calculator::a<<endl;
}
void calculator::nroot(int b)//Babylonian Method
{
	double first = 1;
	double second = 0;
	while(first!=second)
	{
		second = calculator::a/power_n(first, b-1);
		first = (first+second)/2;
	}
	calculator::a = first;
	cout<<"a = "<<calculator::a<<endl;
}
