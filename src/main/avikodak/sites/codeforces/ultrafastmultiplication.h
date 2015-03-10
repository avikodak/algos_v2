/****************************************************************************************************************************************************
 *  File Name   		: ultrafastmultiplication.h 
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\ultrafastmultiplication.h
 *  Created on			: Mar 5, 2015 :: 8:12:47 AM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/61/A
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

#ifndef ULTRAFASTMULTIPLICATION_H_
#define ULTRAFASTMULTIPLICATION_H_

//Tested
void getXORResultVeryLong(){
	char firstUserInput[CODEFORCES_MAX_INPUT_SIZE];
	char secondUserInput[CODEFORCES_MAX_INPUT_SIZE];
	scanf("%s %s",firstUserInput,secondUserInput);
	int lengthOfInputString = strlen(firstUserInput);
	for(int counter = 0;counter < lengthOfInputString;counter++){
		if(firstUserInput[counter] == secondUserInput[counter]){
			printf("0");
		}else{
			printf("1");
		}
	}
}

#endif /* ULTRAFASTMULTIPLICATION_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
