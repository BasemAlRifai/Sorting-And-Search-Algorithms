#include<iostream>
#include<fstream>
#include <cstdlib> 
#include<ctime>

using namespace std;
 
//Prototypes
void bubbleSort(int[], int);
int binarySearch(int[], int, int);
int linearSearch(int[], int, int);

//Main method
int main() {

	//File stream
	ifstream fileIn; //Defines a stream for input

	//Variables
	const int arraySize = 200; //Holds the size of the array
	int randomArray[arraySize]; //Holds the array of random numbers
	int keyElem; //Holds the user's key element
	int keyElemIndex; //Holds the key element's index (if found)


	//Creating a random array
	cout << "\nRandom array: " << endl; //Header
	srand((unsigned)time(0)); //Allows for randomness or else the array will always be the same every time it is run
	for (int i = 0; i < arraySize; i++) {
		randomArray[i] = (rand() % arraySize) + 1; //Creates a random number for each location in array
		cout << randomArray[i] << endl; // Displays the random list
	}


	//Break for sort
	cout << "\nPress any key to SORT array" << endl; //Display
	system("pause>nul"); //Pauses system so user can observe the program working


	//Sorting the array
	cout << "\nSorted array: " << endl; //Header 2
	bubbleSort(randomArray, arraySize); // Calls the bubblesort function


	//Displaying the sorted array
	for (int i = 0; i < arraySize; i++) {
		cout << randomArray[i] << "\n"; //Writes to the standard output
		//arrOut << randomArray[i] << "\n"; //Writes to the output file
	}


	//Finding key element
	cout << "\nPlease enter an key element value between 1 and 200: "; //Asks user for key element to search for
	cin >> keyElem; //Takes in the user's input
	while (keyElem < 1 || keyElem > arraySize) { //Constraints the input value
		cout << "\nPlease input a valid key element value: "; //Ask again
		cin >> keyElem;
	}


	//Break for binary search
	cout << "\nPress any key to search for key value using BINARY SEARCH" << endl; //Display
	system("pause>nul"); //Pauses system so user can observe the program working


	//Calling binary search
	keyElemIndex = binarySearch(randomArray, arraySize, keyElem); //Calls binarySearch()
	if (keyElemIndex > -1) {
		cout << "Key " << keyElem << " found at index " << keyElemIndex << " by Binary Search\n" << endl; //Prints to standard output the index location IF FOUND
		//arrOut << "Key " << keyElem << " found at index " << keyElemIndex << " by Binary Search\n" << endl; //Prints to output file the index location IF FOUND
	}
	else {
		cout << "Value not found!\n" << endl;
		//arrOut << "Value not found!\n" << endl;
	}


	//Break for linear search
	cout << "\nPress any key to search for key value using LINEAR SEARCH" << endl; //Display
	system("pause>nul"); //Pauses system so user can observe the program working


	//Calling linear search
	keyElemIndex = linearSearch(randomArray, arraySize, keyElem); //Calls linearSearch()
	if (keyElemIndex > -1) {
		cout << "Key " << keyElem << " found at index " << keyElemIndex << " by linear search\n" << endl; //Prints to standard output the index location IF FOUND
		//arrOut << "Key " << keyElem << " found at index " << keyElemIndex << " by linear searhch\n" << endl;
	} else {
		cout << "Value not found!\n" << endl;
		//arrOut << "Value not found!\n" << endl;
	}


	cout << "\n\nAll data written to 'arrayData.txt'" << endl;
	//arrOut.close(); //Closes the output file


	return 0;
}



/*
					bubbleSort

Function: To sort an array in order from least to greatest efficiently
Input: An array and size
Output: None
*/
void bubbleSort(int arr[], int arrSize) {

	bool flag = true; //Flag to stop the loop
	int temp; //Holds a value for swapping

	while(flag) {
		flag = false; //Starts with flag in false state to allow the loop to run once and stay in that position if flag is not turned to true
		for (int i = 0; i < arrSize-1; i++) //Scans all values but last value (it would cause a memory overflow)
		{
			if (arr[i] > arr[i + 1]) //If value in front of arr[i] is greater, swap
			{
				temp = arr[i]; //arr[i] original value stored in temp
				arr[i] = arr[i + 1]; //arr[i] gets the value in front of it
				arr[i + 1] = temp; //Assigns temp value that was arr[i]
				flag = true; //Sets flag to true so loop will run again
			}
		}
	}
}



