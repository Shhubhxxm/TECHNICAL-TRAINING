#include <iostream>
#include <unordered_set>
#include <string>

class CrackSafe {
public:
    std::string crackSafe(int n, int k) {
        std::unordered_set<std::string> seen;
        std::string ans;
        
        // Start DFS with a string of (n-1) zeros
        std::string start_node(n - 1, '0');
        dfs(start_node, k, seen, ans);
        
        // Append (n-1) zeros at the end to handle the wrap-around
        return ans + start_node;
    }

private:
    void dfs(const std::string& node, int k, std::unordered_set<std::string>& seen, std::string& ans) {
        for (int x = 0; x < k; ++x) {
            std::string nei = node + std::to_string(x);
            if (seen.find(nei) == seen.end()) {
                seen.insert(nei);
                dfs(nei.substr(1), k, seen, ans);
                ans.push_back('0' + x);
            }
        }
    }
};

// Example usage
int main() {
    int n = 2;
    int k = 2;
    CrackSafe cs;
    std::cout << cs.crackSafe(n, k) << std::endl; // Output: "00110"
    return 0;
}
