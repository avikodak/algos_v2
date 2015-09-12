/****************************************************************************************************************************************************
 *  File Name                   : rgpvr102.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/rgpvr102.h
 *  Created on                  : 12-Sep-2015 :: 5:36:07 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/RGPVR102
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
#include <stdint.h>
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

#ifndef RGPVR102_H_
#define RGPVR102_H_

//Tested
void printMaxScore(vector<unsigned int> wins,vector<unsigned int> ties){
	unsigned int maxScore = 0;
	for(unsigned int counter = 0;counter < wins.size();counter++){
		maxScore = max(maxScore,3*wins[counter]+ties[counter]);
	}
	cout << maxScore << endl;
}

//Tested
void printResults(){
	unsigned int testCases,size,input;
	vector<unsigned int> wins,ties;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&size);
		wins.clear();
		ties.clear();
		for(unsigned int counter = 0;counter < size;counter++){
			scanf("%u",&input);
			wins.push_back(input);
		}
		for(unsigned int counter = 0;counter < size;counter++){
			scanf("%u",&input);
			ties.push_back(input);
		}
		printMaxScore(wins,ties);
	}
}

#endif /* RGPVR102_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
