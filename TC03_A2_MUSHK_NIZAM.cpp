/**********|**********|**********|
Program: TC03_A2_MUSHK_NIZAM.cpp 
Course: OBJECT ORIENTED PROGRAMMING
Year: 2018/19 Trimester 2
Name: Mushk Nizam
ID: **********
Lecture Section: TC103
Tutorial Section: TT06
Email: mushknizam.mn@gmail.com
Phone:***********
**********|**********|**********/
#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int main()

{ 
    cout<<"Kindly wait, your dictionary is being prepared"<<endl;


    string words;
    
    string finaltokens;    
    vector<tuple<string,string,string,int>> vec;  // Making a vector of a tuple as a container holding words,sentence,filename and line number
    tuple<string,string,string,int> p;  // tuple container to hold
    ifstream infile; 
    vector<string>v;
   // vector<string>ve;
    string ext = ".txt"; 
    string filename;
    for(int i = 1; i <= 10; i++)//Opening of file.
    {   string sentence;
        stringstream ss;
        ss << i;
        filename =ss.str() + ext; // filename changing from this line.
        infile.open( filename.c_str() );
        if(infile.is_open()){
        	int lineno=1;
         while (getline(infile, sentence)) // reading sentence from each file
        {      
            transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower); //converting every word into lowercase
		     string tokens;
		     sentence.erase(remove(sentence.begin(), sentence.end(), ','), sentence.end()); // removing , from sentence
		     sentence.erase(remove(sentence.begin(), sentence.end(), ':'), sentence.end()); //removing : from each sentence
		     sentence.erase(remove(sentence.begin(), sentence.end(), '"'), sentence.end()); //removing " from each sentence
           
           stringstream ss1(sentence);  // converting sentence into words
               do{  //loop storing words into token
               	
			   string token;
            ss1>>token;
             ifstream exclu_words;
 	         exclu_words.open("StopWords.txt"); //File stopwords contains a list of words.
	         string stopwords;
	        do{// loop readin stopwords into vector
	    	exclu_words>>stopwords;
	    	v.push_back(stopwords);
			}while(!exclu_words.eof());
		
			exclu_words.close();
     auto it = std::find(v.begin(), v.end(), token); //finding the words in vector matching token words

    if (it == v.end())
      {
	  ( p = make_tuple(token,sentence,filename,lineno)); // saving the words uncommon with stopwords in side tuple
       vec.push_back(p); // tuple saving into vector
   }
               }while(ss1);
         	
           lineno++;
	}
    }
    infile.close();
	} 
	while(1)
	{
	
	int choice;
    cout<<"Welcome to Data Dictionary"<<endl
    <<"************************  "<<endl
    <<"    Enter"<<endl<<endl
    <<" 1. Search a word"<<endl
    <<" 2. Exit this screen"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>choice;
	switch(choice)//switch to make a choice
{

	case 1: 
	{ string word;
		cout<<"Enter the word you want to search!"<<endl;
		cin>>word;
		auto it = vec.begin();
		for(int i=0;i<vec.size();i++)
	{
		if(get<0>(*it)==word)// searched word matching word into vector of tuple
		    
		{
		//	cout<<"entering the loop"<<endl;
			cout<<"You searched for the word :\n "<<get<0>(*it)<<"\n\n"<<"Searched word was in the sentence:\n " <<get<1>(*it)<<"\n\n"<< "Word belongs to filename: " <<get<2>(*it)<< " and from line number:" <<get<3>(*it)<<"\n\n";
			cout<<"****************************************************************************************************************"<<endl;
			} // checking each word and outputting it if found
			it++;
			 
	}
	}break;
	
    case 2:
	       cout<<" We are exiting the Data Dictionary"<<endl;
    break;
}
   if(choice==2)
      {
		break;
          }
}




    return 0;
}


    
