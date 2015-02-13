/****************************************************************************************************************************************************
 *  File Name   		: longestincseq.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\dp\longestincseq.h
 *  Created on			: Feb 12, 2015 :: 8:52:03 PM
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

#ifndef LONGESTINCSEQ_H_
#define LONGESTINCSEQ_H_

//Tested
void printLengthLIS(){
	long int input,size;
	unsigned int counter;
	vector<long int> auxSpace;
	scanf("%ld",&size);
	while(size--){
		scanf("%ld",&input);
		if(auxSpace.size() == 0 || auxSpace[0] > input){
			if(auxSpace.size() == 0){
				auxSpace.push_back(input);
			}else{
				auxSpace[0] = input;
			}
		}else if(auxSpace[auxSpace.size()-1] < input){
			auxSpace.push_back(input);
		}else{
			counter = 0;
			while(counter < auxSpace.size() && input > auxSpace[counter]){
				counter++;
			}
			auxSpace[counter] = input;
		}
	}
	printf("%u",auxSpace.size());
}

#endif /* LONGESTINCSEQ_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
