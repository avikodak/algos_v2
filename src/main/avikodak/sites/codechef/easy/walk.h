/****************************************************************************************************************************************************
 *  File Name                   : walk.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\walk.h
 *  Created on                  : Sep 6, 2015 :: 12:11:37 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/WALK
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

#ifndef WALK_H_
#define WALK_H_

//Tested
void printMinSteps(vector<long long int> userInput){
	long long int minVelocity = 0;
	for(int counter = userInput.size()-1;counter >= 0;counter--){
		minVelocity++;
		if(minVelocity < userInput[counter]){
			minVelocity += (userInput[counter] - minVelocity);
		}
	}
	cout << minVelocity << endl;
}

//Tested
void printResults(){
	unsigned int testCases,size;
	long long int input;
	scanf("%u",&testCases);
	vector<long long int> userInput;
	while(testCases--){
		scanf("%u",&size);
		userInput.clear();
		for(unsigned int counter = 0;counter < size;counter++){
			cin >> input;
			userInput.push_back(input);
		}
		printMinSteps(userInput);
	}
}

#endif /* WALK_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/