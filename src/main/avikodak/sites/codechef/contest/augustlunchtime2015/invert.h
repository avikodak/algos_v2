/****************************************************************************************************************************************************
 *  File Name                   : invert.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\contest\augustlunchtime2015\invert.h
 *  Created on                  : Aug 30, 2015 :: 11:38:02 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/LTIME27/problems/INVERT
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

#ifndef INVERT_H_
#define INVERT_H_

//Tested
void printInversions(vector<int> userInput){
	unsigned int total = 0;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-1;outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[innerCounter] < userInput[outerCounter]){
				total++;
			}
		}
	}
	cout << total << endl;
}

//Tested
void performOperation(vector<int> userInput,unsigned int testCases){
	vector<int> madeUserInput;
	unsigned int start,end,insertAt;
	while(testCases--){
		cin >> start >> end >> insertAt;
		madeUserInput.insert(madeUserInput.begin()+insertAt-1,userInput.begin()+start-1,userInput.begin()+end);
		userInput.erase(userInput.begin()+start-1,userInput.begin()+end);
		printInversions(madeUserInput);
	}
}

//Tested but slow
void printResults(){
	unsigned int size,testCases;
	vector<int> userInput;
	int input;
	cin >> size >> testCases;
	while(size--){
		scanf("%d",&input);
		userInput.push_back(input);
	}
	performOperation(userInput,testCases);
}

#endif /* INVERT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
