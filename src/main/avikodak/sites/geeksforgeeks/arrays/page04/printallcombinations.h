/****************************************************************************************************************************************************
 *  File Name   		: printallcombinations.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page04\printallcombinations.h
 *  Created on			: Dec 22, 2014 :: 11:03:43 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
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

#ifndef PRINTALLCOMBINATIONS_H_
#define PRINTALLCOMBINATIONS_H_
//Tested
void printAllCombinations(vector<int> userInput,vector<int> auxSpace,unsigned int r,unsigned int currentIndex = 0){
	if(userInput.size() < r || currentIndex > userInput.size()){
		return;
	}
	if(auxSpace.size() == r){
		printIVector(auxSpace,false);
		PRINT_NEW_LINE;
		return;
	}
	printAllCombinations(userInput,auxSpace,r,currentIndex+1);
	auxSpace.push_back(userInput[currentIndex]);
	printAllCombinations(userInput,auxSpace,r,currentIndex+1);
}

//Tested
void printAllCombinationsV2(vector<int> userInput,vector<int> auxSpace,unsigned int r,int start,unsigned int index){
	if(userInput.size() < r || index > userInput.size()){
		return;
	}
	if(index == r){
		printIVector(auxSpace,false);
		PRINT_NEW_LINE;
		return;
	}
	for(unsigned int counter = start;counter < userInput.size();counter++){
		auxSpace[index] = userInput[counter];
		printAllCombinationsV2(userInput,auxSpace,r,counter+1,index+1);
	}
}

#endif /* PRINTALLCOMBINATIONS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
