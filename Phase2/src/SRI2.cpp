#include "SRI.h"
using namespace std;


void SRI::load()
{
	string line;
	string filePath;
	cout << "Enter filename: " << endl;
	cin >> filePath;
	ifstream userFile(filePath);
	while (getline(userFile, line)) {
		if (getType(line)) {//FACT
			if (kb.facts(getFactAssoc(line)) != kb.facts.end()) {//found FactAssoc
				if (find(kb.facts[getFactAssoc(line)].begin(), kb.facts[getFactAssoc(line)].end(), getFactParam(line) != kb.facts[getFactAssoc(line)].end())) {//find factParam in vector
					return;
				}
				else {
					kb.itVector = kb.itMap.insert(kb.itVector, getFactParam(line));//insert factParam to i
				}
			}
			else {// insert FactAssocia and FactParam to facts map
				kb.facts[getFactAssoc(line)] = getFactParam(line);
			}
		}
		else if(getType(line)){//RULE
			line.erase(0, line.find(delimiterSpace) + delimiterSpace.length());
			
		}
		else {
			cout << "SRI load error: Invalid command (command FACT and RULE only)" << endl;
			continue;
		}
	}
}
