#include <iostream>
#include "IndexedMultiList.h"

using namespace std;

//constructor not used, but have to call it
IndexedMultiList::IndexedMultiList(void)
{

}

//destructor, not used but have to call it
IndexedMultiList::~IndexedMultiList(void)
{

}

//accessors

bool IndexedMultiList::empty() //Used to check if the array is empty
{
	if (uniqueSize()>0) return false; // uses uniqueSize to check if the array has any inserted values into it.
	else
		return true;
}



int IndexedMultiList::uniqueSize() //Used to get the size of the array, the actual inserted indexs
{
	int counter=0; //counter to keep track of how many slots are being used

	for (int i=0;i<DEFAULT_MAX_ITEMS;i++)
	{
		if (array[i].number>-1) //checks if the array.number has a value >-1 because insert cannot insert a number below 0
			counter=counter+1;
	}
	return counter;
}

int IndexedMultiList::size() // Simple program used just to tell us how many total values are in the array
{
	return uniqueSize()*2;// since each inserted slot must have 2 values we just mult by 2.
}



int IndexedMultiList::find(char val) // Used to find a specific value in the array.
{
	for (int i=0;i<DEFAULT_MAX_ITEMS;i++)
	{
		if (array[i].value==val) // if val matchs array.value then it returns the index where it was found
			{
				return i;
				
		    }
		
	}
	return -1; // if not found then it returns -1
}

int IndexedMultiList::countItem (char val) //Used to see how many times a certain value is in the array, if A is in the array twice then it will return 2.
{
	int counter=0;// if it doesnt find the value it will return 0.
	
	
	for (int i=0;i<DEFAULT_MAX_ITEMS;i++)
	{
		if (array[i].value==val) //adds 1 to the counter each time the value is found
			{
				
				counter=counter+1;
				
		    }

	}
	return counter;
}

int IndexedMultiList::totalItemCount (char val) //Used to add up all the values in the array, if thier is 3As in index 1 and 3As in index 3, then it will return 6 if we search for A.
{
		int countOfValues=0;// if it doesnt find the value it will return 0.
	
	for (int i=0;i<DEFAULT_MAX_ITEMS;i++)
	{
		if (array[i].value==val)
			{
				countOfValues=countOfValues+array[i].number;//adds the number of value it finds to the counter till the end of the array
				
				
		    }

	}
	return countOfValues;
}

int IndexedMultiList::countPosition(int index) //Used to return the number of values at a certain index, if 3A is at index 1 and we call for index 1, 3 will be returned
{
	if (index<0 || index>uniqueSize()) return 0;//check to make sure the index is in the array
	int countOfVal=0;
	for (int i=index;i<DEFAULT_MAX_ITEMS; i++)
	{
		countOfVal=array[i].number;//adds the number of the value it finds at that index
		return countOfVal;
	}
	return false;

}

bool IndexedMultiList::getAt(int index, char &out)//Used to print out the value of array.value at a certain index, it is passed by reference
{
	for (int i=index;i<DEFAULT_MAX_ITEMS; i++)
	{
		if (array[i].number>-1) // checks to see if the index is in use by insert
		{
		out=array[i].value; // checks if out is equal to the array.value and if so returns true
		return true;
		}
	}
	return false;
}

void IndexedMultiList::print() //Used to print out the array
{

	for (int i=0;i<uniqueSize();i++)// only prints till it hits our uniqueSize
	{
		cout << array[i].number << " " <<  array[i].value << endl;
	}
}


//mutators

bool IndexedMultiList::insert(int index, char val, int count) //Used to insert numbers and values into the array slots
{
	if (index<0 || index>uniqueSize())return false; //a check to make sure we are inserting into a proper array slot.
	if (count<0) return false; // check to make sure we only insert positive numbers

for(int i = DEFAULT_MAX_ITEMS-2; i > index - 2; i--) 
array[i + 1] = array[i]; // Used to shift the other values over to make room for new one
array[index].number=count;
array[index].value=val;// inserts the new values

		return true;
	
}



bool IndexedMultiList::change(int index, int amount)//Used to add or substract a value from a certain index, if it removes the entire number then it deletes the slot and shifts
{
	char val;
	if(index<0 || index>DEFAULT_MAX_ITEMS)return false; //a check to make sure we are inserting into a proper array slot.
	
	for (int i=index; i<DEFAULT_MAX_ITEMS; i++)
	{
		val=array[i].value;
		update(val,amount);//sends the amount and the value to update, update will change the value if needed or shift the array to erase the slot if the value goes below 0
		return true;
	}
	
	return false;
}



bool IndexedMultiList::update(char val, int amount)// Used to find a value and add or subtract an amount from it, if it removes the entire number then it deletes the slot and shifts the array
{
		empty(); //checks if it is an empty array!

	for (int i=0;i<DEFAULT_MAX_ITEMS;i++)
	{
		if (array[i].value==val)
			{
				array[i].number=array[i].number+amount; // adds the amount to the current number of values in the array.
				if (array[i].number<=0) // checks if we took the value at or below 0 and if we did then it removes the index.
				{
					removeAll(val); //calls the removeAll function and removes the index and shifts all the values
				}
				return true;
				
		    }
		
	}
	return false; //if no value is found
}

bool IndexedMultiList::remove(char val) //Used to remove 1 value from a slot, it takes in a value and if it is found then it removes 1 value from it.
{
	empty();

	for (int i=0;i<DEFAULT_MAX_ITEMS;i++)
	{
		if (array[i].value==val)
			{
				array[i].number=array[i].number-1;
				if (array[i].number<=0) // checks if we took the value at or below 0 and if we did then it removes the index.
				{
					removeAll(val); //calls the removeAll function and removes the index and shifts all the values
				}
				return true;
				
		    }
		
	}
	return false;//if no value is found

}

int IndexedMultiList::removeIndex(int index)  //Used to remove the entire index
{
	int count=0;

	if (index <0 || index >=uniqueSize()) return -1; // checks to make sure the index is inside our array.
	
	count=array[index].number; //returns the number of values we removed from the index before the shift.
	for (int i=index; i<DEFAULT_MAX_ITEMS-1; i++)
	{
		array[i] = array[i+1]; // shifts all the indexs to the left to erase which ever index was defined.
	}
	return count;
	
}

int IndexedMultiList::removeAll(char val) //Seachs for a value in the array and removes all of it, if its in more then 1 slot it only removes the first slot.
{
	empty(); // tests if the array is empty before going on.
	int number=0;
	for (int i=0;i<DEFAULT_MAX_ITEMS;i++)
	{
		if (array[i].value==val)
			{
				number=array[i].number; //Sets our temp varible to the .numbers value, so we know how many we removed.
				
				for (int j=i; j<DEFAULT_MAX_ITEMS-1; j++) // Nested for loop that shifts all the slots to left to remove the index slot of the value we killed.
				{
					array[j] = array[j+1]; 
				}
				return number; // returns the number of the value we removed. example if we are removing 33 E's it will print out 33
		    }
		
		
	}
	return false; //if val isnt found

}
