#include <bits/stdc++.h>
using namespace std;

// Função auxiliar para encontrar todos os subconjuntos
void findSubsets(vector<int>& nums, vector<int>& subset, int index, vector<vector<int>>& allSubsets) {
    // Adiciona o subconjunto atual à lista de todos os subconjuntos
    allSubsets.push_back(subset);

    // Percorre todos os elementos restantes para formar novos subconjuntos
    for (int i = index; i < nums.size(); i++) {
        // Inclui o elemento atual no subconjunto
        subset.push_back(nums[i]);

        // Chama recursivamente a função para encontrar outros subconjuntos
        findSubsets(nums, subset, i + 1, allSubsets);

        // Remove o elemento atual do subconjunto (backtrack)
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> allSubsets;
    vector<int> subset;
    findSubsets(nums, subset, 0, allSubsets);
    return allSubsets;
}

int main() {
    int n;
    cout << "Digite o tamanho do conjunto: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Digite os elementos do conjunto: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<vector<int>> result = subsets(nums);

    cout << "Os subconjuntos são:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
