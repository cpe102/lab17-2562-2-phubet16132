//Write your code here
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std ;

string ToUpperCase(string t) {
	for (unsigned short i = 0; i < t.size(); i++) {
		if (t[i] >= 97 && t[i] <= 122)
			t[i] -= 32;
	}
	
	return t;
}


int main(){
	
	

	
	ifstream file("name_score.txt");
	
	string line;
	char format[]="%[^:]: %d %d %d";
	char name[100];
	int a,b,c;
	int i=0;
	
	
	vector<string> linevec;
	vector<string> namevec;
	vector<string> grade;
	
	while(getline(file,line)){
		
		linevec.push_back(line);
		
		i++;
	}
	
	for(int j=0;j<linevec.size();j++){
		sscanf(linevec[j].c_str(),format,name,&a,&b,&c);
		
		int sumsco=int(a+b+c);
		
		
		namevec.push_back(name);
		
		string g="";
		
		
		if(sumsco>=80){
			g="A";
		}
		else if(sumsco>=70){
			g="B";
		}
		else if(sumsco>=60){
			g="C";
		}
		else if(sumsco>=50){
			g="D";
		}
		else{
			g="F";
		}
		sumsco=0;
		
		grade.push_back(g);
	}
	
	
	
	
	
	while(true){
		
	cout<<"Please input your command : ";
	
	string com;
	
	getline(cin,com);
	
	
	char format2[]="%s %s";
	
	char com_name_score[100];
	char gradeorname[100];
	
	sscanf(com.c_str(),format2,com_name_score,gradeorname);
	
	vector<string> nameout;
	vector<char> gradeout;
	
	
	
	if(string(com_name_score)=="grade"){
		for(int k=0;k<grade.size();k++){
			if(grade[k]==string(gradeorname)){
				nameout.push_back(namevec[k]);
			}
		}
		cout<<"----------------------------------"<<endl;
		for(int k=0;k<nameout.size();k++){
			cout<<nameout[k]<<endl;
		}
		cout<<"----------------------------------"<<endl;
	}
	else if(string(com_name_score)=="name"){
		for(int k=0;k<namevec.size();k++){
			if(ToUpperCase(namevec[k])==ToUpperCase(gradeorname)){ //page 15 lec 17 sprit
			cout<<"----------------------------------"<<endl;
			cout<<grade[k]<<endl;
			cout<<"----------------------------------"<<endl;
			
			}
			
			
			
			
		}
	}
	
	else if(string(com_name_score)=="exit"){
		break;
	}
	else {
		
		cout<<"Invalid command"<<endl;
	}
	
}
	
}
