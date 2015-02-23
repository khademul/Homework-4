/*Khademul Haque
  CIVL 8903
  Homework 4
  URL: https://github.com/khademul/Homework-4
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <cstdlib>

using namespace std;

void print_string(ofstream& stream, string str){
	if(stream.is_open())
		stream << str;
}

void print_string(ostream& stream, string str){
	stream << str;
}

void open_input(string file_path, ifstream& in){
	in.open(file_path.c_str());
	if(!in.is_open()){
		string str = "Error: cannot open file for reading: " + file_path + "\n";
		print_string(cout, str);
		exit(0);
	}
	else{
		print_string(cout, "Opening " + file_path + " for reading\n");
	}
}

void open_output(string file_path, ofstream& out){
	out.open(file_path.c_str());
	if(!out.is_open()){
		string str = "Error: cannot open file for writing: " +file_path + "\n";
		print_string(cout, str);
		exit(0);
	}
	else{
		print_string(cout, "Opening " + file_path + " for writing\n");
	}
}

int main (){

	cout<<"I was able to compile this code using the HPC at the University of Memphis.\n";
	cout<<"When I compiled it there, it did not produce any warning message.\n";
	cout<<"The HPC uses a GNU C++ compiler that can be \n";
	cout<<"considered a good up-to-date standard.\n";
	cout<<"I also version-controlled this code using git, \n";
	cout<<"and used a remote repository hosted by github. \n";
	cout<<"If I can do this, so can you!!!\n";
	cout<<"\n";
	cout<<"I am so cool, that I was also able to write a code that produces\n";
	cout<<"the first M numbers of the Fibonacci sequence. Here they are: \n";
	cout<<"\n";

	string in_file_path;
	cout<<"Enter input file name: ";
	cin >> in_file_path;
	const char* out_file_path = "khademul.out";
    const char* err_file_path = "khademul.err";

	ifstream in;
	open_input(in_file_path, in);
    ofstream outfile, errfile;
	open_output(out_file_path, outfile);
	open_output(err_file_path, errfile);

	int c;
	//Fibonacci numbers can be very big;
	//Hence, using unsigned long long (64 bit) numbers
	unsigned long long first=0, second=1, fib;

	try{    
        // read N
        int n;

        in >> n;
		if(n <= 0){
			string str = "Error: n must be >= 1\n";
			print_string(errfile, str);
			print_string(cout, str);
			in.close();
			if(outfile.is_open())
				outfile.close();
			errfile.close();
			//exit program
			return 0;
		}
		
		// done with input
		in.close();

		stringstream ss;
		ss <<"First "<< n <<" terms of Fibonacci series are : \n";
		print_string(outfile, ss.str());
		print_string(cout, ss.str());

		int num_items = 10 * n;

		for (c=0; c < num_items ;c++){
			stringstream s_fib;
				if (c <= 1)
					fib=c;
				else{
					fib=first+second;
					first=second;
					second=fib;
				}
				// print fib
				s_fib<<fib;
				print_string(cout, s_fib.str()+"\t");
				print_string(outfile, s_fib.str()+"\t");
				// print a newline after every 10 fib
				if(c % 10 == 0){
					print_string(cout, "\n");
					print_string(outfile, "\n");
				}
		}
		// a new line after all output is done
		print_string(cout, "\n");
		print_string(outfile, "\n");
	}
	catch(exception& e){
        string str = string("Error: ")+e.what()+ "\n";
		print_string(cout, str);
		print_string(outfile, str);
	}

	// clean up
    if(in.is_open()) in.close();
    if(outfile.is_open()) outfile.close();
    if(errfile.is_open()) errfile.close();

	return 0;
}
