/****************************************************************************************************************************************************
 *  File Name   		: prime1.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\spoj\prime1.h
 *  Created on			: Feb 3, 2015 :: 12:38:15 PM
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
#define MAX_SIZE_PRIME 1000000002

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef PRIME1_H_
#define PRIME1_H_

void printPrimeNumbers(){
	vector<bool> auxSpace(MAX_SIZE_PRIME,true);
	long long int counter = 2;
	long long int low,high;
	int testCases;
	for(long long int counter = 4;counter < MAX_SIZE_PRIME;counter+=2){
		auxSpace[counter] = false;
	}
	for(long long int outerCounter = 2;outerCounter < MAX_SIZE_PRIME;outerCounter += 2){
		if(auxSpace[outerCounter]){
			counter = 2;
			while(counter * outerCounter < auxSpace.size()){
				auxSpace[counter*outerCounter] = false;
				counter++;
			}
		}
	}
	scanf("%d",&testCases);
	while(testCases--){
		cin >> low;
		cin >> high;
		for(long long int counter = low;counter <= high;counter++){
			if(auxSpace[counter]){
				cout << counter << endl;
			}
		}
		printf("\n");
	}
}

#endif /* PRIME1_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
