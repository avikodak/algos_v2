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
