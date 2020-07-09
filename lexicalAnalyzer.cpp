#include<iostream>
#include<string>
#include <fstream>
using namespace std;

int identifier_function(int currentState,char word) {

	int array[3][4] = { {1,1,2,2},{1,1,1,2},{2,2,2,2} };
	if (word == '_') {
		return array[currentState][0];
	}
	else if (word == '$' ||word >= 'a' && word <= 'z' || word >= 'A' && word <= 'Z') {
		return array[currentState][1];
	}
	else if (word >= '0' && word <= '9') {
		return array[currentState][2];
	}
	else
	{
		return array[currentState][3];
	}
}

int integer_function(int currentState,char word) {

	int array[4][4] = { {1,1,2,3},{3,3,2,3},{3,3,2,3},{3,3,3,3} };
	if (word == '+') {
		return array[currentState][0];
	}
	else if (word == '-') {
		return array[currentState][1];
	}
	else if (word >= '0' && word <= '9') {
		return array[currentState][2];
	}
	else
	{
		return array[currentState][3];
	}
}

int float_function(int currentState,char word) {

	int array[5][5] = { {1,1,1,2,4},{4,4,1,2,4},{4,4,3,4,4},{4,4,3,4,4},{4,4,4,4,4} };
	if (word == '+') {
		return array[currentState][0];
	}

	else if (word == '-') {
		return array[currentState][1];
	}
	else if (word >= '0' && word <= '9') {
		return array[currentState][2];
	}
	else if (word == '.') {
		return array[currentState][3];
	}
	else
	{
		return array[currentState][4];
	}
}

int character_function(int currentState,char word) {
	
	int array[6][4] = { { 1,5,5,5 },{ 5,4,2,2 },{ 3,5,5,5 },{ 5,5,5,5 },{2,2,5,2},{5,5,5,5} };
	
		if (word == '\'')
		{
			return array[currentState][0];
		}
		else if (word == '\\')
		{
			return array[currentState][1];
		}
		else if (word == 'n' || word == 't' || word == 'a' || word == 'v' || word == 'b' || word == 'r' || word == 'f' || word == '\\' || word == '\'' || word == '\"' || word == '\0' || word == ' ')
		{
			return array[currentState][3];
		}
		else
		{
			return array[currentState][2];
		}
}

int string_function(int currentState,char word) {
	
	int array[6][5] = { { 1,5,5,5,5 }, { 4,4,2,2,2 }, { 3,4,2,2,2 }, { 5,5,5,5,5 },{ 2,2,2,5,5 },{ 5,5,5,5,5 } };
	if (word == '\"')
	{
		return array[currentState][0];
	}
	if (word == '\\')
	{
		return array[currentState][1];
	}
	if(word == 'n' || word == 't' || word == 'a' || word == 'v' || word == 'b' || word == 'r' || word == 'f' || word == '\\' || word == '\'' || word == '\"')
	{
		return array[currentState][2];
	}
	if(word == ' ')
	{
		return array[currentState][3];
	}
	else
	{
		return 5;
	}
	
	
}


int split_id_function(string input) {
	int currentState = 0;
	for (int i = 0; i < input.length(); i++) {
		
		currentState = identifier_function(currentState, input[i]);
		
		
	}
	return currentState;

}
int split_int_function(string input) {
	int currentState = 0;
	for (int i = 0; i < input.length(); i++) {
		
		currentState =integer_function(currentState, input[i]);
	
	}
	return currentState;

}
int split_float_function(string input) {
	int currentState = 0;
	for (int i = 0; i < input.length(); i++) {
		
		currentState = float_function(currentState, input[i]);
		
		
	}
	return currentState;

}

int split_char_function(string input) {
	int currentState = 0;
	for (int i = 0; i < input.length(); i++) {
		
		currentState = character_function(currentState, input[i]);
		
		
	}
	return currentState;

}

bool keyword_function(string input) {

	string keyword[] = { "int","char","bool","double","string","send","stop","go","default","since","until","generate","check","otherwise","shift","scenario","omega","pendown","penread","activity","empty","fixed","section","test","hold","link","general","secured","hide","layout","implement" };
	for (int i = 0; i < 31; i++)
	{
		if (input == keyword[i]) {
			return true;
		}

	}
	return false;

}



