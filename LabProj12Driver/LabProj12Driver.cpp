// Academic Integrity Affidavit:
// I certify that this program code is my work.  Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: Ian Clowes
// Section: CMPSCI 122 - 002L
// Assignment: LabProj12 (Algorithm Analysis)
//

/*CMPSC122 LabProj12 : Project Algorithm Analysis -- sample driver
* *****************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "timer.h"
#include "MaxSubList.h"
const int FROM_SIZE = 500;
const int MUL = 2;
using namespace std;
void Ouput_CSV_File(string filename, Timer* T, int loop);
int main()
{
	int* Result, * Vec;
	Timer* T, Prepare;
	int loop;
	cout << "Please enter the number of loops: ";
	cin >> loop;
	Prepare.start();
	int Size = FROM_SIZE; // the integers sequence array size
	T = new Timer[loop];
	Result = new int[loop];
	cout << setprecision(4) << fixed << endl;
	// change heading for each algorithm
	cout << string(28, '=') << " Algorithm Blue " << string(28, '=') << endl <<
		endl;
	for (int i = 0; i < loop; i++)
	{
		Vec = new int[Size];
		srand((unsigned)time(NULL));
		for (int j = 0; j < Size; j++)
			Vec[j] = rand() % 101 - 50;
		Result[i] = 0;
		Prepare.stop();
		cout << "Preparation Time: " << Prepare.get_elapsedtime() << "s" << endl;
		T[i].start();
		// Comment and uncomment for each test case
		//Result[i] = MaxSublistSum_Blue(Vec, Size);
		//Result[i] = MaxSublistSum_Green(Vec, Size);
		Result[i] = MaxSublistSum_Red(Vec, Size);
		T[i].stop();
		cout << '[' << setw(2) << i << ']' << setw(50) << "Maximum contiguous subsequence sum(array size = "
		<< setw(9) << Size << "): " << setw(6) << Result[i] << endl;
		cout << "Elapsed Time: " << T[i].get_elapsedtime() << 's' << endl;
		cout << string(72, '-') << endl;
		Size = MUL * Size;
		delete[] Vec;
	}
	cout << endl << endl;
	Ouput_CSV_File("Result(Red).csv", T, loop); // change the filename for each algorithm
}
void Ouput_CSV_File(string filename, Timer* T, int loop)
{
	ofstream csvOutFile(filename);
	if (!csvOutFile)
	{
		cerr << "Failed to open output file: " << filename << endl;
		exit(EXIT_FAILURE);
	}
	int Size = FROM_SIZE;
	csvOutFile << "\"Array Size\",\"Run Time (s)\"" << endl;
	for (int i = 0; i < loop; i++)
	{
		csvOutFile << Size << "," << T[i].get_elapsedtime() << endl;
		Size = MUL * Size;
	}
	csvOutFile.close();
}
//OUTPUTS:
/*
Please enter the number of loops: 7

============================ Algorithm Blue ============================

Preparation Time: 0.0010s
[ 0]  Maximum contiguous subsequence sum(array size =       500):   1055
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0020s
[ 1]  Maximum contiguous subsequence sum(array size =      1000):   1846
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0050s
[ 2]  Maximum contiguous subsequence sum(array size =      2000):   1846
Elapsed Time: 0.0040s
------------------------------------------------------------------------
Preparation Time: 0.0110s
[ 3]  Maximum contiguous subsequence sum(array size =      4000):   2098
Elapsed Time: 0.0170s
------------------------------------------------------------------------
Preparation Time: 0.0300s
[ 4]  Maximum contiguous subsequence sum(array size =      8000):   2184
Elapsed Time: 0.0710s
------------------------------------------------------------------------
Preparation Time: 0.1020s
[ 5]  Maximum contiguous subsequence sum(array size =     16000):   3958
Elapsed Time: 0.2880s
------------------------------------------------------------------------
Preparation Time: 0.3930s
[ 6]  Maximum contiguous subsequence sum(array size =     32000):   3958
Elapsed Time: 1.1300s
------------------------------------------------------------------------


Please enter the number of loops: 7

============================ Algorithm Green ============================

Preparation Time: 0.0010s
[ 0]  Maximum contiguous subsequence sum(array size =       500):    714
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0020s
[ 1]  Maximum contiguous subsequence sum(array size =      1000):    714
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0030s
[ 2]  Maximum contiguous subsequence sum(array size =      2000):   2123
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0050s
[ 3]  Maximum contiguous subsequence sum(array size =      4000):   2390
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0070s
[ 4]  Maximum contiguous subsequence sum(array size =      8000):   5453
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0100s
[ 5]  Maximum contiguous subsequence sum(array size =     16000):   5615
Elapsed Time: 0.0030s
------------------------------------------------------------------------
Preparation Time: 0.0150s
[ 6]  Maximum contiguous subsequence sum(array size =     32000):   5842
Elapsed Time: 0.0050s
------------------------------------------------------------------------



============================ Algorithm Red ============================

Preparation Time: 0.0010s
[ 0]  Maximum contiguous subsequence sum(array size =       500):    913
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0020s
[ 1]  Maximum contiguous subsequence sum(array size =      1000):    913
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0040s
[ 2]  Maximum contiguous subsequence sum(array size =      2000):    960
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0050s
[ 3]  Maximum contiguous subsequence sum(array size =      4000):   1350
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0070s
[ 4]  Maximum contiguous subsequence sum(array size =      8000):   1674
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0090s
[ 5]  Maximum contiguous subsequence sum(array size =     16000):   2701
Elapsed Time: 0.0010s
------------------------------------------------------------------------
Preparation Time: 0.0120s
[ 6]  Maximum contiguous subsequence sum(array size =     32000):   2791
Elapsed Time: 0.0010s
------------------------------------------------------------------------





*/