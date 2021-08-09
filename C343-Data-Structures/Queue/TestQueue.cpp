#include "Queue.hpp"
#include <iostream>
#include <string> 
using namespace std;

 int main() {
	typedef Queue1 <int> IntegerQueue;
	typedef Queue1 <string> TextQueue;
	
	TextQueue q2;
	IntegerQueue q1;

	//TESTING QUEUE ONE TYPE INTEGER
	cout << "QUEUE ONE TYPE INT \nQ1:";
	q1.outputQueue();
	int xi;
	cout << "\nTesting ENQUEUE, LENGTH, AND FRONT\n"
	 "Filling Q1 with <21 ,33 ,15 ,1 >\n" ;


	//Testing enqueue,length and front
	cout << endl << "Q1: ";
	xi = 21;
	q1.enqueue(xi);

	xi = 33;
	q1.enqueue(xi);

	xi = 15;
	q1.enqueue(xi);

	xi = 1;
	q1.enqueue(xi);
	
	q1.outputQueue();
	cout << "\nValue of xi:" << xi;
	cout << "\nSize: "<<q1.length();
	cout << "\nFront="<<q1.front()<<"\n";

	//Testing dequeue
	cout << "\nTESTING DEQUEUE\n\n";
	q1.dequeue(xi);
	cout << "Q1: ";
	q1.outputQueue();
	cout << "\nItem removed:" << xi;
	cout << "\nFront:" << q1.front() << "\n";

	q1.dequeue(xi);
	cout << "\nQ1: ";
	q1.outputQueue();
	cout << "\nItem removed:" << xi;
	cout << "\nFront:" << q1.front() << "\n";

	//Testing replaceFront 
	cout << "\nTESTING REPLACEFRONT\n\n"
		"Replacing front with 28\n";
	xi = 28;
	q1.replaceFront(xi);
	cout << "The previous Front " << xi << " was replaced with " << q1.front() << "\n"
		"Q2:";
	q1.outputQueue();

	cout << "\n\nClearing Q1\nQ1:";
	q1.clear();
	q1.outputQueue();

	/*TESTING QUEUE TWO
	* TYPE STRING
	* 
	* 
	* 
	* 
	*/
	cout << "\n\n\nQUEUE TWO TYPE STRING\nQ2:";
	q2.outputQueue();
	string yi;
	cout << "\nTesting ENQUEUE, LENGTH, AND FRONT\n"
		"Filling Q2 with <THIS ,IS ,A ,QUEUE >\n";


	//Testing enqueue,length and front
	cout << endl << "Q2: ";
	yi = "THIS";
	q2.enqueue(yi);

	yi = "IS";
	q2.enqueue(yi);

	yi = "A";
	q2.enqueue(yi);

	yi = "QUEUE";
	q2.enqueue(yi);

	q2.outputQueue();
	cout << "\nValue of yi:" << yi;
	cout << "\nSize: " << q2.length();
	cout << "\nFront:" << q2.front() << "\n";


	//Testing dequeue
	cout << "\nTESTING DEQUEUE\n\n";
	q2.dequeue(yi);
	cout << "Q2: ";
	q2.outputQueue();
	cout << "\nItem removed:" << yi;
	cout << "\nFront:" << q2.front() << "\n";

	q2.dequeue(yi);
	cout << "\nQ2: ";
	q2.outputQueue();
	cout << "\nItem removed:" << yi;
	cout << "\nFront:" << q2.front() << "\n";


	//Testing replaceFront 
	cout << "\nTESTING REPLACEFRONT\n\n"
		"Replacing front with THE\n";
	yi = "THE";
	q2.replaceFront(yi);
	cout << "\nyi:" << yi;
	cout << "\nQ2:";
	q2.outputQueue();

	cout << "\n\nClearing Q2\nQ2:";
	q2.clear();
	q2.outputQueue();

	/* TESTING FUNCTION TRANSFERFROM 
	* AND OPERATOR=
	* 
	* INTEGER QUEUES
	* 
	*/
	IntegerQueue q3;
	TextQueue q4;
	cout << "\n\nQUEUE THREE TYPE INT\nQ3: ";
	q3.outputQueue();
	cout << "\n\nTESTING TRANFERFROM WITH INTEGER QUEUES Q1 & Q3\n\n"
		"Filling Q1 with <21,15,1>\n"
		"Filling Q3 with <1,1,1,1>\n\n";

	xi = 21;
	q1.enqueue(xi);
	xi = 15;
	q1.enqueue(xi);
	xi = 1;
	q1.enqueue(xi);

	xi = 1;
	q3.enqueue(xi);
	xi = 1;
	q3.enqueue(xi);
	xi = 1;
	q3.enqueue(xi);
	xi = 1;
	q3.enqueue(xi);

	cout << "Q1:";
	q1.outputQueue();
	cout << "\nQ3:";
	q3.outputQueue();
	cout << "\n\nTranfering Q3 to Q1 \nQ1:";

	q1.transferFrom(q3);
	q1.outputQueue();
	cout << "\nQ3: ";
	q3.outputQueue();
	/*TESTING WITH STRING QUEUES
	* 
	* 
	* 
	*/
	cout << "\n\nQUEUE FOUR\nQ4:";
	q4.outputQueue();
	cout << "\n\nTESTING TRANFERFROM WITH STRING QUEUES Q2 & Q4\n\n"
		"Filling Q2 with <Billy,Sally,Tommy>\n"
		"Filling Q4 with <Rosalina,Ismal,Tomatos,Tim>\n\n";

	yi = "Billy";
	q2.enqueue(yi);
	yi = "Sally";
	q2.enqueue(yi);
	yi = "Tommy";
	q2.enqueue(yi);

	yi = "Rosalina";
	q4.enqueue(yi);
	yi = "Ismal";
	q4.enqueue(yi);
	yi = "Tomatoes";
	q4.enqueue(yi);
	yi = "Tim";
	q4.enqueue(yi);

	cout << "Q2:";
	q2.outputQueue();
	cout << "\nQ4:";
	q4.outputQueue();
	cout << "\n\nTranfering Q4 to Q2 \nQ2:";

	q2.transferFrom(q4);
	q2.outputQueue();
	cout << "\nQ4: ";
	q4.outputQueue();

	/*TESTING OPERATOR=
	* 
	* INTEGER QUEUES
	*/
	cout << "\n\nTESTING OPERATOR= WITH INTEGER QUEUES Q1 & Q3\n\nQ1:";
	q1.outputQueue();
	cout << "\nQ3: ";
	q3.outputQueue();
	cout << "\nSETTING Q3 EQUAL TO Q1";
	q3 = q1;
	cout << "\nQ3:";
	q3.outputQueue();

	/*TESTING OPERATOR=
	*
	* STRING QUEUES
	*/
	cout << "\n\nTESTING OPERATOR= WITH STRING QUEUES Q2 & Q4\n\nQ2:";
	q2.outputQueue();
	cout << "\nQ4: ";
	q4.outputQueue();
	cout << "\nSETTING Q4 EQUAL TO Q2";
	q4 = q2;
	cout << "\nQ4:";
	q4.outputQueue();

	q1.clear();
	q2.clear();
	q3.clear();
	q4.clear();

	return 0;

}
