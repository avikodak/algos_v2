/****************************************************************************************************************************************************
 *  File Name   		: nextgreaterelement.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\nextgreaterelement.h
 *  Created on			: Nov 26, 2014 :: 6:27:12 PM
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

#ifndef NEXTGREATERELEMENT_H_
#define NEXTGREATERELEMENT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printNextGreatestElement(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	stack<int> auxSpace;
	for(int counter = userInput.size()-1;counter >= 0;counter--){
		while(!auxSpace.empty() && auxSpace.top() > userInput[counter]){
			auxSpace.pop();
		}
		if(auxSpace.empty()){
			printf("%d",INT_MAX);
		}else{
			printf("%d",auxSpace.top());
		}
		auxSpace.push(userInput[counter]);
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void printNextGreatestElement(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	bool nextGreatestFound;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		nextGreatestFound = false;
		for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] > userInput[outerCounter]){
				printf("%d\t",userInput[innerCounter]);
				nextGreatestFound = true;
				break;
			}
		}
		if(!nextGreatestFound){
			printf("%d",INT_MAX);
		}
	}
}

#endif /* NEXTGREATERELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
