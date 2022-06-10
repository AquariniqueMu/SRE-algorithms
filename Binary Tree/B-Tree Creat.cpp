/*
 * @Author: your name
 * @Date: 2022-04-21 17:57:50
 * @LastEditTime: 2022-04-21 17:58:54
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
		cout<<"Please Input the Left  Child of "<<T->val<<"：";
		T->left=createBiTree();
		cout<<"Please Input the Right Child of "<<T->val<<"：";
		T->right=createBiTree();
	}
	return T; //返回创建的二叉树T 
}


int main(){
    BiTree T;
    cout<<"input the root node: ";
    T = createBiTree();
    cout<<endl;
}