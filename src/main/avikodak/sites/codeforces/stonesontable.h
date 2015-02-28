/****************************************************************************************************************************************************
 *  File Name   		: stonesontable.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\stonesontable.h
 *  Created on			: Feb 28, 2015 :: 7:39:48 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/266/A
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
#define MAX_INPUT_SIZE 51

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef STONESONTABLE_H_
#define STONESONTABLE_H_

//Tested
void stonesToBeRemoved(){
	unsigned int size,counter = 0,stonesRemovedCounter = 0,frequency;
	char userInput[MAX_INPUT_SIZE];
	scanf("%d",&size);
	scanf("%s",userInput);
	while(counter < size){
		frequency = 1;
		while(counter + 1 < size && userInput[counter] == userInput[counter+1]){
			frequency++;
			counter++;
		}
		if(frequency > 1){
			stonesRemovedCounter += frequency-1;
		}
		counter++;
	}
	printf("%u",stonesRemovedCounter);
}

#endif /* STONESONTABLE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