/*
					binarySearch

Function: To find a value in an array efficiently
Input: An array, a size, and the search value
Output: The index location of the search value
*/
int binarySearch(int arr[], int arrSize, int searchValue) {

	int a = 0; //Low value
	int b = arrSize; //High value

	while (a <= b) {
		int mid = a + (b - a) / 2; //Adds the midpoint to the lower value to get the midpoint of a b
		if (arr[mid] == searchValue) { //If the value is at that index
			return mid;
		}
		else if (arr[mid] < searchValue) { //If midpoint is less than search value
			a = mid + 1; //Moves right 1 to search all values
		}
		else {
			b = mid - 1; //If midpoint is greater than search value; Moves left 1 to search all values
		}
	}

	return -1;

}



/*
					linearSearch

Function: To find a value in an array, but not as effeciently as binary search. Linear searches through EVERY value until search term is reached or all values are looked through. 
Input: An array, a size, and the search value
Output: The index location of the search value
*/
int linearSearch(int arr[], int arrSize, int searchValue) {

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == searchValue) { //If value at location i equals search value
			return i; //Return it
		}
	}

	return -1;

}



/* Sample output:

Random array:
55
20
166
183
24
115
142
70
86
12
128
34
71
145
111
4
46
184
32
54
90
154
34
146
11
67
189
54
27
100
38
54
2
150
26
106
106
8
18
26
164
34
29
24
3
146
124
109
47
47
26
158
117
101
98
16
173
96
158
146
43
5
21
130
139
125
188
130
39
107
136
116
107
136
195
164
11
92
62
109
139
40
6
87
110
178
130
160
75
129
83
192
53
186
100
169
194
58
181
158
199
5
155
35
50
38
162
174
128
15
197
149
88
148
5
136
183
179
81
120
109
78
53
152
72
125
94
43
143
109
108
39
130
126
17
8
145
12
137
87
186
43
195
60
79
9
199
42
79
30
56
171
83
143
132
163
180
4
145
185
147
30
114
67
177
101
90
122
24
49
105
78
81
80
141
43
80
15
131
188
37
132
86
78
189
107
55
41
56
144
149
90
76
189
15
148
146
132
136
89

Press any key to SORT array

Sorted array:
2
3
4
4
5
5
5
6
8
8
9
11
11
12
12
15
15
15
16
17
18
20
21
24
24
24
26
26
26
27
29
30
30
32
34
34
34
35
37
38
38
39
39
40
41
42
43
43
43
43
46
47
47
49
50
53
53
54
54
54
55
55
56
56
58
60
62
67
67
70
71
72
75
76
78
78
78
79
79
80
80
81
81
83
83
86
86
87
87
88
89
90
90
90
92
94
96
98
100
100
101
101
105
106
106
107
107
107
108
109
109
109
109
110
111
114
115
116
117
120
122
124
125
125
126
128
128
129
130
130
130
130
131
132
132
132
136
136
136
136
137
139
139
141
142
143
143
144
145
145
145
146
146
146
146
147
148
148
149
149
150
152
154
155
158
158
158
160
162
163
164
164
166
169
171
173
174
177
178
179
180
181
183
183
184
185
186
186
188
188
189
189
189
192
194
195
195
197
199
199

Please enter an key element value between 1 and 200: 197

Press any key to search for key value using BINARY SEARCH
Key 197 found at index 197 by Binary Search


Press any key to search for key value using LINEAR SEARCH
Key 197 found at index 197 by linear search



All data written to 'arrayData.txt'
Press any key to continue . . .
*/