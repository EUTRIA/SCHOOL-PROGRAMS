#include "List.hpp"
#include <iostream>
using namespace std;

int main() {
	
	typedef List1<int> IntegerList;
	IntegerList list1, list2, list3;

	
	cout << "TESTING LIST FUNCTIONS ADDRIGHTFRONT, LEFTLENGTH, RIGHTLENGTH, RIGHTFRONT\nLIST1:";
	list1.outputList();
	cout << "\n\nUsing ADDRIGHTFRONT TO Add <23,35,4,12,300> TO LIST1 \nLIST1:"; // <>, <23,35,4,12,300>

	//TESTING ADDRIGHTFRONT 

	int xi;
	xi = 300;
	list1.addRightFront(xi);

	xi = 12;
	list1.addRightFront(xi);

	xi = 4;
	list1.addRightFront(xi);

	xi = 35;
	list1.addRightFront(xi);

	xi = 23;
	list1.addRightFront(xi);

	list1.outputList();

	//TESTING LEFTLENGTH RIGHTLENGTH AND RIGHTFRONT 

	cout << "\nSize:" << list1.leftLength() + list1.rightLength() << "\nLeft size:"
		<< list1.leftLength() << "\nRight size:" << list1.rightLength();
	cout << "\nRIGHTFRONT:" << list1.rightFront();

	cout << "\n\nTESTING MOVETOFINISH\nLIST1:";
	//TESTING MOVETOFINISH
	list1.moveToFinish();
	list1.outputList();

	cout << "\n\nTESTING MOVETOSTART\nLIST1:";
	//TESTING MOVETOSTART
	list1.moveToStart();
	list1.outputList();

	cout << "\n\nTESTING ADVANCE 3 TIMES\nLIST1:";
	//TESTING ADVANCE
	list1.advance();
	list1.advance();
	list1.advance();
	list1.outputList();

	cout << "\n\nTESTING REPLACERIGHTFRONT\nLIST1:";
	//TESTING REPLACERIGHTFRONT
	xi = 2000;
	list1.replaceRightFront(xi);
	list1.outputList();
	cout << "\nReplaced " << xi << " with " << list1.rightFront();

	cout << "\n\nTESTING REMOVERIGHTFRONT \nLIST1:";
	//TESTING REMOVERIGHTFRONT 
	list1.removeRightFront(xi);
	list1.outputList();
	cout << "\nRemoved: "<<xi;

	cout << "\n\nTESTING SWAPRIGHT WITH LIST1 AND LIST2 \nLIST2:";
	//TESTING SWAPRIGHT
	list2.outputList();
	cout << "\nFILLING LIST2 RIGHT SIDE WITH <5,10,80>\nLIST2:"; // <><5,10,80>

	xi = 80;
	list2.addRightFront(xi);
	xi = 10;
	list2.addRightFront(xi);
	xi = 5;
	list2.addRightFront(xi);
	list2.outputList();

	cout << "\n\nSWAPPING RIGHTS LIST1 & LIST2\nLIST1:";
	list1.swapRights(list2);
	list1.outputList();
	cout << "\nLIST2:";
	list2.outputList();

	cout << "\n\nTESTING TRANSFERFROM AND OPERATOR= WITH LIST1, LIST2, AND LIST3 \nLIST1:";
	list1.outputList();
	cout << "\nLIST2:";
	list2.outputList();
	cout << "\nLIST3:";
	list3.outputList();

	//TESTING OPERATOR=
	cout << "\n\nSETTING LIST3 EQUAL TO LIST1\nLIST3:";
	list3 = list1;
	list3.outputList();
	cout << "\nSize:" << list3.leftLength() + list3.rightLength() << "\nLeft size:"
		<< list3.leftLength() << "\nRight size:" << list3.rightLength();

	//TESTING TRANFERFROM
	cout << "\n\nTRANFERING LIST3 TO LIST2\nLIST2:";
	list2.transferFrom(list3);
	list2.outputList();
	cout << "\nLIST3:";
	list3.outputList();

	cout << "\n\nCLEARING LIST1 LIST2 AND LIST3";
	//TESTING CLEAR
	list1.clear();
	list2.clear();
	list3.clear();
	cout << "\n\nLIST1:";
	list1.outputList();
	cout << "\nLIST2:";
	list2.outputList();
	cout << "\nLIST3:";
	list3.outputList();
}
/* IMPLEMENTER OUTPUT 
TESTING LIST FUNCTIONS ADDRIGHTFRONT, LEFTLENGTH, RIGHTLENGTH, RIGHTFRONT
LIST1:<><>

Using ADDRIGHTFRONT TO Add <23,35,4,12,300> TO LIST1
LIST1:<><23, 35, 4, 12, 300>
Size:5
Left size:0
Right size:5
RIGHTFRONT:23

TESTING MOVETOFINISH
LIST1:<23, 35, 4, 12, 300><>

TESTING MOVETOSTART
LIST1:<><23, 35, 4, 12, 300>

TESTING ADVANCE 3 TIMES
LIST1:<23, 35, 4><12, 300>

TESTING REPLACERIGHTFRONT
LIST1:<23, 35, 4><2000, 300>
Replaced 12 with 2000

TESTING REMOVERIGHTFRONT
LIST1:<23, 35, 4><300>
Removed: 2000

TESTING SWAPRIGHT WITH LIST1 AND LIST2
LIST2:<><>
FILLING LIST2 RIGHT SIDE WITH <5,10,80>
LIST2:<><5, 10, 80>

SWAPPING RIGHTS LIST1 & LIST2
LIST1:<23, 35, 4><5, 10, 80>
LIST2:<><300>

TESTING TRANSFERFROM AND OPERATOR= WITH LIST1, LIST2, AND LIST3
LIST1:<23, 35, 4><5, 10, 80>
LIST2:<><300>
LIST3:<><>

SETTING LIST3 EQUAL TO LIST1
LIST3:<23, 35, 4><5, 10, 80>
Size:6
Left size:3
Right size:3

TRANFERING LIST3 TO LIST2
LIST2:<23, 35, 4><5, 10, 80>
LIST3:<><>

CLEARING LIST1 LIST2 AND LIST3

LIST1:<><>
LIST2:<><>
LIST3:<><>
*/

