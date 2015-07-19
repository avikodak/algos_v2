/****************************************************************************************************************************************************
 *  File Name                   : morselikecode.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\page03\morselikecode.h
 *  Created on                  : Jul 19, 2015 :: 2:48:47 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=8152
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

#ifndef MORSELIKECODE_H_
#define MORSELIKECODE_H_

class MorselikeCode {
public:
	string decrypt(vector<string> library, string message){
		map<string,string> codes;
		map<string,string>::iterator itToCodes;
		char *ptrToCh,*ptrToCode;
		string decryptedMessage;
		for(unsigned int counter = 0;counter < library.size();counter++){
			ptrToCh = strtok((char *)library[counter].c_str()," ");
			ptrToCode = strtok(NULL, " ");
			string ch(ptrToCh);
			string code(ptrToCode);
			codes.insert(pair<string,string>(code,ch));
		}
		char *ptrToMessage = strtok((char *)message.c_str()," ");
		while(ptrToMessage != NULL){
			string subString(ptrToMessage);
			if((itToCodes = codes.find(subString)) != codes.end()){
				decryptedMessage.append(itToCodes->second.begin(),itToCodes->second.end());
			}else{
				decryptedMessage.append("?");
			}
			ptrToMessage = strtok(NULL," ");
		}
		return decryptedMessage;
	}
};

#endif /* MORSELIKECODE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
