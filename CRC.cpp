//============================================================================
// Name        : CRC.cpp
// Author      : Shrikant Singh
// Version     :
// Copyright   : 
// Description : 
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class CRC
{
public:
	void get_data();
	void get_gen();
	void calc_redundent_bit();
	void print_remainder();
	vector<bool> data;
	vector<bool> generator;
	vector<bool> remainder;

};

void CRC::get_data()
{
	cout<<"======================================================\n";
	cout<<"Enter the Data Bit\n";
	cout<<"======================================================\n";
	int temp_input;


	while (true){
		cin>>temp_input;
		if (temp_input == 0){
			data.push_back(temp_input);
		}
		else if (temp_input == 1){
			data.push_back(temp_input);
		}
		else
			return;
	}//while loop
}//get data funciton

void CRC::get_gen()
{
	cout<<"======================================================\n";
	cout<<"Enter the Generaotor bit\n";
	cout<<"======================================================\n";
	int temp_input;

	while (true){
		cin>>temp_input;
		if (temp_input == 0){
			generator.push_back(temp_input);
		}
		else if (temp_input == 1){
			generator.push_back(temp_input);
		}
		else
			return;
	}//while loop
}//Generator Bit

void CRC:: calc_redundent_bit()
{
	cout<<"======================================================\n";
	cout<<"Calculating redundent bits........"<<endl;
	cout<<"======================================================\n";

	int head = 0;
	int count = 0;
	int tail = generator.size();
	int temp;




	//copying the data bits into remainder bits
	for (int i = 0; i < data.size(); i++)
	{
		temp = data[i];
		remainder.push_back(temp);

	}//for loop


	bool condition = true;
	int a;

	while(condition)
	{
		if (tail >= data.size())
				{
					condition = false;
				}

//		cout<<"***** tail = "<<tail<<" , "<<data.size()<<"******"<<endl;
//		cout<<"\n count is : "<<count<<endl;
		//cin>>a;
		for (head ; head < tail; head++ )
		{
			remainder[head] = remainder[head] ^ generator[head-count];

		}// XORing and saving the result in remainder, which is a copy of data bit,
		 // so that we just have to the generator to the right and keep XORing
		 // without saving the xor and anywhere.



		for (int k = count; k < generator.size()+count; k++)
		{
			if (remainder.front() == 1)
				break;
			else if (remainder[k] == 0)
				count++;
			else
				k = remainder.size()+count;
		}
		head = count;
		tail = generator.size() + count;


	}//While loop////////////////////////////////////////////////////////

}//calc redundant bit

void CRC:: print_remainder()
{
	cout<<"======================================================\n";
	cout<<"Remainder bits are: ........"<<endl;
	cout<<"======================================================\n";
	{
		for (int n = 0; n < remainder.size(); n++)
			cout<<remainder[n]<<" ";
	}
	cout<<endl;
}



int main()
{

	CRC crc;
	crc.get_data();
	crc.get_gen();
	crc.calc_redundent_bit();
	cout<<"Size of Data bit is : "<<crc.data.size()<<endl;

	cout<<"Size of gen bit is : "<<crc.generator.size()<<endl;

	crc.print_remainder();
	cout<<"Size of Rem Data bit is : "<<crc.remainder.size()<<endl;


	cout<<"\nExiting program\n";
	return 0;
}
