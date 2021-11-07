//Implementation for session1_seq_search.h

#include "ss.h"

//Search for the first occurrence of key in arr
//Returns the 0-based index of the first occurrence of key in arr on successful search.
//Otherwise, returns -1.
int seqsearch(int *arr, int n, int key) 
{
	int j;
	for (j = 0; j < n; ++j) 
      {
		if(arr[j] == key) 
            {
			return j; //returns the 0-based index of the first occurrence of key(SUCCESSFUL SEARCH)
            }
      }
	return -1; //returns -1(DENOTES UNSUCCESFUL SEARCH)
}
