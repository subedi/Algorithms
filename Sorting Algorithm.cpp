#include<iostream>
using namespace std;

template <class T> 
class sort_algo
{
	public:
	
	T swap(T&, T&);
	T sel_sort(T arr[], T size);
	T bub_sort(T arr[], T size);
	T ins_sort(T arr[], T size);
	T merge_sort(T arr[], T first, T last);
	T merge(T arr[], T,T,T,T );


};


template <class T> 
T sort_algo <T>::swap(T &item1, T &item2)
{
	T temp;
	
	temp = item1;
	item1 = item2;
	item2 = temp;
}


// selection sort algorithm

template <class T> 
T sort_algo <T>::sel_sort(T arr[], T size)
{
	int datamove=0;
	int comparision=0;

	for(int pass=0; pass<size-1; pass++)
	{
		int smallest = pass; // assume this is smallest index
		comparision= pass+comparision;
		
	//--- Look over remaining elements to find smallest.
	for (int i=pass+1; i<size; i++) 
	{
            if (arr[i] < arr[smallest]) 
		{
              //remember index for latter swap.
		smallest = i;
		}
	}
	
	// swap smallest remaining elements
	swap(arr[pass], arr[smallest]);
	datamove++;
	}
	
	cout<<"comparision is: "<<comparision<<endl;
	cout<<" datamove: "<<datamove<<endl;
} 	

// bubble sort algorithm


template <class T> 
T sort_algo <T>::bub_sort(T arr[], T size) {

	int datamove=0;
	int comparision=0;

      bool swapped = true;

      int j = 0;

      int tmp;

      while (swapped) {

            swapped = false;

            j++;

            for (int i = 0; i < size - j; i++) {

		comparision++;

                  if (arr[i] > arr[i + 1]) {
			
			swap(arr[i], arr[i+1]);

                        swapped = true;
				
				datamove++;

                  }
            }
      }

	cout<<"comparision is: "<<comparision<<endl;
	cout<<" datamove: "<<datamove<<endl;
}

template <class T>
T sort_algo<T>:: ins_sort(T arr[], T length) {
      int i, j, tmp;	
	int datamove=0;
	int comparision=0;
      for (i = 1; i < length; i++) {
            j = i;
		datamove++;
            while (j > 0 && arr[j - 1] > arr[j]) {
                  swap(arr[j], arr[j-1]);
				datamove++;
				comparision++;
                  j--;
            }
      }
	cout<<"comparision is: "<<comparision<<endl;
	cout<<" datamove: "<<datamove<<endl;
}


template <class T> 
T sort_algo <T>:: merge(T array[], T leftFirst, T leftLast, T rightFirst, T rightLast)
{
	T tempArray[100];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while((leftFirst<=leftLast) && (rightFirst <= rightLast))
	{
		if(array[leftFirst] < array[rightFirst])
		{
			tempArray[index]=array[leftFirst];
			leftFirst++;
		}
		else
		{
			tempArray[index]=array[rightFirst];
			rightFirst++;	
		}
			index++;
	}

	while(leftFirst<=leftLast)
	// copy remnaining items from left half
	{
		tempArray[index]=array[leftFirst];
		leftFirst++;
		index++;
	}

	while(rightFirst<=rightLast)
	// copy remnaining items from right half
	{
		tempArray[index]=array[rightFirst];
		rightFirst++;
		index++;
	}

	for( index=saveFirst; index<=rightLast; index++)
		array[index]=tempArray[index];
	
}

template <class T> 
T sort_algo <T>:: merge_sort(T array[], T first, T last)
{
	if(first<last)
	{
		int middle = (first+last)/2;
		merge_sort(array, first, middle);
		merge_sort(array, middle+1, last);
		merge(array, first, middle, middle+1, last);
	}
}






int main()
{
cout<<"\n\n |Selection Sort| vs |Bubble Sort| vs |Insertion Sort| vs |Merge Sort| "<<endl<<endl;
cout<<"Random 100 items are: "<<endl;

sort_algo<int> int_array;
sort_algo<char> char_array;

int a[100];
int b[100];
int c[100];
int d[100];


for(int i=0; i<100; i++)
{
	a[i]=rand()%100;
	b[i]=a[i];
	c[i]=a[i];
	d[i]=a[i];
	
	cout<<a[i]<< " ";
	

}
cout<<endl<<endl;


/* Selection sort */
int_array.sel_sort(a, 100);
cout<<" Selction sorted array is: "<<endl;
for(int i=0; i<100; i++)
{
	cout<<a[i]<<" ";
}
cout<<endl<<endl;


/* Bubble sort */
int_array.bub_sort(b, 100);
cout<<" Bubble sorted array is: "<<endl;
for(int i=0; i<100; i++)
{
	cout<<b[i]<<" ";
}
cout<<endl<<endl;

/* insertion sort */
int_array.ins_sort(c, 100);
cout<<" Insertion sorted array is: "<<endl;
for(int i=0; i<100; i++)
{
	cout<<c[i]<<" ";
}
cout<<endl<<endl;

/* merge sort */
cout<<" Merge Sort sorted array is: "<<endl;
int_array.merge_sort(d, 0,99);
cout<<"sorted array is"<<endl;
for(int i=0; i<100; i++)
{
	cout<<d[i]<<" ";
}
cout<<endl<<endl;


// end of main
}

