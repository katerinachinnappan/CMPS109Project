#include "common_headers.h"
#include "Fact.h"
#include "Rule.h"

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
	
	switch(command2)
	case "i":
		cout<<"Fact entered: "<<command1<<endl; //pring the fact entered on console
		fout.open("output.sri"); //write to output file
		string outputFile = "output.sri";
		fout << command1; put everything to the output file
		sriobj.load()// load will check which one is Rules and Facts and load accordingly 
		fout.close();
		
	}
}

/*void menu()
{
    SRI *sriobj;
    string command;//the command user enters
    string input;
    string firstWordFound;
    int space ;
    int spaceEnd;
    cout<<"Enter your command: "<<endl;
    cout<<"(i)FACT"<<endl;
    cout<<"(ii)RULE"<<endl;
    cout<<"(iii)LOAD"<<endl;
    cout<<"(iv)DUMP"<<endl;
    cout<<"(v)DROP"<<endl;
    cout<<"(vi)INFERENCE"<<endl;
    cout<<"(vii)QUIT"<<endl;
    cout<<"-------------"<<endl;
    while(getline(cin,command)){
    {
        //cin>>command;
            //cout<<"Enter your command: "<<endl;

        if(command == "FACT")sriobj->fact();//cout<<"you entered FACT"<<endl;
        else if(command == "RULE")sriobj->rule()//cout<<"you entered RULE"<<endl;
        else if(command == "LOAD")sriobj->load();//cout<<"you entered LOAD"<<endl;
        else if(command == "DUMP")sriobj->dump(os);//cout<<"you entered DUMP"<<endl;
        else if(command == "DROP")sriobj->drop(string)//cout<<"you entered DROP"<<endl;
        else if(command == "INFERENCE")sriobj->infer()//cout<<"you entered INFERENCE"<<endl;
        else if(command == "QUIT"){
            cout<<"CIAO"<<endl;
            break;
        }
        else cout<<"please enter a valid command"<<endl;
    }
        cout<<"Enter your command: "<<endl;
}
}*/
int main(){
	menu();
}
