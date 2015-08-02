/****************************************************************************************************************************************************
 *  File Name                   : poisnousplants.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\competitions\countercode2015\poisnousplants.h
 *  Created on                  : Aug 2, 2015 :: 6:36:02 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested But TimeOut
 *  URL                         : https://www.hackerrank.com/contests/countercode/challenges/poisonous-plants
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef POISNOUSPLANTS_H_
#define POISNOUSPLANTS_H_

//Tested
bool isSortedDesc(vector<unsigned int> userInput){
	if(userInput.size() == 0){
		return true;
	}
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		if(userInput[counter] > userInput[counter-1]){
			return false;
		}
	}
	return true;
}

//Tested
void getNoOfDays(){
	unsigned int size,input;
	vector<unsigned int> userInput;
	vector<unsigned int> temp;
	scanf("%u",&size);
	while(size--){
		scanf("%u",&input);
		userInput.push_back(input);
	}
	unsigned int daysCount = 0;
	do{
		if(isSortedDesc(userInput)){
			break;
		}
		temp.clear();
		temp.push_back(userInput[0]);
		daysCount++;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			if(userInput[counter] <= userInput[counter-1]){
				temp.push_back(userInput[counter]);
			}
		}
		userInput = temp;
	}while(true);
	cout << daysCount << endl;
}

#endif /* POISNOUSPLANTS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
