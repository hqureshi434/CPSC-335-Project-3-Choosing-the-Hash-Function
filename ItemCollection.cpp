#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d;
	string str_barcode = std::to_string(barcode); // converts barcode to string
	char digit = str_barcode.at(0); // isolates digit at desired index
	d = digit - '0'; // stores digit value into variable d provided
	
    return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d;
	string str_barcode = std::to_string(barcode);
	char digit = str_barcode.at(1);
	d = digit - '0';
    return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d;
	string str_barcode = std::to_string(barcode);
	char digit = str_barcode.at(2);
	d = digit - '0';
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d;
	string str_barcode = std::to_string(barcode);
	char digit = str_barcode.at(3);
	d = digit - '0';
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d;
	string str_barcode = std::to_string(barcode);
	char digit = str_barcode.at(4);
	d = digit - '0';
    return d;
}

// function to return the hash value based on the sixth digit
unsigned int hashfct6(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d;
	string str_barcode = std::to_string(barcode);
	char digit = str_barcode.at(5);
	d = digit - '0';
    return d;
}

// function to return the hash value based on the seventh digit
unsigned int hashfct7(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d;
	string str_barcode = std::to_string(barcode);
	char digit = str_barcode.at(6);
	d = digit - '0';
    return d;
}


// Constructor for struct Item
Item::Item(string itemColor, string itemShape, string itemBrand,
		 unsigned int barcode):itemColor_(itemColor),itemShape_(itemShape), itemBrand_(itemBrand),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemColor;
    string itemShape;
    string itemBrand;
    unsigned int barcode;
    while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
			if (itemColor.size() > 0)
				addItem(itemColor, itemShape, itemBrand, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
  // TO BE COMPLETED
  // function that adds the specified pair of glasses to main display (i.e., to all hash tables)
	Item myItem(itemColor, itemShape, itemBrand, barcode); // object Item created
	hT1.insert({barcode, myItem}); // insert item into key barcode
	hT2.insert({barcode, myItem});
	hT3.insert({barcode, myItem});
	hT4.insert({barcode, myItem});
	hT5.insert({barcode, myItem});
	hT6.insert({barcode, myItem});
	hT7.insert({barcode, myItem});
}

bool ItemCollection::removeItem(unsigned int barcode) {
	
  // TO BE COMPLETED
  // function that removes the pair of glasses specified by the barcode from the display
  // if pair is found, then it is removed and the function returns true
  // else returns false
	std::unordered_map<unsigned int, Item, decltype(&hashfct1)>::const_iterator search1 = hT1.find(barcode); // to find specific key
	std::unordered_map<unsigned int, Item, decltype(&hashfct1)>::const_iterator search2 = hT2.find(barcode);
	std::unordered_map<unsigned int, Item, decltype(&hashfct1)>::const_iterator search3 = hT3.find(barcode);
	std::unordered_map<unsigned int, Item, decltype(&hashfct1)>::const_iterator search4 = hT4.find(barcode);
	std::unordered_map<unsigned int, Item, decltype(&hashfct1)>::const_iterator search5 = hT5.find(barcode);
	std::unordered_map<unsigned int, Item, decltype(&hashfct1)>::const_iterator search6 = hT6.find(barcode);
	std::unordered_map<unsigned int, Item, decltype(&hashfct1)>::const_iterator search7 = hT7.find(barcode);
	
	if (search1 == hT1.end() && search2 == hT2.end() && search3 == hT3.end() && search4 == hT4.end() &&
		search5 == hT5.end() && search6 == hT6.end() && search7 == hT7.end()){
		//cout << "NOT FOUND" << endl;
		return false;
	}	
	else{
		hT1.erase(barcode);
		hT2.erase(barcode);
		hT3.erase(barcode);
		hT4.erase(barcode);
		hT5.erase(barcode);
		hT6.erase(barcode);
		hT7.erase(barcode);
		return true;
	}
}

