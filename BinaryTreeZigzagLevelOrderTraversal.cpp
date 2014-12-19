#include<iostream>
#include<new>
#include<vector>
#include<stack>
using namespace std;

//Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        stack<int> st;
        vector<vector<int> > vec;//�������ÿһ��Ĺؼ���
        vector<vector<TreeNode*> > rvec; //�������ÿһ��Ľ��
        size_t i=0;
        if(root==NULL)
            return vector<vector<int> >();
        vec.push_back({root->val});
        rvec.push_back({root});
        vector<int> v1; //�������һ��Ĺؼ���
        vector<TreeNode*> v2; //�������һ��Ľ��
        int flag=0;//�����������������ӡ�ò��Ԫ��
        while(rvec.size())
        {
            v1.clear();
            v2.clear();
            if(flag==0)
            {
                //ÿ��ֻ�����һ����в���
                for(i=0; i<rvec[rvec.size()-1].size(); i++)
                {
                    TreeNode *tmp=rvec[rvec.size()-1][i];
                    if(tmp->left)
                    {
                        st.push(tmp->left->val);
                        v2.push_back(tmp->left);
                    }
                    if(tmp->right)
                    {
                        st.push(tmp->right->val);
                        v2.push_back(tmp->right);
                    }
                }
                while(!st.empty())
                {
                    v1.push_back(st.top());
                    st.pop();
                }
                if(!v1.empty()&&!v2.empty())
                {
                    vec.push_back(v1);
                    rvec.push_back(v2);
                }
                else
                    break;
                flag=1;
            }
            else
            {
                for(i=0; i<rvec[rvec.size()-1].size(); i++)
                {
                    TreeNode *tmp=rvec[rvec.size()-1][i];
                    if(tmp->left)
                    {
                        v1.push_back(tmp->left->val);
                        v2.push_back(tmp->left);
                    }
                    if(tmp->right)
                    {
                        v1.push_back(tmp->right->val);
                        v2.push_back(tmp->right);
                    }
                }
                if(!v1.empty()&&!v2.empty())
                {
                    vec.push_back(v1);
                    rvec.push_back(v2);
                }
                else
                    break;
                flag=0;
            }
        }
        return vec;
    }
    void createTree(TreeNode *&root)
    {
        int i;
        cin>>i;
        if(i!=0)
        {
            root=new TreeNode(i);
            if(root==NULL)
                return;
            createTree(root->left);
            createTree(root->right);
        }
    }
};

int main()
{
    Solution s;
    TreeNode *root;
    s.createTree(root);
    vector<vector<int> > vec=s.zigzagLevelOrder(root);
    for(auto a:vec)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}


