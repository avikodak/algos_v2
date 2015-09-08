/****************************************************************************************************************************************************
 *  File Name                   : ammeat.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\ammeat.h
 *  Created on                  : Sep 6, 2015 :: 12:00:52 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/AMMEAT
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

#ifndef AMMEAT_H_
#define AMMEAT_H_

//Tested
void printMinPlates(vector<unsigned long long int> userInput,unsigned long long int reqSum){
	sort(userInput.begin(),userInput.end());
	unsigned long long int sum = 0,total = 0;
	for(int counter = userInput.size()-1;counter >= 0;counter--){
		sum += userInput[counter];
		total++;
		if(sum >= reqSum){
			cout << total << endl;
			return;
		}
	}
	cout << "-1" << endl;
}

//Tested
void printResults(){
	unsigned int testCases;
	unsigned long long int size,requiredSum,input;
	vector<unsigned long long int> userInput;
	cin >> testCases;
	while(testCases--){
		cin >> size >> requiredSum;
		userInput.clear();
		for(unsigned int counter = 0;counter < size;counter++){
			cin >> input;
			userInput.push_back(input);
		}
		printMinPlates(userInput,requiredSum);
	}
}

#endif /* AMMEAT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
