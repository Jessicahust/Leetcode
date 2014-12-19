#include<iostream>
#include<new>
#include<vector>
using namespace std;

//Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n)
	{
        return generateTrees(1,n);
    }

	vector<TreeNode *> generateTrees(int start, int end)
	{
		vector<TreeNode *> trees;
		if (start > end)
		{
			trees.push_back(NULL);
			cout<<trees.size()<<endl;
			return trees;
		}
		if (start==end)
		{
			trees.push_back(new TreeNode(start));
			return trees;
		}

		for (int i=start; i<=end; ++i)
		{
			vector<TreeNode *> treesleft = generateTrees(start,i-1);
			vector<TreeNode *> treesright = generateTrees(i+1,end);

			for (size_t j=0; j<treesleft.size(); ++j)
			{
				for (size_t k=0; k<treesright.size(); ++k)
				{
					TreeNode *root = new TreeNode(i);
					root->left = treesleft[j];
					root->right = treesright[k];
					trees.push_back(root);
				}
			}
		}

		return trees;
	}
};

int main()
{
    Solution s;
    vector<TreeNode*> vec=s.generateTrees(3);
    for(auto a:vec)
        cout<<a->val<<" ";
    cout<<endl;
}
