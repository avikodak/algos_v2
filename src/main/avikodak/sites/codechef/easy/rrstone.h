/****************************************************************************************************************************************************
 *  File Name                   : rrstone.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\rrstone.h
 *  Created on                  : Sep 7, 2015 :: 9:23:36 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/RRSTONE
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

#ifndef RRSTONE_H_
#define RRSTONE_H_

//Tested
void printArray(long long int size, vector<long long int> userInput){
    for(long long int counter = 0;counter < size;counter++){
        cout << userInput[counter] << " ";
    }
    cout << endl;
}

//Tested
void printArrayPostOps(){
	long long int size,operations,maxVal,input;
	cin >> size >> operations;
	vector<long long int> userInput;
	for(long long int counter = 0;counter < size;counter++){
		cin >> input;
		userInput.push_back(input);
	}
	if(operations == 0){
		printArray(size,userInput);
		return;
	}
	if(operations%2 == 1){
		operations = 1;
	}else{
		operations = 2;
	}
	for(long long int counter = 0;counter < operations;counter++){
		maxVal = *max_element(userInput.begin(),userInput.end());
		for(int innerCounter = 0;innerCounter < size;innerCounter++){
			userInput[innerCounter] = maxVal - userInput[innerCounter];
		}
	}

    printArray(size, userInput);
}

#endif /* RRSTONE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
