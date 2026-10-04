/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
    int n;

    Node* buildtree(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        Node* root = new Node();
        if (x1 == x2 && y1 == y2) {
            if (grid[x1][y1] == 1)
                root->val = true;
            root->isLeaf = true;
            return root;
        }

        int value = grid[x1][y1];
        bool leaf = true;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (grid[i][j] != value)
                    leaf = false;
            }
        }
        if(leaf){
            root->val = value;
            root->isLeaf = true;
            return root;
        }
        int len = x2 - x1 + 1;
        int nx1 = x1, ny1 = y1;
        int nx2 = nx1, ny2 = ny1 + len / 2;
        int nx3 = nx1 + len / 2, ny3 = ny1;
        int nx4 = nx1 + len / 2, ny4 = ny1 + len / 2;

        root->topLeft =
            buildtree(grid, nx1, ny1, nx1 + len / 2 - 1, ny1 + len / 2 - 1);
        root->topRight =
            buildtree(grid, nx2, ny2, nx2 + len / 2 - 1, ny2 + len / 2 - 1);
        root->bottomLeft =
            buildtree(grid, nx3, ny3, nx3 + len / 2 - 1, ny3 + len / 2 - 1);
        root->bottomRight =
            buildtree(grid, nx4, ny4, nx4 + len / 2 - 1, ny4 + len / 2 - 1);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        n = grid.size();
        return buildtree(grid, 0, 0, n - 1, n - 1);
    }
};