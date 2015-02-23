/*Khademul Haque
  CIVL 8903
  Homework 4

   for(int c = 0; c < 10*n; c++){
if(c <= 1) sum = c;
else{
sum = first + second;
std::cout << sum << " ";
if(c % 10 == 0 ){
std::cout << "\n";
}
}
// next fib
first = second;
second = sum;
}

void print_output(ofstream& stream, string str){

  stream << str;
}
print_output(cout, "\n");
  // convert a number into string

*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <exception>

using namespace std;

struct Info{
    string name;
    unsigned int value;
    
    Info(string name = "", unsigned int value = 0){
        this->name = name;
        this->value =  value;
    }
};

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

	string in_file_path;
	cout<<"Enter input file name: ";
	cin >> in_file_path;
	const char* out_file_path = "khademul.out";
    const char* err_file_path = "khademul.err";

	// Two dimensional array, unlimited rows, first 10 columns
    // Cell values are number of Fibonaaci series
    unsigned int** matrix = NULL;

	// total values
    vector<Info> row_totals, column_totals;

	// row to row index mapping
    map<string, int> row_to_row;
    // column to column index mapping
    map<string, int> column_to_column;

	string last_line; // For showing errors in the input
    int last_line_no = 1;

	ifstream in(in_file_path.c_str());
    ofstream outfile(out_file_path);
    ofstream errfile(err_file_path);
	if(!errfile.is_open()){
        cerr << "Cannot open error file for writing: " << err_file_path << "\n";
        return 0;
    }    

	int c, first=0, second=1, sum;

	try{    
        if(in.is_open() ){
            cout << "Reading " << in_file_path << "...\n";

            // read N
            int n;

            in >> n;

			// done with input
            in.close();

			cout <<"First "<< n <<" terms of Fibonacci series are : " <<endl;
			// create output matrix
            matrix = new unsigned int*[n];
            for(int a = 0; a < n; a++){
                matrix[a] = new unsigned int[10];
                for(int b = 0; b <10; b++){
                    matrix[a][b] = 0;
			for (c=0; c<n ;c++){
				if (c <= 1)
					sum=c;
				else{
					sum=first+second;
					first=second;
					second=sum;
				}
				cout<<sum<<endl;
			}
			void print_output(ofstream, string){
               for(int c = 0; c < 10*n; c++){
if(c <= 1) sum = c;
else{
sum = first + second;
cout << sum << " ";

if(c % 10 == 0 ){
	cout << "\n";
}
}
}
// next fib
first = second;
second = sum;
}
		   // validate
                if( n >= 1)
                {
                    // save the value in the matrix
                    matrix[a][b] = sum;

                }
                else{
                    cerr << "Entry# " << n << ": " << last_line << " -- Warning: negative entry\n";
                    errfile << "Entry# " << n << ": " << last_line << " -- Warning: negative entry\n";
                    sum++;
					}
				 }
		      }
			// save output
            if(outfile.is_open()){
				cout << "Writing output in file: " << out_file_path << "\n";
				// print matrix
                outfile << "First "<< n <<" terms of Fibonacci series are :\n";
                for(int a = 0; a < n; a++){
                   outfile << matrix[a];
                    for(int b = 0; b < 11; b++){
                        outfile << "\t" << matrix[a][b];
                    }
                    outfile << "\n";
                }
				// done
                outfile.close();
			}
			else{
                cerr << "Error: cannot open file for writing: " << out_file_path << "\n";                
                errfile << "Error: cannot open file for writing: " << out_file_path << "\n";                
            }
        }
        else{
            cerr << "Error: cannot open file for reading: " << in_file_path << "\n";
            errfile << "Error: cannot open file for reading: " << in_file_path << "\n";
        }
	}
	catch(exception& e){
        cerr << "Error: " << e.what() << "\n";
        cerr << "Error: " << e.what() << "\nLine " << last_line_no << ": " << last_line << "\n";
        errfile << "Error: Line " << last_line_no << ": " << last_line << "\n";
    }
	// clean up
    if(in.is_open()) in.close();
    if(outfile.is_open()) outfile.close();
    if(matrix != NULL) {
        for(int a = 0; a < sum; a++){
            if(matrix[a]) delete[] matrix[a];
        }
        delete[] matrix;
    }
	return 0;
}
