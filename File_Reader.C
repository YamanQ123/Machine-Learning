#include "File_Reader.h"
#include <fstream>
#include <sstream>

std::vector<std::string> FileReader::split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

void FileReader::read(){

        std::ifstream infile(fileName.c_str());
        std::string line;
        while (std::getline(infile, line))
        {
            fileRows.push_back(split(line,separator));
        }
        infile.close();

}



std::ostream& operator<<(std::ostream& os, const FileReader& fr)
{
    int m,n;
    m = fr.fileRows.size();
    if(m){
        n = fr.fileRows[0].size();
        for(int i =0; i<m; i++){
            for(int j=0;j<n;j++){
                os<<fr.fileRows[i][j]<<" ";
            }
            os << "\n";
        }
    }
    return os;
}
