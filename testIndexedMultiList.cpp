#include <iostream>

#include "IndexedMultiList.h"

using namespace std;

//Professor Underwood,
// As you are about to see I did massive tests for each function, I have seperated the tests into thier own commented out blocks, 
//there is one for each function and they go in order though the accessors though the mutators.  I have tried to do a test for everything i could think of
//or was asked for.  Every line has a comment as to what it should be doing and what it should be printing out, i know you will not use my test data but it
//should be easy to understand.   Mark

void main()
{
	
	IndexedMultiList iml;

	/*
//ACCESSOR TEST AREA
//for obv reason insert was tested in almost every block and I used the same code.

	
	//EMPTY FUNCTION TEST

	cout << iml.empty() << endl; // does the first check to see if the list is empty, should return a 1.
	iml.insert(0, 'D', 4);	//prints 1 and inserts 4 D into iml
	cout << iml.empty() << endl; // Now it does an empty check, since we inserted it should return a 0
	*/

	/*
	//uniqueSize FUNCTION TEST
	cout << iml.uniqueSize() << endl; // prints out how many array indexs are being used by us, since no insert was called should be 0.
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	cout << iml.uniqueSize() << endl; // now it should read the one array index that we inserted into and print out a 1
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 which is at end
	cout << iml.uniqueSize() << endl; // now it should read the 3 additional inserting and tell us our uniqueSize is 4.
	*/

	/*
	//size Function Test
	cout << iml.size() << endl; // prints out how many total items are in the array, only the indexs used by us.  should be double of uniqueSize, noting in the array so should be 0.
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 which is at end
	cout << iml.size() << endl; //after inserting 4 indexs, it should now print 8 since we have 4 numbers and 4 values.
	*/

	/*
	//find Function Test
	cout << iml.find('Y') << endl;	//Should print -1 because the array is empty and 'Y' isnt in it
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 which is at end
	cout << iml.find('C') << endl;	//prints 0 because the value 'C' is in index 0
	cout << iml.find('E') << endl;	//prints 3 because the value 'C' is in index 3
	cout << iml.find('D') << endl;	//prints 2 because the value 'C' is in index 2
	cout << iml.find('Y') << endl;	//Should print -1 because  'Y' isnt in the array
	*/

	/*
	//countItem Function Test
	cout << iml.countItem('E') << endl; // Should return 0 because the array is empty
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 
	cout << iml.countItem('E') << endl; // Now it should return 1 because 'E' is in the array once.
	iml.insert(4, 'E', 5);	//inserts 5 E’s at index 4 
	cout << iml.countItem('E') << endl; // Now it should return 2 because 'E' is in the array twice.
	*/

	/*
	//totalItemCount Function Test

	cout << iml.totalItemCount('E') << endl; // Should return 0 because the array is empty
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 
	cout << iml.totalItemCount('E') << endl; // Should return 5 because thier are 5 'E''s in the array
	iml.insert(4, 'E', 5);	//inserts 5 E’s at index 4 
	cout << iml.totalItemCount('E') << endl; // Should return 10 because thier are 10 total 'E''s in the array
	*/

	/*
	//countPosition Function Test
	cout << iml.countPosition(1) << endl; // Test to print out the number of items in a certain index, should return 0 because the array is empty.
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	cout << iml.countPosition(1) << endl; // Test to print out the number of items in index 1, should print out 4 because 4D is at index 1.
	cout << iml.countPosition(-1) << endl; // Test to print out the number of items outside of the array at start, should return 0.
	cout << iml.countPosition(21) << endl; // Test to print out the number of items outside of the array at end, should return 0.
	cout << iml.countPosition(5) << endl; // Test to print out the number of items if the index is outside my unique size, should return 0;
	*/

	
	/*
	//getAt Function Test

	char ch; // declairing the vairiable to pass by reference.
	cout << iml.getAt(1, ch) << endl;; // Should print a false(0) because our array is empty

	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 

	cout << iml.getAt(1, ch) << endl;; // Should print a true(1) because we have a index 1
	cout << ch<< endl; // should print out the var in index 1, which is Z in this example.
	cout << iml.getAt(6, ch) << endl;;//Should print out a false(0) because index 6 is outside our unqueSize
	*/

	/*
	//print Function Test

	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 
	iml.print();			//prints out the following 4 lines:
							//3 C
							//33 Z
							//4 D
							//5 E 
	*/

 //MUTATOR TEST AREA
	
	/*
	//insert Function Test
	cout <<	iml.insert(0, 'D', 4) << endl;	//A TEST TO INSERT INTO THE FIRST BEGINNING SLOT OF THE ARRAY INDEX 0, should return true(1)

	cout << iml.insert(10, 'C', 3)<< endl;	//A TEST TO INSERT INTO THE MIDDLE OF THE ARRAY, should return false(0) because our uniqueSize is 1 atm.
	cout << iml.insert(1, 'Z', 33)<< endl;//A TEST TO INSERT INTO THE SLOT NEXT TO OUR previous insert, should return true(1) because you can only insert into the slot that is active or the one right next to it.

	cout << iml.insert(0, 'E', 5)<< endl;	//A test to insert into a slot that is already taken, it should push all the other slots over and make this the new index 0, and return true(1)

	iml.print(); // prints to prove it
	*/

	/*
	//change Function Test
	
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 which is at end
	cout << iml.change(1,12) << endl; //   Test to see if the function adds 12 to the index 1, should print out true(1) and add 12 to whatever value is in index 1.
	cout << iml.change(0,-2) << endl; //   Test to add a negative number to index 0, it should subtract the value and print true(1)
	cout << iml.change(2,-6) << endl; // Test to add a negative number that would remove everythign in the slot, it should completely delete the index and shift all the others over, and print true(1)
	cout << iml.change(21,5) << endl; //  Test to update an item that is not in the array, should return false(0)
	iml.print(); // prints to prove the updated array, should look like this
								//1 C
								//45 Z
								//5 E 
	*/

	/*
	//update Function Test
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 which is at end
	cout << iml.update('E',12) << endl; // Test to at 12 more E's to the first location in the array. Should print out a true(1) and update the index slots .number
	cout << iml.update('C',-2) << endl; // Test to add a negative number, it should subtract the value and print true(1)
	cout << iml.update('D',-6) << endl; // Test to add a negative number that would remove everythign in the slot, it should completely delete the index and shift all the others over, and print true(1)
	cout << iml.update('Y',5) << endl; //  Test to update an item that is not in the array, should return false(0)
	iml.print(); // prints to prove the updated array, should look like this
									//1 C
									//33 Z
									//17 E 
	*/

	/*
	//remove Function Test

	cout << iml.remove('Y') << endl; // runs the empty function and returns false(0) if nothing is in array.
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 which is at end
	cout << iml.remove('E') << endl; // Removes 1 'E' from the first index the loop hits and returns true(1)
	cout << iml.remove('Z') << endl; // Removes 1 'Z' from the first index the loop hits and returns true(1)
	cout << iml.remove('Y') << endl; // returns false(0) if not in the array
	iml.print(); // prints to prove the updated array, should look like this
										//3 C
										//32 Z
										//4D
										//4 E 
	*/


	/*
	//removeIndex Function Test

	cout << iml.removeIndex(6) << endl; //EMPTY LIST test at removing an index we didnt insert or is not in our uniqueSize, should return -1
	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 which is at end
	cout << iml.removeIndex(1) << endl; // Should remove all the values in index 1, it will return the number of values you removed and shift all the others over.
	cout << iml.removeIndex(10) << endl; //test at removing an index we didnt insert or is not in our uniqueSize, should return -1
		iml.print(); // prints to prove the updated array, should look like this
										//3 C
										//4D
										//5E 
	*/

	/*
	//removeALL Function Test

	iml.insert(0, 'D', 4);	//inserts 4 D into iml
	iml.insert(0, 'C', 3);	//inserts 3 C before the D in iml
	iml.insert(1, 'Z', 33);	//inserts 33 Z at index 1, between C and D
	iml.insert(3, 'E', 5);	//inserts 5 E’s at index 3 which is at end
	cout << iml.removeAll('E') << endl; // Test to remove all of the value 'E' the first time its found in the list, 
									    //It should print out the number of E's that were removed and it should shift the array to erase the slot.

	cout << iml.removeAll('Y') << endl; // Test to remove a value that isnt in the array, should return a false(0).
	iml.print(); // prints to prove the updated array, should look like this
										//3 C
										//33 Z
										//4D 

	*/

}//end main
