
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include<time.h>	//clock
#include<stdlib.h>  //exit
#include "book.h" 
using namespace std;



int main(int argc, char* argv[])
{


Book* array = NULL;
int N=0;

  ifstream file;
	file.open("books.csv");
	
	if (!file){
		cerr << "File cannot be opened!";
		exit(1);
	}

  string linee;
  while (getline(file, linee))
    {
        N++;
    }
  array = new Book[N];

  file.close();
	file.open("books.csv");

  string line;
  //this is the header line
	getline(file, line); 

  int tempbookID, tempratings_count, temptext_reviews_count, tempnum_pages;
  float tempaverage_rating;
  for(int i = 0; i<N; i++){
   
    //bookid
    getline(file, line , ',');
		stringstream id(line);
    string strID = id.str();

    //checking if all info in one cell
    int index1 = strID.find("\\");
    int index2 = strID.find("\"");

    //fixing the problem of all info in one cell input
    if(index1 != std::string::npos){
      strID.replace(index1,1, " ");}

    if(index2 != std::string::npos){
      strID.replace(index2,1, " ");}

    stringstream checkedID(strID);
    checkedID >>  tempbookID;
		array[i].bookID=tempbookID;

    //title
    getline(file, line , ',');
    array[i].title = line;

    //authors
    getline(file, line , ',');
    array[i].authors = line;

    //average rating
    //file >> line;
    getline(file, line , ',');
		stringstream rating(line);
    string str= rating.str();
    // check if bookId has "
    int index = str.find('\"');
    if(index != std::string::npos){
      str.replace(index,1, " ");
    }
    stringstream ratingchecked(str);
		ratingchecked>>tempaverage_rating;
		array[i].average_rating=tempaverage_rating;

    //isbn
    getline(file, line , ',');
    array[i].isbn = line;

    //isbn13
    getline(file, line , ',');
    array[i].isbn13 = line;

    //language code
    getline(file, line , ',');
    array[i].language_code = line;
   
    //page num
    getline(file, line , ',');
		stringstream page(line);
		page>>tempnum_pages;
		array[i].num_pages=tempnum_pages;

    //rating count
    getline(file, line , ',');
		stringstream countAll(line);
		countAll>>tempratings_count;
		array[i].ratings_count=tempratings_count;

    //text review count
    getline(file, line , ',');
		stringstream countText(line);
		countText>>temptext_reviews_count;
		array[i].text_reviews_count=temptext_reviews_count;

    //publication date
    getline(file, line , ',');
    array[i].publication_date = line;

    //publisher
    getline(file, line , '\r');
    array[i].publisher = line;

    //get rid of \n
    getline(file, line, '\n');
	}
	file.close();


  //for execution time of quicksort
  clock_t t; 
	t=clock();
  //quicksort
  quicksort(array,0,N/4);
  t=clock()-t;

//statistics of the algorithm
/*
  cout<<"first quicksort is executed" <<endl;
  cout<<"Execusion time of quicksort: "<<(float)t/CLOCKS_PER_SEC<<" seconds, t="<<t<<endl;
  cout<< "swap count: " << swapCount << endl;
  cout<< "partition count: " << partitionCount << endl << endl;
*/



// worst case for quicksort
/*
  cout<< "second quicksort is executed" <<endl;
  swapCount=0;
  partitionCount=0;
  clock_t t_2;
  t_2=clock();
  quicksort(array,0,N-1);
  t_2=clock()-t_2;
  cout<<"Execusion time of second quicksort: "<<(float)t_2/CLOCKS_PER_SEC<<" seconds, t="<<t_2<<endl;
  cout<< "swap count: " << swapCount << endl;
  cout<< "partition count: " << partitionCount << endl;*/


//sorted output
ofstream outputfile;
outputfile.open("sorted_books.csv");
outputfile << "bookID" << "," << "title" << "," << "authors" << "," << "average_rating" << "," << "isbn" << "," << "isbn13" << "," << "language_code" << "," << "num_pages" << "," << "ratings_count" << "," << "text_reviews_count" << "," << "publication_date" << "," << "publisher" <<"\r";
for(int i=0;i<N;i++){
    outputfile << array[i].bookID  << ",";
    outputfile << array[i].title  << ",";
    outputfile << array[i].authors  << ",";
    outputfile << array[i].average_rating  << ",";
    outputfile << array[i].isbn  << ",";
    outputfile << array[i].isbn13  << ",";
    outputfile << array[i].language_code  << ",";
    outputfile << array[i].num_pages  << ",";
    outputfile << array[i].ratings_count  << ",";
    outputfile << array[i].text_reviews_count << ",";
    outputfile << array[i].publication_date  << ",";
    outputfile << array[i].publisher  << "\r";
	}
  outputfile.close();

delete[]array;
return 0;
}


