#include "common_headers.h"
#include "Fact.h"
#include "Rule.h"
#include "SRI.cpp"
void menu()
{
    SRI *sriobj;
    string command, command1, command2; //command
    string input;
    ofstream fout;
    bool exit = false;

    while(!exit){
    cout<<"(i)FACT"<<endl;
    cout<<"(ii)RULE"<<endl;
    cout<<"(iii)LOAD"<<endl;
    cout<<"(iv)DUMP"<<endl;
    cout<<"(v)DROP"<<endl;
    cout<<"(vi)INFERENCE"<<endl;
    cout<<"(vii)QUIT"<<endl;
    cout<<"-------------"<<endl;
	cout<<"Enter your command: "<<endl;
	getline(cin, input);
	stringstream str(input);
	getline(str, command, ' ');//catch the first command entered
	getline(str, command1);
	command2 = input;

	if(command2 == "i"){
		cout<<"Fact entered: "<<command1<<endl; //pring the fact entered on console
		fout.open("output.sri", fstream::app); //write to output file
		//string outputFile = "output.sri";
		fout << command1; //put everything to the output file
		sriobj->load();// load will check which one is Rules and Facts and load accordingly
		fout.close();
    }
	else if(command2 == "ii"){
            cout<<"Rule entered: "<<command1<<endl;
            fout.open("output.sri", fstream::app);
            fout<<command1;
            sriobj->load();
            fout.close();
        }

	else if(command2 == "iii"){
            cout<<"LOADING"<<endl;
            sriobj->load();
    }
    else if(command2 == "iv"){
            sriobj->dump();
            cout<<"DUMPING KB AND RB"<<endl;

    }
    else if(command2 == "v"){
            cout<<"DROPPING"<<endl;
            sriobj->drop(command1);

    }
    else if(command2 == "vi"){
        cout<<"Issuing a query"<<endl;
        sriobj->inference();
    }
    else if(command == "vii"){
        cout<<"CIAO BAMBINO"<<endl;
        break;
    }

      }
}
int main(){
	menu();
}
