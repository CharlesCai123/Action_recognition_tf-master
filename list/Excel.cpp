//��Excel�ļ����ж�д; 
#include<sstream>
#include<iostream>
#include<fstream> 
#include<string>
#include<vector>
using namespace std;

class csvdata{
	public:
		int label;	//��ǩ
		string path;	//·�� 
};	//�Լ������csv������� 


void writeExcel()		//д��.csv(Excel)�ļ�; 
{
    char chy[4]={ 'x' ,'a' ,'h','w' } ;
    int data[4]={ 1 , 3 , 6 ,9  };
    int i ;
    FILE *fp = NULL ;
    fp = fopen("2.csv","a+") ;
    for (i=0 ; i<4 ;i++)
        fprintf(fp,"%c,%d\n",chy[i],data[i] ) ;
    fclose(fp);
}
#include <stdio.h>
void readExcel(FILE *fp,vector<csvdata> &data)			//��ȡ.csv(Excel)�ļ�; 
{
	/*csvdata temp;
	while(1)
	{
		fscanf(fp,"%d,%s",&temp.label,&temp.path);
		//printf("%d %s\n",temp.label,temp.path.data());	
		data.push_back(temp);
		if(feof(fp))
			break;
	}
	fclose(fp);
	for(int i=0;i<data.size();i++)
		cout<<data[i].label<<" "<<data[i].path<<endl;*/
	
	// ���ļ�  
    
}

int main()
{                   
   // vector<csvdata> example;
    //ifstream inFile("train_data.csv", ios::in);  		//���ļ� 
    ifstream inFile("train_data_old.csv",ios::in);
    string lineStr;  	//Excel��ÿһ�е�����; 
    vector<vector<string>> strArray;  
    
	while(getline(inFile, lineStr))  
    {  
        // ��ӡ�����ַ���  
        cout << lineStr << endl;  
        // ��ɶ�ά��ṹ  
        stringstream ss(lineStr);  
        string str;  
        vector<string> lineArray;  
        // ���ն��ŷָ�  
        while (getline(ss, str, ','))  
            lineArray.push_back(str);  
        strArray.push_back(lineArray);  
    }  
    inFile.close();
    
    cout<<"strArray:"<<strArray[1].at(1)<<endl;
    string ordinary_path="C:\\Users\\Charlescai\\PycharmProjects\\Action_recognition_tf-master\\ActionRecognitionData\\FutureCamp_ActionRecognitionData_TrainVal";
    ofstream outFile;
    outFile.open("2.csv",ios::out);		//д�ļ�; 
    
    for(int i=1;i<strArray.size();i++)
    {
		string temp=strArray[i][1];
    	int len=temp.length();
		string temp2;
    	cout<<temp<<endl;
   		cout<<"len:"<<len<<endl; 	
    	int count=0;
	    for(int j=0;j<len;j++)
	    {
	    	if(temp.c_str()[j]=='/')
	    		count++;
	    	if(count==5)
	    	{
	    		temp2=temp.substr(j+1,len-j-1);
	    		break;
			}
		}
		cout<<temp2<<endl;
		strArray[i][1]=ordinary_path+"\\"+temp2;
		outFile<<strArray[i][0]<<","<<strArray[i][1]<<endl;
		cout<<strArray[i][1]<<endl;
		//cout<<"last:"<<temp.c_str()[len-1]<<endl;    	
	}
	outFile.close();
}


