/****************************************************************************************************************************************************
 *  File Name   		: rotatearray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\rotatearray.h
 *  Created on			: Nov 25, 2014 :: 7:08:55 PM
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

#ifndef ROTATEARRAY_H_
#define ROTATEARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void rotateArrayAuxspace(vector<int> &userInput,unsigned int rotateBy){
	if(userInput.size() == 0){
		return;
	}
	vector<int> auxSpace;
	unsigned int counter;
	for(counter = 0;counter < rotateBy;counter++){
		auxSpace.push_back(userInput[counter]);
	}
	int fillCounter = -1;
	while(counter < userInput.size()){
		userInput[++fillCounter] = userInput[counter++];
	}
	for(counter = 0;counter < auxSpace.size();counter++){
		userInput[++fillCounter] = auxSpace[counter];
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void rotateArrayByOne(vector<int> &userInput){
	int temp = userInput[0];
	for(unsigned int counter = 0;counter < userInput.size()-1;counter++){
		userInput[counter] = userInput[counter+1];
	}
	userInput[userInput.size()-1] = temp;
}

//Tested
void rotateArrayON2(vector<int> &userInput,unsigned rotateBy){
	while(rotateBy--){
		rotateArrayByOne(userInput);
	}
}

#endif /* ROTATEARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
