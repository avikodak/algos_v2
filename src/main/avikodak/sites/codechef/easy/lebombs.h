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