/*CLIENT OUTPUT
TESTING LIST FUNCTIONS ADDRIGHTFRONT, LEFTLENGTH, RIGHTLENGTH, RIGHTFRONT
LIST1:<>

Using ADDRIGHTFRONT TO Add <23,35,4,12,300> TO LIST1
LIST1:<23, 35, 4, 12, 300>
Size:5
Left size:0
Right size:5
RIGHTFRONT:23

TESTING MOVETOFINISH
LIST1:<23, 35, 4, 12, 300>

TESTING MOVETOSTART
LIST1:<23, 35, 4, 12, 300>

TESTING ADVANCE 3 TIMES
LIST1:<23, 35, 4, 12, 300>

TESTING REPLACERIGHTFRONT
LIST1:<23, 35, 4, 2000, 300>
Replaced 12 with 2000

TESTING REMOVERIGHTFRONT
LIST1:<23, 35, 4, 300>
Removed: 2000

TESTING SWAPRIGHT WITH LIST1 AND LIST2
LIST2:<>
FILLING LIST2 RIGHT SIDE WITH <5,10,80>
LIST2:<5, 10, 80>

SWAPPING RIGHTS LIST1 & LIST2
LIST1:<23, 35, 4, 5, 10, 80>
LIST2:<300>

TESTING TRANSFERFROM AND OPERATOR= WITH LIST1, LIST2, AND LIST3
LIST1:<23, 35, 4, 5, 10, 80>
LIST2:<300>
LIST3:<>

SETTING LIST3 EQUAL TO LIST1
LIST3:<23, 35, 4, 5, 10, 80>
Size:6
Left size:3
Right size:3

TRANFERING LIST3 TO LIST2
LIST2:<23, 35, 4, 5, 10, 80>
LIST3:<>

CLEARING LIST1 LIST2 AND LIST3

LIST1:<>
LIST2:<>
LIST3:<>*/
