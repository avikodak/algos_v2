/****************************************************************************************************************************************************
 *  File Name   		: doublecola.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\doublecola.h
 *  Created on			: Feb 28, 2015 :: 10:29:08 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/82/A
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

#ifndef DOUBLECOLA_H_
#define DOUBLECOLA_H_

//Tested
void printCharacter(){
	long int userInput;
	scanf("%ld",&userInput);
	long int level = floor(log2(ceil((double)userInput/(double)5)));
	long int character = ceil(((double)userInput - 5*((double)pow(2,level)-1))/((double)pow(2,level)));
	switch(character){
	case 1:
		printf("Sheldon");
		break;
	case 2:
		printf("Leonard");
		break;
	case 3:
		printf("Penny");
		break;
	case 4:
		printf("Rajesh");
		break;
	case 5:
		printf("Howard");
		break;
	}
}

#endif /* DOUBLECOLA_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
