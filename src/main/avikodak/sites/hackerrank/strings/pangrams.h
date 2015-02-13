/****************************************************************************************************************************************************
 *  File Name   		: pangrams.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\strings\pangrams.h
 *  Created on			: Feb 12, 2015 :: 8:51:55 PM
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

#ifndef PANGRAMS_H_
#define PANGRAMS_H_

//Tested
void isStringPangram(){
	string userInput;
	getline(cin, userInput);
	vector<bool> flags(26,false);
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] >= 'a' && userInput[counter] <= 'z'){
			flags[userInput[counter] - 'a'] = true;
		}else if(userInput[counter] >= 'A' && userInput[counter] <= 'Z'){
			flags[userInput[counter] - 'A'] = true;
		}
	}

	bool allAlphaUsed = true;
	for(unsigned int counter = 0;counter < flags.size();counter++){
		if(!flags[counter]){
			allAlphaUsed = false;
			break;
		}

	}
	printf("%s",allAlphaUsed?"pangram":"not pangram");
}

#endif /* PANGRAMS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
