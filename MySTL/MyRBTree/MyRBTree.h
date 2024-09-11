#pragma once
#include <iostream>
#include <sstream>
#include <string>

enum class Color { RED, BLACK}; 


template < typename Key, typename Value > class RBTree {

	//红黑树节点定义

	class Node {
	public:
		Key key;
		Value value;
		Color color;
		Node* left;
		Node* right;
		Node* parent;
	

	Node(const Key& k, const Value& v, Color c, Node* p = nullptr)
		:key(k), value(v), color(c), left(nullptr), right(nullptr), parent(p) {
	}
	Node()
		:color(Color::BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
	};

private:
	Node* root;
	size_t size;
	Node *Nil;

	// 查询某节点
	Node* lookUp(Key key) {
		Node* comNode = root;

		while (cmpNode) {
			if (key < comNode->key) {
				comNode = comNode->left;  //  <  左子树  >  右子树  ==  本节点 
			}
			else if (key > comNode->key) {
				comNode = comNode->right;  //  <  左子树  >  右子树  ==  本节点 
			}
			else {
				return cmpNode;
			}
		}
		return cmpNode;
	}


	// 右旋函数
	void rightRotate(Node* node) {
		Node* l_son = node->left; //获取当前节点的左子节点
		// 当前节点的左子树变成左子节点的右子树
		node->left = l_son->right;
		// 如果左子节点的右子树非空，更新其父指针
		if (l_son->right)
			lson->right->parent = node;
		// 左子节点升为当前节点位置，并处理父节点关系
		l_son->parent = node->parent;

		if (!node->parent)
		{
			root = l_son;   //如果当前节点是根节点，更新根节点为左子节点
		}
		else if (node == node->parent->left) {
			node->parent->left = l_son; // 如果当前节点是其父节点的左子节点，更新父节点的左子节点为左子节点
		}
		else {
			node->parent->right = l_son;// 如果当前节点是其父节点的右子节点，更新父节点的右子节点为左子节点
		}

		//node用完了就给放到右子树去
		l_son->right = node;
		node->parent = l_son;
	}

	//左旋函数
	void leftRotate(Node* node) {
		Node* r_son = node->right;
		node->right = r_son->left;
		//维护双向
		if (r_son->left)
		{
			r_son->left->parent = node;
		}
		r_son->parent = node->parent;

		//根节点特判
		if (!node->parent)
		{
			root = l_son;
		}
		else if (node == node->parent->right) {
			node->parent->right = r_son;
		}
		else {
			node->parent->left = r_son;
		}

		//node用完了就给放到右子树去
		r_son->left = node;
		node->parent = r_son;

	}
};