unsigned int ItemCollection::bestHashing() {
	// TO BE COMPLETED
  // function that decides the best has function, i.e. the ones among
  // fct1-fct7 that creates the most balanced hash table for the current
  // ItemCollection data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance
	
	unsigned int balance[7]; // array to store the difference ratios
	unsigned int highest, lowest; 
	 
	for (unsigned int j = 1; j <= 7; j++){ // iterates through each table
		 if(j == 1){
			highest = hT1.bucket_size(0); // default highest and lowest sizes
			lowest = hT1.bucket_size(0);
		 }
		 if(j == 2){
			highest = hT2.bucket_size(0);
			lowest = hT2.bucket_size(0);
		 }
		 if(j == 3){
			highest = hT3.bucket_size(0);
			lowest = hT3.bucket_size(0);
		 }
		 if(j == 4){
			highest = hT4.bucket_size(0);
			lowest = hT4.bucket_size(0);
		 }
		 if(j == 5){
			highest = hT5.bucket_size(0);
			lowest = hT5.bucket_size(0);
		 }
		 if(j == 6){
			highest = hT6.bucket_size(0);
			lowest = hT6.bucket_size(0);
		 }
		 if(j == 7){
			highest = hT7.bucket_size(0);
			lowest = hT7.bucket_size(0);
		 }
		 for (unsigned i=0; i < 10; i++) { // iterates through each cubby/bucket. 
			 if(j == 1){ 						// checks which table is being iterated
				 if (hT1.bucket_size(i) > highest)
					 highest = hT1.bucket_size(i); // identifies and stores highest and lowest values
				 if (hT1.bucket_size(i) < lowest)
					 lowest = hT1.bucket_size(i);
			}
			 if(j == 2){
				 if (hT2.bucket_size(i) > highest)
					 highest = hT2.bucket_size(i);
				 if (hT2.bucket_size(i) < lowest)
					 lowest = hT2.bucket_size(i);
			 }
			 if(j == 3){
				 if (hT3.bucket_size(i) > highest)
					 highest = hT3.bucket_size(i);
				 if (hT3.bucket_size(i) < lowest)
					 lowest = hT3.bucket_size(i);
			 }
			 if(j == 4){
				 if (hT4.bucket_size(i) > highest)
					 highest = hT4.bucket_size(i);
				 if (hT4.bucket_size(i) < lowest)
					 lowest = hT4.bucket_size(i);
			 }
			 if(j == 5){
				 if (hT5.bucket_size(i) > highest)
					 highest = hT5.bucket_size(i);
				 if (hT5.bucket_size(i) < lowest)
					 lowest = hT5.bucket_size(i);
			 }
			 if(j == 6){
				 if (hT6.bucket_size(i) > highest)
					 highest = hT6.bucket_size(i);
				 if (hT6.bucket_size(i) < lowest)
					 lowest = hT6.bucket_size(i);
			 }
			 if(j == 7){
				 if (hT7.bucket_size(i) > highest)
					 highest = hT7.bucket_size(i);
				 if (hT7.bucket_size(i) < lowest)
					 lowest = hT7.bucket_size(i);
			 }
		}
		balance[j-1] = highest - lowest; // calculates difference and stores into array position corresponding to table number. 
										// i.e. hT1 in index 0, hT2 in index 1, hT3 in index 2, etc...
	}
	unsigned int min_loc;
	min_loc = balance[0]; // default min value
	unsigned int index = 0;
	for (unsigned int i = 0; i < 7; i++){
		if (balance[i] < min_loc){ // finds the first occurrence of the smallest value in the array
			min_loc = balance[i];
			index = i;
		}
	}
	min_loc = index + 1; // stores table number that contains smallest ratio value. 
						 // i.e. if smallest value is in index 0, that refers to hT1. thus, return 1.
	
    return min_loc;
}

// ALREADY COMPLETED
size_t ItemCollection::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
