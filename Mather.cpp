

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;


int main(int argc, char* argv[])
{
	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	/// -++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	// ALTER THIS CODE TO ADAPT TO FILEDATA
	const int participantCount = 16;		//stoi(argv[0]);
	const int types = 3;	// FixCount, VisCount, VisDuration
	int songs = 8;
	const int areas = 5;	// Bot MidBot MidTop TopBot TopTop
	//int streakTypes = 2;
	int rowLength = songs * areas;	// 24

	cout << "PRESS 'y' FOR STREAKS, PRESS WHATEVER FOR SONGS" << endl;
	char input = ' ';
	cin >> input;

	string source[types];
	string destination[types];
	if (input == 'y') {	// STREAKS
		source[0] = "FixationCountStreaks.txt";
		source[1] = "VisitCountStreaks.txt";
		source[2] = "TotalVisitDurationStreaks.txt";
		destination[0] = "M_FixationCountStreaks.tsv";
		destination[1] = "M_VisitCountStreaks.tsv";
		destination[2] = "M_TotalVisitDurationStreaks.tsv";
	}					
	else {				// SONGS
		source[0] = "FixationCountSongs.txt";
		source[1] = "VisitCountSongs.txt";
		source[2] = "TotalVisitDurationSongs.txt";
		destination[0] = "M_FixationCountSongs.tsv";
		destination[1] = "M_VisitCountSongs.tsv";
		destination[2] = "M_TotalVisitDurationSongs.tsv";
	}

	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	/// -++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
									// ALLOCATE CONTAINERS
	stringstream participantData_s;
	string rowData;
	string elementData;
	string temp = "";
	ifstream datafile;

	// Allocate data 
	double ***data = new double**[types];			// (4 * Participants * 24)
	for (int i = 0; i < types; i++)						// 4
	{
		data[i] = new double*[participantCount];
		for (size_t j = 0; j < participantCount; j++)		// X
		{
			data[i][j] = new double[rowLength];				// 24
			for (size_t k = 0; k < rowLength; k++)
			{
				// Init as '0'
				data[i][j][k] = 0;
			}
		}
	}


	double ***finishedData = new double**[types];	// (4 * Participants * 8)
	for (int i = 0; i < types; i++)						// 4
	{
		finishedData[i] = new double*[participantCount];
		for (size_t j = 0; j < participantCount; j++)		// 16
		{
			finishedData[i][j] = new double[areas];				// 3	
			for (size_t k = 0; k < areas; k++)
			{
				finishedData[i][j][k] = 0;
			}
		}
	}

	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	/// -++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	// READ FROM FILES
	// Per Type 
	for (size_t currentType = 0; currentType < types; currentType++)
	{
		datafile.open(source[currentType]);

		if (datafile.is_open()) {
			// Always skip first line
			getline(datafile, temp);

			// Per Participant
			int currentParticipant = 0;

			// Get the entire row for the current participant
			rowData.clear();

			while (getline(datafile, rowData, '\n')) {
				bool parsedName = false;
				int currentElement = 0;

				// Enable further Getlinin' by using stringstream
				participantData_s.clear();
				participantData_s << rowData;

				// Parse the elements
				while (getline(participantData_s, elementData, '\t')) {
					if (parsedName) {
						// If it crashes here, it means the input-file dimensions are not correct! The file is longer than you thought :O
						data[currentType][currentParticipant][currentElement++] = strtod(elementData.c_str(), 0);
					}
					else {
						parsedName = true;
					}
				}
				currentParticipant++;
			}
			datafile.close();
		}
	}


	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	/// -++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	// DO MATH

	// Per type
	float areaTots[areas] = { 0 };
	float botTot = 0;
	float midTot = 0;
	float topTot = 0;
	float megaTot = 0;
	float botPercent = 0;
	float midPercent = 0;
	float topPercent = 0;

	/* ORDER
	10,11,7,6,2,14,13,3,9,5,15,8,12,4,1,16
	*/
	/* ORDER-To-GO (BUT DANIEL THINKING)
	15,	5,	8,	14,	10,	4,	3,	12,	9,	1,
	2,	13,	7,	6,	11, 16
	*/

	int IndexToRank[participantCount] = {	// What place the index should go to, ie: index 0's rank is 15.
		15,	5,	8,	14,	10,	4,	3,	12,	9,	1,
		2,	13,	7,	6,	11, 16
	};

	for (int i = 0; i < types; i++)		// Per File
	{	
		for (size_t j = 0; j < participantCount; j++)  // Per Participant
		{
			// Reset
			megaTot = 0;
			for (size_t k = 0; k < areas; k++)
			{
				areaTots[k] = 0;
			}

			for (size_t k = 0; k < songs; k++)					// Per Song
			{
				for (size_t l = 0; l < areas; l++)					// Per Area
				{
					//botTot += data[i][j][(k * 3) + 0];	// Add Current Bot % to the 
					//midTot += data[i][j][(k * 3) + 1];	// TotMid
					//topTot += data[i][j][(k * 3) + 2];	// TotTop

					areaTots[l] += data[i][j][(k * areas) + l];	// Add Current Bot % to the 
				}
			}

			// Sum up to get total (still per participant)
			for (size_t l = 0; l < areas; l++)
			{
				//megaTot = botTot + midTot + topTot;

				megaTot += areaTots[l];
			}
			
			// Add final math'd to finishedData
			for (size_t l = 0; l < areas; l++)
			{
				//finishedData[i][IndexToRank[j] - 1][0] = botPercent = (botTot / megaTot) * 100;	// Scaled so percentages are better displayed
				//finishedData[i][IndexToRank[j] - 1][1] = midPercent = (midTot / megaTot) * 100;	// in GnuPlot (-1 because 1-16 --> 0-15)
				//finishedData[i][IndexToRank[j] - 1][2] = topPercent = (topTot / megaTot) * 100;
				
				finishedData[i][IndexToRank[j] - 1][l] = (areaTots[l] / megaTot) * 100;
			}
		}
	}

	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	/// -++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	// --++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
	// WRITE TO FILES
	ofstream file;

	// Per Type(file)
	for (size_t i = 0; i < types; i++)
	{
		file.open(destination[i]);
		if (file.is_open())
		{
			int stepper = 0;
			file << "\t";	// Start of file indent

			// Adding LABLES, so that GNUPLOT can IGNORE them
			for (size_t j = 0; j < rowLength; j++)
			{
				file << "COLUMN_" << i;
			}
			file << "\n";

			// Per Participant(row)
			for (size_t j = 0; j < participantCount; j++)
			{
				
				file << "P" << (j+1) << "\t";	// Row LABLES
				
				for (size_t k = 0; k < areas-1; k++)
				{
					//file << finishedData[i][j][0] << "\t";
					//file << finishedData[i][j][1] << "\t";
					//file << finishedData[i][j][2] << "\n";

					file << finishedData[i][j][k] << "\t";		// Tab as delimiter
				}
				file << finishedData[i][j][areas-1] << "\n";	// Last element needs a newline
				
			}
			file << "\n";
		}
		file.close();
	}

	return 0;
}
