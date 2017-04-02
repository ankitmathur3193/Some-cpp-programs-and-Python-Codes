#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
class node
{
	public:
		node *left;
		node *right;
		int height;
		int data;
		node(int x):left(NULL),right(NULL),height(0),data(x){}
};
class Balance_binary_search_tree
{
		public:
			virtual void insert(int x)=0;
			//virtual void delete_node(int x)=0;
			virtual ~Balance_binary_search_tree(){};
			

};
class tree
{
		public:
			tree(){};
			void inorder(node *root);
			void preorder(node *root);
			node* delete_tree(node *root);
			virtual ~tree(){};
			
};
class avl_tree : public Balance_binary_search_tree,public tree
{
	private:
		node *root;
		int high(node *p);
		node *left_rotate(node *p);//when node is inserted as right child of right subtree
		node *right_rotate(node *p);//when node is inserted as left child of left subtree
		node *left_right_rotate(node *p);//when node is inserted as right child of left substree
		node *right_left_rotate(node *p);//when node is inserted as left child of right subtree
		node *insert(node *root,int x);
		bool check_balance(node *p);
		node *copy_tree(node *p);
	public:	
		avl_tree()
		{
			root=NULL;
		}
		virtual ~avl_tree()
		{
			root=delete_tree(root);
		}
		avl_tree(const avl_tree &p)
		{
			cout<<"copy constructor invoked"<<endl;
			root=copy_tree(p.root);
		}
		void operator=(const avl_tree &p)
		{
			cout<<"= operator overloaded"<<endl;
			root=copy_tree(p.root);
		}
		void insert(int x);
		void delete_node(int x);
		void inorder();
		void preorder();


};
node * avl_tree :: copy_tree(node *p)
{
	if(p==NULL)
		return NULL;
	node *temp=new node(p->data);
	temp->left=copy_tree(p->left);
	temp->right=copy_tree(p->right);
	return temp;
}
void avl_tree :: insert(int x)
{
	root=insert(root,x);
	//cout<<"fuck yeh"<<endl;
	/*if(!check_balance(root))
	{
		cout<<"node not inserted correctly "<<x<<endl;
	}*/
}
node * avl_tree :: left_right_rotate(node *p)//when node is inserted as right child of left substree
{
	p->left=left_rotate(p->left);
	return right_rotate(p);
}
node * avl_tree :: right_left_rotate(node *p)//when node is inserted as left child of right subtree
{
	p->right=right_rotate(p->right);
	return left_rotate(p);
}
node * avl_tree :: right_rotate(node *p)//when node is inserted as left child of left subtree
{
	node *left_subtree=p->left;
	p->left=left_subtree->right;
	left_subtree->right=p;
	p->height=max(high(p->left),high(p->right))+1;
	left_subtree->height=max(high(left_subtree->left),high(left_subtree->right))+1;
	return left_subtree;
}
node * avl_tree :: left_rotate(node *p)//when node is inserted as right child of right subtree
{
	node *right_subtree=p->right;
	p->right=right_subtree->left;
	right_subtree->left=p;
	p->height=max(high(p->left),high(p->right))+1;
	right_subtree->height=max(high(right_subtree->right),high(right_subtree->left))+1;
	return right_subtree;
}
node * avl_tree :: insert(node *root,int key)
{
	if(root==NULL)
	{
		node *temp=new node(key);
		return temp;
		//return new node(key);
	}
	if(root->data<key)
	{
		root->right=insert(root->right,key);
	}
	else
	{
		root->left=insert(root->left,key);
	}
	int balance=high(root->left)-high(root->right);
	if(balance > 1)//node inserted in left subtree
	{
		if(root->left->data>key)//node inserted as left child in left subtree
		{
			root=right_rotate(root);
		}
		else//node is inserted as right child in left subtree
		{
			root=left_right_rotate(root);
		}
	}
	else if(balance < -1)//node is inserted in right subtree
	{
		if(root->right->data<key)//node is right child in right subtree
		{
			root=left_rotate(root);
		}
		else//node is inserted as left child in right subtree
		{
			root=right_left_rotate(root);
		}
	}
	root->height=max(high(root->left),high(root->right))+1;
	return root;

}
bool avl_tree :: check_balance(node *p)
{
	//cout<<"nice"<<endl;
	if(p==NULL)
		return true;
	//cout<<"wth "<<p->data<<" ";
	int balance=fabs(high(p->left)-high(p->right));
	//cout<<"wth "<<p->data<<" ";
	if(balance<=1)
	{
		if(check_balance(p->left)&&check_balance(p->right))
			return true;
	}
	return false;
	//return (balance<=1&&check_balance(root->left)&&check_balance(root->right));
}
int avl_tree :: high(node *p)
{
	if(p==NULL)
		return 0;
	return p->height;
}
void avl_tree :: inorder()
{
	tree::inorder(root);
	cout<<endl;
}
void avl_tree :: preorder()
{
	tree::preorder(root);
	cout<<endl;
}
void tree :: inorder(node *root)
{
		if(root==NULL)
		{
			return;
		}
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
}
node * tree :: delete_tree(node *root)
{
	if(root==NULL)
		return NULL;
	root->left=delete_tree(root->left);
	root->right=delete_tree(root->right);
	delete root;
	return NULL;
}
void tree :: preorder(node *root)
{
	if(root==NULL)
		return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	//cout<<"why"<<endl;
		avl_tree p;
		//cout<<"wtf"<<endl;
		for(int i=0;i<20;++i)
		{
			//cout<<"cool "<<i<<" ";
			p.insert(i+1);
		}
		for(int i=60;i>40;--i)
		{
			//cout<<"cool "<<i<<" ";
			p.insert(i+1);
		}

		p.inorder();
		p.preorder();
		avl_tree q=p;
		avl_tree r;
		r=q;
		return 0;

}