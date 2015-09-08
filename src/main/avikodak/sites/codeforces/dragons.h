/****************************************************************************************************************************************************
 *  File Name                   : dragons.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\dragons.h
 *  Created on                  : Apr 11, 2015 :: 12:50:49 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/230/A
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

#ifndef DRAGONS_H_
#define DRAGONS_H_

//Tested
struct upair{
public:
	unsigned int first;
	unsigned int second;

	upair(unsigned int first,unsigned int second){
		this->first = first;
		this->second = second;
	}
};

//Tested
bool compare(upair *fpair,upair *spair){
	return fpair->first < spair->first;
}

//Tested
void winOrLoss(){
	unsigned int strength,testCases,first,second;
	scanf("%u %u",&strength,&testCases);
	vector<upair *> userInput;
	upair *element;
	while(testCases--){
		scanf("%u %u",&first,&second);
		element = new upair(first,second);
		userInput.push_back(element);
	}
	sort(userInput.begin(),userInput.end(),compare);
	unsigned int counter = 0;
	for(;counter < userInput.size() && strength > userInput[counter]->first;counter++){
		strength += userInput[counter]->second;
	}
	printf("%s",counter == userInput.size()?"YES":"NO");
}


#endif /* DRAGONS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
