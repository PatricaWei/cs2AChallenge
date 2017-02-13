//
//  main.cpp
//  FindStats
//    
//  Created by Anand Venkataraman on 2/8/17.
//  Completed by Patricia Wei on 2/12/17.
//  Copyright © 2017 Anand Venkataraman. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// The following methods are stubs, meaning incomplete functions.
// You need to complete them and adjust their code to return the 
// correct values. Hopefully the function names are self-explanatory.
// If in doubt, ask in the forum.
//
int getArrayMin(int array[], int size) {
   int min = array[0];

   for(int i=0; i < size; i++)
   {
      if (array[i] < min)
      {
         min = array[i];
      }
   }

   return min;
}

int getArrayMax(int array[], int size) {
   int max = array[0];

   for(int i = 0; i < size; i++)
   {
      if(array[i] > max)
      {
         max = array[i];
      }
   }

   return max;
}

int getArrayMean(int array[], int size) {
   long sum = 0;
   int average = 0;

   for(int i=0; i < size; i++)
   {
      sum += array[i];
   }

   average = int (sum / size);
   return average;
}

int getCountOfTargetInArray(int array[], int size, int target) {
   int count = 0;

   for(int i=0; i < size; i++)
   {
      if(array[i] == target)
      {
         count++;
      }
   }
   return count;
}


int* createHistogram(int array[], int arraySize)
{
   int const HISTOGRAM_SIZE = 101;
   int* histogram = new int[HISTOGRAM_SIZE];

   for(int i=0; i < HISTOGRAM_SIZE; i++)
   {
      for(int k=0; k < arraySize; k++)
      {
         if(array[k]==i)
         {
            histogram[i] += 1;
         }
      }
   }
   return histogram;
}

void printHistogram(int histogram[], int size)
{
   cout << "Number\t\t" << "Frequency\t\t"<< endl;
   for(int i=0; i < size; i++)
   {
      cout << i << "\t\t\t\t" << histogram[i] << endl;
   }
   cout << endl;
}


int main(int argc, const char * argv[]) {
    // 1. Create an array of 1MM integers
    
    // 2. Stuff a million random ints into this array
    
    // 3. Call each of the above methods on this array and print
    //    the result.

    // 4. Pick some random target number and find the number of
    //    occurrences of this target in the array
    
    // 5. Histogram it. (Harder challenge) Use a smaller range to stuff
    //    the array, e.g. 0-100 Count the frequencies of each of these numbers
    //    in the array. e.g. 1 occurs X times, 2 occurs Y times, etc.

   int *numbers;
   int const LENGTH = 1000000;

   numbers = new int[LENGTH];

   int randomNum;

   for(int i=0; i < LENGTH; i++)
   {
      randomNum = rand()%101;
      numbers[i] = randomNum;
   }

   int min = getArrayMin(numbers, LENGTH);
   int max = getArrayMax(numbers, LENGTH);
   int mean = getArrayMean(numbers, LENGTH);

   cout << "Min: " << min << endl;
   cout << "Max: " << max << endl;
   cout << "Mean: " << mean << endl;
   cout << endl;

   int target = 55; //can be changed anytime
   int targetCount = getCountOfTargetInArray(numbers, LENGTH, target);
   cout << "The target number, " << target << " appears " << targetCount
        << " times." << endl << endl;

   int* histogram = createHistogram(numbers, LENGTH);
   printHistogram(histogram, 101);

   delete[] numbers;
   delete[] histogram;
}

/*----------- OUTPUT -------------
Min: 0
Max: 100
Mean: 49

The target number, 55 appears 9953 times.

Min: 0
Max: 100
Mean: 49

The target number, 55 appears 9953 times.

Number		Frequency		
0				9901
1				9998
2				10083
3				9780
4				9793
5				9844
6				9899
7				9865
8				9981
9				9992
10				9929
11				10135
12				9812
13				9908
14				9801
15				9961
16				10065
17				9702
18				10046
19				9953
20				9981
21				9965
22				10024
23				9965
24				9914
25				10089
26				9898
27				9789
28				9865
29				9824
30				9754
31				10024
32				9982
33				9812
34				10025
35				9988
36				9743
37				10028
38				9824
39				9756
40				9862
41				10131
42				9821
43				9868
44				9998
45				9946
46				9775
47				9908
48				9722
49				9769
50				9857
51				9807
52				9994
53				9974
54				9862
55				9953
56				9804
57				9947
58				9995
59				9867
60				9880
61				9861
62				9947
63				9748
64				9787
65				9836
66				9786
67				9806
68				9922
69				10007
70				9993
71				9940
72				9827
73				9908
74				9947
75				9784
76				9954
77				9939
78				9834
79				9926
80				10096
81				9916
82				9834
83				10094
84				10018
85				9948
86				9872
87				9848
88				9763
89				9967
90				9791
91				9737
92				9788
93				10004
94				9883
95				9937
96				9705
97				9859
98				9842
99				10038
100				9870

Program ended with exit code: 0
Program ended with exit code: 0
--------------------------------*/

