#include <algorithm>
#include <cstring>

extern void recursion_full_permutation(char * c_array ,int begin, int end);

using namespace std;
int main()
{
	char c_array[] = {'2','1' ,' 4','4','\0'};
	int len = strlen(c_array);

	sort(c_array, c_array+len-1);
	recursion_full_permutation(c_array, 0, len -1);
}