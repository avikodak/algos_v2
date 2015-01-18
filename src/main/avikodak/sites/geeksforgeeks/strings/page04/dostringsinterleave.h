/****************************************************************************************************************************************************
 *  File Name   		: dostringsinterleave.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\strings\page04\dostringsinterleave.h
 *  Created on			: Jan 16, 2015 :: 9:31:38 AM
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

#ifndef DOSTRINGSINTERLEAVE_H_
#define DOSTRINGSINTERLEAVE_H_

bool doStringsInterleave(char *firstUserinput,char *secondUserinput,char *thirdUserinput){
	if(firstUserinput[0] == '\0' && secondUserinput == '\0' && thirdUserinput == '\0'){
		return true;
	}
	if(thirdUserinput[0] == '\0'){
		return false;
	}
	bool truthValue = false;
	if(firstUserinput[0] != '\0'){
		truthValue = truthValue || (firstUserinput[0] == thirdUserinput[0] && doStringsInterleave(firstUserinput+1,secondUserinput,thirdUserinput+1));
	}else{
		truthValue = truthValue || (secondUserinput[0] == thirdUserinput[0] && doStringsInterleave(firstUserinput,secondUserinput+1,thirdUserinput+1));
	}
	return truthValue;
}

#endif /* DOSTRINGSINTERLEAVE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
