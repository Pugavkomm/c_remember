#include <iostream>

typedef int Data;
typedef struct Node {
    Data data;
    struct Node* left;
    struct Node* right;
} Node;

Node *tree_add(Node* tree, Data x);
Node *tree_destroy(Node* tree);
Node *tree_search(Node* tree, Data x);
Node *tree_min(Node* tree);
Node *tree_max(Node* tree);
Node *tree_del_max(Node* tree);
Node *tree_del_min(Node* tree);
Node *tree_del(Node* tree, Data x);
void tree_print(Node *tree);
void print(Node* tree);


int main(){
    Node *tree = NULL; // point to root 
    Data test_data[] = {7, 3, 2, 1, 9, 5, 4, 6, 0, 0, 0, 0, 25, 1};
    for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i){
        tree = tree_add(tree, test_data[i]);
        print(tree);
    }
    std::cout << tree->data << '\n'; 

    Node *Node_find_root = NULL;
    Node_find_root = tree_search(tree, 3);
    print(Node_find_root);
    Node_find_root = tree_search(tree, 1);
    print(Node_find_root);
    std::cout << "min: " << tree_min(tree)->data << '\n';
    std::cout << "max: " << tree_max(tree)->data << '\n';
    print(tree);
	std::cout << "Delete min..." << '\n';
	tree = tree_del_min(tree);
	print(tree);
	std::cout << "Delete max..." << '\n';
	tree = tree_del_max(tree);
	print(tree);
	tree_del(tree, 4);
	print(tree);
    tree = tree_destroy(tree);
    return 0;
}



void tree_print(Node *tree){
    
    if (tree == NULL) return;
    tree_print(tree->left);
    std::cout << tree->data << ' ';
    tree_print(tree->right);
    
}

Node *tree_del_max(Node* tree){
	if (tree == NULL) return NULL;
	Node *max = NULL; 
	max = tree; 
	while (max->right->right != NULL){
		max = max->right;
	}
	free((void*)max->right);
	max->right = NULL;
	return tree; 
}

Node *tree_del_min(Node* tree){
	if (tree == NULL) return NULL; 
	Node *min = NULL;
   	min = tree; 
	while (min->left->left != NULL){
		min = min->left;
	}
	free((void*)min->left );
	min->left = NULL; 
	return tree; 
}

Node *tree_min(Node* tree){
    Node *min = NULL;
    if (tree == NULL) return NULL;
    min = tree;
    while (min->left != NULL){
        min = min->left;
    }
    return min;
}
Node *tree_max(Node* tree){
    Node *max = NULL;
    if (tree == NULL) return NULL;
    max = tree; 
    while(max->right != NULL){
        max = max->right;
    
    }
    return max;
}

Node *tree_del(Node* tree, Data x){
	if (tree == NULL) return NULL;

	if (x < tree->data)
		tree->left = tree_del(tree->left, x);
	else if (x > tree->data)
		tree->right = tree_del(tree->right, x);
	else{
		if (tree->left==NULL && tree->right==NULL){
			free((void*) tree);
			return NULL; 
		}
		else if (tree->right==NULL){
			Node *temp = tree->left;
			free((void*)tree); 
			return temp;
		}
		else if (tree->left == NULL){
			Node *temp = tree->right;
			free((void*)tree);
			return temp;
		}
		Node *temp = tree_min(tree->right);
		tree->data = temp->data;
		tree->right = tree_del(tree->right, temp->data);
	}
	return tree;
	
}

Node *tree_search(Node *tree, Data x){
    if (tree == NULL) return NULL;
    if (tree->data == x) return tree; 
    if (x < tree->data) 
        return (tree_search(tree->left, x));
    if (x > tree->data)
        return (tree_search(tree->right, x));
    return NULL;
}

Node *tree_add(Node *tree, Data x){
    if (tree == NULL){
        Node *t = (Node *)malloc(sizeof(Node));
        t->data = x;
        t->left = t->right = NULL;
        return t; 
    }
    if (x < tree->data){
        tree->left = tree_add(tree->left, x);
    } else if (x > tree->data){
        tree->right = tree_add(tree->right, x);
    }
    return tree;
}

Node * tree_destroy(Node *tree){
    if (tree == NULL) return NULL;  
    tree_destroy(tree->left);
    tree_destroy(tree->right);
    free((void *) tree); 
    return NULL;
   
}

void print(Node* tree){
    tree_print(tree);
    std::cout << '\n';
}
