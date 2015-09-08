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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

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
