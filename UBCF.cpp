// 0.989 rating
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <unordered_map>
#include <limits>
#include <cstdio>
#include <cmath>

using namespace std;

vector<string> split(const string& line, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = line.find(delimiter, pos_start)) != string::npos) {
        token = line.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(line.substr(pos_start));
    return res;
}




    
int main()
{	
    string trainFname = "train.csv";

    ifstream finTrain;
    string line;

    finTrain.open(trainFname);
    finTrain.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> userIDs;
    vector<int> movieIDs;
    unordered_map<int, unordered_map<int, double>> utilityMatrix;

    while (getline(finTrain, line)) {
        vector<string> v = split(line, ",");
        int userID = stoi(v[0]);
        int movieID = stoi(v[1]);
        double rating = stod(v[2]);

        if (find(movieIDs.begin(), movieIDs.end(), movieID) == movieIDs.end()) {
            movieIDs.push_back(movieID);
        }

        if (find(userIDs.begin(), userIDs.end(), userID) == userIDs.end()) {
            userIDs.push_back(userID);
        }
        
        utilityMatrix[movieID][userID] = rating;
    }
    finTrain.close();

    std::cout << "Training data traversel ended \n";

    std::sort(movieIDs.begin(), movieIDs.end());
    std::sort(userIDs.begin(), userIDs.end());

    std::cout << "Data sorting ended \n";
    
    

    
    string testFname = "test.csv";
    ifstream finTest;

    

    finTest.open(testFname);
    finTest.ignore(numeric_limits<streamsize>::max(), '\n');

    // unordered_map<vector<int>, double> similarityMatrix;
    map<int, double> idRating;


    while (getline(finTest, line)) {
        vector<string> v = split(line, ",");
        int T_ID = stoi(v[0]);
        int T_userID = stoi(v[1]);
        int T_movieID = stoi(v[2]);

        
        double ratingSum = 0;
        double similaritySum = 0;

        for (int& movieID : movieIDs) {
            if (utilityMatrix[movieID].find(T_userID) != utilityMatrix[movieID].end()) {
                // std::cout << "MovieID" << movieID << " is picked" << endl;

                double dotProduct = 0;
                double lengthv1 = 0;
                double lengthv2 = 0;

                for 
                    (auto& [userID, rating] : utilityMatrix[T_movieID]) {

                    lengthv1 += rating * rating;

                    if (utilityMatrix[movieID].find(userID) != utilityMatrix[movieID].end()) {

                        dotProduct += utilityMatrix[movieID][userID] * utilityMatrix[T_movieID][userID];
                        //cout << "Dot product " << dotProduct << endl;

                    }
                }

                if (dotProduct == 0) {
                    // pass this user
                }

                else {

                    for (auto& [userID, rating] : utilityMatrix[movieID]) {

                        lengthv2 += rating * rating;

                    }

                    //std::cout << "DotProduct " << dotProduct << " lengthv1 " << lengthv1 << " lengthv2 " << lengthv2 << endl;

                    double similarity = dotProduct / (sqrt(lengthv1) * sqrt(lengthv2));

                    //std::cout << "Similarity was: " << similarity << endl;

                    ratingSum += similarity * utilityMatrix[movieID][T_userID];
                    similaritySum += similarity;

                    // std::cout << "RatingSum: " << ratingSum << " SimilaritySum: " << similaritySum << endl;

                }

            }
        }

        std::cout << "RatingSum: " << ratingSum << " SimilaritySum: " << similaritySum << endl;

        double score = ratingSum / similaritySum;
        idRating[T_ID] = score;

        std::cout << T_ID << " is finished with rating " << score << endl;
    }
        
    finTest.close();


    for (auto& [id, data] : idRating) {
            cout << data << "\n";
    }

    return 0;

}