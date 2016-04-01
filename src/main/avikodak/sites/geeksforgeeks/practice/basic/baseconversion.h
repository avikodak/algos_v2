/****************************************************************************************************************************************************
 *  File Name                   : baseconversion.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/baseconversion.h
 *  Created on                  : Aug 1, 2016 :: 9:01:10 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=1122
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_BASECONVERSION_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_BASECONVERSION_H_

//Tested
void printInBinary(long long int userInput) {
    stack<int> auxSpace;
    while (userInput) {
        auxSpace.push(userInput % 2);
        userInput /= 2;
    }
    while (!auxSpace.empty()) {
        printf("%d", auxSpace.top());
        auxSpace.pop();
    }
}

//Tested
void printDecimalToHex(long long int decimal) {
    std::stringstream ss;
    ss << std::hex << decimal;
    std::string res(ss.str());
    transform(res.begin(), res.end(),res.begin(), ::toupper);
    std::cout << res << " ";
}

//Tested
void printHexToDecimal(string hexaVal) {
    long long int decimalValue;
    std::stringstream ss;
    ss << hexaVal;
    ss >> std::hex >> decimalValue;
    std::cout << decimalValue;
}

//Tested
void solveProblem() {
    unsigned int testCases;
    long long int decimalToBinary, decimalToHexa;
    string binaryToDecimal, hexaToDecimal;
    scanf("%u", &testCases);
    while (testCases--) {
        cin >> decimalToBinary >> binaryToDecimal >> decimalToHexa >> hexaToDecimal;
        printInBinary(decimalToBinary);
        cout << " ";
        cout << bitset<16>(binaryToDecimal).to_ulong() << " ";
        printDecimalToHex(decimalToHexa);
        printHexToDecimal(hexaToDecimal);
        printf("\n");
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_BASECONVERSION_H_ */
