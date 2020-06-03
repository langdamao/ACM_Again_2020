#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct NodeType{
	TreeNode *x;
	int ty;
    NodeType(TreeNode *xx,int t) :  x(xx),ty(t) {}
};
stack<NodeType> q;
int main(){
	TreeNode *root = new TreeNode(1);
	NodeType r= NodeType(root,0);
	while(!q.empty()) q.pop();
	q.push(r);
	while(!q.empty()){
		NodeType tmpn = q.top();
		q.pop();
		TreeNode *tmp = tmpn.x;
		if(tmpn.ty==0){
			q.push(NodeType(tmp,1));
			while(tmp->left!=NULL) {
				q.push(NodeType(tmp->left,1));
				tmp=tmp->left;
			}
		}
		else if (tmpn.ty==1){
			q.push(NodeType(tmp,2));
			if (tmp->right!=NULL){
				q.push(NodeType(tmp->right,0));
			}
		}
		else if (tmpn.ty==2){
			printf("%d ",tmp->val);
		}
	}
	return 0;
}
