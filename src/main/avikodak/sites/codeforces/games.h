/****************************************************************************************************************************************************
 *  File Name                   : games.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\games.h
 *  Created on                  : Apr 28, 2015 :: 7:09:23 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/268/A
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

#ifndef GAMES_H_
#define GAMES_H_

//Tested
struct uniforms{
public:
	unsigned int home;
	unsigned int guest;

	uniforms(){

	}

	uniforms(unsigned int home,unsigned int guest){
		this->home = home;
		this->guest = guest;
	}

};

//Tested
void getTotalNumberOfHomeGuestUniform(){
	unsigned int totalTeams,homeInput,guestInput;
	scanf("%u",&totalTeams);
	vector<uniforms *> userInput;
	uniforms *teamInput;
	for(unsigned int counter = 0;counter <totalTeams;counter++){
		scanf("%u %u",&homeInput,&guestInput);
		teamInput = new uniforms(homeInput,guestInput);
		userInput.push_back(teamInput);
	}
	unsigned int totalCount = 0;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[outerCounter]->home == userInput[innerCounter]->guest){
				totalCount++;
			}
			if(userInput[innerCounter]->home == userInput[outerCounter]->guest){
				totalCount++;
			}
		}
	}
	printf("%u",totalCount);
}

#endif /* GAMES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
