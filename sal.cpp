#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumOfVector(const vector<int>& vec) {
    int sum = 0;
    for (const int element : vec) {
        sum += element;
    }
    return sum;
}

int getLastNonZeroElement(const vector<int>& numbers) {

    for (int i = numbers.size() - 1; i >= 0; --i) {
        if (numbers[i] != 0) {
            return numbers[i];
        }
    }

    return 100001;
}

int main() {
    int N, K;

    cin >> N >> K;

    vector<int> goatWeights(N);

    for(int i = 0; i < N; i++)
    {
        cin >> goatWeights[i];
    }

    try
    {
        if(N < 1 || N > 1000)
        {
            throw invalid_argument("Invalid input the goats should be between 1 and 1000");
        }

        if(N < 1 || N > 1000)
        {
            throw invalid_argument("Invalid input the cources should be between 1 and 1000");
        }

        for(int i = 0; i < N; i++)
        {
            if(goatWeights[i] < 1 || goatWeights[i] > 100000)
            {
                throw invalid_argument("Invalid input the weight of every goat should be between 1 and 100000");
            }
        }
    } catch(const invalid_argument& e)
    {
        cout << e.what() << endl;
    }


    sort(goatWeights.rbegin(), goatWeights.rend());

    int course = 0;
    int minWeight = sumOfVector(goatWeights) / K;
    int sum = 0;
    vector<int> safer = goatWeights;

    int i = 0;

    vector<int> result;

    while(course != K)
    {
        course = 0;
        i = 0;
        result.clear();
        while (sumOfVector(goatWeights) != 0)
        {
            if(goatWeights[i] < minWeight && goatWeights[i] != 0)
            {
                sum = goatWeights[i];
                goatWeights[i] = 0;
                int dif = minWeight - goatWeights[i];
                if(dif >= getLastNonZeroElement(goatWeights))
                {
                    for(int j = 0; j < N; j++)
                    {
                        if(goatWeights[j] != 0 && goatWeights[j] + sum <= minWeight)
                        {
                            sum = sum + goatWeights[j];
                            goatWeights[j] = 0;
                            result.push_back(sum);
                        }
                    }
                }
                course++;
            }else if(goatWeights[i] != 0)
            {
                result.push_back(goatWeights[i]);
                goatWeights[i] = 0;
                course++;
            }
            i++;

            if(course >= 11)
            {
                break;
            }
        }
        
        minWeight++;
        goatWeights = safer;
    }

    cout << *max_element(result.begin(), result.end()) << endl;

    return 0;
}