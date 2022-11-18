#include <iostream>
#include<cstdlib>

using namespace std;
static long int swapCount = 0;
static long int partitionCount = 0;


// class to keep every book and its info
class Book{
    public:
	int bookID;
	string title;
	string authors;
	float average_rating;
	string isbn;
  string isbn13;
	string language_code;
	int num_pages;
	int ratings_count;
	int text_reviews_count;
	string publication_date;
	string publisher;
};

//partition for quicksort
int partition(Book array[], int low, int high){
    //counting number of partition
    partitionCount++;
    // assign i,j and pivot
    int i = low;
    int j= low;
    Book pivot = array[high];
    do
    {
        //if both the values at i and j are smaller, continue (j must not reach to the pivot)
        while (array[i].average_rating <= pivot.average_rating &&  array[j].average_rating <= pivot.average_rating && j <high )
        {
            j++;
            i++;
        }
        //if value at j is bigger than pivot,  (j must not reach to the pivot)
        while (array[j].average_rating > pivot.average_rating && j <high)
        {
            j++;
            //checking if we reached to the pivot
            if(j==high){break;}
            swap(array[i],array[j]);
            //update swap count
            swapCount++;

            if(array[i].average_rating <= pivot.average_rating ){
              i++;
            }
        }
        //put pivot into pos,t,on
        if(j==high){
          swap(array[i],array[j]);
          swapCount++;
          return i;
          break;
        } 
    } while(j>=i) ;
    return i;
}

void quicksort(Book array[], int low, int high){
  if (low<high)
  {
    int pivot = partition(array, low, high);
    quicksort(array,low,pivot-1);
    quicksort(array,pivot+1,high);
  }
}






/*      if(i==pivot){
      swap(array[j],array[i]); 
      }*/