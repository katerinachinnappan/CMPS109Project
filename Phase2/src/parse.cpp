#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void menu()
{
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

        if(command == "FACT")cout<<"you entered FACT"<<endl;
        else if(command == "RULE")cout<<"you entered RULE"<<endl;
        else if(command == "LOAD")cout<<"you entered LOAD"<<endl;
        else if(command == "DUMP")cout<<"you entered DUMP"<<endl;
        else if(command == "DROP")cout<<"you entered DROP"<<endl;
        else if(command == "INFERENCE")cout<<"you entered INFERENCE"<<endl;
        else if(command == "QUIT"){
            cout<<"CIAO"<<endl;
            break;
        }
        else cout<<"please enter a valid command"<<endl;
    }
        //when parsing the file, find space between words
        space = command.find(" " , 0);
        spaceEnd = command.find("(" , 0);
        cout << "there is a space @" << space << endl;
        firstWordFound=command.substr(space+1,(spaceEnd-space-1));
        cout<<firstWordFound<<endl;
        cout<<"Enter your command: "<<endl;
}
}
int main(int args, char* argv[]){
  //if entered greater than 1 , proceed
  if(args > 1){
    ifstream infile(argv[1]);
    //each line in file
    string line;

    while (getline(infile, line))
    {
      //can delete later, for testing purposes
      cout<<line<<endl;
    }
  }

  else{
    menu();
    return 0;
 }
}
