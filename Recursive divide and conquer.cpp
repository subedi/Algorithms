/* 
   Program: implementation of following algorithm using divide and
   conquer or decrease and conquer algorithm in recursive manner.

   Programmer: Uday Subedi, Algorithm analysis
*/

#include <iostream>
using namespace std;

int cnt=0;

/* prototypes */

// summation prototype
int sum(int A[], int low, int high);

// maximum prototype
int max(int A[], int low, int high);

//maximum index prototype
int maxIndex(int A[], int low, int high);

// key index prototype
int keyIndex(int A[], int low, int high, int key);

// count key protoype
int count(int A[], int low, int high, int n);

// is sorted prototype
bool isSorted(int A[], int low, int high);

// reverse array prototype
void reverse(int A[], int low, int high);

/* Driver implementation */

int main()
{
// user array input
int size; int key; int num;

cout<<"Enter array size: "; cin>>size;
cout<<"Enter array elements: "<<endl;

int array[size];
for(int i=0; i<size; i++)
cin>>array[i];

cout<<"\nEnter search key: "; cin>>key;
cout<<"Enter the counting value: "; cin>>num;

int low=0; int high=size-1;

cout<<"\nSum of array is "<< sum(array, low, high)<<endl;
cout<<"Max value of array is "<<max(array, low, high)<<endl;
cout<<"Index of max value is "<< 1+maxIndex(array, low, high)<<endl;

cout<<"Index of search key ("<< key<<") is "<< 1+keyIndex(array, low, high, key)<<endl;
cout<<"Count of number "<<num <<" is "<<count(array, low, high, num)<<endl;

// sort implementation
if(isSorted(array, low, high))
cout<<"Array is sorted"<<endl<<endl;
else
cout<<"Array is not sorted"<<endl<<endl;

// reverse implementation
cout<<"The reversed array is "<<endl;
reverse(array, low, high);
for(int i=0; i<size; i++)
cout<<array[i]<<" ";

cout<<endl<<endl;
}

/* Algorithm implementation */

// returns the sum of array
int sum(int A[], int low, int high)
{
        if(low==high)
        {
               return A[low];
        }
        else
        {
               return  A[low] + sum(A, low+1, high);
        }
}

// returns the maximum value 
int max(int A[], int low, int high)
{
	if(low<high)
	{
		if(A[low]<A[high])
		return max(A, low+1, high);
		else	
		return max(A, low, high-1);
	}
	
	return A[high];
}

// returns the index of maximum value
int maxIndex(int A[], int low, int high)
{
        if(low<high)
        {
                if(A[low]<A[high])
                return maxIndex(A, low+1, high);
                else
                return maxIndex(A, low, high-1);
        }

        return high;
}

// returns the index of search key
int keyIndex(int A[], int low, int high, int key)
{
	if(low <= high)
	{
		int mid = (low+high)/2;

		if(key == A[mid])
			return mid;
		else if(key > A[mid])
			return keyIndex(A, mid+1, high, key);
		else
			return keyIndex(A, low, mid-1, key);
	}
	return -1;
}

// returns the count of search value n
int count(int A[], int low, int high, int n)
{	
       	if(low <= high)
        {
                if(n == A[low])
               	cnt++;

              	count(A, low+1, high, n);
        }
        return cnt;
}
			
// returns if the array is sorted or not
bool isSorted(int A[], int low, int high)
{
	if(low < high)
        {
                int mid = (low+high)/2;

                if(A[mid-1]> A[mid])
                        return false;
		else
		{
                        return isSorted(A, mid+1, high);
                        return isSorted(A, low, mid-1);
		}
        }
	return true;
}

void reverse(int A[], int low, int high)
{
	if(low<high)
	{
		int temp = A[low];
		A[low]=A[high];
		A[high]=temp;
	
	reverse(A, low+1, high-1);
	}
}
