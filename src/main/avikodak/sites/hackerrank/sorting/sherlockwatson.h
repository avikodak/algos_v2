/****************************************************************************************************************************************************
 *  File Name   		: sherlockwatson.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\sorting\sherlockwatson.h
 *  Created on			: Feb 12, 2015 :: 4:41:24 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
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

#ifndef SHERLOCKWATSON_H_
#define SHERLOCKWATSON_H_

//Tested
void reverseArray(vector<long int> &userInput,int start,int end){
	while(start < end){
		swap(userInput[start],userInput[end]);
		start++;
		end--;
	}
}

//Tested
void rotateArray(vector<long int> &userInput,long int rotateBy){
	if(rotateBy == 0){
		return;
	}
	rotateBy = rotateBy % userInput.size();
	reverseArray(userInput,0,userInput.size() - rotateBy-1);
	reverseArray(userInput,userInput.size() - rotateBy,userInput.size()-1);
	reverseArray(userInput,0,userInput.size()-1);
}

//Tested
void queriesInRotatedArray(){
	long int size,rotateBy,queryCount,query,input;
	scanf("%ld %ld %ld",&size,&rotateBy,&queryCount);
	vector<long int> userInput;
	while(size--){
		scanf("%ld",&input);
		userInput.push_back(input);
	}
	rotateArray(userInput,rotateBy);
	while(queryCount--){
		scanf("%ld",&query);
		printf("%ld\n",userInput[query]);
	}
}

#endif /* SHERLOCKWATSON_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
