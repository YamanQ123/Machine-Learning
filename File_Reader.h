#ifndef FILEREADER
#define FILEREADER

#include<string>
#include<vector>
#include<iostream>


////////////////////////////////////////////////////////////////////////
///                                                                  ///
///                                                                  ///
///                             File Reader                          ///
///                                                                  ///
/// Input:                                                           ///
///     1)file name.                                                 ///
///     2)separator: (comma, space, etc).                            ///
///     3)lines to ignore: where to start reading (line number).     ///
///                                                                  ///
/// Output:                                                          ///
///     vector of vector of strings each vector represent a row.     ///
///                                                                  ///
/// Usage:                                                           ///
///     reading .tsv, .csv files.                                    ///
///                                                                  ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////



typedef std::vector< std::vector<std::string> > FileRows;

class FileReader{

private:
    std::string fileName;
    char separator;
    unsigned int linesToSkip;
    FileRows fileRows;

    std::vector<std::string> split(const std::string& s, char delimiter);




public:

    FileReader(std::string file_name,char Separator = ',',unsigned int lines_to_skip = 0):
               fileName(file_name), separator(Separator),linesToSkip(lines_to_skip){

    }


     void read();

     inline const FileRows& getContent() const{return fileRows;}

     friend std::ostream& operator<<(std::ostream& os, const FileReader& fr);




};





#endif // FILEREADER

