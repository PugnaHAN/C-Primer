#include "functions.h"
#include "common.h"

/* Elementary sorts */
#include "Selection.h"
#include "Insertion.h"
#include "Shell.h"
/* MergeSort */
#include "MergeSort.h"

#include "SortCompare.h"

using namespace std;


int main(int argc, char* argv[])
{
	vector<int> nums = { 3, 4, 1, 5, 2, 5, 6, 8, 7, 9, 0 };
	// Selection<int> selection;
	// selection.sort(nums);
	// Insertion<int> insertion;
	// insertion.sort(nums);
	// Shell<int> shell;
	// shell.sort(nums);
	// print(nums);
	SortBase<int>* insertion = new Insertion<int>();
	SortBase<int>* shell = new Shell<int>();
	SortBase<int>* selection = new Selection<int>();
	sortCompare(nums, insertion, shell, selection);
	MergeSort<int> mergeSort;
	mergeSort.sort(nums);
	print(nums);
}