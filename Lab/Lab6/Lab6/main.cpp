#include "Header.h"

int main(void)
{
	Complex comp1,comp2;

	comp1.setreal(3);
	comp1.setimaginary(3 );
	comp2.setreal(2);
	comp2.setimaginary(1);

	comp1 = comp1.add(comp2);
	cout << comp1.getreal() << endl;
	cout << comp1.getimaginary() << endl;

}