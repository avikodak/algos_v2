/****************************************************************************************************************************************************
 *  File Name   		: reversearray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\reversearray.h
 *  Created on			: Nov 25, 2014 :: 6:38:54 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/write-a-program-to-reverse-an-array/
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
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

#ifndef REVERSEARRAY_H_
#define REVERSEARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reverseArrayMain(vector<int> &userInput,unsigned int &startIndex,unsigned int endIndex){
	if(userInput.size() == 0 || endIndex >= userInput.size()){
		return;
	}
	reverseArrayMain(userInput,startIndex,endIndex+1);
	if(startIndex < endIndex){
		swap(userInput[startIndex],userInput[endIndex]);
		startIndex++;
	}
}

//Tested
void rReverseArray(vector<int> &userInput){
	unsigned int startIndex = 0;
	reverseArrayMain(userInput,startIndex,0);
}

//Tested
void reverseArrayIterative(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	while(frontCrawler < rearCrawler){
		swap(userInput[frontCrawler],userInput[rearCrawler]);
		frontCrawler++;
		rearCrawler--;
	}
}

//Tested
void reverseArrayAuxspace(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	stack<int> auxSpace;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		auxSpace.push(userInput[counter]);
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[counter] = auxSpace.top();
		auxSpace.pop();
	}
}

#endif /* REVERSEARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
