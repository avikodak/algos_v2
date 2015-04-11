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
