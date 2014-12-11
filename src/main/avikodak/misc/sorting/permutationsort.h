/****************************************************************************************************************************************************
 *  File Name   		: permutationsort.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\misc\sorting\permutationsort.h
 *  Created on			: Dec 11, 2014 :: 12:45:14 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PERMUTATIONSORT_H_
#define PERMUTATIONSORT_H_

/****************************************************************************************************************************************************/
/* 																O(N!) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> *permutationSort(vector<int> userInput,int currentIndex){
	if(currentIndex == userInput.size()){
		return isVectorSorted(userInput)?userInput:null;
	}
	vector<int> *result;
	for(unsigned int counter = currentIndex;counter < userInput.size();counter++){
		swap(userInput[currentIndex],userInput[counter]);
		result = permutationSort(userInput,currentIndex+1);
		if(result != null){
			return result;
		}
		swap(userInput[currentIndex],userInput[counter]);
	}
	return null;
}

#endif /* PERMUTATIONSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