bool punctuator_function(char character) {

	char punctuator[] = { '(',')','{','}','[',']',';',':' };
	for (int i = 0; i < 8; i++)
	{
		if (character == punctuator[i]) {
			return true;
		}
		
	}
	return false;
}



bool ArthmeticOp_function(char character) {

	char opt[] = { '+','-','*','/','%' };

	for (int i = 0; i < 6; i++)
	{
		if (character == opt[i]) {
			return true;
		}

	}

	return false;
}

bool  RelationalOp_function(char character) {

	char opt[] = { '<','>','<','>','!','=' };

	for (int i = 0; i < 6; i++)
	{
		if (character == opt[i]) {
			return true;
		}

	}

	return false;
}

bool  LogicalOp_function(char character) {

	char opt[] = { '&','|'};

	for (int i = 0; i < 2; i++)
	{
		if (character == opt[i]) {
			return true;
		}

	}

	return false;
}

int main()
{
		string word = "";
	  string input;
	  int line=0;
	  bool comment = true;
	  bool no_string = true;
      ifstream myfile("program.txt");
      ofstream outputFile("output.txt",ios::out);
      //outputFile.open ("output.txt");
      if (myfile.is_open() && outputFile.is_open())
	  {
	  	cout<<" \t\t\tLexical Analyzer\n\n Token Sets as [Class part, Value part , Line no]\n\n";
	  	outputFile<<" \t\t\tLexical Analyzer\n\n Token Sets as [Class part, Value part , Line no]\n\n";
	    while ( getline (myfile,input))
	    {
	    	line++;
	    	
	    	for (int i = 0; i <= input.length(); i++)
			{
				if(input[i] == '\/' && input[i+1]=='$')
				{
					comment = false;
					//cout<<"comment start ho gaya ";
					i++;
				}
				if(input[i] == '$' && input[i+1]=='\/' )
				{
					comment = true;
				///	cout<<"comment end ho gaya";
					i+=2;
					word = "";
				}
			    if (input[i] == '\/' && input[i+1]=='\/' && comment)
				{
					i++;
					break;
				}
				if(comment)
				{
					if( input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '\0' && no_string)   
			{
				if(no_string && comment && word != "")
				{
					if (keyword_function(word)) 
					{
						if(word!="int"&&word!="float"&&word!="string"&&word!="char"&&word!="double"&&word!="bool")
						{
						cout << "\n [ "<<word<<" , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ Keyword, "<<word<<", line no: "<<line<<"] \n";
						}
						else
						cout << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
					}
					else if (split_id_function(word)==1) 
					{
						cout << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
						outputFile << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
					}
					else if(split_int_function(word)==2)
					{
						cout << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
						outputFile << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
					}
					else if(split_float_function(word)==3)
					{
						cout << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
						outputFile << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
					} 
					
					
					else 
					{	
						cout <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
						outputFile <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
					}
					word = "";
					
				}
				else
				{
					if(!no_string)
					{
						outputFile <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
						no_string = true;
						word = "";
					}
				}
				
					
			}
		  		
				else if(punctuator_function(input[i]) && comment && no_string)
				{
					if(word != "")
					{
						//cout << word ;
					if (keyword_function(word)) 
					{
						if(word!="int"&&word!="float"&&word!="string"&&word!="char"&&word!="double"&&word!="bool")
						{
						cout << "\n [ "<<word<<" , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ Keyword, "<<word<<", line no: "<<line<<"] \n";
						}
						else
						cout << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
					}
					else if (split_id_function(word)==1) 
					{
						cout << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
						outputFile << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
					}
					else if(split_int_function(word)==2)
					{
						cout << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
						outputFile << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
					}
					else if(split_float_function(word)==3)
					{
						cout << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
						outputFile << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
					}
					
					else 
					{	
						cout <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
						outputFile <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
					}
					word = "";
					}	
					cout << "\n [ "<<input[i] <<" , "<<input[i] << ", line no: "<<line<<"] \n";
					outputFile << "\n [ "<<input[i] <<" , " <<input[i] << ", line no: "<<line<<"] \n";		
				}
				else if (ArthmeticOp_function(input[i]) && comment && no_string)
				{
					if (word != "")
					{
						//cout << word;
						if (keyword_function(word))
						{
							if(word!="int"&&word!="float"&&word!="string"&&word!="char"&&word!="double"&&word!="bool")
						{
						cout << "\n [ "<<word<<" , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ Keyword, "<<word<<", line no: "<<line<<"] \n";
						}
						else
						cout << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						}
						else if (split_id_function(word) == 1)
						{
							cout << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
							outputFile << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
						}
						else if (split_int_function(word) == 2)
						{
							cout << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
							outputFile << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
						}
						else if (split_float_function(word) == 3)
						{
							cout << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
							outputFile << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
						}
						
						else
						{
							cout <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
							outputFile <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
						}
						word = "";
					}

					if (input[i + 1] == '=' )
					{
						cout << "\n [ Assignment Operator, "<<input[i] << input[i + 1]<<", line no: "<<line<<"] \n";
						outputFile << "\n [ Assignment Operator, "<<input[i] << input[i + 1]<<", line no: "<<line<<"] \n";
						i++;
						
					}
					else if(input[i]=='+' && input[i+1]=='+')
					{
						cout << "\n [ Increment Operator, "<<input[i] << input[i + 1]<<", line no: "<<line<<"] \n";
						outputFile << "\n [ Increment Operator, "<<input[i] << input[i + 1]<<", line no: "<<line<<"] \n";
						i++;
					}
					else if(input[i]=='-' && input[i+1]=='-')
					{
						cout << "\n [ Decrement Operator, "<<input[i] << input[i + 1]<<", line no: "<<line<<"] \n";
						outputFile << "\n [ Decrement Operator, "<<input[i] << input[i + 1]<<", line no: "<<line<<"] \n";
						i++;
					}
					else
					{
						cout << "\n [ Arithematic Operator, "<<input[i]<<", line no: "<<line<<"] \n";
						outputFile << "\n [ Arithematic Operator, "<<input[i] <<", line no: "<<line<<"] \n";
						
					}

				}
				else if (RelationalOp_function(input[i]) && comment && no_string)
				{
					if (word != "")
					{
						//cout << word;
						if (keyword_function(word))
						{
							if(word!="int"&&word!="float"&&word!="string"&&word!="char"&&word!="double"&&word!="bool")
						{
						cout << "\n [ "<<word<<" , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ Keyword, "<<word<<", line no: "<<line<<"] \n";
						}
						else
						cout << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						}
						else if (split_id_function(word) == 1)
						{
							cout << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
							outputFile << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
						}
						else if (split_int_function(word) == 2)
						{
							cout << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
							outputFile << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
						}
						else if (split_float_function(word) == 3)
						{
							cout << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
							outputFile << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
						}
						
						else
						{
							cout <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
							outputFile <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
						}
						word = "";
					}

                    if ((input[i] == '>' || input[i] == '<') && input[i+1]!='=')
					{
						cout << "\n [ Relational Operator, "<<input[i] << ", line no: "<<line<<"] \n";
						outputFile << "\n [ Relational Operator, "<<input[i] << ", line no: "<<line<<"] \n";
					}
					else if(input[i] == '>' || input[i] == '<' && input[i+1]=='=')
					{
						cout << "\n [ Relational Operator, "<<input[i]<<input[i+1] << ", line no: "<<line<<"] \n";
						outputFile << "\n [ Relational Operator, "<<input[i]<<input[i+1] << ", line no: "<<line<<"] \n";
						i++;
					}
					else if(input[i] == '=' || input[i] == '!' && input[i+1]=='=')
					{
						cout << "\n [ Relational Operator, "<<input[i]<<input[i+1] << ", line no: "<<line<<"] \n";
						outputFile << "\n [ Relational Operator, "<<input[i]<<input[i+1] << ", line no: "<<line<<"] \n";
						i++;
					}
					else if(input[i] == '!')
					{
						cout << "\n [ Logical Operator, "<<input[i] << ", line no: "<<line<<"] \n";
						outputFile << "\n [ Logical Operator, "<<input[i] << ", line no: "<<line<<"] \n";
					}
					else
					{
						cout <<"\n"<< input[i] << " : Invalid at line number: "<<line<<" \n";
						outputFile <<"\n"<< input[i] << " : Invalid at line number: "<<line<<" \n";
					}
				}
				else if (LogicalOp_function(input[i]) && comment && no_string)
				{
					if (word != "")
					{
						//cout << word;
						if (keyword_function(word))
						{
							if(word!="int"&&word!="float"&&word!="string"&&word!="char"&&word!="double"&&word!="bool")
						{
						cout << "\n [ "<<word<<" , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ Keyword, "<<word<<", line no: "<<line<<"] \n";
						}
						else
						cout << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						}
						else if (split_id_function(word) == 1)
						{
							cout << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
							outputFile << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
						}
						else if (split_int_function(word) == 2)
						{
							cout << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
							outputFile << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
						}
						else if (split_float_function(word) == 3)
						{
							cout << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
							outputFile << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
						}
						
						else
						{
							cout <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
							outputFile <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
						}
						word = "";
					}

                    if (input[i] == '&' && input[i+1]=='&')
					{
						cout << "\n [ Logical Operator, "<<input[i]<<input[i+1] << ", line no: "<<line<<"] \n";
						outputFile << "\n [ Logical Operator, "<<input[i]<<input[i+1] << ", line no: "<<line<<"] \n";
						i++;
					}
					else if(input[i] == '|'&& input[i+1]=='|')
					{
						cout << "\n [ Logical Operator, "<<input[i]<<input[i+1] << ", line no: "<<line<<"] \n";
						outputFile << "\n [ Logical Operator, "<<input[i]<<input[i+1] << ", line no: "<<line<<"] \n";
						i++;
					}
					else
					{
						cout <<"\n"<<word<< input[i] << " : Invalid at line number: "<<line<<" \n";
						outputFile << "\n [ Logical Operator, "<<input[i]<<input[i+1] << ", line no: "<<line<<"] \n";
					}
				}
				else if(input[i] == '\'' && comment  && no_string)
				{
					
					if(word != "")
					{
						//cout << word ;
					if (keyword_function(word)) 
					{
						if(word!="int"&&word!="float"&&word!="string"&&word!="char"&&word!="double"&&word!="bool")
						{
						cout << "\n [ "<<word<<" , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ Keyword, "<<word<<", line no: "<<line<<"] \n";
						}
						else
						cout << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
					}
					else if (split_id_function(word)==1) 
					{
						cout << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
						outputFile << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
					}
					else if(split_int_function(word)==2)
					{
						cout << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
						outputFile << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
					}
					else if(split_float_function(word)==3)
					{
						cout << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
						outputFile << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
					}
					
					
					
					word = "";
					}
					
				if(input[i+1] == '\\')
				{
				word = input.substr(i,4);
				if(split_char_function(word) == 3)
				{
					outputFile<<"( Character_cons , "<< word <<" , "<<line<<" )\n";
				}
				else 
					{	
						cout <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
						outputFile <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
					}
				i+=3;
				word="";
			}
			else
			{
				word = input.substr(i,3);
				if(split_char_function(word) == 3)
				{
					outputFile<<"( Character_cons , "<< word <<" , "<<line<<" )\n";
				}
				else 
					{	
						cout <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
						outputFile <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
					}
				i+=2;
				word="";
			}
					
					
					
					
								
		}
		else if(input[i] == '\"' && comment)
		{
			if(no_string)
			{
				if (word != "")
					{
						//cout << word;
						if (keyword_function(word))
						{
							if(word!="int"&&word!="float"&&word!="string"&&word!="char"&&word!="double"&&word!="bool")
						{
						cout << "\n [ "<<word<<" , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ Keyword, "<<word<<", line no: "<<line<<"] \n";
						}
						else
						cout << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						}
						else if (split_id_function(word) == 1)
						{
							cout << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
							outputFile << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
						}
						else if (split_int_function(word) == 2)
						{
							cout << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
							outputFile << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
						}
						else if (split_float_function(word) == 3)
						{
							cout << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
							outputFile << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
						}
						word = "";
					
				}
				no_string = false;
				word+=input[i];
			}
			else
			{
				if(input[i-1] == '\\')
				{
					word+=input[i];
				}
				else
				{
					no_string = true;
					word+=input[i];
					outputFile<<"( String_Const , "<< word <<" , "<<line<<" )\n";
					word = "";
				}
			}
			
		}
		else if(comment && input[i] == '.' && no_string)
		{
			if(word == "")
			{
				if(input[i+1] >='0' && input[i+1] <= '9')
				{
					word += input[i];
				}
				else
				{
					outputFile<<"( Dot , "<< input[i] <<" , "<<line<<" )\n";
					word = "";
				}
			}
			else if(split_float_function(word) == 3)
			{	
					outputFile<<"( Float_Const , "<< word <<" , "<<line<<" )\n";
					word="";
					i--;		
		    } 
			else 
			{
				if(keyword_function(word))
				{
					if (keyword_function(word))
						{
							if(word!="int"&&word!="float"&&word!="string"&&word!="char"&&word!="double"&&word!="bool")
						{
						cout << "\n [ "<<word<<" , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ Keyword, "<<word<<", line no: "<<line<<"] \n";
						}
						else
						cout << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						}
						else if (split_id_function(word) == 1)
						{
							cout << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
							outputFile << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
						}
						else if (split_int_function(word) == 2)
						{
							cout << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
							outputFile << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
						}
						else if (split_float_function(word) == 3)
						{
							cout << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
							outputFile << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
						}
					word = "";
					if(input[i+1] >='0' && input[i+1] <= '9')
					{
						word += input[i];
					}
					else
					{
						outputFile<<"( Dot , "<< input[i] <<" , "<<line<<" )\n";
					}
				}
				else if(split_id_function(word) == 1)
				{
					if (keyword_function(word))
						{
							if(word!="int"&&word!="float"&&word!="string"&&word!="char"&&word!="double"&&word!="bool")
						{
						cout << "\n [ "<<word<<" , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ Keyword, "<<word<<", line no: "<<line<<"] \n";
						}
						else
						cout << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						outputFile << "\n [ DT , "<<word<<" , line no: "<<line<<"] \n";
						}
						else if (split_id_function(word) == 1)
						{
							cout << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
							outputFile << "\n [ Identifier, "<<word<<", line no: "<<line<<"] \n";
						}
						else if (split_int_function(word) == 2)
						{
							cout << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
							outputFile << "\n [ int_const, "<<word<<", line no: "<<line<<"] \n";//integer
						}
						else if (split_float_function(word) == 3)
						{
							cout << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
							outputFile << "\n [ float_const, "<<word<<", line no: "<<line<<"] \n";//float
						}
					word = "";
					if(input[i+1] >='0' && input[i+1] <= '9')
					{
						word += input[i];
					}
					else
					{
						outputFile<<"( Dot , "<< input[i] <<" , "<<line<<" )\n";
					}
				}
				else if(split_int_function(word) == 2 )
				{
					if(input[i+1] >='0' && input[i+1] <= '9')
					{
						word += input[i];
					}
					else 
					{
						outputFile<<"( Integer_Const , "<< word <<" , "<<line<<" )\n";
						word = "";
						outputFile<<"( Dot , "<< input[i] <<" , "<<line<<" )\n";
					}
				}
				
				else
				{
					cout <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
					outputFile <<"\n"<<word<< " : Invalid at line number: "<<line<<" \n";
					word = "";
					i--;
				}
				
			}	
			
		}
				
                 else
				{
					word += input[i];
				}
				
				}
			
				
				
			}
		
		
			    
		}
		
				outputFile.close();
			    
			    myfile.close();
			    
	 }
			
			  else
			    {
			  	
			  		cout << "Unable to open file"; 
			  	
			    } 

	
	
	
	//system("pause");
	return 0;
}
	


