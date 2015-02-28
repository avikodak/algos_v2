/****************************************************************************************************************************************************
 *  File Name   		: helpfulmaths.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\helpfulmaths.h
 *  Created on			: Feb 28, 2015 :: 11:22:53 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/339/A
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
#define MAX_INPUT_SIZE 101

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef HELPFULMATHS_H_
#define HELPFULMATHS_H_

//Tested
void printAscExpression(){
	string userInput;
	cin >> userInput;
	sort(userInput.begin(),userInput.end());
	unsigned int counter = 0;
	while(userInput[counter] == '+'){
		counter++;
	}
	for(;counter < userInput.size();counter++){
		printf("%c",userInput[counter]);
		if(counter+1 < userInput.size()){
			printf("+");
		}
	}
}


#endif /* HELPFULMATHS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
