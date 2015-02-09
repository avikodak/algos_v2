/****************************************************************************************************************************************************
 *  File Name   		: marcha1.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\easy\marcha1.h
 *  Created on			: Feb 9, 2015 :: 10:47:42 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.codechef.com/problems/MARCHA1
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

#ifndef MARCHA1_H_
#define MARCHA1_H_

//Tested
bool subsetForMoney(map<int,int> notesFrequency,int amount){
	if(amount == 0){
		return true;
	}
	map<int,int>::iterator itToNotesFrequency;
	for(itToNotesFrequency = notesFrequency.begin();itToNotesFrequency != notesFrequency.end();itToNotesFrequency++){
		if(itToNotesFrequency->first > amount){
			return false;
		}
		if(itToNotesFrequency->second > 0){
			itToNotesFrequency->second -= 1;
			if(subsetForMoney(notesFrequency,amount - itToNotesFrequency->first)){
				return true;
			}
			itToNotesFrequency->second += 1;
		}
	}
	return false;
}

//Tested
void solveSubsetMoneyProblem(){
	int testCases,note,amount,size;
	map<int,int> notesFrequency;
	map<int,int>::iterator itToNotesFrequency;
	scanf("%d",&testCases);
	while(testCases--){
		scanf("%d %d",&size,&amount);
		notesFrequency.clear();
		while(size--){
			scanf("%d",&note);
			if((itToNotesFrequency = notesFrequency.find(note)) == notesFrequency.end()){
				notesFrequency.insert(pair<int,int>(note,1));
			}else{
				notesFrequency[note] += 1;
			}
		}
		if(subsetForMoney(notesFrequency,amount)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}

#endif /* MARCHA1_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
