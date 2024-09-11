#pragma once
#include <iostream>
#include <sstream>
#include <string>

enum class Color { RED, BLACK}; 


template < typename Key, typename Value > class RBTree {

	//������ڵ㶨��

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

	// ��ѯĳ�ڵ�
	Node* lookUp(Key key) {
		Node* comNode = root;

		while (cmpNode) {
			if (key < comNode->key) {
				comNode = comNode->left;  //  <  ������  >  ������  ==  ���ڵ� 
			}
			else if (key > comNode->key) {
				comNode = comNode->right;  //  <  ������  >  ������  ==  ���ڵ� 
			}
			else {
				return cmpNode;
			}
		}
		return cmpNode;
	}


	// ��������
	void rightRotate(Node* node) {
		Node* l_son = node->left; //��ȡ��ǰ�ڵ�����ӽڵ�
		// ��ǰ�ڵ��������������ӽڵ��������
		node->left = l_son->right;
		// ������ӽڵ���������ǿգ������丸ָ��
		if (l_son->right)
			lson->right->parent = node;
		// ���ӽڵ���Ϊ��ǰ�ڵ�λ�ã��������ڵ��ϵ
		l_son->parent = node->parent;

		if (!node->parent)
		{
			root = l_son;   //�����ǰ�ڵ��Ǹ��ڵ㣬���¸��ڵ�Ϊ���ӽڵ�
		}
		else if (node == node->parent->left) {
			node->parent->left = l_son; // �����ǰ�ڵ����丸�ڵ�����ӽڵ㣬���¸��ڵ�����ӽڵ�Ϊ���ӽڵ�
		}
		else {
			node->parent->right = l_son;// �����ǰ�ڵ����丸�ڵ�����ӽڵ㣬���¸��ڵ�����ӽڵ�Ϊ���ӽڵ�
		}

		//node�����˾͸��ŵ�������ȥ
		l_son->right = node;
		node->parent = l_son;
	}

	//��������
	void leftRotate(Node* node) {
		Node* r_son = node->right;
		node->right = r_son->left;
		//ά��˫��
		if (r_son->left)
		{
			r_son->left->parent = node;
		}
		r_son->parent = node->parent;

		//���ڵ�����
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

		//node�����˾͸��ŵ�������ȥ
		r_son->left = node;
		node->parent = r_son;

	}
};