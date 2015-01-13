/****************************************************************************************************************************************************
 *  File Name   		: maxlengthwithoutrepeating.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page04\maxlengthwithoutrepeating.h
 *  Created on			: Jan 13, 2015 :: 8:17:43 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
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

#ifndef MAXLENGTHWITHOUTREPEATING_H_
#define MAXLENGTHWITHOUTREPEATING_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int maxLengthWithoutRepeatingON(char *userInput){
	if(userInput == null || userInput[0] == '\0'){
		return 0;
	}
	int length = strlen(userInput);
	int maxLength = INT_MIN,currentLength = 0;
	hash_map<char,int> charIndexMap;
	hash_map<char,int>::iterator itToCharIndexMap;
	for(int counter = 0;counter < length;counter++){
		if((itToCharIndexMap = charIndexMap.find(userInput[counter])) == charIndexMap.end() || itToCharIndexMap->second < counter - currentLength){
			currentLength++;
		}else{
			//printf("%d\t",currentLength);
			maxLength = max(maxLength,currentLength);
			currentLength = counter - itToCharIndexMap->second;
		}
		charIndexMap[userInput[counter]] = counter;
	}
	return maxLength;
}

#endif /* MAXLENGTHWITHOUTREPEATING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
