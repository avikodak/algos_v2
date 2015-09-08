/****************************************************************************************************************************************************
 *  File Name                   : pcycle.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\pcycle.h
 *  Created on                  : Sep 2, 2015 :: 11:24:25 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/PCYCLE
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef PCYCLE_H_
#define PCYCLE_H_

//Tested
void printPermutationCycle(vector<unsigned int> userInput){
	vector<bool> visitedFlags;
	visitedFlags.assign(userInput.size(),false);
	vector<vector<unsigned int> > cyclesList;
	for(unsigned int outerCounter = 1;outerCounter < userInput.size();outerCounter++){
		if(!visitedFlags[outerCounter]){
			vector<unsigned int> cycle;
			while(true){
				cycle.push_back(outerCounter);
				if(visitedFlags[outerCounter]){
					break;
				}
				visitedFlags[outerCounter] = true;
				outerCounter = userInput[outerCounter];
			}
			cyclesList.push_back(cycle);
		}
	}
	cout << cyclesList.size() << endl;
	for(unsigned int outerCounter = 0;outerCounter < cyclesList.size();outerCounter++){
		for(unsigned int innerCounter = 0;innerCounter < cyclesList[outerCounter].size();innerCounter++){
			cout << cyclesList[outerCounter][innerCounter] << " ";
		}
		cout << endl;
	}
}

//Tested
void printResults(){
	vector<unsigned int> userInput;
	userInput.push_back(0);
	unsigned int size,input;
	scanf("%u",&size);
	while(size--){
		scanf("%u",&input);
		userInput.push_back(input);
	}
	printPermutationCycle(userInput);
}

#endif /* PCYCLE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
