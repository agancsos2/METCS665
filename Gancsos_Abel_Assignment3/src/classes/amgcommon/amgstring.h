#ifndef __AMGSTRING_H_INCLUDED__  
#define __AMGSTRING_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace amgcommon{
	/**
 	 * This class helps manipulate strings
 	 * @author  (Abel Gancsos)
 	 * @version (v. 1.0.0)
 	 */
	class AMGString {
		private:
			string str;
		public:
			AMGString();
			AMGString(string st);
			~AMGString();
			string PadRight(int len, string pad);
			string PadLeft(int len, string pad);
			vector<string> Split(string delim);
			vector<string> SplitByLine();
			string ReplaceAll(string search,string replace);
			string Strip();
			bool Contains(string search);
			string ToLowerCase();
			string ToUpperCase();
	};
}

#endif
