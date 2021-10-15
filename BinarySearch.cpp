#include <iostream>
#include <vector>
using namespace std;

//g++ -std=c++11 -o binary BinarySearch.cpp  for executing this source code

//Finding the target value in non-rotated array using Binary Search
//Function returned the target value index in the array or return -1 if it does not exist
int findValueArray(vector<int> arr, int target);

//Finding the target value in the rotated Array using Binary Search
//Function returned the target value index in the array or return -1 if it does not exist
int findValueRotatedArray(vector<int>arr, int target);

//Finding the mininum value in the rotated Array using Binary Search
//Function returned the minimum value in the array
int findMinRotatedArray(vector<int> arr);

//Output Messages for Error/Success for searching value in an array
void OutputToScreen(int returnVal)
{
	if(returnVal == -1)
	{
		cout << "No such element exists\n";
	}
	else
	{
		cout << "Value found at index: " << returnVal << endl;
	}
}


int main()
{
	//------------Arrays for Testing--------------
	vector <int> orderedArray1{0,1,2,3,4,5,6,7,8} ;
	vector <int> orderedArray2{2,4,5,8,9,11,22,33} ;

	vector <int> rotatedArray1{0,1,2,4,5,6,7} ;
	vector <int> rotatedArray2{7,0,1,2,4,5,6} ;
	vector <int> rotatedArray3{6,7,0,1,2,4,5} ;
	vector <int> rotatedArray4{5,6,7,0,1,2,4} ;
	vector <int> rotatedArray5{4,5,6,7,1,2} ;
	vector <int> rotatedArray6{2,4,5,6,7,0,1} ;
	vector <int> rotatedArray7{1,2,4,5,6,7,0} ;

	
	int resultFoundOrderedArray = 0;
	int rotatedOutFound = 0, rotatedMin = 0;

	cout << "-----------------Binary Search Applications-----------------\n";
	cout << "Searching for value in non-rotated array with Binary Search\n";
	/*-----------------Searching in array 1---------------------*/
	cout << "Searching in array 1: [0,1,2,3,4,5,6,7,8]\n";
	cout << "Looking for value 3.\n";
	resultFoundOrderedArray = findValueArray(orderedArray1, 3);
	OutputToScreen(resultFoundOrderedArray); //output to the screen
	cout << "Looking for value 9.\n";
	resultFoundOrderedArray = findValueArray(orderedArray1, 9);
	OutputToScreen(resultFoundOrderedArray); //output to the screen
	/*-----------------Searching in array 2---------------------*/
	cout << "\nSearching in array 2: [2,4,5,8,9,11,22,33]\n";
	cout << "Looking for value 11 \n";
	resultFoundOrderedArray = findValueArray(orderedArray2, 11);
	OutputToScreen(resultFoundOrderedArray);
	cout << "Looking for value 33 \n";
	resultFoundOrderedArray = findValueArray(orderedArray2, 33);
	OutputToScreen(resultFoundOrderedArray);

	/*-----------------Searching in rotated array---------------------*/
	cout << "\nSearching for value in rotated array with Binary Search\n";
	cout << "Searching in array 1: [0,1,2,4,5,6,7]\n";
	cout << "Looking for value 5 \n";
	rotatedOutFound = findValueRotatedArray(rotatedArray1, 5);
	OutputToScreen(rotatedOutFound);
	cout << "Searching in array 2: [7,0,1,2,4,5,6]\n";
	cout << "Looking for value 5 \n";
	rotatedOutFound = findValueRotatedArray(rotatedArray2, 5);
	OutputToScreen(rotatedOutFound);
	cout << "Searching in array 3: [6,7,0,1,2,4,5]\n";
	cout << "Looking for value 9 \n";
	rotatedOutFound = findValueRotatedArray(rotatedArray3, 9);
	OutputToScreen(rotatedOutFound);

	/*-------------Searching for min value in rotated array-------*/
	cout << "\nSearching for minimum value in rotated array with Binary Search\n";
	cout << "Searching for minimum value in array 4: [5,6,7,0,1,2,4]\n";
	rotatedMin = findMinRotatedArray(rotatedArray4);
	cout << "Minimum value found is " << rotatedMin << endl;
	cout << "Searching for minimum value in array 5: [4,5,6,7,1,2]\n";
	rotatedMin = findMinRotatedArray(rotatedArray5);
	cout << "Minimum value found is " << rotatedMin << endl;

	return 0;
}

//Finding the target value in non-rotated array using Binary Search
//Function returned the target index value in the array or return -1 if it does not exist
int findValueArray(vector<int> arr, int target)
{
	int sizeArray = arr.size();
	int left = 0, right = sizeArray-1, mid = 0;
	
	
	if( sizeArray == 0 || (sizeArray == 1 && target != arr[0] ) )//empty array or first element is not the target
		return -1;
	if(sizeArray == 1 && target == arr[0]) //first element is the target
		return 0;

	while(left <= right)
	{
		mid = left + (right - left)/2 ;
		if( arr[mid] == target ) 
			return mid;
		if (target > arr[mid])
			left = mid + 1; //exists in the right side of the subarray
		else
			right = mid - 1 ; //exists in the left side of the subarray
	}
	return -1; //not found
}

//Finding the target value in the rotated Array using Binary Search
//Function returned the target value index in the array or return -1 if it does not exist
int findValueRotatedArray(vector<int> arr, int target)
{
	int sizeArray = arr.size();
	int left = 0, right = sizeArray-1, mid = 0;

	if( sizeArray == 0 || (sizeArray == 1 && target != arr[0] ) )//empty array or first element is not the target
		return -1;
	if(sizeArray == 1 && target == arr[0]) //first element is the target
		return 0;


	while (left <= right)
	{
		mid = left + ( right - left )/2;
		if(arr[mid]== target) //target found
			return mid;
		if( arr[mid] >= arr[left] )  
		{
			if( target < arr[mid] && target >= arr[left] ) //exist in the left subarray
				right =  mid - 1;
			else					
				left = mid + 1;	//exist in the right subarray, right of mid
		}
		else  //arr[mid] <= arr[left]
		{
			if( target > arr[mid] && target <= arr[right] )  
				left = mid + 1;
			else
				right = mid - 1;
		}

	}
	return -1; //not found
}




//Finding the mininum value in the rotated Array using Binary Search
//Function returned the minimum value in the array
int findMinRotatedArray(vector<int> arr)
{
	int sizeArray = arr.size();
	int left = 0, right = sizeArray-1, mid = 0;
	if(sizeArray == 0) //empty array
		return -1;
	while(	left < right ) 
	{
		if(arr[left] < arr[right])
			return arr[left];  //indicating that the min has been found
		mid = left + (right -left)/2;
		if(arr[mid] >= arr[left]) //implies that min has to be on the right-side of min
			left = mid +1;
		else
			right = mid;
	}
	return arr[left];
}

