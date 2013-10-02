#include <iostream>
#ifndef IndexedMultiList_H
#define IndexedMultiList_H

const int DEFAULT_MAX_ITEMS=20;

class IndexedMultiList {
public:
//Constructors/destructors
	IndexedMultiList();//creates an empty list capable of storing 
//DEFAULT_MAX_ITEMS items
    ~IndexedMultiList();	//destructor ONLY if needed

//accessors
	bool empty();//returns true iff (if and only if) list is empty
	int uniqueSize();//returns number of positions in the list in use
	int size();	//returns total number of items in list using counts
//If 2 A, 3 C, 1 D are inserted into an IndexedMultiList iml then 
//iml.uniqueSize() would return 3 and iml.size() would return 6.
	int find(char val);   	
//returns index of first position with val in it or �1 if not found
	int countItem (char val);
//returns number of locations val is in the list (vacuously 0 if not //found)
	int totalItemCount (char val);
/*returns number of val in the list (vacuously 0 if not found)
Example: there are 3 A�s in the first position, 6 B�s in the second and 4 A�s in the third position.
find(�A�) returns 0, find(�B�) returns 1 and find(�C�) returns -1
countItem(�A�) returns 2  (it is in the first and third location)
countItem(�B�) returns 1, countItem(�C�) returns 0
totalItemCount(�A�) returns 7, totalItemCount(�B�) returns 6,
totalItemCount(�C�) returns 0
*/

	int countPosition(int index);//returns number of items at position index (0 based) or 0 if index is invalid
	bool getAt(int index, char &out);
/*if position index is in use, out is set to char at that position and true is returned, otherwise false is returned.  This is kind of like [] for an array but with error checking*/

	void print();		
//prints out the content of the list in order by position, see below

//mutators
	bool insert(int index, char val, int count);
/*insert count number of val into the list at position index
returns true iff val was able to fit in list and index was valid and count >=1
valid indices range from 0 up to unique size (inclusive).  So for an empty list, 0 is the only valid index.  
insert should do nothing if index is invalid
If the list has 3 A�s in the first position, then 0 and 1 are the only valid indices.
*/
	bool change(int index, int amount);
/*add amount to item in position index
returns true iff index was valid
change should do nothing if index is invalid
amount could be negative, if adding amount to the current count results in a count of <= 0 then position should be removed
For example, if there are 3 A�s at index 0 and 2 B�s at index 1 in the list iml then
iml.change(0, -4) 
would remove all the A�s and the 2 B�s would be at index 0.
*/

	bool update(char val, int amount); //finds val in list and adds amount (which could be negative)
//return true iff found, works similarly to change but is based on the
//character to find instead of the position.  If val is in multiple //locations within the list, then only change the first location

	bool remove(char val);	//removes 1 instance of val from list, //returns true iff val was in list, if val is in multiple locations,
//then only remove from the first location

	int removeIndex(int index);	//remove item in position index, returns count //of items removed or -1 if index not in use

	int removeAll(char val); //removes all instances of val from list
//returns number of items removed, which could be 0, if val is in //multiple locations it should remove only the first location

private:
//put whatever methods or data you need in here, 
//you must put the 1-dimensional array here


 struct multi{ // my struct 
			
	int number;
    char value;
    } ;
	
 multi array[DEFAULT_MAX_ITEMS];//my array that takes in both a number and a charactor, set to defaul_max_items const
 
};

#endif