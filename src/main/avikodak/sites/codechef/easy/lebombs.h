/****************************************************************************************************************************************************
 *  File Name                   : lebombs.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\lebombs.h
 *  Created on                  : Sep 2, 2015 :: 11:07:10 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/LEBOMBS
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

#ifndef LEBOMBS_H_
#define LEBOMBS_H_

//Tested
void getBuildingCount(string userInput){
	string bombedBuilding = userInput;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == '1'){
			if(counter-1 >= 0){
				bombedBuilding[counter-1] = '1';
			}
			if(counter+1 < userInput.size()){
				bombedBuilding[counter+1] = '1';
			}
		}
	}
	unsigned int savedBuilding = 0;
	for(unsigned int counter = 0;counter < bombedBuilding.size();counter++){
		if(bombedBuilding[counter] == '0'){
			savedBuilding++;
		}
	}
	cout << savedBuilding << endl;
}

//Tested
void printResults(){
	unsigned int testCases,size;
	scanf("%u",&testCases);
	string userInput;
	while(testCases--){
		cin >> size >> userInput;
		getBuildingCount(userInput);
	}
}

#endif /* LEBOMBS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
