/*
 * @Author: your name
 * @Date: 2022-04-21 17:12:32
 * @LastEditTime: 2022-04-21 17:55:55
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Binary Tree\B-Tree Creat.cpp
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}Tnode, *BiTree;

typedef struct{
  BiTree *top;
  BiTree *base;
  int size;  
}Stack;

void initStack(Stack &S){
    S.base = (BiTree *)malloc(50*sizeof(BiTree));
    S.top = S.base;
    S.size = 50;
}

int EmptyStack(Stack S){
    if(S.base == S.top){
        return 1;
    }
    else{
        return 0;
    }
}


//二叉树结点及左右孩子结点入栈 
void Push(Stack &S,BiTree p){
	if(S.top-S.base>=S.size){
		cout<<"栈满了";
	}
	*(S.top)=p;
	S.top++;
}

//栈中存储的结点出栈 
void Pop(Stack &S,BiTree &p){
	if(S.top==S.base){
		cout<<"栈为空";
	}
	S.top--;
	p=*(S.top);
}

//获取栈中位于栈顶的结点
int GetTop(Stack &S,BiTree &p){
	if(S.top==S.base){
		return 0; //如果栈为空，返回0 
	}else{
		if(p==NULL){ //判断是否为空 
			return 0; //返回0
		}
		else{
			p=*(S.top-1); //获取栈顶元素 
			return 1; //返回1
		} 
	}
} 

//创建二叉树结构体型函数-BiTree函数，递归创建二叉树
BiTree createBiTree(){
	BiTree T; //定义二叉树结点结构体变量 
	char val;  
	cin>>val; //输入数据元素 
	if(val == '#'){
		T=NULL; //输入字符#，则将对应结点孩子指针域置为空 
	}else{
		T=(Tnode *)malloc(sizeof(BiTree)); //分配结点存储空间 
		T->val=(int)val-48;
		cout<<"Please Input the Left Child of "<<T->val<<"：";
		T->left=createBiTree();
		cout<<"Please Input the Right Child of "<<T->val<<"：";
		T->right=createBiTree();
	}
	return T; //返回创建的二叉树T 
}


class PreSolution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    vector<int> res;
    void dfs(TreeNode* Node){
        if(Node == nullptr) return;
        res.push_back(Node->val);
        dfs(Node->left);
        dfs(Node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        dfs(root);
        return res;
    }
};

class InSolution {
public:
    void Traversal(vector<int> &res,TreeNode* root){
        if(root == NULL) return;
        Traversal(res,root->left);
        res.push_back(root->val);
        Traversal(res,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Traversal(res,root);
        return res;
    }
};

class PostSolution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> res;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        dfs(node->right);
        res.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // write code here
        if (root == nullptr) return {};
        dfs(root);
        return res;
    }
};

class LevelSolution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> leaves;
        vector<vector<int> > ans;
        int n =1;
        TreeNode* tmp;
        leaves.push(root);
        while(!leaves.empty()){
            n=leaves.size();
            vector<int> parts;
            for(int i =0;i<n;i++){
                tmp = leaves.front();
                leaves.pop();
                if(tmp->left){
                    leaves.push(tmp->left);
                }
                if(tmp->right){
                    leaves.push(tmp->right);
                }
                parts.push_back(tmp->val);
            }
            ans.push_back(parts);
        }
        return ans;
    }
};





int main(){
    BiTree T;
    vector<int> res;
    vector<vector<int>> levelRes;
    PreSolution pre;
    InSolution in;
    PostSolution post;
    LevelSolution level;
    cout<<"input the root node: ";
    T = createBiTree();
    cout<<endl;

    res = pre.preorderTraversal(T);
    cout<<"The result of Preorder Traversal is: [ ";
    for(auto e:res){
        cout<<e<<" ";
    }
    cout<<"]"<<endl;

    res = in.inorderTraversal(T);
    cout<<"The result of Inorder Traversal is: [ ";
    for(auto e:res){
        cout<<e<<" ";
    }
    cout<<"]"<<endl;

    res = post.postorderTraversal(T);
    cout<<"The result of Postorder Traversal is: [ ";
    for(auto e:res){
        cout<<e<<" ";
    }
    cout<<"]"<<endl;

    levelRes = level.levelOrder(T);
    cout<<"The result of Preorder Traversal is: [ ";
    for(auto e:levelRes){
        cout<<"[ ";
        for(auto a:e){
            cout<<a<<" ";
        }
        cout<<"] ";
    }
    cout<<"]"<<endl;
}