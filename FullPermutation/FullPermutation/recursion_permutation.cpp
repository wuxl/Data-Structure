#include<iostream>
#include <algorithm>
using namespace std;

static bool is_swap(char * c_array, int begin, int end)
{
	for(int i = begin; i < end; i++){
		if(c_array[i] == c_array[end])
			return false;
	}
	return true;
}

//end is strlen(c_array) - 1 
void recursion_full_permutation(char * c_array ,int begin, int end)
{	
	if(begin == end){
		cout<<c_array<<" ";		
	}
	else
	{

		for(int i = begin; i <= end; i++){
			if(is_swap(c_array,begin, i))
			{
				swap(c_array[begin],c_array[i]);
				recursion_full_permutation(c_array, begin+1, end);
				swap(c_array[begin], c_array[i]);
			}
		}		
	}
}