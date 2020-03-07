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
	vector<string> upname;
	
	while(getline(file,line)){
				
		linevec.push_back(line);
		
	
		
		i++;
		
	}
	
	for(int j=0;j<linevec.size();j++){
		sscanf(linevec[j].c_str(),format,name,&a,&b,&c);
		
		int sumsco=int(a+b+c);
		
		
		namevec.push_back(name);
		
		upname.push_back(ToUpperCase(name));
		
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
	
	int check=0;
	
	
	
	
	
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
			//page 15 lec 17 sprit
			int count=0;
			int start=0;
			vector<string> p;
			int end=namevec[k].find_frist_of(" ");
			while(end != -1){
				p.push_back(namevec[k].substr(start,end-start));
				start=end+1;
				end=name[k].find_first_of(" ",start);
				count++;
			}
			
			
			
			if(ToUpperCase(namevec[k])==p[0] or ToUpperCase(namevec[k])==p[1] or ToUpperCase(namevec[k])==p[2] ){ 
			
			check+=1;
			
			if(check==1){
				cout<<"----------------------------------"<<endl;
				cout<<grade[k]<<endl;
				cout<<"----------------------------------"<<endl;
			}
		
			
			}
			
			
		}
			 if(check==0){
			 	cout<<"----------------------------------"<<endl;
				cout<<"Cannot found."<<endl;
				cout<<"----------------------------------"<<endl;
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
