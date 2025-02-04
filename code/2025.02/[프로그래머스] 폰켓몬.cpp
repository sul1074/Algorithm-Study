#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> pokemonMap;
    
    for (auto n : nums) pokemonMap[n]++;
    
    return min(pokemonMap.size(), nums.size() / 2);
}
